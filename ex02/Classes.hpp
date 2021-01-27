/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Classes.hpp                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: averheij <averheij@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/27 17:55:45 by averheij      #+#    #+#                 */
/*   Updated: 2021/01/27 17:56:51 by averheij      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLASSES_HPP
#define CLASSES_HPP

class Base {
	public:
		virtual ~Base(void);
};

class A : public Base {
};

class B : public Base {
};

class C : public Base {
};

#endif
