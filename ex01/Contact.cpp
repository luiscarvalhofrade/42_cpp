/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luide-ca <luide-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 10:43:37 by luide-ca          #+#    #+#             */
/*   Updated: 2025/07/23 12:13:26 by luide-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact(void) {
	std::cout << "constructor for Contact called" << std::endl;
	this->_first_name = "";
	this->_last_name = "";
	this->_phone_number = 0;
};

Contact::~Contact(void) {
	std::cout << "destructor for Contact called" << std::endl;
}

void	Contact::getData(void) {
	std::cout << "fn is: " << this->_first_name << std::endl;
	std::cout << "ln is: " << this->_last_name << std::endl;
	std::cout << "pn is: " << this->_phone_number << std::endl;
}

void	Contact::setData(void) {
	std::cout << "fn is: "; std::cin >> this->_first_name;
	std::cout << "ln is: "; std::cin >> this->_last_name;
	std::cout << "pn is: "; std::cin >> this->_phone_number;
}
