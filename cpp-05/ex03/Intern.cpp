/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luide-ca <luide-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 13:47:14 by luide-ca          #+#    #+#             */
/*   Updated: 2025/10/07 15:32:31 by luide-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern(void) {
    std::cout << "Default Intern constructor called" << std::endl;
}

Intern::Intern(const Intern& other) {
	std::cout << "Intern copy has been made" << std::endl;
	*this = other;
}

Intern& Intern::operator=(const Intern& other) {
    std::cout << "Intern copy assignment operator has been called" << std::endl;
	(void)other;
	return *this;
}

Intern::~Intern(void) {
    std::cout << "Intern has been destroyed!!!" << std::endl;
}

AForm*    Intern::makeForm(const std::string& name, const std::string& target) {
    std::string forms[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
    AForm* (Intern::*makeFormPtr[3])(const std::string& target) = {
        &Intern::_makeShrubberyForm,
        &Intern::_makeRobotomyForm,
        &Intern::_makePresidentialForm
    };

    for (int i = 0; i < 3; i++) {
        if (name == forms[i]) {
            std::cout << "Intern creates " << name << " form." << std::endl;
            return (this->*makeFormPtr[i])(target);
        }
    }

    std::cout << "Intern does not know how to create " << name << " form." << std::endl;
    return NULL;
}

AForm*	Intern::_makeShrubberyForm(const std::string& target) {       	
	return new ShrubberyCreationForm(target);
}

AForm*	Intern::_makeRobotomyForm(const std::string& target) {
	return new RobotomyRequestForm(target);
}

AForm*	Intern::_makePresidentialForm(const std::string& target) {
	return new PresidentialPardonForm(target);
}