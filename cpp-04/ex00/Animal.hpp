/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luide-ca <luide-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 20:58:01 by luide-ca          #+#    #+#             */
/*   Updated: 2025/08/21 22:03:23 by luide-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>

class Animal {
protected:
    std::string _type;
public:
    Animal(void);
    Animal(const Animal& other);
    virtual ~Animal(void);

    Animal& operator=(const Animal& other);

    virtual void makeSound(void) const;
    std::string getType(void) const;
};

#endif