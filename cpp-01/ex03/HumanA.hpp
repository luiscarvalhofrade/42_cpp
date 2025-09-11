/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luide-ca <luide-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 19:33:09 by luide-ca          #+#    #+#             */
/*   Updated: 2025/08/04 20:03:00 by luide-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

# include "Weapon.hpp"

class HumanA {
private:
        std::string _name;
        Weapon      *_weapon;

public:
        HumanA(std::string name, Weapon &weapon);
        ~HumanA(void);
        void    setWeapon(Weapon &weapon);
        void    attack(void);
};

#endif