/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luide-ca <luide-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 21:00:51 by luide-ca          #+#    #+#             */
/*   Updated: 2025/08/22 13:28:22 by luide-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

AAnimal::AAnimal(void) : _type("random animal") {
    std::cout << "AAnimal constructor called!!!" << std::endl;
}

AAnimal::~AAnimal(void) {
    std::cout << "AAnimal destructor called!!!" << std::endl;
}

AAnimal::AAnimal(const AAnimal& other) : _type(other._type) {
    std::cout << "AAnimal copy constructor called!!!" << std::endl;
}

AAnimal& AAnimal::operator=(const AAnimal& other) {
    if(this != &other)
        this->_type = other._type;
    return (*this);
}

void AAnimal::makeSound(void) const {
    std::cout << "Who am I?" << std::endl;
}

std::string AAnimal::getType(void) const {
    return (this->_type);
}