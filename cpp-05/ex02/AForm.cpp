/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luide-ca <luide-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 16:54:26 by luide-ca          #+#    #+#             */
/*   Updated: 2025/11/17 15:40:30 by luide-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm(void) : _name("undefined form"), _gradeToSign(150), _gradeToExec(150), _target("target not defined") {
    std::cout << "Default AForm constructor called" << std::endl;
}

AForm::AForm(std::string name, int gradeToSign, int gradeToExec, std::string target) : _name(name), _gradeToExec(gradeToExec),
    _gradeToSign(gradeToSign), _signed(false), _target(target) {
    if (gradeToSign > LOWEST_GRADE || gradeToExec > LOWEST_GRADE)
        throw GradeTooLowException();
    else if (gradeToSign < HIGHEST_GRADE || gradeToExec < HIGHEST_GRADE)
        throw GradeTooHighException();
    std::cout << "AForm " << this->_name << " with grade to be signed:" <<  this->_gradeToSign << "has been created!!!";
    std::cout << " and grade to be executed: " << this->_gradeToExec << std::endl;
}

AForm::AForm(const AForm& other) : _name(other._name), _gradeToExec(other._gradeToExec),  _gradeToSign(other._gradeToSign), _target(other._target) {
    std::cout << "AForm copy has been made" << std::endl;
}

AForm::~AForm(void) {
    std::cout << "AForm " << this->_name << " has been destroyed!!!" << std::endl;
}

AForm& AForm::operator=(const AForm& other) {
    std::cout << "AForm copy assingment operator has been called" << std::endl;
    if (this != &other)
        _signed = other.isSigned();
    return (*this);
}

const std::string AForm::getName(void) const {
    return (this->_name);
}

int AForm::getGradeToExec(void) const {
    return (this->_gradeToExec);
}

int AForm::getGradeToSign(void) const {
    return (this->_gradeToSign);
}

bool AForm::isSigned(void) const {
    return (this->_signed);
}

const std::string AForm::getTarget(void) const {
    return (this->_target);
}

bool    AForm::beSigned(Bureaucrat &signner) {
    if (signner.getGrade() <= this->_gradeToSign)
    {
        this->_signed = true;
        return (true);
    }
    return (false);
}

void AForm::FormRequirements(Bureaucrat const &executor) const {
    if (!this->_signed)
        throw AForm::FormNotSigned();
    if (executor.getGrade() > this->_gradeToExec)
        throw AForm::GradeTooLowException();
}

std::ostream&	operator<<(std::ostream& out, const AForm& f) {
	out << f.getName();
	if (f.isSigned())
		out << " is signed. ";
	else
		out << " is unsigned. ";
	out << "Grade to sign: " << f.getGradeToSign() << ". Grade to Execute: " << f.getGradeToExec();
	return out;
}

const char* AForm::GradeTooHighException::what() const throw() {
    return "AForm grade is too high!";
}

const char* AForm::GradeTooLowException::what() const throw() {
    return "AForm grade is too low!";
}

const char* AForm::FormNotSigned::what() const throw() {
    return "AForm is not signed!";
}