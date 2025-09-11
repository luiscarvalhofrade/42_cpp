/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luide-ca <luide-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 21:23:19 by luide-ca          #+#    #+#             */
/*   Updated: 2025/08/19 22:43:05 by luide-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void) : _intFixedPoint(0) {
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int value) {
    std::cout << "Int constructor called" << std::endl;
    _intFixedPoint = value << _intFractional;
}

Fixed::Fixed(const float value) {
    std::cout << "Float constructor called" << std::endl;
     _intFixedPoint = static_cast<int>(roundf(value * (1 <<_intFractional)));
}

Fixed::Fixed(const Fixed& other) : _intFixedPoint(other._intFixedPoint) {
    std::cout << "Copy constructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed& other) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other) {
		_intFixedPoint = other._intFixedPoint;
	}
	return (*this);
}

Fixed::~Fixed(void) {
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const {
    std::cout << "getRawBits member function called" << std::endl;
    return _intFixedPoint;
}

void Fixed::setRawBits(int const raw) {
    std::cout << "setRawBits member function called" << std::endl;
    _intFixedPoint = raw;
}

float   Fixed::toFloat(void) const {
    return (static_cast<float>(_intFixedPoint) / (1 << _intFractional));
}

int Fixed::toInt(void) const {
    return (_intFixedPoint >> _intFractional);
}

std::ostream&	operator<<(std::ostream& out, const Fixed& fixed) {
	out << fixed.toFloat();
	return out;
}