/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luide-ca <luide-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 16:54:09 by luide-ca          #+#    #+#             */
/*   Updated: 2025/10/07 13:39:42 by luide-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void) : _name("nobody"), _grade(150) {
    std::cout << "Default Bureaucrat constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name) {
    if (grade > LOWEST_GRADE)
        throw GradeTooLowException();
    else if (grade < HIGHEST_GRADE)
        throw GradeTooHighException();
    _grade = grade;
    std::cout << "Bureaucrat " << this->_name << " with grade:" <<  this->_grade << "has been created!!!" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : _name(other._name), _grade(other._grade) {
    std::cout << "Bureaucrat copy has been made" << std::endl;
}

Bureaucrat::~Bureaucrat(void) {
    std::cout << "Bureaucrat " << this->_name << " has been destroyed!!!" << std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) {
    std::cout << "Bureaucrat copy assingment operator has been called" << std::endl;
    if (this != &other)
        _grade = other.getGrade();
    return *this;
}

const std::string Bureaucrat::getName(void) const {
    return this->_name;
}

int Bureaucrat::getGrade(void) const {
    return this->_grade;
}

void    Bureaucrat::incrementGrade(void) {
    if (this->_grade <= HIGHEST_GRADE)
        throw GradeTooHighException();
    _grade--;
}

void    Bureaucrat::decrementGrade(void) {
    if (this->_grade >= LOWEST_GRADE)
        throw GradeTooLowException();
    _grade++;
}

void    Bureaucrat::signForm(AForm& form) {
    try {
        form.beSigned(*this);
        std::cout << this->_name << " signed" << form.getName() << std::endl;
    }
    catch (std::exception& e) {
        std::cout << this->_name << " couldn't sign " << form.getName() << e.what() << std::endl;
    }
}

const char*	Bureaucrat::GradeTooHighException::what() const throw() {
	return "grade is too high!";
}

const char*	Bureaucrat::GradeTooLowException::what() const throw() {
	return "grade is too low!";
}

void Bureaucrat::executeForm(AForm const & form) const {
	std::cout << this->getName() << " executed " << form.getName() << std::endl;
}

std::ostream&	operator<<(std::ostream& out, const Bureaucrat& b) {
	out << b.getName() << ", bureaucrat grade " << b.getGrade() << ".";
	return out;
}