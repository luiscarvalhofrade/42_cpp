/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luide-ca <luide-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 17:46:30 by luide-ca          #+#    #+#             */
/*   Updated: 2025/11/21 16:02:26 by luide-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALAR_CONVERTER_HPP
# define SCALAR_CONVERTER_HPP

# include <iostream>
#include <limits>
#include <cstdlib>
#include <cerrno>
#include <cctype>
#include <iomanip>

class ScalarConverter {
    private:
        // Not instantiable
        ScalarConverter();
        ScalarConverter(const ScalarConverter &other);
        ScalarConverter &operator=(const ScalarConverter &other);
        ~ScalarConverter();

		static bool isWholeNumber(double value);

        // Type detection helpers
        static bool isPseudoLiteral(const std::string &input);
        static bool isChar(const std::string &input);
        static bool isInteger(const std::string &input);
        static bool isFloat(const std::string &input);
        static bool isDouble(const std::string &input);

        // Conversion/printing helpers
        static void convertPseudo(const std::string &input);
        static void convertChar(const std::string &input);
        static void convertInteger(const std::string &input);
        static void convertFloat(const std::string &input);
        static void convertDouble(const std::string &input);

    public:
        static void convert(const std::string &input);
};

#endif