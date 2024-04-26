/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pviegas <pviegas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 11:21:30 by pviegas           #+#    #+#             */
/*   Updated: 2024/04/26 11:21:32 by pviegas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/PresidentialPardonForm.hpp"

// Default Constructor
PresidentialPardonForm::PresidentialPardonForm() : AForm("presidential pardon", 25, 5), _target("")
{
}

// Parameterized Constructor
PresidentialPardonForm::PresidentialPardonForm(const std::string& target) : AForm("presidential pardon", 25, 5), _target(target)
{
}

// Copy Constructor
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& target) : AForm(target), _target(target._target)
{
}

// Copy assignment operator
PresidentialPardonForm& PresidentialPardonForm::operator=(PresidentialPardonForm& other)
{
	if ( this != &other )
		*this = other;
	return (*this);
}

// Destructor
PresidentialPardonForm::~PresidentialPardonForm()
{
}

// Getters
std::string PresidentialPardonForm::getTarget() const
{
	return (_target);
}

// Member functions
void PresidentialPardonForm::beExecuted(const Bureaucrat& executor) const
{
	if ( this->getIsSigned() == false )
		throw AForm::NotSignedException();
	else if ( executor.getGrade() > this->getGradeToExecute() )
		throw AForm::GradeTooLowException();
	else
		std::cout << "Informs that " << this->_target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}