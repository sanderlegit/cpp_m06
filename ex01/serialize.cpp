/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   serialize.cpp                                     e8'   8   '8e          */
/*                                                     +:+                    */
/*   By: averheij <averheij@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/27 13:15:20 by averheij      #+#    #+#                 */
/*   Updated: 2021/11/22 15:50:09 by dries               **ee8ee**            */
/*                                                                            */
/* ************************************************************************** */

#include "serialize.hpp"

std::string		*rand_string(int length) {
	std::string		*str = new std::string();

	for (int i = 0; i < length; i++) {
		switch (rand() % 3) {
			case 0: str->push_back((rand() % (ALPHAUPPERMAX - ALPHAUPPERMIN)) + ALPHAUPPERMIN);
					break;
			case 1: str->push_back((rand() % (ALPHALOWERMAX - ALPHALOWERMIN)) + ALPHALOWERMIN);
					break;
			case 2: str->push_back((rand() % (NUMMAX - NUMMIN)) + NUMMIN);
					break;
		}
	}
	return str;
}

void			*do_serialization(std::string *s1, std::string *s2, int n) {
	char			*serial;
	char			*tmp;
	int				offset;

	serial = new char[SERIALSIZE];
	std::memset(serial, 0, SERIALSIZE);

	offset = 0;
	tmp = reinterpret_cast<char *>(s1);
	for (int i = 0; i < static_cast<int>(sizeof(*s1)); i++) {
		*(serial + offset + i) = *(tmp + i);
	}

	offset += sizeof(*s1);
	tmp = reinterpret_cast<char *>(&n);
	for (int i = 0; i < static_cast<int>(sizeof(n)); i++) {
		*(serial + offset + i) = *(tmp + i);
	}

	offset += sizeof(n);
	tmp = reinterpret_cast<char *>(s2);
	for (int i = 0; i < static_cast<int>(sizeof(*s2)); i++) {
		*(serial + offset + i) = *(tmp + i);
	}

	return reinterpret_cast<void *>(serial);
}

void			*serialize(void) {
	std::string		*s1;
	std::string		*s2;
	int				n;
	void			*serial;

	std::cout << std::endl << "generating random values..." << std::endl;
	s1 = rand_string(8);
	s2 = rand_string(8);
	n = rand() % INT_MAX;
	std::cout << "s1: " << *s1 << std::endl;
	std::cout << "n: " << n << std::endl;
	std::cout << "s2: " <<  *s2 << std::endl;

	std::cout << std::endl << "serializing..." << std::endl;
	serial = do_serialization(s1, s2, n);

	delete s1;
	delete s2;

	return serial;
}
