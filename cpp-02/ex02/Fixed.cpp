/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luide-ca <luide-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 21:23:19 by luide-ca          #+#    #+#             */
/*   Updated: 2025/08/19 23:29:51 by luide-ca         ###   ########.fr       */
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
    _intFixedPoint = roundf(value * (1 << _intFractional));
}

Fixed::Fixed(const Fixed& other) : _intFixedPoint(other._intFixedPoint) {
    std::cout << "Copy constructor called" << std::endl;
}

Fixed::~Fixed(void) {
    std::cout << "Destructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed& other) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other)
        _intFixedPoint = other._intFixedPoint;
    return *this;
}

bool Fixed::operator>(const Fixed& other) const {
    std::cout << "Greater than comparison operator called" << std::endl;
    return (_intFixedPoint > other._intFixedPoint);
}

bool Fixed::operator>=(const Fixed& other) const {
    std::cout << "Greate or equal than comparison operator called" << std::endl;
    return (_intFixedPoint >= other._intFixedPoint);
}

bool Fixed::operator<(const Fixed& other) const {
    std::cout << "Less than comparison operator called" << std::endl;
    return (_intFixedPoint < other._intFixedPoint);
}

bool Fixed::operator<=(const Fixed& other) const {
    std::cout << "Less or equal than comparison operator called" << std::endl;
    return (_intFixedPoint <= other._intFixedPoint);
}

bool Fixed::operator==(const Fixed& other) const {
    return (_intFixedPoint == other._intFixedPoint);
}

bool Fixed::operator!=(const Fixed& other) const {
    std::cout << "Different comparison operator called" << std::endl;
    return (_intFixedPoint != other._intFixedPoint);
}

Fixed Fixed::operator+(const Fixed& other) const {
    Fixed result;
    result.setRawBits(this->_intFixedPoint + other._intFixedPoint);
    return (result);
}

Fixed Fixed::operator-(const Fixed& other) const {
    Fixed result;
    result.setRawBits(this->_intFixedPoint - other._intFixedPoint);
    return (result);
}

Fixed Fixed::operator*(const Fixed& other) const {
    Fixed	result;
	result.setRawBits((this->_intFixedPoint * other._intFixedPoint) >> _intFractional);
	return result;
}

Fixed Fixed::operator/(const Fixed& other) const {
	if (other._intFixedPoint == 0) {
		if (this->_intFixedPoint > 0)
			return (Fixed(INFINITY));
		else if (this->_intFixedPoint < 0)
			return (Fixed(-INFINITY));
		else
			return (Fixed(0));
	}
	Fixed	result;
	result.setRawBits((this->_intFixedPoint << _intFractional) / other._intFixedPoint);
	return result;
}

Fixed&	Fixed::operator++() {
    _intFixedPoint++;
	return *this;
}

Fixed&	Fixed::operator--() {
    _intFixedPoint--;
	return *this;
}

Fixed	Fixed::operator++(int) {
	Fixed	temp(*this);
    _intFixedPoint++;
	return temp;
}

Fixed	Fixed::operator--(int) {
	Fixed	temp(*this);
    _intFixedPoint--;
	return temp;
}

Fixed&	Fixed::min(Fixed& a, Fixed& b) {
	return (a < b) ? a : b;
}

const Fixed&	Fixed::min(const Fixed& a, const Fixed& b) {
	return (a < b) ? a : b;
}

Fixed&	Fixed::max(Fixed& a, Fixed& b) {
	return (a > b) ? a : b;
}

const Fixed&	Fixed::max(const Fixed& a, const Fixed& b) {
	return (a > b) ? a : b;
}

int Fixed::getRawBits(void) const {
    std::cout << "getRawBits member function called" << std::endl;
    return _intFixedPoint;
}

void Fixed::setRawBits(int const raw) {
    std::cout << "setRawBits member function called" << std::endl;
    _intFixedPoint = raw;
}

float Fixed::toFloat(void) const {
    return static_cast<float>(_intFixedPoint) / (1 << _intFractional);
}

int Fixed::toInt(void) const {
    return _intFixedPoint >> _intFractional;
}