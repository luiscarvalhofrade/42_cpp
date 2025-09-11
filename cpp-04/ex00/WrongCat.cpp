/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luide-ca <luide-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 21:20:55 by luide-ca          #+#    #+#             */
/*   Updated: 2025/08/21 21:41:00 by luide-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat(void) : WrongAnimal() {
    std::cout << "WrongCat constructor called!!!" << std::endl;
    this->_type = "WRONGCAT";
}

WrongCat::WrongCat(const WrongCat& other) : WrongAnimal(other) {
    std::cout << "WrongCat copy assignment called!!!" << std::endl;
}

WrongCat::~WrongCat(void) {
    std::cout << "WrongCat destructor called!!!" << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& other) {
    std::cout << "WrongCat copy operator called" << std::endl;
    if (this != &other)
        this->_type = other._type;
    return (*this);
}

void WrongCat::makeSound(void) const {
    std::cout << "WrongCats say: mibarwk" << std::endl;
}