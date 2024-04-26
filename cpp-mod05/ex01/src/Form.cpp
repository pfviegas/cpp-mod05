/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pviegas <pviegas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 10:33:28 by pviegas           #+#    #+#             */
/*   Updated: 2024/04/26 10:33:30 by pviegas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Form.hpp"

// Default Constructor
Form::Form() : _name(""), _isSigned(false), _gradeToSign(0), _gradeToExecute(0)
{
}

// Parameterized Constructor
Form::Form(const std::string& name, int gradeToSign, int gradeToExecute) : _name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw GradeTooHighException();
	if (gradeToSign > 150 || gradeToExecute > 150)
		throw GradeTooLowException();
}

// Copy Constructor
Form::Form(const Form& other) : _name(other.getName()), _gradeToSign(other.getGradeToSign()), _gradeToExecute(other.getGradeToExecute())
{
}

// Copy assignment operator
Form& Form::operator=(const Form& other)
{
	if ( this != &other )
		*this = other;
	return (*this);
}

// Destructor
Form::~Form()
{
}

// Getters
std::string Form::getName() const
{
	return (_name);
}

bool Form::getIsSigned() const
{
	return (_isSigned);
}

int Form::getGradeToSign() const
{
	return (_gradeToSign);
}

int Form::getGradeToExecute() const
{
	return (_gradeToExecute);
}


// Exception classes
const char* Form::GradeTooHighException::what() const throw()
{
	return ("the Grade is too high !!");
}

const char* Form::GradeTooLowException::what() const throw()
{
	return ("the Grade is too low !!");
}

const char* Form::AlreadySignedException::what() const throw()
{
	return ("the Form is already signed !!");
}

const char* Form::NotSignedException::what() const throw()
{
	return ("the Form it's not signed !!");
}

// Member functions
void Form::beSigned(const Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() > _gradeToSign)
		throw Form::GradeTooLowException();
	_isSigned = true;
}

void Form::beExecuted(const Bureaucrat& bureaucrat) const
{
	if (bureaucrat.getGrade() > _gradeToExecute)
		throw Form::GradeTooLowException();
	if (!_isSigned)
		throw Form::NotSignedException();
}

// insertion operator overload
std::ostream& operator<<(std::ostream& os, const Form& form)
{
	os << std::endl;
	os << std::endl;
	os << "------------- Form Info -------------" << std::endl;
	os << "        Form name: " << form.getName() << std::endl
		<< "   Grade to sign: " << form.getGradeToSign() << std::endl
		<< "Grade to execute: " << form.getGradeToExecute() << std::endl
		<< "       Is Signed: " << form.getIsSigned() << std::endl;
	return (os);
}
