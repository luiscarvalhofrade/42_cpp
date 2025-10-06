/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luide-ca <luide-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 16:55:04 by luide-ca          #+#    #+#             */
/*   Updated: 2025/10/06 18:26:05 by luide-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>
# include <exception>
# include "Bureaucrat.hpp"

class AForm {
    private:
        const std::string _name;
        const std::string _target;
        bool _signed;
        const int _gradeToSign;
        const int _gradeToExec;
        static const int HIGHEST_GRADE = 1;
        static const int LOWEST_GRADE = 150;
    public:
        AForm(void);
        AForm(std::string name, int gradeToSign, int gradeToExec, std::string target);
        AForm(const AForm& other);
        virtual ~AForm(void);
        
        AForm& operator=(const AForm& other);

        const std::string getName(void) const;
        const std::string getTarget(void) const;
        virtual bool isSigned(void) const = 0;
        int getGradeToSign(void) const;
        int getGradeToExec(void) const;

        bool beSigned(Bureaucrat &signner);
        class GradeTooHighException : public std::exception {
            public:
                virtual const char* what() const throw();
        };

        class GradeTooLowException : public std::exception {
            public:
                virtual const char* what() const throw();
        };
};

std::ostream&	operator<<(std::ostream& out, const AForm& f);

#endif