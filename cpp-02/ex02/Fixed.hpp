/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luide-ca <luide-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 21:16:37 by luide-ca          #+#    #+#             */
/*   Updated: 2025/08/19 23:34:18 by luide-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed {
private:
        int _intFixedPoint;
        static int const _intFractional = 8;
public:
        Fixed(void);
        Fixed(const int value);
        Fixed(const float value);
        Fixed(const Fixed& other);
        
        Fixed& operator=(const Fixed& other);
        
        bool operator>(const Fixed& other) const;
        bool operator>=(const Fixed& other) const;
        bool operator<(const Fixed& other) const;
        bool operator<=(const Fixed& other) const;
        bool operator==(const Fixed& other) const;
        bool operator!=(const Fixed& other) const;

        Fixed operator+(const Fixed& other) const;
        Fixed operator-(const Fixed& other) const;
        Fixed operator*(const Fixed& other) const;
        Fixed operator/(const Fixed& other) const;

        Fixed&	operator++(void);
        Fixed&	operator--(void);
        Fixed	operator++(int);
        Fixed	operator--(int);

        static Fixed&	min(Fixed& a, Fixed& b);
        static Fixed&	max(Fixed& a, Fixed& b);
        static const Fixed&    min(const Fixed& a, const Fixed& b);
        static const Fixed&    max(const Fixed& a, const Fixed& b);
        
        ~Fixed(void);

        int getRawBits(void) const;
        void setRawBits(int const raw);
        float toFloat(void) const;
        int toInt(void) const;
};

std::ostream& operator<<(std::ostream& os, const Fixed& obj);

#endif