/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luide-ca <luide-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 17:25:20 by luide-ca          #+#    #+#             */
/*   Updated: 2025/10/07 13:31:26 by luide-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(void) : AForm("RobotomyRequestForm", 72, 45, "undefined") {
    std::cout << "Default RobotomyRequestForm constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string target) : AForm("RobotomyRequestForm", 72, 45, target) {
    std::cout << "Default RobotomyRequestForm constructor called, with " << target << " as target!!!" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) : AForm("RobotomyRequestForm", 72, 45, other.getTarget()) {
    std::cout << "RobotomyRequestForm copy has been made" << std::endl;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other) {
    std::cout << "RobotomyRequestForm copy assignment operator has been called" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm(void) {
    std::cout << "RobotomyRequestForm has been destroyed!!!" << std::endl;
}

void RobotomyRequestForm::drillingNoise(void) const {
	std::cout << "ion ion ion ion... ";
	std::cout << "...tru tru tru tru... ";
	std::cout << "Doneee!!!" << std::endl;
}

bool RobotomyRequestForm::randomRobotomyFactor() const {
    return std::rand() % 2 == 0;
}

void RobotomyRequestForm::executeAction(const Bureaucrat& bureaucrat) const {
	this->FormRequirements(bureaucrat);
	drillingNoise();
    if (randomRobotomyFactor()) {
        std::cout << this->getTarget() << " has been robotomized successfully!" << std::endl;
    } else {
        std::cout << "Robotomy of " << this->getTarget() << " has failed..." << std::endl;
    }
    
}
