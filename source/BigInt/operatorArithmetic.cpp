/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operatorArithmetic.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 20:49:30 by jbrousse          #+#    #+#             */
/*   Updated: 2024/10/23 21:15:16 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "BigInt.hpp"

BigInt BigInt::operator+(const BigInt &other) const
{
	// Negative + Negative or Positive + Positive
	if (m_negative == other.m_negative) {
		std::cout << "Add" << std::endl;
		int	   size;
		bytes *result = add(m_num, m_size, other.m_num, other.m_size, size);
		BigInt tmp;
		tmp.m_num = result;
		tmp.m_size = size;
		tmp.m_negative = m_negative;
		return tmp;
	}
	// Negative + Positive
	else {
		if (compare(m_num, m_size, other.m_num, other.m_size) > 0) {
			int	   size;
			bytes *result = sub(m_num, m_size, other.m_num, other.m_size, size);
			BigInt tmp;
			tmp.m_num = result;
			tmp.m_size = size;
			tmp.m_negative = true;
			return tmp;
		}
		if (compare(m_num, m_size, other.m_num, other.m_size) < 0) {
			int	   size;
			bytes *result = sub(other.m_num, other.m_size, m_num, m_size, size);
			BigInt tmp;
			tmp.m_num = result;
			tmp.m_size = size;
			tmp.m_negative = false;
			return tmp;
		}
	}
	std::cout << "Error: operator+()" << std::endl;
	return BigInt();
}