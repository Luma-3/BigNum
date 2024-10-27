/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 20:22:59 by jbrousse          #+#    #+#             */
/*   Updated: 2024/10/26 21:29:29 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <deque>
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

// TODO : Optimize with a most greater block of bytes (like 1000)
void BigInt::printDecimal() const
{
	std::deque<bytes> number;
	for (int i = m_size - 1; i >= 0; --i) {
		number.push_back(m_num[i]);
	}

	std::string result;
	while (!number.empty() && !(number.size() == 1 && number[0] == 0)) {
		int remainder = 0;

		for (size_t i = 0; i < number.size(); ++i) {
			int current = remainder * 256 + number[i];
			number[i] = current / 10;
			remainder = current % 10;
		}

		while (!number.empty() && number.front() == 0) {
			number.pop_front();
		}

		result.insert(result.begin(), '0' + remainder);
	}

	std::cout << (m_negative ? "-" : "") << (result.empty() ? "0" : result)
			  << std::endl;
}