/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Multitype.cpp                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: averheij <averheij@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/26 14:36:40 by averheij      #+#    #+#                 */
/*   Updated: 2021/01/26 17:40:50 by averheij      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Multitype.hpp"

Multitype::Multitype(void) {
	for (int i = 0; i < 4; i++)
		_valid[i] = 1;
	_c = 0;
	_i = 0;
	_f = 0.0f;
	_d = 0.0;
	_prec = 1;
	return;
}

Multitype::Multitype(std::string str) {//No -inf, +inf, nan
	for (int i = 0; i < 4; i++)
		_valid[i] = 0;
	_prec = 1;

	if (str.length() > 2 && str[0] == '\'' && str[2] == '\'') {
		_fromChar(str);
	} else if (str.find('.') != std::string::npos) {
		if (str.find('f') != std::string::npos)
			_fromFloat(str);
		else
			_fromDouble(str);
	} else {
		int		i = 0;
		while (iswspace(str[i]))
			i++;
		if (str[i] == '-')
			i++;
		for (; i < static_cast<int>(str.length()); i++) {
			if (!isdigit(str[i]))
				break;
			if (i == static_cast<int>(str.length() - 1)) {
				_fromInt(str);
				return;
			}
		}
		std::cout << "Invalid entry" << std::endl << std::endl;
	}
}


Multitype::Multitype(Multitype const & src) {
	*this = src;
	return;
}

Multitype::~Multitype(void) {
	return;
}

char					Multitype::getChar(void) {
	return (_c);
}

int						Multitype::getInt(void) {
	return (_i);
}

float					Multitype::getFloat(void) {
	return (_f);
}

double					Multitype::getDouble(void) {
	return (_d);
}

void					Multitype::_fromChar(std::string in) {
	std::cout << "from char" << std::endl << std::endl;
	_c = in[1];
	_valid[0] = 1;

	_i = static_cast<char>(_c);
	_valid[1] = 1;
	_f = static_cast<float>(_c);
	_valid[2] = 1;
	_d = static_cast<double>(_c);
	_valid[3] = 1;
	return ;
}

void					Multitype::_fromInt(std::string in) {
	std::istringstream	str(in);

	std::cout << "from int" << std::endl << std::endl;
	str >> _i;
	if (!str.fail())
		_valid[1] = 1;
	else
		return;

	if (_i >= -128 && _i <= 127) {
		_c = static_cast<char>(_i);
		_valid[0] = 1;
	}
	_f = static_cast<float>(_i);
	_valid[2] = 1;
	_d = static_cast<double>(_i);
	_valid[3] = 1;
	return ;
}

void					Multitype::_fromFloat(std::string in) {//no overflow check
	std::istringstream	str(in);
	double				tmp;

	std::cout << "from float" << std::endl << std::endl;
	str >> tmp;
	if (tmp >= (std::numeric_limits<float>::max() * -1) && tmp <= std::numeric_limits<float>::max())
		_valid[2] = 1;
	else
		return;
	_f = static_cast<float>(tmp);
	_prec = in.find('f') - in.find('.') - 1;

	if (_f >= -128.0f && _f <= 127.0f) {
		_c = static_cast<char>(_f);
		_valid[0] = 1;
	}
	if (_f >= -2147483648.0f && _f <= 2147483647.0f) {
		_i = static_cast<int>(_f);
		_valid[1] = 1;
	}
	_d = static_cast<double>(_f);
	_valid[3] = 1;
	return ;
}

void					Multitype::_fromDouble(std::string in) {//no overflow check
	std::istringstream	str(in);
	long double			tmp;

	std::cout << "from double" << std::endl << std::endl;
	str >> tmp;
	if (tmp >= (std::numeric_limits<double>::max() * -1) && tmp <= std::numeric_limits<double>::max())
		_valid[3] = 1;
	else
		return;
	_d = static_cast<double>(tmp);
	_prec = in.length() - in.find('.') - 1;

	if (_d >= -128.0 && _d <= 127.0) {
		_c = static_cast<char>(_d);
		_valid[0] = 1;
	}
	if (_d >= -2147483648.0 && _d <= 2147483647.0) {
		_i = static_cast<int>(_d);
		_valid[1] = 1;
	}
	if (_d >= (std::numeric_limits<float>::max() * -1) && _d <= std::numeric_limits<float>::max()) {
		_f = static_cast<float>(_d);
		_valid[2] = 1;
	}
	return ;
}

void					Multitype::output(void) {
	std::cout << "char: ";
	if (_valid[0])
		if (isprint(_c))
			std::cout << "'" << _c << "'" << std::endl;
		else
			std::cout << "Non displayable" << std::endl;
	else
		std::cout << "impossible" << std::endl;

	std::cout << "int: ";
	if (_valid[1])
		std::cout << _i << std::endl;
	else
		std::cout << "impossible" << std::endl;

	std::cout << "float: ";
	if (_valid[2])
		std::cout << std::fixed << std::setprecision(_prec) << _f << "f" << std::endl;
	else
		std::cout << "impossible" << std::endl;

	std::cout << "double: ";
	if (_valid[3])
		std::cout << std::fixed << std::setprecision(_prec) << _d << std::endl;
	else
		std::cout << "impossible" << std::endl;
}


Multitype &					Multitype::operator=(Multitype const & rhs) {
	for (int i = 0; i < 4; i++)
		_valid[i] =rhs._valid[i];
	_c = rhs._c;
	_i = rhs._i;
	_f = rhs._f;
	_d = rhs._d;
	return *this;
}
