/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luide-ca <luide-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 20:58:36 by luide-ca          #+#    #+#             */
/*   Updated: 2025/08/21 22:36:52 by luide-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void) : Animal() {
    std::cout << "Cat constructor called!!!" << std::endl;
    this->_type = "CAT";
    this->_brain = new Brain();
}

Cat::Cat(const Cat& other) : Animal(other) {
    std::cout << "Cat copy assignment called!!!" << std::endl;
    this->_brain = new Brain(*other._brain);
}

Cat::~Cat(void) {
    delete _brain;
    std::cout << "Cat destructor called!!!" << std::endl;
}

Cat& Cat::operator=(const Cat& other) {
    std::cout << "Cat copy operator called" << std::endl;
    if (this != &other)
    {
        this->_type = other._type;
        delete _brain;
		_brain = new Brain(*other._brain);
    }
    return (*this);
}

void Cat::makeSound(void) const {
    std::cout << "Cats say: miaw" << std::endl;
}