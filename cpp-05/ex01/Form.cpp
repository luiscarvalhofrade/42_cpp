/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luide-ca <luide-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 16:54:26 by luide-ca          #+#    #+#             */
/*   Updated: 2025/09/15 17:56:05 by luide-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(void) : _name("undefined form"), _grade(150) {
    std::cout << "Default Form constructor called" << std::endl;
}

Form::Form(std::string name, int grade) : _name(name) {
    if (grade > LOWEST_GRADE)
        throw GradeTooLowException();
    else if (grade < HIGHEST_GRADE)
        throw GradeTooHighException();
    _grade = grade;
    std::cout << "Form " << this->_name << " with grade:" <<  this->_grade << "has been created!!!" << std::endl;
}

Form::Form(const Form& other) : _name(other._name), _grade(other._grade) {
    std::cout << "Form copy has been made" << std::endl;
}

Form::~Form(void) {
    std::cout << "Form " << this->_name << " has been destroyed!!!" << std::endl;
}

Form& Form::operator=(const Form& other) {
    std::cout << "Form copy assingment operator has been called" << std::endl;
    if (this != &other)
        _grade = other.getGrade();
    return *this;
}

const std::string Form::getName(void) const {
    return this->_name;
}