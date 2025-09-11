/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luide-ca <luide-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 20:58:01 by luide-ca          #+#    #+#             */
/*   Updated: 2025/08/22 13:31:59 by luide-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AANIMAL_HPP
# define AANIMAL_HPP

# include <iostream>

class AAnimal {
protected:
    std::string _type;
public:
	AAnimal(void);
    AAnimal(const AAnimal& other);
    virtual ~AAnimal(void);

    AAnimal& operator=(const AAnimal& other);

    virtual void makeSound(void) const = 0;
    std::string getType(void) const;
};

#endif