/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pviegas <pviegas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 11:21:17 by pviegas           #+#    #+#             */
/*   Updated: 2024/04/26 13:57:41 by pviegas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Intern.hpp"
#include "../include/RobotomyRequestForm.hpp"
#include "../include/ShrubberyCreationForm.hpp"
#include "../include/PresidentialPardonForm.hpp"

// Default Constructor
Intern::Intern()
{
}

// Parameterized Constructor

// Copy Constructor
Intern::Intern(const Intern& other)
{
  *this = other;
}

// Copy assignment operator
Intern& Intern::operator=(const Intern& other)
{
	if ( this != &other )
		*this = other;
	return (*this);
}

// Destructor
Intern::~Intern()
{
}

// Getters

// Exception classes

// Member functions
AForm* Intern::makeForm(const std::string& formName, const std::string& target) const
{
	AForm*	form = NULL;
	AForm*	(Intern::*funcPtr[3])(const std::string& target) const = {&Intern::newShrubbery, &Intern::newRobotomy, &Intern::newPresidential};
	std::string	formNames[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};

	for (int i = 0; i < 3; ++i)
	{
		if (formName == formNames[i])
		{
			form = (this->*funcPtr[i])(target);
			std::cout << "Intern create " << formName << " form." << std::endl;
			return (form);
		}
	}
	std::cout << "Intern cannot create " << formName << " form : Invalid form name !" << std::endl;
	return (NULL);
}

AForm* Intern::newShrubbery(const std::string& target) const
{
	AForm*	form = new ShrubberyCreationForm(target);
	return (form);
}

AForm* Intern::newRobotomy(const std::string& target) const
{
	AForm*	form = new RobotomyRequestForm(target);
	return (form);
}

AForm* Intern::newPresidential(const std::string& target) const
{
	AForm *	form = new PresidentialPardonForm(target);
	return form;
}

// insertion operator overload
