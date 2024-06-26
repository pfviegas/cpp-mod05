/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pviegas <pviegas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 10:36:45 by pviegas           #+#    #+#             */
/*   Updated: 2024/04/26 11:17:52 by pviegas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/AForm.hpp"

// Default Constructor
AForm::AForm() : _name(""), _isSigned(false), _gradeToSign(0), _gradeToExecute(0)
{
}

// Parameterized Constructor
AForm::AForm(const std::string& name, int gradeToSign, int gradeToExecute) : _name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw GradeTooHighException();
	if (gradeToSign > 150 || gradeToExecute > 150)
		throw GradeTooLowException();
}

// Copy Constructor
AForm::AForm(const AForm& other) : _name(other.getName()), _gradeToSign(other.getGradeToSign()), _gradeToExecute(other.getGradeToExecute())
{
}

// Copy assignment operator
AForm& AForm::operator=(const AForm& other)
{
	if ( this != &other )
		*this = other;
	return (*this);
}

// Destructor
AForm::~AForm()
{
}

// Getters
std::string AForm::getName() const
{
	return (_name);
}

bool AForm::getIsSigned() const
{
	return (_isSigned);
}

int AForm::getGradeToSign() const
{
	return (_gradeToSign);
}

int AForm::getGradeToExecute() const
{
	return (_gradeToExecute);
}


// Exception classes
const char* AForm::GradeTooHighException::what() const throw()
{
	return ("The Grade is too high !!");
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return ("The Grade is too low !!");
}

const char* AForm::AlreadySignedException::what() const throw()
{
	return ("The AForm is already signed !!");
}

const char* AForm::NotSignedException::what() const throw()
{
	return ("The AForm it's not signed !!");
}

// Member functions
void AForm::beSigned(const Bureaucrat& bureaucrat)
{
	if ( bureaucrat.getGrade() > _gradeToSign )
		throw AForm::GradeTooLowException();
	_isSigned = true;
}

// insertion operator overload
std::ostream&   operator<<( std::ostream& os, const AForm& AForm )
{
	os << std::endl;
	os << std::endl;
	os << "------------- AForm Info -------------" << std::endl;
	os << "AForm name: " << AForm.getName() << std::endl
		<< "Grade to sign: " << AForm.getGradeToSign() << std::endl
		<< "Grade to execute: " << AForm.getGradeToExecute();
	return (os);
}
