/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 20:22:59 by jbrousse          #+#    #+#             */
/*   Updated: 2024/10/23 20:58:10 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "BigInt.hpp"

void BigInt::printBinary() const
{
	std::cout << (m_negative ? "-" : "") << " ";
	for (int i = m_size - 1; i >= 0; --i) {
		for (int j = 7; j >= 0; --j) {
			std::cout << ((m_num[i] >> j) & 1);
		}
		std::cout << " ";
	}
	std::cout << std::endl;
}

void BigInt::printHex() const
{
	std::cout << (m_negative ? "-" : "") << " ";
	for (int i = m_size - 1; i >= 0; --i) {
		std::cout << std::hex << (int)m_num[i] << " ";
	}
	std::cout << std::endl;
}

void BigInt::printDecimal() const
{
	int result = 0;
	std::cout << (m_negative ? "-" : "") << " ";
	for (int i = m_size - 1; i >= 0; --i) {
		result = (result << 8) + m_num[i];
	}
	std::cout << result << std::endl;
}