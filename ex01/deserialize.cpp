/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   deserialize.cpp                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: averheij <averheij@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/27 14:07:47 by averheij      #+#    #+#                 */
/*   Updated: 2021/01/27 17:38:22 by averheij      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "deserialize.hpp"

Data			*deserialize(void *raw) {
	Data			*d = new Data();
	char			*serial;

	std::cout << std::endl << "deserializing..." << std::endl;
	serial = reinterpret_cast<char *>(raw);

	d->s1 = *reinterpret_cast<std::string *>(serial);
	serial += sizeof(std::string);

	d->n = *reinterpret_cast<int *>(serial);
	serial += sizeof(int);

	d->s2 = *reinterpret_cast<std::string *>(serial);
	return d;
}
