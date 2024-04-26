/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pviegas <pviegas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 10:37:09 by pviegas           #+#    #+#             */
/*   Updated: 2024/04/26 10:49:59 by pviegas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/RobotomyRequestForm.hpp"

// Default Constructor
RobotomyRequestForm::RobotomyRequestForm()
{
}

// Parameterized Constructor
RobotomyRequestForm::RobotomyRequestForm(const std::string& target) : AForm("Robotomy Request Form", 72, 45), _target(target)
{
}

// Copy Constructor
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& target) : AForm(target), _target(target._target)
{
}

// Copy assignment operator
RobotomyRequestForm& RobotomyRequestForm::operator=(RobotomyRequestForm& other)
{
	if (this != &other)
		*this = other;
	return (*this);
}

// Destructor
RobotomyRequestForm::~RobotomyRequestForm()
{
}

// Member functions
void RobotomyRequestForm::execute(const Bureaucrat& executor) const
{
	if (this->getIsSigned() == false)
		throw AForm::NotSignedException();
	else if (executor.getGrade() > this->getGradeToExecute())
		throw AForm::GradeTooLowException();
	else
	{
		static int  i;
		if (i % 2 == 0)
		{
			std::cout << "Bzzzzz... " << std::endl;
			std::cout << "Vrrrrr... " << std::endl;
			std::cout << "Whirrr... " << std::endl;
			std::cout << "Trrrrr... " << std::endl;
			std::cout << this->_target << " has been sucessful !!" << std::endl;
		}
		else
			std::cout << this->_target << "'s Robotomy Failed !! "  << std::endl;
		i++;
	}
}