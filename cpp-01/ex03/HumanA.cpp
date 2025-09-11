/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luide-ca <luide-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 19:33:07 by luide-ca          #+#    #+#             */
/*   Updated: 2025/08/04 20:03:08 by luide-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon) : _name(name), _weapon(&weapon) {
}

HumanA::~HumanA(void) {
}

void    HumanA::setWeapon(Weapon &weapon) {
    this->_weapon = &weapon;
}

void    HumanA::attack(void) {
    std::cout << this->_name << " attacks with their " << this->_weapon->getType() << std::endl;
}