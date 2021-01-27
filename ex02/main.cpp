/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: averheij <averheij@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/27 17:58:49 by averheij      #+#    #+#                 */
/*   Updated: 2021/01/27 18:12:12 by averheij      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <time.h>
#include <stdlib.h>
#include <iostream>
#include <exception>
#include "Classes.hpp"

Base		*generate(void) {
	switch(rand() % 3) {
		case 0: return (new A());
		case 1: return (new B());
		case 2: return (new C());
	}
	return (NULL);
}

void		identify_from_pointer(Base *p) {
	A *ptrA = dynamic_cast<A *>(p);
	if (ptrA != NULL)
		std::cout << "A" << std::endl;
	B *ptrB = dynamic_cast<B *>(p);
	if (ptrB != NULL)
		std::cout << "B" << std::endl;
	C *ptrC = dynamic_cast<C *>(p);
	if (ptrC != NULL)
		std::cout << "C" << std::endl;
}

void		identify_from_reference(Base &p) {
	try {
		A &ptr = dynamic_cast<A &>(p);
		static_cast<void>(ptr);
		std::cout << "A" << std::endl;
	} catch (std::exception &e) {
	}

	try {
		B &ptr = dynamic_cast<B &>(p);
		static_cast<void>(ptr);
		std::cout << "B" << std::endl;
	} catch (std::exception &e) {
	}

	try {
		C &ptr = dynamic_cast<C &>(p);
		static_cast<void>(ptr);
		std::cout << "C" << std::endl;
	} catch (std::exception &e) {
	}
}

int			main(void) {
	Base		*ptr;

	srand((int) time(0));

	ptr = generate();

	std::cout << "Identify by pointer: " << std::endl;
	identify_from_pointer(ptr);

	std::cout << "Identify by reference: " << std::endl;
	identify_from_pointer(ptr);

	return (0);
}
