/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luide-ca <luide-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 22:11:55 by luide-ca          #+#    #+#             */
/*   Updated: 2025/08/21 22:42:30 by luide-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain(void) {
	std::cout << "Brain constructor called!!!" << std::endl;
}

Brain::Brain(const Brain& other) {
	std::cout << "Brain copy constructor called!!!" << std::endl;
	for (int i = 0; i < 100; ++i) {
		_ideas[i] = other._ideas[i];
	}
}

Brain::~Brain(void) {
	std::cout << "Brain destructor called!!!" << std::endl;
}

Brain&	Brain::operator=(const Brain& other) {
	std::cout << "Brain assignment called!!!" << std::endl;
	if (this != &other) {
		for (int i = 0; i < 100; ++i) {
			_ideas[i] = other._ideas[i];
		}
	}
	return *this;
}

std::string	Brain::getIdea(int index) const {
	if (index < 0 || index >= 100) {
		return NULL;
	}
	return _ideas[index];
}

void	Brain::setIdea(int index, const std::string idea) {
	if (index < 0 || index >= 100) {
		return ;
	}
	_ideas[index] = idea;
}