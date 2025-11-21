/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luide-ca <luide-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 17:46:23 by luide-ca          #+#    #+#             */
/*   Updated: 2025/11/21 16:02:52 by luide-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

// ---------------------------------------------------------------------------
// Canonical form (private, só para cumprir o subject)
// ---------------------------------------------------------------------------

ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter &other)
{
    (void)other;
}
ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other)
{
    (void)other;
    return *this;
}
ScalarConverter::~ScalarConverter() {}

// ---------------------------------------------------------------------------
// Type checks
// ---------------------------------------------------------------------------

bool ScalarConverter::isPseudoLiteral(const std::string &input)
{
    const std::string pseudo[] = {
        "nan", "+nan", "-nan",
        "nanf", "+nanf", "-nanf",
        "inf", "+inf", "-inf",
        "inff", "+inff", "-inff"
    };

    for (size_t i = 0; i < sizeof(pseudo) / sizeof(pseudo[0]); ++i)
    {
        if (input == pseudo[i])
            return true;
    }
    return false;
}

bool ScalarConverter::isChar(const std::string &input)
{
    // Formato 'a'
    if (input.length() == 3 && input[0] == '\'' && input[2] == '\''
        && std::isprint(static_cast<unsigned char>(input[1])))
        return true;

    // Um único caractere imprimível que não seja dígito
    if (input.length() == 1
        && std::isprint(static_cast<unsigned char>(input[0]))
        && !std::isdigit(static_cast<unsigned char>(input[0])))
        return true;

    return false;
}

bool ScalarConverter::isInteger(const std::string &input)
{
    if (input.empty())
        return false;

    char *end = 0;
    errno = 0;

    long value = std::strtol(input.c_str(), &end, 10);

    // Nenhum dígito lido
    if (end == input.c_str())
        return false;

    // Caracteres sobrando
    if (*end != '\0')
        return false;

    // Overflow/underflow para long
    if (errno == ERANGE)
        return false;

    // Verificar se cabe em int
    if (value < static_cast<long>(std::numeric_limits<int>::lowest())
        || value > static_cast<long>(std::numeric_limits<int>::max()))
        return false;

    return true;
}

bool ScalarConverter::isFloat(const std::string &input)
{
    if (input.empty())
        return false;

    // Pseudo-literal já é tratado antes
    if (isPseudoLiteral(input))
        return false;

    char *end = 0;
    errno = 0;

    std::strtof(input.c_str(), &end);

    // Nenhum dígito lido
    if (end == input.c_str())
        return false;

    // Tem que terlowestar com 'f' e nada depois
    if (*end != 'f' || *(end + 1) != '\0')
        return false;

    if (errno == ERANGE)
        return false;

    return true;
}

bool ScalarConverter::isDouble(const std::string &input)
{
    if (input.empty())
        return false;

    // Pseudo-literal já é tratado antes
    if (isPseudoLiteral(input))
        return false;

    char *end = 0;
    errno = 0;

    std::strtod(input.c_str(), &end);

    // Nenhum dígito lido
    if (end == input.c_str())
        return false;

    // Não pode sobrar nada
    if (*end != '\0')
        return false;

    if (errno == ERANGE)
        return false;

    return true;
}

// ---------------------------------------------------------------------------
// Conversion helpers
// ---------------------------------------------------------------------------

bool ScalarConverter::isWholeNumber(double value) {
    return value == static_cast<long long>(value);
}

void ScalarConverter::convertPseudo(const std::string &input)
{
    // Sempre:
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;

    std::string floatStr;
    std::string doubleStr;

    if (!input.empty() && input[input.length() - 1] == 'f')
    {
        // pseudo literal de float: nanf, inff, etc
        floatStr = input;
        doubleStr = input.substr(0, input.length() - 1);
    }
    else
    {
        // pseudo literal de double: nan, inf, etc
        doubleStr = input;
        floatStr = input + "f";
    }

    std::cout << "float: " << floatStr << std::endl;
    std::cout << "double: " << doubleStr << std::endl;
}

void ScalarConverter::convertChar(const std::string &input)
{
    char c;

    if (input.length() == 3 && input[0] == '\'' && input[2] == '\'')
        c = input[1];
    else
        c = input[0];

    if (std::isprint(static_cast<unsigned char>(c)))
        std::cout << "char: '" << c << "'" << std::endl;
    else
        std::cout << "char: Non displayable" << std::endl;

    int i = static_cast<int>(c);
    float f = static_cast<float>(c);
    double d = static_cast<double>(c);

    std::cout << "int: " << i << std::endl;
    std::cout << "float: " << f << "f" << std::endl;
    std::cout << "double: " << d << std::endl;
}

void ScalarConverter::convertInteger(const std::string &input)
{
    char *end = 0;
    errno = 0;
    long value = std::strtol(input.c_str(), &end, 10);
    int i = static_cast<int>(value);

    // char
    if (value < static_cast<long>(std::numeric_limits<char>::lowest())
        || value > static_cast<long>(std::numeric_limits<char>::max()))
    {
        std::cout << "char: impossible" << std::endl;
    }
    else
    {
        char c = static_cast<char>(i);
        if (std::isprint(static_cast<unsigned char>(c)))
            std::cout << "char: '" << c << "'" << std::endl;
        else
            std::cout << "char: Non displayable" << std::endl;
    }

    // int
    std::cout << "int: " << i << std::endl;

    // float / double
    float f = static_cast<float>(i);
    double d = static_cast<double>(i);

    std::cout << "float: " << f << "f" << std::endl;
    std::cout << "double: " << d << std::endl;
}

void ScalarConverter::convertFloat(const std::string &input)
{
    char *end = 0;
    errno = 0;
    float f = std::strtof(input.c_str(), &end);

	if (isWholeNumber(f)) {
		std::cout << std::fixed << std::setprecision(1);
	} else {
		std::cout << std::defaultfloat << std::setprecision(7); // or appropriate precision
	}
    // char
    if (f < static_cast<float>(std::numeric_limits<char>::lowest())
        || f > static_cast<float>(std::numeric_limits<char>::max()))
    {
        std::cout << "char: impossible" << std::endl;
    }
    else
    {
        char c = static_cast<char>(f);
        if (std::isprint(static_cast<unsigned char>(c)))
            std::cout << "char: '" << c << "'" << std::endl;
        else
            std::cout << "char: Non displayable" << std::endl;
    }

    // int
    if (f < static_cast<float>(std::numeric_limits<int>::lowest())
        || f > static_cast<float>(std::numeric_limits<int>::max()))
    {
        std::cout << "int: impossible" << std::endl;
    }
    else
    {
        int i = static_cast<int>(f);
        std::cout << "int: " << i << std::endl;
    }

    double d = static_cast<double>(f);

    std::cout << "float: " << f << "f" << std::endl;
    std::cout << "double: " << d << std::endl;
}

void ScalarConverter::convertDouble(const std::string &input)
{
    char *end = 0;
    errno = 0;
    double d = std::strtod(input.c_str(), &end);

	if (isWholeNumber(d)) {
		std::cout << std::fixed << std::setprecision(1);
	} else {
		std::cout << std::defaultfloat << std::setprecision(7); // or appropriate precision
	}
    // char
    if (d < static_cast<double>(std::numeric_limits<char>::lowest())
        || d > static_cast<double>(std::numeric_limits<char>::max()))
    {
        std::cout << "char: impossible" << std::endl;
    }
    else
    {
        char c = static_cast<char>(d);
        if (std::isprint(static_cast<unsigned char>(c)))
            std::cout << "char: '" << c << "'" << std::endl;
        else
            std::cout << "char: Non displayable" << std::endl;
    }

    // int
    if (d < static_cast<double>(std::numeric_limits<int>::lowest())
        || d > static_cast<double>(std::numeric_limits<int>::max()))
    {
        std::cout << "int: impossible" << std::endl;
    }
    else
    {
        int i = static_cast<int>(d);
        std::cout << "int: " << i << std::endl;
    }

    // float
    if (d < -static_cast<double>(std::numeric_limits<float>::max())
        || d > static_cast<double>(std::numeric_limits<float>::max()))
    {
        std::cout << "float: impossible" << std::endl;
    }
    else
    {
        float f = static_cast<float>(d);
        std::cout << "float: " << f << "f" << std::endl;
    }

    // double
    std::cout << "double: " << d << std::endl;
}

// ---------------------------------------------------------------------------
// Public API
// ---------------------------------------------------------------------------

void ScalarConverter::convert(const std::string &input)
{
    std::cout << std::fixed << std::setprecision(1);

    if (isPseudoLiteral(input))
        convertPseudo(input);
    else if (isChar(input))
        convertChar(input);
    else if (isInteger(input))
        convertInteger(input);
    else if (isFloat(input))
        convertFloat(input);
    else if (isDouble(input))
        convertDouble(input);
    else
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: impossible" << std::endl;
        std::cout << "double: impossible" << std::endl;
    }
}
