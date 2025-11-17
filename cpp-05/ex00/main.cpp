/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luide-ca <luide-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 16:45:06 by luide-ca          #+#    #+#             */
/*   Updated: 2025/11/17 14:39:16 by luide-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

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

void testInvalidGradeTooHigh()
{
	try
	{
		Bureaucrat B("Bob", 0);
		std::cout << B << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << "Caught exception: " << e.what() << std::endl;
	}
}

void testInvalidGradeTooLow()
{
	try
	{
		Bureaucrat C("Charlie", 151);
		std::cout << C << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << "Caught exception: " << e.what() << std::endl;
	}
}

void testBoundaryConditions()
{
	try
	{
		Bureaucrat D("Dave", 1);
		std::cout << D << std::endl;
		D.incrementGrade(); // Should throw an exception
	}
	catch (const std::exception &e)
	{
		std::cout << "Caught exception: " << e.what() << std::endl;
	}

	try
	{
		Bureaucrat E("Eve", 150);
		std::cout << E << std::endl;
		E.decrementGrade(); // Should throw an exception
	}
	catch (const std::exception &e)
	{
		std::cout << "Caught exception: " << e.what() << std::endl;
	}
}

int main(void)
{
	std::cout << "Testing valid Bureaucrat:" << std::endl;
	testValidBureaucrat();

	std::cout << "\nTesting invalid grade (too high):" << std::endl;
	testInvalidGradeTooHigh();

	std::cout << "\nTesting invalid grade (too low):" << std::endl;
	testInvalidGradeTooLow();

	std::cout << "\nTesting boundary conditions:" << std::endl;
	testBoundaryConditions();

	return 0;
}