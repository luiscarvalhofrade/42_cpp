/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luide-ca <luide-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 12:08:45 by luide-ca          #+#    #+#             */
/*   Updated: 2025/07/23 16:21:13 by luide-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void) {
	std::cout << "constructor for PhoneBook called" << std::endl;
}

PhoneBook::~PhoneBook(void) {
	std::cout << "destructor for PhoneBook called" << std::endl;
}

int	PhoneBook::add(void) {
	return (0);
}

int	PhoneBook::search(int index, std::string fn, std::string ln) {
	if (index > 7 || index < 0)
	{
		std::cout << "Input not correspond a valid number" << std::endl;
		std::cout << "Try again" << std::endl;
	}
	else if (index != NULL || index > 7 || index < 0)
	{
		contact[index].getData();
		return (0);
	}
	else if (fn != NULL)
	{
		for (int i = 0; i < 8; ++i)
		{
			if (contact[i].getFirstName() == fn)
			{
				contact[i].getData();
				return (0);
			}
		}
		std::cout << "First Name not found!" << std::endl;
	}
	if (ln != NULL)
	{
		for (int i = 0; i < 8; ++i)
		{
			if (contact[i].getLastName() == fn)
			{
				contact[i].getData();
				return (0);
			}
		}
		std::cout << "Last Name not found!" << std::endl;
	}
	else
	{

	}
	return (0);
}

int	PhoneBook::exit(void) {
	return (0);
}
