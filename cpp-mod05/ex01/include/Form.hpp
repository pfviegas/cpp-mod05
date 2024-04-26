/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pviegas <pviegas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 10:33:11 by pviegas           #+#    #+#             */
/*   Updated: 2024/04/26 10:33:13 by pviegas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{

	public:
		Form();
		Form(const std::string& name, int gradeToSign, int gradeToExecute);
		Form(const Form& other);
		~Form();

		Form& operator=(const Form& other);

		std::string getName() const;
		bool getIsSigned() const;
		int getGradeToSign() const;
		int getGradeToExecute() const;

		void beSigned(const Bureaucrat& bureaucrat);
		void beExecuted(const Bureaucrat& bureaucrat) const;

		// Exception Classes
		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		 };
		class AlreadySignedException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
		class NotSignedException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

	private:
		const std::string _name;
		bool _isSigned;
		const int _gradeToSign;
		const int _gradeToExecute;

};

std::ostream& operator<<(std::ostream& os, const Form& form);

#endif