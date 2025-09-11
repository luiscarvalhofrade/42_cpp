/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luide-ca <luide-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 14:11:59 by luide-ca          #+#    #+#             */
/*   Updated: 2025/08/07 21:09:29 by luide-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(void) {
    Harl harl;
    
    std::cout << "=== Tests ===" << std::endl << std::endl;
    
    std::cout << "Testing DEBUG level:" << std::endl;
    harl.complain("DEBUG");
    
    std::cout << "Testing INFO level:" << std::endl;
    harl.complain("INFO");
    
    std::cout << "Testing WARNING level:" << std::endl;
    harl.complain("WARNING");
    
    std::cout << "Testing ERROR level:" << std::endl;
    harl.complain("ERROR");
    
    std::cout << "Testing invalid level:" << std::endl;
    harl.complain("CRITICAL");
    
    std::cout << "Testing empty string:" << std::endl;
    harl.complain("");
    
    std::cout << "Testing lowercase:" << std::endl;
    harl.complain("debug");
    
    std::cout << "=== End of tests ===" << std::endl;
    
    return 0;
}