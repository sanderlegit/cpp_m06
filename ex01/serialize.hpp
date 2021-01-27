/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   serialize.hpp                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: averheij <averheij@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/27 14:05:47 by averheij      #+#    #+#                 */
/*   Updated: 2021/01/27 17:43:36 by averheij      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZE_HPP
#define SERIALIZE_HPP
#include <string>
#include <iostream>
#include <stdlib.h> //rand
#include <time.h>	//time
#include <limits>
#include <cstring>	//memset

#define SERIALSIZE	static_cast<int>(sizeof(std::string) + sizeof(int) + sizeof(std::string))
#define ALPHAUPPERMAX	90
#define ALPHAUPPERMIN	65
#define ALPHALOWERMAX	122
#define ALPHALOWERMIN	97
#define NUMMAX	57
#define NUMMIN	48

std::string		*rand_string(int length);
int				rand_int(void);
void			*do_serialization(std::string *s1, std::string *s2, int n);
void			*serialize(void);

#endif
