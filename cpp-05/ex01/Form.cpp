/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luide-ca <luide-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 16:54:26 by luide-ca          #+#    #+#             */
/*   Updated: 2025/11/17 15:20:26 by luide-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(void) : _name("undefined form"), _gradeToSign(150), _gradeToExec(150) {
    std::cout << "Default Form constructor called" << std::endl;
}

Form::Form(std::string name, int gradeToSign, int gradeToExec) : _name(name), _gradeToExec(gradeToExec),
    _gradeToSign(gradeToSign), _signed(false) {
    if (gradeToSign > LOWEST_GRADE || gradeToExec > LOWEST_GRADE)
        throw GradeTooLowException();
    else if (gradeToSign < HIGHEST_GRADE || gradeToExec < HIGHEST_GRADE)
        throw GradeTooHighException();
    std::cout << "Form " << this->_name << " with grade to be signed:" <<  this->_gradeToSign << "has been created!!!";
    std::cout << " and grade to be executed: " << this->_gradeToExec << std::endl;
}

Form::Form(const Form& other) : _name(other._name), _gradeToExec(other._gradeToExec),  _gradeToSign(other._gradeToSign) {
    std::cout << "Form copy has been made" << std::endl;
}

Form::~Form(void) {
    std::cout << "Form " << this->_name << " has been destroyed!!!" << std::endl;
}

Form& Form::operator=(const Form& other) {
    std::cout << "Form copy assingment operator has been called" << std::endl;
    if (this != &other)
    {
        _signed = other.isSigned();
    }
    return *this;
}

const std::string Form::getName(void) const {
    return this->_name;
}

int Form::getGradeToExec(void) const {
    return this->_gradeToExec;
}

int Form::getGradeToSign(void) const {
    return this->_gradeToSign;
}

bool Form::isSigned(void) const {
    return (this->_signed);
}

bool    Form::beSigned(const Bureaucrat &signner) {
    if (signner.getGrade() <= this->_gradeToSign)
    {
        this->_signed = true;
        return (true);
    }
    throw (GradeTooLowException());
}

const char *Form::GradeTooHighException::what() const throw() {
	return ("Bureaucrat grade too high");
}

const char *Form::GradeTooLowException::what() const throw() {
	return ("Bureaucrat grade too low");
}

std::ostream&	operator<<(std::ostream& out, const Form& f) {
	out << f.getName();
	if (f.isSigned())
		out << " is signed. ";
	else
		out << " is unsigned. ";
	out << "Grade to sign: " << f.getGradeToSign() << ". Grade to Execute: " << f.getGradeToExec();
	return out;
}

std::ostream&	operator<<(std::ostream& out, const Form* f) {
	out << f->getName();
	if (f->isSigned())
		out << " is signed. ";
	else
		out << " is unsigned. ";
	out << "Grade to sign: " << f->getGradeToSign() << ". Grade to Execute: " << f->getGradeToExec();
	return out;
}