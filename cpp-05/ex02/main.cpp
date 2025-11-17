/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luide-ca <luide-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 15:25:20 by luide-ca          #+#    #+#             */
/*   Updated: 2025/11/17 15:29:05 by luide-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

void testValidBureaucrat()
{
	try
	{
		Bureaucrat A("Alice", 50);
		std::cout << A << std::endl;
		A.incrementGrade();
		std::cout << "After grade increase: " << A << std::endl;
		A.decrementGrade();
		std::cout << "After grade decrease: " << A << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}

void testShrubberyForm()
{
	try
	{
		Bureaucrat john("John", 136);
		std::cout << john << std::endl;

		ShrubberyCreationForm shrubberyForm("garden");
		std::cout << "------FORM INFORMATION (OP OVERLOADING)------" << std::endl;
		std::cout << shrubberyForm << std::endl;
		std::cout << "---------------------------------------------" << std::endl;
		std::cout << "John attempts to sign the ShrubberyCreationForm..." << std::endl;
		shrubberyForm.beSigned(john);
		std::cout << "Form signed status: " << (shrubberyForm.isSigned() ? "Signed" : "Not Signed") << std::endl;

		std::cout << "John attempts to execute the ShrubberyCreationForm..." << std::endl;
		shrubberyForm.executeAction(john);
	}
	catch (const std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}
}

void testRobotomyRequestForm()
{
	try
	{
		Bureaucrat bob("Bob", 32);
		std::cout << bob << std::endl;

		RobotomyRequestForm robotomyForm("target1");
		std::cout << "------FORM INFORMATION (OP OVERLOADING)------" << std::endl;
		std::cout << robotomyForm << std::endl;
		std::cout << "---------------------------------------------" << std::endl;

		std::cout << "Bob attempts to sign the RobotomyRequestForm..." << std::endl;
		robotomyForm.beSigned(bob);
		std::cout << "Form signed status: " << (robotomyForm.isSigned() ? "Signed" : "Not Signed") << std::endl;

		std::cout << "Bob attempts to execute the RobotomyRequestForm..." << std::endl;
		robotomyForm.executeAction(bob);
	}
	catch (const std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}
}


void testPresidentialPardonForm()
{
	try
	{
		Bureaucrat charles("Charles", 5);
		std::cout << charles << std::endl;

		PresidentialPardonForm pardonForm("target2");
		std::cout << "------FORM INFORMATION (OP OVERLOADING)------" << std::endl;
		std::cout << pardonForm << std::endl;
		std::cout << "---------------------------------------------" << std::endl;

		std::cout << "Charles attempts to sign the PresidentialPardonForm..." << std::endl;
		pardonForm.beSigned(charles);
		std::cout << "Form signed status: " << (pardonForm.isSigned() ? "Signed" : "Not Signed") << std::endl;

		std::cout << "Charles attempts to execute the PresidentialPardonForm..." << std::endl;
		pardonForm.executeAction(charles);
	}
	catch (const std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}
}

void testExecuteForm()
{
	try
	{
		Bureaucrat executor("Executor", 1);
		std::cout << executor << std::endl;

		ShrubberyCreationForm shrubberyForm("park");
		RobotomyRequestForm robotomyForm("robot_target");
		PresidentialPardonForm pardonForm("criminal");

		std::cout << "\nExecutor attempts to sign all forms..." << std::endl;
		shrubberyForm.beSigned(executor);
		robotomyForm.beSigned(executor);
		pardonForm.beSigned(executor);

		std::cout << "Form signed status: " << (shrubberyForm.isSigned() ? "Signed" : "Not Signed") << std::endl;
		std::cout << "Form signed status: " << (robotomyForm.isSigned() ? "Signed" : "Not Signed") << std::endl;
		std::cout << "Form signed status: " << (pardonForm.isSigned() ? "Signed" : "Not Signed") << std::endl;

		std::cout << "\nExecutor attempts to execute ShrubberyCreationForm..." << std::endl;
		executor.executeForm(shrubberyForm);

		std::cout << "\nExecutor attempts to execute RobotomyRequestForm..." << std::endl;
		executor.executeForm(robotomyForm);

		std::cout << "\nExecutor attempts to execute PresidentialPardonForm..." << std::endl;
		executor.executeForm(pardonForm);
	}
	catch (const std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}
}

int main(void)
{
	std::cout << "Testing valid Bureaucrat:" << std::endl;
	testValidBureaucrat();

	std::cout << "\nTesting Shrubbery Form:" << std::endl;
	testShrubberyForm();

	std::cout << "\nTesting Robotomy Request Form:" << std::endl;
	testRobotomyRequestForm();
	
	std::cout << "\nTesting Presidential Pardon Form:" << std::endl;
	testPresidentialPardonForm();

	std::cout << "\nTesting Execute form:" << std::endl;
	testExecuteForm();
	
	return 0;
}