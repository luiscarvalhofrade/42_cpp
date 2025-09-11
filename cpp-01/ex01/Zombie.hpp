/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luide-ca <luide-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 18:38:56 by luide-ca          #+#    #+#             */
/*   Updated: 2025/07/30 19:12:23 by luide-ca         ###   ########.fr       */
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
    void    announce(void);
    void    setName(std::string name);

};

Zombie  *zombieHorde(int N, std::string name);

#endif