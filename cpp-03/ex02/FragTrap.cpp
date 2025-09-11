/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luide-ca <luide-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 17:52:40 by luide-ca          #+#    #+#             */
/*   Updated: 2025/08/22 10:34:15 by luide-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(void) : ClapTrap() {
	std::cout << "FragTrap default constructor called!!!" << std::endl;
}

FragTrap::FragTrap(const std::string name) : ClapTrap(name) {
	std::cout << "FragTrap constructor with name " << name << " called!!!" << std::endl;
}

FragTrap::~FragTrap(void) {
	std::cout << "FragTrap destructor called for " << _name << "!!!" << std::endl;
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other) {
	std::cout << "FragTrap copy constructor called!!!" << std::endl;
} 

FragTrap& FragTrap::operator=(const FragTrap& other) {
	std::cout << "FragTrap copy assignment operator called" << std::endl;
    
    if (this != &other)
	{
        this->_name = other.getName();
		this->_hitPoints = other.getHitPoints();
    	this->_energyPoints = other.getEnergyPoints();
    	this->_attackDamage = other.getAttackDamage();
	}
    return (*this);
}

void FragTrap::highFiveGuys(void) {
	std::cout << "I'm, a FragTrap " << this->_name << ", needs a high five!!!" << std::endl;
}