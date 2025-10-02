/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luide-ca <luide-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 16:55:04 by luide-ca          #+#    #+#             */
/*   Updated: 2025/09/15 17:43:35 by luide-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <exception>
# include "Bureaucrat.hpp"

class Form {
    private:
        const std::string _name;
        bool _signed;
        const int _gradeToSign;
        const int _gradeToExec;
    public:
        Form(void);
        Form(std::string name, int gradeToSign, int gradeToExec);
        Form(const Form& other);
        ~Form(void);
        
        Form& operator=(const Form& other);

        const std::string getName(void) const;
        bool isSigned(void);
        int getGradeToSign(void) const;
        int getGradeToExec(void) const;

        void beSigned(Bureaucrat signner);
        class GradeTooHighException : public std::exception {
            public:
                virtual const char* what() const throw();
        };

        class GradeTooLowException : public std::exception {
            public:
                virtual const char* what() const throw();
        };
};

#endif