/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luide-ca <luide-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 17:56:11 by luide-ca          #+#    #+#             */
/*   Updated: 2025/07/30 18:27:41 by luide-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void) {
    std::string option;
    std::string name;

    std::cout << "We are going to create the random Chump Luis in the stack" << std::endl;
    randomChump("Luis");
    std::cout << std::endl;

    std::cout << "now, creating the new Zombie Frade in the heap" << std::endl;
    Zombie *heapZombie = newZombie("Frade");
    heapZombie->announce();
    std::cout << std::endl;
    std::cout << "No memory leaks in our project, right? deleting Zombie in the heap" << std::endl;
    std::cout << std::endl;
    delete heapZombie;
    
    return (0);
}