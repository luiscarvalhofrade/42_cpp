/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luide-ca <luide-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 21:21:14 by luide-ca          #+#    #+#             */
/*   Updated: 2025/08/21 21:42:16 by luide-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void) : _type("random animal") {
    std::cout << "WrongAnimal constructor called!!!" << std::endl;
}

WrongAnimal::~WrongAnimal(void) {
    std::cout << "WrongAnimal destructor called!!!" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& other) : _type(other._type) {
    std::cout << "WrongAnimal copy constructor called!!!" << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other) {
    if(this != &other)
        this->_type = other._type;
    return (*this);
}

void WrongAnimal::makeSound(void) const {
    std::cout << "Who am I? Im a WrongAnimal" << std::endl;
}

std::string WrongAnimal::getType(void) const {
    return (this->_type);
}