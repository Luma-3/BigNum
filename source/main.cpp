/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 20:35:56 by jbrousse          #+#    #+#             */
/*   Updated: 2024/10/27 12:00:37 by jbrousse         ###   ########.fr       */
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
	// Test Div
	BigInt a(3456789);
	BigInt b(123456);

	BigInt c = a / b;
	c.printDecimal();
}

#include <iostream>
#include <string>
#include <vector>

// std::string bigIntToDecimalString(const std::vector<bytes> &bytes1)
// {
// 	std::vector<bytes> number(bytes1); // Copie du nombre pour manipulation
// 	std::string		   result;

// 	// Tant que le nombre n'est pas réduit à zéro
// 	while (!number.empty() && !(number.size() == 1 && number[0] == 0)) {
// 		int remainder = 0;

// 		// Division en cascade par 10
// 		for (size_t i = 0; i < number.size(); ++i) {
// 			std::cout << "number[i] : " << '0' + number[i] << std::endl;
// 			int current = remainder * 256 +
// 						  number[i];  // Intègre le retenu à l'octet actuel
// 			number[i] = current / 10; // Met à jour l'octet avec le quotient
// 			remainder = current % 10; // Calcul du reste pour le prochain octet
// 		}

// 		// Supprime les zéros non-significatifs
// 		while (!number.empty() && number[0] == 0) {
// 			number.erase(number.begin());
// 		}

// 		// Ajoute le chiffre de l'unité trouvé
// 		result.insert(result.begin(), '0' + remainder);
// 	}

// 	return result.empty() ? "0" : result;
// }

// std::string bigIntToDecimalStringLittleEndian(const std::vector<bytes>
// &bytes1)
// {
// 	std::vector<bytes> number(bytes1); // Copie du nombre pour manipulation
// 	std::string		   result;

// 	// Tant que le nombre n'est pas réduit à zéro
// 	while (!number.empty() && !(number.size() == 1 && number[0] == 0)) {
// 		int remainder = 0;

// 		// Division en cascade par 10 en partant de l'octet le moins
// 		// significatif
// 		for (size_t i = 0; i < number.size(); ++i) {
// 			int current = remainder * 256 +
// 						  number[i];  // Intègre le retenu à l'octet actuel
// 			number[i] = current / 10; // Met à jour l'octet avec le quotient
// 			remainder = current % 10; // Calcul du reste pour le prochain octet
// 		}

// 		// Supprime les zéros non-significatifs
// 		while (!number.empty() && number.back() == 0) {
// 			number.pop_back();
// 		}

// 		// Ajoute le chiffre de l'unité trouvé
// 		result.insert(result.begin(), '0' + remainder);
// 	}

// 	return result.empty() ? "0" : result;
// }

// int main()
// {
// 	// Exemple de nombre très grand : 0x0504030201 (little-endian)
// 	std::vector<bytes> bigNumber;

// 	bigNumber.push_back(0x05);
// 	bigNumber.push_back(0x04);
// 	bigNumber.push_back(0x03);
// 	bigNumber.push_back(0x02);
// 	bigNumber.push_back(0x01);

// 	std::string decimalRepresentation =
// 		bigIntToDecimalStringLittleEndian(bigNumber);
// 	std::cout << "Représentation décimale : " << decimalRepresentation
// 			  << std::endl;

// 	return 0;
// }

// int main()
// {
// 	// Exemple de nombre très grand : 0x0102030405 (big endian)
// 	std::vector<bytes> bigNumber;

// 	bigNumber.push_back(0x05);
// 	bigNumber.push_back(0x30);
// 	bigNumber.push_back(0x20);

// 	for (const auto &byte : bigNumber) {
// 		std::cout << std::hex << static_cast<int>(byte) << " ";
// 	}

// 	std::string decimalRepresentation = bigIntToDecimalString(bigNumber);
// 	std::cout << "Représentation décimale : " << decimalRepresentation
// 			  << std::endl;

// 	return 0;
// }

// 2147483647
// 4328719365