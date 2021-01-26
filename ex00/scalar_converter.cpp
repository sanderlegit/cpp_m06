/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   scalar_converter.cpp                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: averheij <averheij@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/26 14:07:00 by averheij      #+#    #+#                 */
/*   Updated: 2021/01/26 17:45:35 by averheij      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <sstream>
#include <iostream>
#include "Multitype.hpp"

int		main(int argc, char **argv) {
	Multitype		*m;

	if (argc != 2) {
		std::cout << "Invalid arguments" << std::endl;
		return (1);
	}
	std::cout << "in: " << argv[1] << std::endl;
	m = new Multitype(argv[1]);
	m->output();
	delete m;
	return (0);
}

