/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operatorArithmetic.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 20:49:30 by jbrousse          #+#    #+#             */
/*   Updated: 2024/10/27 11:59:31 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "BigInt.hpp"

BigInt BigInt::operator+(const BigInt &other) const
{
	size_t size;
	// m_negative == other.m_negative
	if (m_negative == other.m_negative) {
		bytes *result = add(m_num, m_size, other.m_num, other.m_size, size);
		return BigInt(result, size, m_negative);
	}
	// m_negative != other.m_negative
	int cmp = compare(m_num, m_size, other.m_num, other.m_size);
	if (cmp > 0) {
		bytes *result = sub(m_num, m_size, other.m_num, other.m_size, size);
		return BigInt(result, size, m_negative);
	} else if (cmp < 0) {
		bytes *result = sub(other.m_num, other.m_size, m_num, m_size, size);
		return BigInt(result, size, other.m_negative);
	}
	return BigInt();
}

BigInt BigInt::operator-(const BigInt &other) const
{
	size_t size;
	// m_negative == other.m_negative
	if (m_negative == other.m_negative) {
		int cmp = compare(m_num, m_size, other.m_num, other.m_size);
		if (cmp > 0) {
			bytes *result = sub(m_num, m_size, other.m_num, other.m_size, size);
			return BigInt(result, size, m_negative);
		} else if (cmp < 0) {
			bytes *result = sub(other.m_num, other.m_size, m_num, m_size, size);
			return BigInt(result, size, !m_negative);
		}
		return BigInt();
	}
	// m_negative != other.m_negative
	bytes *result = add(m_num, m_size, other.m_num, other.m_size, size);
	return BigInt(result, size, m_negative);
}

BigInt BigInt::operator*(const BigInt &other) const
{
	size_t size;
	bytes *result = mult(m_num, m_size, other.m_num, other.m_size, size);
	return BigInt(result, size, m_negative != other.m_negative);
}

BigInt BigInt::operator/(const BigInt &other) const
{
	size_t size;
	bytes *result = div(m_num, m_size, other.m_num, other.m_size, size);
	return BigInt(result, size, m_negative != other.m_negative);
}