/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luide-ca <luide-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 12:13:29 by luide-ca          #+#    #+#             */
/*   Updated: 2025/08/17 17:38:53 by luide-ca         ###   ########.fr       */
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
		std::cout << "what do you want? Add/1, search/2 or exit/3?" << std::endl;
		std::cout << "option -> "; std::cin >> option;
		if (option == "add" || option == "1")
			my_pb.add();
		else if (option == "search" || option == "2")	
		{
			std::cout << "====== Search =====" << std::endl;
			my_pb.getPhoneList();
			std::cout << "====== ====== =====" << std::endl;
			std::cout << "what info do you have? Write the index/1 or for the first or last name/2 from the contact?" << std::endl;
			std::cout << "option -> "; std::cin >> index;
			if (index == 1)
			{
				std::cout << "====== ====== =====" << std::endl;
				std::cout << "what is the index?" << std::endl;
				std::cout << "index -> "; std::cin >> index2;
				std::cout << "====== ====== =====" << std::endl;
				my_pb.search(index2, "");
			}
			else if (index == 2)
			{
				std::cout << "====== ====== =====" << std::endl;
				std::cout << "what is the name?" << std::endl;
				std::cout << "name -> "; std::cin >> name;
				std::cout << "====== ====== =====" << std::endl;
				my_pb.search(-1, name);
			}
			else
				std::cout << "Option not found, try again" << std::endl;
		}
		else if (option == "exit"  || option == "3")
			break;
		else
		{
			std::cout << "====== ====== =====" << std::endl;
			std::cout << "Option not found, try again" << std::endl;
			std::cout << "====== ====== =====" << std::endl;
		}
	}
	return (0);
}