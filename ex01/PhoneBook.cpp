/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luide-ca <luide-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 12:08:45 by luide-ca          #+#    #+#             */
/*   Updated: 2025/07/28 18:35:48 by luide-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void) {
	std::cout << "constructor for PhoneBook called" << std::endl;
	_contact_count = 0;
}

PhoneBook::~PhoneBook(void) {
	std::cout << "destructor for PhoneBook called" << std::endl;
}

int	PhoneBook::add(void) {
	std::string	fn;
	std::string	ln;
	std::string	pn;

	fn = contact[_contact_count].setFirstName();
	ln = contact[_contact_count].setLastName();
	pn = contact[_contact_count].setPhoneNumber();

	contact[_contact_count].setContact(fn, ln, pn);
	std::cout << "Phone added succesfully at index " << _contact_count << "!!!" << std::endl;
	contact[_contact_count].getData();
	_contact_count++;
	return (0);
}

int	PhoneBook::search(int index, std::string name) {
	if (index <= 7 && index >= 0)
	{
		contact[index].getData();
		return (0);
	}
	else if (!name.empty())
	{
		for (int i = 0; i < 8; ++i)
		{
			if (contact[i].getFirstName() == name)
			{
				contact[i].getData();
				return (0);
			}
		}
		for (int i = 0; i < 8; ++i)
		{
			if (contact[i].getLastName() == name)
			{
				contact[i].getData();
				return (0);
			}
		}
		std::cout << "Name not found!" << std::endl;
	}
	std::cout << "Input did not match any contact." << std::endl;
	return (1);
}

int	PhoneBook::exit(void) {
	return (0);
}
