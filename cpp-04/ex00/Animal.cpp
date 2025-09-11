/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luide-ca <luide-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 21:00:51 by luide-ca          #+#    #+#             */
/*   Updated: 2025/08/21 21:31:39 by luide-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(void) : _type("random animal") {
    std::cout << "Animal constructor called!!!" << std::endl;
}

Animal::~Animal(void) {
    std::cout << "Animal destructor called!!!" << std::endl;
}

Animal::Animal(const Animal& other) : _type(other._type) {
    std::cout << "Animal copy constructor called!!!" << std::endl;
}

Animal& Animal::operator=(const Animal& other) {
    if(this != &other)
        this->_type = other._type;
    return (*this);
}

void Animal::makeSound(void) const {
    std::cout << "Who am I?" << std::endl;
}

std::string Animal::getType(void) const {
    return (this->_type);
}