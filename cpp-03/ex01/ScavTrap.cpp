/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luide-ca <luide-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 17:21:54 by luide-ca          #+#    #+#             */
/*   Updated: 2025/08/23 00:03:33 by luide-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void) : ClapTrap() {
	std::cout << "ScavTrap default constructor called!!!" << std::endl;
}

ScavTrap::ScavTrap(const std::string name) : ClapTrap(name) {
	std::cout << "ScavTrap constructor with name " << name << " called!!!" << std::endl;
}

ScavTrap::~ScavTrap(void) {
	std::cout << "ScavTrap destructor called for " << _name << "!!!" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other) {
	std::cout << "ScavTrap copy constructor called!!!" << std::endl;
} 

ScavTrap& ScavTrap::operator=(const ScavTrap& other) {
	std::cout << "ScavTrap copy assignment operator called" << std::endl;
    
    if (this != &other)
	{
        this->_name = other.getName();
		this->_hitPoints = other.getHitPoints();
    	this->_energyPoints = other.getEnergyPoints();
    	this->_attackDamage = other.getAttackDamage();
	}
    return (*this);
}

void ScavTrap::attack(const std::string& target) {
	if (this->_hitPoints == 0)
	{
		std::cout << "ScavTrap " << this->_name << " is already dead!!!" << std::endl;
		return ;
	}
	else if (this->_energyPoints == 0)
	{
		std::cout << "ScavTrap " << this->_name << " doesnt have energy points enough to attack..." << std::endl;
		return ;
	}
	this->_energyPoints--;
	std::cout << "ScavTrap " << this->_name << " attacks " << target << ", causing " << this->_attackDamage << " points of damage!" << std::endl;
	return ;
}

void ScavTrap::guardGate(void) {
	std::cout << "ScavTrap " << this->_name << " is now a Gate Guard!!!" << std::endl;
}
