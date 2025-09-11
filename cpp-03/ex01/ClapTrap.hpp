/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luide-ca <luide-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 23:48:01 by luide-ca          #+#    #+#             */
/*   Updated: 2025/08/22 10:19:42 by luide-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>

class ClapTrap {
protected:
    std::string			_name;
    unsigned int        _hitPoints;
    unsigned int        _energyPoints;
    unsigned int        _attackDamage;
public:
    ClapTrap(void);
    ClapTrap(const std::string name);
    ClapTrap(const ClapTrap& other);
    virtual ~ClapTrap(void);

    ClapTrap& operator=(const ClapTrap& other);

    std::string		getName(void) const;
    unsigned int	getHitPoints(void) const;
    unsigned int	getEnergyPoints(void) const;
    unsigned int	getAttackDamage(void) const;

    void	attack(const std::string& target);
    void	takeDamage(unsigned int amount);
    void	beRepaired(unsigned int amount);
};

#endif