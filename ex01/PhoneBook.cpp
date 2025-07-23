/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luide-ca <luide-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 12:08:45 by luide-ca          #+#    #+#             */
/*   Updated: 2025/07/23 13:35:00 by luide-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void) {
	std::cout << "constructor for PhoneBook called" << std::endl;
}

PhoneBook::~PhoneBook(void) {
	std::cout << "destructor for PhoneBook called" << std::endl;
}

void	PhoneBook::add(void) {
	Contact	new_contact;

	new_contact.setData();
	std::cout << "=== confirming data ===" << std::endl;
	new_contact.getData();
	std::cout << "=== =============== ===" << std::endl;
}