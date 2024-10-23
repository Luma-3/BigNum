/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 20:35:56 by jbrousse          #+#    #+#             */
/*   Updated: 2024/10/23 21:18:07 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

#include "BigInt.hpp"

// #define SIZE 4

// void printBinary(u_int8_t num)
// {
// 	for (int j = 7; j >= 0; --j) {
// 		std::cout << ((num >> j) & 1);
// 	}
// 	std::cout << " ";
// }

// void mult(std::array<u_int8_t, SIZE> &num1, std::array<u_int8_t, SIZE> &num2,
// 		  std::array<u_int8_t, 2 * SIZE> &result)
// {
// 	std::fill(result.begin(), result.end(), 0);
// 	for (int i = SIZE - 1; i >= 0; --i) {
// 		u_int8_t carry = 0;
// 		for (int j = SIZE - 1; j >= 0; --j) {
// 			u_int16_t tmp = result[i + j + 1] + num1[i] * num2[j] + carry;
// 			printBinary(tmp);
// 			std::cout << std::endl;
// 			result[i + j + 1] = tmp & 0xFF;
// 			carry = (tmp >> 8) & 0xFF;
// 		}
// 		result[i] += carry;
// 	}
// }

// int HexToInt(std::array<u_int8_t, SIZE> &num)
// {
// 	int result = 0;
// 	for (int i = 0; i < SIZE; ++i) {
// 		result = (result << 8) + num[i];
// 	}
// 	return result;
// }

// int HexToInt(std::array<u_int8_t, 2 * SIZE> &num)
// {
// 	int result = 0;
// 	for (int i = 0; i < 2 * SIZE; ++i) {
// 		result = (result << 8) + num[i];
// 	}
// 	return result;
// }

int main()
{

	// std::array<u_int8_t, SIZE> num1 = {0x00, 0x00, 0xA3, 0x00};
	// std::cout << "Num1: " << HexToInt(num1) << std::endl;
	// std::cout << "Num1 Binary: ";
	// for (int i = 0; i < SIZE; ++i) {
	// 	printBinary(num1[i]);
	// }
	// std::cout << std::endl;

	// std::array<u_int8_t, SIZE> num2 = {0x00, 0x00, 0xB2, 0x00};
	// std::cout << "Num2: " << HexToInt(num2) << std::endl;
	// std::cout << "Num2 Binary: ";
	// for (int i = 0; i < SIZE; ++i) {
	// 	printBinary(num2[i]);
	// }
	// std::cout << std::endl;

	// std::array<u_int8_t, 2 * SIZE> result;

	// mult(num1, num2, result);

	// std::cout << "Result: " << HexToInt(result) << std::endl;

	Int num(340000);
	Int num2(340000);

	std::cout << "Binary: ";
	num.printBinary();
	std::cout << std::endl;

	std::cout << "Decimal: ";
	num.printDecimal();
	std::cout << std::endl;

	std::cout << "Hexa: ";
	num.printHex();
	std::cout << std::endl;

	Int result = num + num2;

	std::cout << "Result: ";
	result.printBinary();
	std::cout << std::endl;

	return 0;
}