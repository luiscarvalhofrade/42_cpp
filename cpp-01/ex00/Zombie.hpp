/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luide-ca <luide-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 17:35:59 by luide-ca          #+#    #+#             */
/*   Updated: 2025/07/30 19:21:53 by luide-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>

class Zombie {
private:
    std::string _name;

public:
    Zombie(void);
    ~Zombie(void);
    void    setName(std::string name);
    void    announce(void);

};

Zombie  *newZombie(std::string name);
void    randomChump(std::string name);

#endif