/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   deserialize.hpp                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: averheij <averheij@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/27 14:07:49 by averheij      #+#    #+#                 */
/*   Updated: 2021/01/27 14:49:00 by averheij      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef DESERIALIZE_HPP
#define DESERIALIZE_HPP
#include <iostream>
#include <string>

struct Data {
	std::string		s1;
	int				n;
	std::string		s2;
};

Data				*deserialize(void *raw);

#endif
