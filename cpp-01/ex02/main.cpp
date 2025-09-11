/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luide-ca <luide-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 15:48:33 by luide-ca          #+#    #+#             */
/*   Updated: 2025/07/31 16:11:30 by luide-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(void) {
    std::string string_var = "HI THIS IS BRAIN";
    std::string *stringPTR = &string_var;
    std::string &stringREF = string_var;

    std::cout << "Address of string_var" << std::endl;
    std::cout << &string_var << std::endl;
    std::cout << "Address of stringPTR" << std::endl;
    std::cout << stringPTR << std::endl;
    std::cout << "Address of stringREF" << std::endl;
    std::cout << &stringREF << std::endl;
    std::cout << std::endl;
    std::cout << "Value of string_var" << std::endl;
    std::cout << string_var << std::endl;
    std::cout << "Value of stringPTR" << std::endl;
    std::cout << *stringPTR << std::endl;
    std::cout << "Value of stringREF" << std::endl;
    std::cout << stringREF << std::endl;

    return (0);
}