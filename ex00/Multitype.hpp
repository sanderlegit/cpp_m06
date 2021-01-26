/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Multitype.hpp                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: averheij <averheij@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/26 14:36:42 by averheij      #+#    #+#                 */
/*   Updated: 2021/01/26 16:40:51 by averheij      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef MULTITYPE_HPP
# define MULTITYPE_HPP
# include <string>
# include <sstream>
# include <iostream>
# include <ctype.h>
# include <iomanip>

class Multitype {
	public:
		Multitype(void);
		Multitype(std::string str);
		Multitype(Multitype const & src);
		~Multitype(void);

		char					getChar(void);
		int						getInt(void);
		float					getFloat(void);
		double					getDouble(void);

		void					output(void);

		Multitype &				operator=(Multitype const & rhs);
	private:
		bool					_valid[4];
		char					_c;
		int						_i;
		float					_f;
		double					_d;
		int						_prec;

		void					_fromChar(std::string in);
		void					_fromInt(std::string in);
		void					_fromFloat(std::string in);
		void					_fromDouble(std::string in);


};

#endif
