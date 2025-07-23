/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luide-ca <luide-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 12:13:29 by luide-ca          #+#    #+#             */
/*   Updated: 2025/07/23 13:35:46 by luide-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"

int main(void) {
	std::string option;
	PhoneBook my_pb;

	while (1)
	{
		std::cout << "====== starting program something 1 =====" << std::endl;
		std::cout << "what do you want? Add, search or exit?" << std::endl;
		std::cout << "option -> "; std::cin >> option;
		if (option == "add")
			my_pb.add();
		else if (option == "exit")
			break;
		//else if (option == "search")
			/*add here management of */
	}

	return (0);
}