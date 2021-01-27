/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: averheij <averheij@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/27 13:15:20 by averheij      #+#    #+#                 */
/*   Updated: 2021/01/27 17:47:33 by averheij      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <bitset>	//displaying bits
#include "serialize.hpp"
#include "deserialize.hpp"

void	print_serial(void *raw) {
	std::cout << "serial size: " << (SERIALSIZE) << std::endl;
	std::cout << "serial data: " << std::endl;
	std::cout << "s1: " << std::endl;
	for (int i = 0; i < static_cast<int>(sizeof(std::string)); i++) {
		std::bitset<8> bits(static_cast<char *>(raw)[i]);
		std::cout << bits << " ";
		if ((i + 1) % 8 == 0 && i != 0 && i != (static_cast<int>(sizeof(std::string))) - 1)
			std::cout << std::endl;
	}
	std::cout << std::endl;
	std::cout << "n: " << std::endl;
	for (int i = 0; i < static_cast<int>(sizeof(int)); i++) {
		std::bitset<8> bits(static_cast<char *>(raw)[i]);
		std::cout << bits << " ";
	}
	std::cout << std::endl;
	std::cout << "s2: " << std::endl;
	for (int i = 0; i < static_cast<int>(sizeof(std::string)); i++) {
		std::bitset<8> bits(static_cast<char *>(raw)[i]);
		std::cout << bits << " ";
		if ((i + 1) % 8 == 0 && i != 0 && i != (static_cast<int>(sizeof(std::string))) - 1)
			std::cout << std::endl;
	}
	std::cout << std::endl;
}

int		main(void) {
	void		*raw;
	Data		*data;

	srand((int) time(0));

	raw = serialize();

	print_serial(raw);

	data = deserialize(raw);

	std::cout << "s1: " << data->s1 << std::endl;
	std::cout << "n: " << data->n << std::endl;
	std::cout << "s2: " << data->s2 << std::endl;
}
