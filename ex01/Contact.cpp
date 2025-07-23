/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luide-ca <luide-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 10:43:37 by luide-ca          #+#    #+#             */
/*   Updated: 2025/07/23 15:45:56 by luide-ca         ###   ########.fr       */
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
	std::cout << "first name is: " << this->_first_name << " | ";
	std::cout << "last name is: " << this->_last_name << " | ";
	std::cout << "phone number is: " << this->_phone_number << std::endl;
}

std::string	Contact::setFirstName(void) {
	std::string first_name;

	std::cout << "fn is: "; 
	std::cin >> first_name;
	
	return (first_name);
}

std::string	Contact::setLastName(void) {
	std::string last_name;

	std::cout << "ln is: "; 
	std::cin >> last_name;

	return (last_name);
}

int	Contact::setPhoneNumber(void) {
	int	phone_number;

	std::cout << "pn is: ";
	std::cin >> phone_number;

	return (phone_number);
}
