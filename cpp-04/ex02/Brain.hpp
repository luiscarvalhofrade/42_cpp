/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luide-ca <luide-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 22:11:58 by luide-ca          #+#    #+#             */
/*   Updated: 2025/08/21 22:33:05 by luide-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>

class Brain {
private:
    std::string _ideas[100];
public:
    Brain(void);
    Brain(const Brain& other);
    ~Brain(void);

    Brain& operator=(const Brain& other);

    std::string	getIdea(int index) const;
	void		setIdea(int index, const std::string idea);
};

#endif