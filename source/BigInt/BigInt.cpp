/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BigInt.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 19:35:59 by jbrousse          #+#    #+#             */
/*   Updated: 2024/10/23 21:17:56 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BigInt.hpp"

#include <iostream>

BigInt::BigInt() : m_num(NULL), m_size(0), m_negative(false) {}

BigInt::BigInt(int num) : m_negative(false)
{
	m_num = IntToBytes(num, m_size, m_negative);
}

BigInt::BigInt(const BigInt &other)
{
	copy(other);
}

BigInt::~BigInt()
{
	clear();
}

bytes *BigInt::IntToBytes(int num, int &size, bool &negative)
{
	if (num == 0) {
		size = 1;
		bytes *result = new bytes[size];
		result[0] = 0;
		return result;
	}
	if (num < 0) {
		negative = true;
		num = -num;
	}
	size = 0;
	int tmp = num;
	while (tmp) {
		tmp >>= 8;
		++size;
	}
	bytes *result = new bytes[size];
	for (int i = 0; i < size; ++i) {
		result[i] = num & m_mask;
		num >>= 8;
	}
	return result;
}

void BigInt::resize(int size)
{
	bytes *tmp = new bytes[size];
	for (int i = 0; i < m_size && i < size; ++i) {
		tmp[i] = m_num[i];
	}
	delete[] m_num;
	m_num = tmp;
	m_size = size;
}

void BigInt::copy(const BigInt &other)
{
	m_negative = other.m_negative;
	m_num = new bytes[other.m_size];
	for (int i = 0; i < other.m_size; ++i) {
		m_num[i] = other.m_num[i];
	}
	m_size = other.m_size;
}

void BigInt::clear()
{
	m_size;
	delete m_num;
}

bytes *BigInt::add(const bytes *num1, int size1, const bytes *num2, int size2,
				   int &size)
{
	size = (size1 > size2) ? size1 + 1 : size2 + 1;
	bytes *result = new bytes[size];
	int	   carry = 0;
	for (int i = 0; i < size; ++i) {
		int tmp = carry;
		if (i < size1) {
			tmp += num1[i];
		}
		if (i < size2) {
			tmp += num2[i];
		}
		result[i] = tmp & m_mask;
		carry = tmp >> 8;
	}
	return result;
}

bytes *BigInt::sub(const bytes *num1, int size1, const bytes *num2, int size2,
				   int &size)
{
	size = size1;
	bytes *result = new bytes[size];
	int	   carry = 0;
	for (int i = 0; i < size; ++i) {
		int tmp = carry;
		if (i < size1) {
			tmp += num1[i];
		}
		if (i < size2) {
			tmp -= num2[i];
		}
		if (tmp < 0) {
			carry = -1;
			tmp += m_mask + 1;
		} else {
			carry = 0;
		}
		result[i] = tmp & m_mask;
	}
	return result;
}

int BigInt::compare(const bytes *num1, int size1, const bytes *num2,
					int size2) const
{
	if (size1 > size2) {
		return 1;
	}
	if (size1 < size2) {
		return -1;
	}
	for (int i = size1 - 1; i >= 0; --i) {
		if (num1[i] > num2[i]) {
			return 1;
		}
		if (num1[i] < num2[i]) {
			return -1;
		}
	}
	return 0;
}