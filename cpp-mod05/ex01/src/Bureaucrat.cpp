/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pviegas <pviegas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 10:33:20 by pviegas           #+#    #+#             */
/*   Updated: 2024/04/26 10:33:23 by pviegas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Bureaucrat.hpp"
#include "../include/Form.hpp"

// Default Constructor
Bureaucrat::Bureaucrat() : _name(""), _grade(1) {}

// Parameterized Constructor
Bureaucrat::Bureaucrat(const std::string& name, int grade) : _name(name), _grade(grade)
{
	if (this->_grade < Bureaucrat::MAX_GRADE)
		throw Bureaucrat::GradeTooHighException();
	else if (this->_grade > Bureaucrat::MIN_GRADE)
		throw Bureaucrat::GradeTooLowException();
}

// Copy Constructor
Bureaucrat::Bureaucrat(const Bureaucrat& other) : _name(other._name), _grade(other._grade)
{
}

// Copy assignment operator
Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
	if ( this != &other )
		_grade = other.getGrade();
	return (*this);
}

// Destructor
Bureaucrat::~Bureaucrat()
{
}

// Getters
const std::string& Bureaucrat::getName() const
{
	return (this->_name);
}

int Bureaucrat::getGrade() const
{
	return (this->_grade);
}

// Member functions
void Bureaucrat::incrementGrade()
{
	if ( _grade - 1 < MAX_GRADE )
		throw Bureaucrat::GradeTooHighException();
	_grade--;
}

void    Bureaucrat::decrementGrade()
{
	if ( _grade + 1 > MIN_GRADE )
		throw Bureaucrat::GradeTooLowException();
	_grade++;
}

void Bureaucrat::signForm(Form& form)
{
	try
	{
		form.beSigned(*this);
		std::cout << this->_name << " signed " << form.getName() << " form." << std::endl;
	}
	catch (Form::GradeTooLowException &e)
	{
		std::cout << this->_name << " coulnd't sign " << form.getName() << " because " << e.what() << std::endl;
	}
}

void Bureaucrat::executeForm(const Form& form)
{
	try
	{
		form.beExecuted(*this);
		std::cout << this->getName() << " executed " << form.getName() << " form !!" << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << this->getName() << " couldn't execute " << form.getName() << " form because " << e.what() << std::endl;
	}
}

// Exception Member functions
const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("the Grade is too high !!");
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("the Grade is too low !!");
}

// insertion operator overload
std::ostream& operator<<(std::ostream& os, const Bureaucrat& value)
{
	os << value.getName() << ", bureaucrat with grade " << value.getGrade() << std::endl;
	return (os);
}