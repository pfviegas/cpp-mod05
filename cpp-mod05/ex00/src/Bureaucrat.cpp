/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pviegas <pviegas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 10:32:25 by pviegas           #+#    #+#             */
/*   Updated: 2024/04/26 10:32:27 by pviegas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Bureaucrat.hpp"

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
	if (this->_grade - 1 < MAX_GRADE)
		throw Bureaucrat::GradeTooHighException();
	this->_grade--;
}

void Bureaucrat::decrementGrade()
{
	if (this->_grade + 1 > MIN_GRADE)
		throw Bureaucrat::GradeTooLowException();
	this->_grade++;
}

// Exception Member functions
const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("The Grade is too high !!");
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("The Grade is too low !!");
}

// insertion operator overload
std::ostream& operator<<(std::ostream& os, const Bureaucrat& value)
{
	return (os << value.getName() << ", bureaucrat grade " << value.getGrade());
}