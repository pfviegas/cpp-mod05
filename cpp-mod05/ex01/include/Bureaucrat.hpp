// colocar o header 42

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <iostream>
#include <exception>
#include <sstream>

#include "Form.hpp"

class Form;

class Bureaucrat
{
	public:
		Bureaucrat();
  		Bureaucrat(const std::string& name, int grade);
		Bureaucrat(const Bureaucrat& other);
		~Bureaucrat();
		
		Bureaucrat& operator=(const Bureaucrat& other);

		const std::string& getName() const;
		int getGrade() const;

		static const int MAX_GRADE = 1;
		static const int MIN_GRADE = 150;

		void incrementGrade();
		void decrementGrade();
		void signForm( Form& form);
		void executeForm(const Form& form);

		// Exception Classes
		class GradeTooHighException : public std::exception
		{
			public:
				const char* what() const throw();
		};

		class GradeTooLowException : public std::exception
		{
			public:
				const char* what() const throw();
		};

	private:
		const std::string _name;
		int _grade;
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& value);

#endif