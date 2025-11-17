/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luide-ca <luide-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 16:55:04 by luide-ca          #+#    #+#             */
/*   Updated: 2025/11/17 15:14:28 by luide-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <exception>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form {
    private:
        const std::string _name;
        bool _signed;
        const int _gradeToSign;
        const int _gradeToExec;
        static const int HIGHEST_GRADE = 1;
        static const int LOWEST_GRADE = 150;
    public:
        Form(void);
        Form(std::string name, int gradeToSign, int gradeToExec);
        Form(const Form& other);
        ~Form(void);
        
        Form& operator=(const Form& other);

        class GradeTooHighException : public std::exception {
            public:
                virtual const char* what() const throw();
        };

        class GradeTooLowException : public std::exception {
            public:
                virtual const char* what() const throw();
        };

        const std::string getName(void) const;
        bool isSigned(void) const;
        int getGradeToSign(void) const;
        int getGradeToExec(void) const;

        bool beSigned(const Bureaucrat& signner);
        
};

std::ostream&	operator<<(std::ostream& out, const Form& f);
std::ostream&	operator<<(std::ostream& out, const Form* f);

#endif