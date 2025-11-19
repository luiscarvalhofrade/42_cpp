/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luide-ca <luide-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 17:46:23 by luide-ca          #+#    #+#             */
/*   Updated: 2025/11/19 15:27:00 by luide-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

// checks the type of input
bool ScalarConverter::isPseudoLiteral(const std::string &input) {
    std::string pseudo[] = {"+inf", "-inf", "+inff", "-inff", "inf", "inff", "nan", "+nan", "-nan", "nanf", "+nanf", "-nanf"};
    bool        isPseudo = false;

    for (unsigned long i = 0; i < (sizeof(pseudo) / sizeof(std::string)); i++)
    {
        if (!pseudo[i].compare(input))
        {
            isPseudo = true;
            break;
        }
        continue ;
    }
    return (isPseudo);
}

bool ScalarConverter::isChar(const std::string &input) {
    if (input[0] == '\'' && isascii(input[1]) && input[2] == '\'')
        return (true);
    else if (input.length() == 1 && isalpha(input[0]))
        return (true);
    return (false);
}

bool ScalarConverter::isInteger(const std::string &input) {
    char        *rest;
    long int    value;

    errno = 0;
    /*
        strtol is string to double, it has 3 argumnts: 
        
        1. input.c_str(): the string in the const char* form, 
            1.1 because of it, it is necessary to use c_str() (transform an input of std::string to char *)
        2. &res: Optionally tells you where the parsing stopped (could be NULL or null_ptr).
        3. base: it is necessary to pass the base used to convert.
        
        Also, If the number is out of range for float, strtof returns: sets errno = ERANGE.
    */
    value = std::strtol(input.c_str(), &rest, 10);
    if (errno == ERANGE)
        return (false);
    if (*rest != '\0')
        return (false);
    if (rest == input.c_str())
        return (false);
    if (value < std::numeric_limits<int>::min() || value > std::numeric_limits<int>::max())
        return (true);
}

bool ScalarConverter::isFloat(const std::string &input) {
    char  *end;
    float value;

    errno = 0;
    /*
        strtof is string to float, it has 2 argumnts: 
        
        1. input.c_str(): the string in the const char* form, 
            1.1 because of it, it is necessary to use c_str() (transform an input of std::string to char *)
        2. &end: Optionally tells you where the parsing stopped (could be NULL or null_ptr).
        
        Also, If the number is out of range for float, strtof returns: sets errno = ERANGE.
    */
    value = std::strtof(input.c_str(), &end);
    if (errno == ERANGE || end == input.c_str() || *end != 'f' || *(end+1) != '\0')
        return (false);
    if (value < -std::numeric_limits<float>::min() || value > std::numeric_limits<float>::max())
        return (false);
    return (true);
}

bool ScalarConverter::isDouble(const std::string &input) {
    char  *end;
    float value;

    errno = 0;
    /*
        strtod is string to double, it has 2 argumnts: 
        
        1. input.c_str(): the string in the const char* form, 
            1.1 because of it, it is necessary to use c_str() (transform an input of std::string to char *)
        2. &end: Optionally tells you where the parsing stopped (could be NULL or null_ptr).
        
        Also, If the number is out of range for float, strtof returns: sets errno = ERANGE.
    */
    value = std::strtod(input.c_str(), &end);
    if (errno == ERANGE || end == input.c_str() || *end != '\0')
        return (false);
    if (value < -std::numeric_limits<double>::min() || value > std::numeric_limits<double>::max())
        return (false);
    return (true);
}

// after defined the type of input, we use the specific function to print all 4 types
void	ScalarConverter::convertPseudo(const std::string &input) {

}

void	ScalarConverter::convertChar(const std::string &input) {

}

void	ScalarConverter::convertInteger(const std::string &input) {

}

void	ScalarConverter::convertFloat(const std::string &input) {

}

void	ScalarConverter::convertDouble(const std::string &input) {

}

// canonical form functions
ScalarConverter::ScalarConverter(void) { }

ScalarConverter::~ScalarConverter(void) { }

ScalarConverter::ScalarConverter(const ScalarConverter& other) { }

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other) { }

void ScalarConverter::convert(const std::string &input) { }