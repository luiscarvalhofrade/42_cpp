/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luide-ca <luide-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 23:48:04 by luide-ca          #+#    #+#             */
/*   Updated: 2025/08/22 10:49:55 by luide-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void) : _name("need name"), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
	std::cout << "Default constructor called!!!" << std::endl;
}

ClapTrap::ClapTrap(const std::string name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
	std::cout << "Constructor with name " << this->_name << " called!!!" << std::endl;
}

ClapTrap::~ClapTrap(void) {
	std::cout << "Destructor called!!!" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other) : _name(other._name), _hitPoints(other._hitPoints), _energyPoints(other._energyPoints), _attackDamage(other._attackDamage) {
	std::cout << "Copy constructor called!!!" << std::endl;
} 

ClapTrap& ClapTrap::operator=(const ClapTrap& other) {
	std::cout << "Copy assignment operator called" << std::endl;
    
    if (this != &other)
	{
        this->_name = other.getName();
		this->_hitPoints = other.getHitPoints();
    	this->_energyPoints = other.getEnergyPoints();
    	this->_attackDamage = other.getAttackDamage();
	}
    return (*this);
}

std::string ClapTrap::getName(void) const {
	return (this->_name);
}

unsigned int ClapTrap::getHitPoints(void) const {
	return (this->_hitPoints);
}

unsigned int ClapTrap::getEnergyPoints(void) const {
	return (this->_energyPoints);
}

unsigned int ClapTrap::getAttackDamage(void) const {
	return (this->_attackDamage);
}

void ClapTrap::attack(const std::string& target) {
	if (this->_hitPoints == 0)
	{
		std::cout << "ClapTrap " << this->_name << " is already dead!!!" << std::endl;
		return ;
	}
	else if (this->_energyPoints == 0)
	{
		std::cout << "ClapTrap " << this->_name << " doesnt have energy points enough to attack..." << std::endl;
		return ;
	}
	this->_energyPoints--;
	std::cout << "ClapTrap " << this->_name << " attacks " << target << ", causing " << this->_attackDamage << " points of damage!" << std::endl;
	return ;
}

void ClapTrap::takeDamage(unsigned int amount) {
	if (this->_hitPoints == 0)
	{
		std::cout << "ClapTrap " << this->_name << " is already dead!!!" << std::endl;
		return ;
	}
	else if (this->_hitPoints <= amount)
	{
		this->_hitPoints = 0;
		std::cout << "ClapTrap " << this->_name << " was hit and now is dead!!!" << std::endl;
		return ;
	}
	this->_hitPoints -= amount;
	std::cout << "ClapTrap " << this->_name << " was attacked and suffered" << amount << " points in damage!!!" << std::endl;
	return ;
}

void ClapTrap::beRepaired(unsigned int amount) {
	if (this->_hitPoints == 0)
	{
		std::cout << "ClapTrap " << this->_name << " is already dead!!!" << std::endl;
		return ;
	}
	else if (this->_energyPoints == 0)
	{
		std::cout << "ClapTrap " << this->_name << " doesnt have energy points enough to be repaired!!!" << std::endl;
		return ;
	}
	this->_hitPoints += amount;
	this->_energyPoints--;
	std::cout << "ClapTrap " << this->_name << " was repaired in " << amount << " points!!!" << std::endl;
	return ;
}