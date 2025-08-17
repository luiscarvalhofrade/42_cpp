/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luide-ca <luide-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 10:43:37 by luide-ca          #+#    #+#             */
/*   Updated: 2025/08/14 21:06:12 by luide-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact(void) {
	this->_first_name = "";
	this->_last_name = "";
	this->_phone_number = "";
};

Contact::~Contact(void) {
}

void	Contact::getData(void) {
	std::cout << "first name is: " << this->_first_name << " | ";
	std::cout << "last name is: " << this->_last_name << " | ";
	std::cout << "phone number is: " << this->_phone_number << std::endl;
}

std::string	Contact::getFirstName(void) {
	return (this->_first_name);
}

std::string	Contact::getLastName(void) {
	return (this->_last_name);
}

std::string	Contact::getPhoneNUmber(void) {
	return (this->_phone_number);
}

std::string	Contact::setFirstName(void) {
	std::string first_name;

	std::cout << "Enter first name: ";
	//std::cin.ignore();
	std::getline(std::cin, first_name);
	return (first_name);
}

std::string	Contact::setLastName(void) {
	std::string last_name;

	std::cout << "Enter last name: ";
	//std::cin.ignore();
	std::getline(std::cin, last_name);
	return (last_name);
}

std::string	Contact::setPhoneNumber(void) {
	std::string	phone_number;

	std::cout << "Enter phone number: ";
	//std::cin.ignore();
	std::getline(std::cin, phone_number);
	return (phone_number);
}

int Contact::setContact(std::string fn, std::string ln, std::string pn) {
	this->_first_name = fn;
	this->_last_name = ln;
	this->_phone_number = pn;
	return (0);
}