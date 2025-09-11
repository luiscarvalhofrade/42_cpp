/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luide-ca <luide-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 20:59:35 by luide-ca          #+#    #+#             */
/*   Updated: 2025/08/22 13:28:48 by luide-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "AAnimal.hpp"
# include "Brain.hpp"

class Cat : public AAnimal {
private:
    Brain* _brain;
public:
    Cat(void);
    Cat(const Cat& other);
    ~Cat(void);

    Cat& operator=(const Cat& other);

    void makeSound(void) const;
};

#endif