/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luide-ca <luide-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 18:49:54 by luide-ca          #+#    #+#             */
/*   Updated: 2025/07/30 19:16:29 by luide-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
    Zombie *zombie;
    int i;
    std::cout << "Creating 5 Zombies called Luis" << std::endl;
    zombie = zombieHorde(5, "Luis");
    std::cout << std::endl;

    std::cout << "To prove that all Zombies from the Horde were created, They are going to say hello :)" << std::endl;
    i = 0;
    while (i < 5)
    {
        zombie[i].announce();
        i++;
    }
    std::cout << "Before calling agian our function, time to say good bye to our beloved Zombies ;(" << std::endl;
    delete[] zombie;
    std::cout << std::endl; 

    std::cout << "Creating 10 Zombies called Frade" << std::endl;
    zombie = zombieHorde(10, "Frade");
    std::cout << std::endl;

    std::cout << "To prove that all Zombies from the Horde were created, They are going to say hello :)" << std::endl;
    i = 0;
    while (i < 10)
    {
        zombie[i].announce();
        i++;
    }
    std::cout << "Before calling agian our function, time to say good bye to our beloved Zombies ;(" << std::endl;
    delete[] zombie;
    return (0);
}