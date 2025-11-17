/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luide-ca <luide-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 14:45:09 by luide-ca          #+#    #+#             */
/*   Updated: 2025/11/17 15:21:16 by luide-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

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

void testFormWithBureaucrat()
{
	try
	{
		// Create a Bureaucrat
		Bureaucrat bob("Bob", 45);
		std::cout << bob << std::endl;

		// Create a Form
		Form taxForm("Tax Form", 50, 30);
		std::cout << taxForm << std::endl;

		// Attempt to sign the form
		std::cout << "Bob attempts to sign the form..." << std::endl;
		taxForm.beSigned(bob);
		std::cout << "Form signed status: " << (taxForm.isSigned() ? "Signed" : "Not Signed") << std::endl;

		// Create another Bureaucrat with lower grade
		Bureaucrat alice("Alice", 60);
		std::cout << alice << std::endl;

		// Attempt to sign the form with Alice
		std::cout << "Alice attempts to sign the form..." << std::endl;
		taxForm.beSigned(alice);
		std::cout << "Form signed status: " << (taxForm.isSigned() ? "Signed" : "Not Signed") << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}
}

void testBureaucratSignForm()
{
	try
	{
		// Create a Bureaucrat
		Bureaucrat charlie("Charlie", 40);
		std::cout << charlie << std::endl;

		// Create a Form
		Form reportForm("Report Form", 50, 30);
		Form taxForm("Tax Form", 50, 30);
		std::cout << reportForm << std::endl;

		// Bureaucrat attempts to sign the form using signForm
		std::cout << "Charlie attempts to sign the form using signForm..." << std::endl;
		charlie.signForm(reportForm);
		std::cout << "Form signed status: " << (reportForm.isSigned() ? "Signed" : "Not Signed") << std::endl;

		// Create another Bureaucrat with lower grade
		Bureaucrat dave("Dave", 60);
		std::cout << dave << std::endl;

		// Bureaucrat attempts to sign the form using signForm
		std::cout << "Dave attempts to sign the form using signForm..." << std::endl;
		dave.signForm(taxForm);
		std::cout << "Form signed status: " << (taxForm.isSigned() ? "Signed" : "Not Signed") << std::endl;
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

	std::cout << "\nTesting Form with Bureaucrat:" << std::endl;
	testFormWithBureaucrat();

	std::cout << "\nTesting Bureaucrat with Form:" << std::endl;
	testBureaucratSignForm();

	return 0;
}