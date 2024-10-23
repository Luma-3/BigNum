/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BigInt.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 19:29:31 by jbrousse          #+#    #+#             */
/*   Updated: 2024/10/23 21:11:35 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BIGINT_HPP
#define BIGINT_HPP

#include <cstddef>

typedef unsigned char bytes;

class BigInt
{
  private:
	bytes			  *m_num;
	int				   m_size;
	bool			   m_negative;
	static const bytes m_mask = 0xFF;

	void resize(int size);
	void copy(const BigInt &other);
	void clear();

	static bytes *IntToBytes(int num, int &size, bool &negative);

	static bytes *add(const bytes *num1, int size1, const bytes *num2,
					  int size2, int &size);
	static bytes *sub(const bytes *num1, int size1, const bytes *num2,
					  int size2, int &size);
	static bytes *mult(const bytes *num1, int size1, const bytes *num2,
					   int size2, int &size);

	int compare(const bytes *num1, int size1, const bytes *num2,
				int size2) const;

  public:
	BigInt();
	BigInt(int num);
	BigInt(const BigInt &other);
	~BigInt();

	BigInt &operator=(const BigInt &other);
	BigInt	operator+(const BigInt &other) const;
	BigInt	operator-(const BigInt &other) const;
	BigInt	operator*(const BigInt &other) const;
	BigInt	operator/(const BigInt &other) const;
	BigInt	operator%(const BigInt &other) const;
	BigInt	operator<<(int shift) const;
	BigInt	operator>>(int shift) const;
	BigInt	operator&(const BigInt &other) const;
	BigInt	operator|(const BigInt &other) const;
	BigInt	operator^(const BigInt &other) const;
	BigInt	operator~() const;
	BigInt	operator-() const;
	BigInt	operator++();
	BigInt	operator++(int);
	BigInt	operator--();
	BigInt	operator--(int);
	bool	operator==(const BigInt &other) const;
	bool	operator!=(const BigInt &other) const;
	bool	operator<(const BigInt &other) const;
	bool	operator>(const BigInt &other) const;
	bool	operator<=(const BigInt &other) const;
	bool	operator>=(const BigInt &other) const;

	static BigInt add(const BigInt &num1, const BigInt &num2);
	static BigInt sub(const BigInt &num1, const BigInt &num2);
	static BigInt mult(const BigInt &num1, const BigInt &num2);
	static BigInt div(const BigInt &num1, const BigInt &num2);

	void printBinary() const;
	void printHex() const;
	void printDecimal() const;
};

typedef BigInt Int;

#endif // BIGINT_HPP