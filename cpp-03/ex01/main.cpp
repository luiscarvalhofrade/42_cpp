/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luide-ca <luide-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 23:47:56 by luide-ca          #+#    #+#             */
/*   Updated: 2025/08/22 10:43:15 by luide-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

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
    clap2.takeDamage(50);
    clap2.beRepaired(25);
    
    std::cout << "\n=== TESTING SCAVTRAP ===" << std::endl;
    
    // Test ScavTrap default constructor
    ScavTrap scav1;
    std::cout << "ScavTrap " << scav1.getName() << " has " << scav1.getHitPoints() 
              << " HP, " << scav1.getEnergyPoints() << " EP, and " 
              << scav1.getAttackDamage() << " AD" << std::endl;
    
    // Test ScavTrap with name constructor
    ScavTrap scav2("Guardian");
    scav2.attack("intruder");
    scav2.guardGate();
    scav2.takeDamage(30);
    scav2.beRepaired(15);
    
    std::cout << "\n=== TESTING COPY CONSTRUCTORS ===" << std::endl;
    
    // Test copy constructors
    ScavTrap scav3(scav2);
    
    std::cout << "\n=== TESTING ASSIGNMENT OPERATORS ===" << std::endl;
    
    // Test assignment operators
    ScavTrap scav4;
    scav4 = scav2;
    scav4.guardGate();
    
    std::cout << "\n=== TESTING EDGE CASES ===" << std::endl;
    
    // Test attacking with no energy
    ScavTrap energyTest("NoEnergy");
    // Drain all energy points
    for (int i = 0; i < 50; i++) {
        energyTest.attack("dummy");
    }
    // This should fail
    energyTest.attack("dummy");
    
    // Test taking lethal damage
    ScavTrap deathTest("Doomed");
    deathTest.takeDamage(150); // Should kill it
    deathTest.attack("ghost"); // Should fail - already dead
    deathTest.beRepaired(50);  // Should fail - already dead
    
    std::cout << "\n=== TESTING POLYMORPHISM ===" << std::endl;
    
    // Test polymorphic behavior
    ClapTrap* robots[2];
    robots[0] = new ClapTrap("PolyClap");
    robots[1] = new ScavTrap("PolyScav");
    
    for (int i = 0; i < 2; i++) {
        robots[i]->attack("polymorphic_target");
    }
    
    // Clean up
    for (int i = 0; i < 2; i++) {
        delete robots[i];
    }
    
    std::cout << "\n=== DESTRUCTORS WILL BE CALLED AUTOMATICALLY ===" << std::endl;
    
    return 0;
}