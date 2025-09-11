/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luide-ca <luide-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 21:00:27 by luide-ca          #+#    #+#             */
/*   Updated: 2025/08/22 13:29:02 by luide-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void) : AAnimal() {
    std::cout << "Dog constructor called!!!" << std::endl;
    this->_type = "DOG";
    this->_brain = new Brain();
}

Dog::Dog(const Dog& other) : AAnimal(other) {
    std::cout << "Dog copy assignment called!!!" << std::endl;
    this->_brain = new Brain(*other._brain);
}

Dog::~Dog(void) {
    delete _brain;
    std::cout << "Dog destructor called!!!" << std::endl;
}

Dog& Dog::operator=(const Dog& other) {
    std::cout << "Dog copy operator called" << std::endl;
    if (this != &other)
    {
        this->_type = other._type;
        delete _brain;
		_brain = new Brain(*other._brain);
    }
    return (*this);
}

void Dog::makeSound(void) const {
    std::cout << "Dogs bark: au au" << std::endl;
}