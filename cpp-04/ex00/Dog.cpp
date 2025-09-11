/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luide-ca <luide-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 21:00:27 by luide-ca          #+#    #+#             */
/*   Updated: 2025/08/21 21:39:56 by luide-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void) : Animal() {
    std::cout << "Dog constructor called!!!" << std::endl;
    this->_type = "DOG";
}

Dog::Dog(const Dog& other) : Animal(other) {
    std::cout << "Dog copy assignment called!!!" << std::endl;
}

Dog::~Dog(void) {
    std::cout << "Dog destructor called!!!" << std::endl;
}

Dog& Dog::operator=(const Dog& other) {
    std::cout << "Dog copy operator called" << std::endl;
    if (this != &other)
        this->_type = other._type;
    return (*this);
}

void Dog::makeSound(void) const {
    std::cout << "Dogs bark: au au" << std::endl;
}