/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luide-ca <luide-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 16:43:45 by luide-ca          #+#    #+#             */
/*   Updated: 2025/07/31 17:07:33 by luide-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string type) {
    this->_type = type;
}

Weapon::~Weapon(void) {
}

const std::string &Weapon::getType(void) {
    return (this->_type);
}

void    Weapon::setType(const std::string type) {
    _type = type;
}