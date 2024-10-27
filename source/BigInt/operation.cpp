/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 11:30:32 by jbrousse          #+#    #+#             */
/*   Updated: 2024/10/27 12:05:26 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <algorithm>

#include "BigInt.hpp"

bytes *BigInt::div(const bytes *num1, size_t size1, const bytes *num2,
				   size_t size2, size_t &size)
{
	bytes *U = new bytes[size1];
	bytes *V = new bytes[size2];
	bytes *Q = new bytes[size1 - size2 + 1];
	bytes *R = new bytes[size1];

	for (size_t i = 0; i < size1; ++i) {
		U[i] = num1[i];
	}
	for (size_t i = 0; i < size2; ++i) {
		V[i] = num2[i];
	}

	// Normalize
	int shift = 0;
	while (V[size2 - 1] < 0x80) {
		++shift;
		for (size_t i = size2 - 1; i > 0; --i) {
			V[i] = (V[i] << 1) | (V[i - 1] >> 7);
		}
		V[0] <<= 1;
	}
	if (shift > 0) {
		for (size_t i = size1 - 1; i > 0; --i) {
			U[i] = (U[i] << shift) | (U[i - 1] >> (8 - shift));
		}
		U[0] <<= shift;
	}

	// Initialize Q and R to zero
	std::fill(Q, Q + size1 - size2 + 1, 0);
	std::fill(R, R + size1, 0);

	// Main loop
	for (size_t i = size1 - size2; i >= 0; --i) {
		// Approximate Q[i]
		if (V[size2 - 1] != 0) {
			Q[i] = (U[i + size2] * 0x100 + U[i + size2 - 1]) / V[size2 - 1];
		} else {
			Q[i] = 0xFF;
		}
		size_t sizeQ = 1;
		bytes *tmp = mult(V, size2, &Q[i], 1, sizeQ);
		while (compare(U + i, size2 + 1, tmp, sizeQ) < 0) {
			--Q[i];
			delete[] tmp;
			tmp = mult(V, size2, &Q[i], 1, sizeQ);
		}
	}

	// Compute R
	for (size_t i = 0; i < size1; ++i) {
		R[i] = U[i];
	}
	for (size_t i = 0; i < size1 - size2 + 1; ++i) {
		bytes *tmp = mult(V, size2, &Q[i], 1, size);
		for (size_t j = 0; j < size; ++j) {
			R[i + j] -= tmp[j];
		}
		delete[] tmp;
	}

	// Denormalize
	if (shift > 0) {
		for (ssize_t i = size1 - 1; i >= 0; --i) {
			R[i] = (R[i] >> shift) | (R[i + 1] << (8 - shift));
		}
	}

	// Normalize R
	while (R[size1 - 1] < 0x80) {
		--size1;
	}
	size = size1;
	return R;
}