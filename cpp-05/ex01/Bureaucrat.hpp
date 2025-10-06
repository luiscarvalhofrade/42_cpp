/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luide-ca <luide-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 16:54:19 by luide-ca          #+#    #+#             */
/*   Updated: 2025/10/06 15:15:53 by luide-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <exception>
# include "Form.hpp"

class Bureaucrat {
    private:
        const std::string _name;
        int _grade;
        static const int HIGHEST_GRADE = 1;
        static const int LOWEST_GRADE = 150;

    public:
        Bureaucrat(void);
        Bureaucrat(const std::string name, int grade);
        Bureaucrat(const Bureaucrat& other);
        ~Bureaucrat(void);

        Bureaucrat& operator=(const Bureaucrat& other);
        
        const std::string getName(void) const;
        int getGrade(void) const;
        void incrementGrade(void);
        void decrementGrade(void);

        void signForm(Form& form);

        class GradeTooHighException : public std::exception {
            public:
                virtual const char* what() const throw();
        };

        class GradeTooLowException : public std::exception {
            public:
                virtual const char* what() const throw();
        };
};

std::ostream&	operator<<(std::ostream& out, const Bureaucrat& b);

#endif