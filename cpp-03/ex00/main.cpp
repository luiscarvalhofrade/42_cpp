/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luide-ca <luide-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 23:47:56 by luide-ca          #+#    #+#             */
/*   Updated: 2025/08/22 10:47:54 by luide-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main() {
    std::cout << "=== TESTING CLAPTRAP ===" << std::endl;
    
    // Test ClapTrap default constructor
    ClapTrap clap1;
    std::cout << "ClapTrap " << clap1.getName() << " has " << clap1.getHitPoints() 
              << " HP, " << clap1.getEnergyPoints() << " EP, and " 
              << clap1.getAttackDamage() << " AD" << std::endl;
    
    // Test ClapTrap with name constructor
    ClapTrap clap2("Warrior");
    clap2.attack("enemy");
    clap2.takeDamage(2);
    clap2.beRepaired(25);

    std::cout << "\n=== TESTING COPY CONSTRUCTORS ===" << std::endl;
    
    // Test copy constructors
    ClapTrap clap3(clap2);
    
    std::cout << "\n=== TESTING ASSIGNMENT OPERATORS ===" << std::endl;
    
    // Test assignment operators
    ClapTrap clap4;
    clap4 = clap2;
    
    std::cout << "\n=== TESTING EDGE CASES ===" << std::endl;
    
    // Test attacking with no energy
    ClapTrap energyTest("NoEnergy");
    // Drain all energy points
    for (int i = 0; i < 10; i++) {
        energyTest.attack("dummy");
    }
    // This should fail
    energyTest.attack("dummy");
    
    // Test taking lethal damage
    ClapTrap deathTest("Doomed");
    deathTest.takeDamage(15);
    deathTest.attack("ghost");
    deathTest.beRepaired(50);

    std::cout << "\n=== DESTRUCTORS WILL BE CALLED AUTOMATICALLY ===" << std::endl;
    
    return 0;
}