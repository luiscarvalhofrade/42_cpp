/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luide-ca <luide-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 17:25:30 by luide-ca          #+#    #+#             */
/*   Updated: 2025/10/07 15:10:32 by luide-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void) : AForm("ShrubberyCreationForm", 145, 137, "undefined") {
    std::cout << "Default ShrubberyCreationForm constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string target) : AForm("ShrubberyCreationForm", 145, 137, target) {
    std::cout << "Default ShrubberyCreationForm constructor called, with " << target << " as target!!!" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) : AForm(other) {
    std::cout << "ShrubberyCreationForm copy has been made" << std::endl;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other) {
    std::cout << "ShrubberyCreationForm copy assignment operator has been called" << std::endl;
	if (this != &other)
		AForm::operator=(other);
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void) {
    std::cout << "ShrubberyCreationForm has been destroyed!!!" << std::endl;
}

void ShrubberyCreationForm::drawAsciiTree(std::ofstream &outFile) const {
	outFile << "      *****      " << std::endl;
	outFile << "     *******     " << std::endl;
	outFile << "    *********    " << std::endl;
	outFile << "     *******     " << std::endl;
	outFile << "      *****      " << std::endl;
	outFile << "       |||       " << std::endl;
	outFile << "       |||       " << std::endl;
}

const char* ShrubberyCreationForm::FileException::what() const throw() {
	return "Error during file creation";
}

void ShrubberyCreationForm::executeAction(const Bureaucrat& bureaucrat) const {
	this->FormRequirements(bureaucrat);

	std::string filename = this->getTarget() + "_shrubbery";
	std::ofstream outFile(filename.c_str());

	if (!outFile.is_open())
		throw FileException();

	drawAsciiTree(outFile);
	outFile << std::endl;
	drawAsciiTree(outFile);

	outFile.close();
}