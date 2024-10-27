/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BigInt.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 19:29:31 by jbrousse          #+#    #+#             */
/*   Updated: 2024/10/27 11:57:36 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BIGINT_HPP
#define BIGINT_HPP

#include <cstddef>

typedef unsigned char	   bytes;
typedef unsigned short int u_16int;

#define MASK16 0x10000
#define MASK8  0x100

class BigInt
{
  private:
	bytes			  *m_num;
	size_t			   m_size;
	bool			   m_negative;
	static const bytes m_mask = 0xFF;

	BigInt(bytes *num, size_t size, bool negative);

	void resize(int size);
	void copy(const BigInt &other);
	void clear();

	static bytes *IntToBytes(int num, size_t &size, bool &negative);

	static bytes *add(const bytes *num1, size_t size1, const bytes *num2,
					  size_t size2, size_t &size);
	static bytes *sub(const bytes *num1, size_t size1, const bytes *num2,
					  size_t size2, size_t &size);
	static bytes *mult(const bytes *num1, size_t size1, const bytes *num2,
					   size_t size2, size_t &size);
	static bytes *div(const bytes *num1, size_t size1, const bytes *num2,
					  size_t size2, size_t &size);

	static int compare(const bytes *num1, size_t size1, const bytes *num2,
					   size_t size2);

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