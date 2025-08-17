/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luide-ca <luide-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 12:08:45 by luide-ca          #+#    #+#             */
/*   Updated: 2025/08/17 17:36:32 by luide-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void) {
	_contact_count = 0;
}

PhoneBook::~PhoneBook(void) {
}

int	PhoneBook::add(void) {
	std::string	fn;
	std::string	ln;
	std::string	pn;

	do {
        fn = contact[_contact_count].setFirstName();
        if (fn.empty()) {
            std::cout << "First name cannot be empty. Please try again." << std::endl;
        }
    } while (fn.empty());
    do {
        ln = contact[_contact_count].setLastName();
        if (ln.empty()) {
            std::cout << "Last name cannot be empty. Please try again." << std::endl;
        }
    } while (ln.empty());
    do {
        pn = contact[_contact_count].setPhoneNumber();
        if (pn.empty()) {
            std::cout << "Phone number cannot be empty. Please try again." << std::endl;
        }
    } while (pn.empty());
	

	contact[_contact_count].setContact(fn, ln, pn);
	std::cout << "Phone added succesfully at index " << ((_contact_count + 1) % 8) << "!!!" << std::endl;
	contact[_contact_count].getData();
    _contact_count = (_contact_count + 1) % 8;
	return (0);
}

void	PhoneBook::getPhoneList(void) {
	std::string	name;

    std::cout << "Index | First Name" << std::endl;
    std::cout << "------|----------" << std::endl;
    for (int i = 0; i < 8; ++i) {
        name = this->contact[i].getFirstName();
        if (!name.empty()) {
            std::cout << "  " << (i + 1) << "   | " << name << std::endl;
        }
    }
}

int	PhoneBook::search(int index, std::string name) {
	if (index <= 8 && index >= 1)
	{
		index = index - 1;
		if (!contact[index].getFirstName().empty())
			contact[index].getData();
		else
			std::cout << "No contact at index " << (index + 1) << std::endl;
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
		std::cout << "Name: " << name << " not found!" << std::endl;
	}
	std::cout << "Input did not match any contact." << std::endl;
	return (1);
}

int	PhoneBook::exit(void) {
	return (0);
}
