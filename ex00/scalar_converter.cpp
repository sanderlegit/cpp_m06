/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   scalar_converter.cpp                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: averheij <averheij@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/26 14:07:00 by averheij      #+#    #+#                 */
/*   Updated: 2021/01/26 16:44:25 by averheij      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <sstream>
#include <iostream>
#include "Multitype.hpp"

//Multitype	*to_char(std::string str) {

//}

//Multitype	*to_int(std::string str) {
	//int i;

	//std::istringstream(str) >> i;
	//std::cout << i;
//}

//Multitype	*to_float(std::string str) {

//}

//Multitype	*to_double(std::string str) {

//}

int		main(int argc, char **argv) {
	Multitype		*m;

	if (argc != 2) {
		std::cout << "Invalid arguments" << std::endl;
		return (1);
	}
	//Convert given str literal to represented type
	std::cout << "in: " << argv[1] << std::endl;
	m = new Multitype(argv[1]);
	m->output();
	return (0);
}

