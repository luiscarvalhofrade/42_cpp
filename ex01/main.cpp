/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luide-ca <luide-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 12:13:29 by luide-ca          #+#    #+#             */
/*   Updated: 2025/07/28 18:26:44 by luide-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"

int main(void) {
	std::string option;
	std::string name;
	int			index;
	int			index2;
	PhoneBook my_pb;

	while (1)
	{
		std::cout << "====== Phone Book =====" << std::endl;
		std::cout << "what do you want? Add (option 1), search (option 2) or exit (option 3)?" << std::endl;
		std::cout << "option -> "; std::cin >> option;
		if (option == "add" || option == "1")
			my_pb.add();
		else if (option == "search" || option == "2")	
		{
			std::cout << "====== Search =====" << std::endl;
			std::cout << "what info do you have? Write the index (option '1') or for the first or last name (option '2')?" << std::endl;
			std::cout << "option -> "; std::cin >> index;
			if (index == 1)
			{
				std::cout << "what is the index?" << std::endl;
				std::cout << "index -> "; std::cin >> index2;
				my_pb.search(index2, "");
			}
			else if (index == 2)
			{
				std::cout << "what is the name?" << std::endl;
				std::cout << "name -> "; std::cin >> name;
				my_pb.search(-1, name);
			}

		}
		else if (option == "exit"  || option == "3")
			break;
		else
			std::cout << "Option not found, try again" << std::endl;
	}
	return (0);
}