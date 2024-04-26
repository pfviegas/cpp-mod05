/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pviegas <pviegas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 11:20:29 by pviegas           #+#    #+#             */
/*   Updated: 2024/04/26 11:30:18 by pviegas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AForm_HPP
#define AForm_HPP

#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	public:
		AForm();
		AForm(const std::string& name, int gradeToSign, int gradeToExecute);
		AForm(const AForm& other);
		virtual ~AForm();

		AForm& operator=(const AForm& other);

		std::string getName() const;
		bool getIsSigned() const;
		int getGradeToSign() const;
		int getGradeToExecute() const;

		void beSigned(const Bureaucrat& bureaucrat);
		virtual void beExecuted(const Bureaucrat& bureaucrat) const = 0;

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

std::ostream&   operator<<( std::ostream& o, const AForm& rhs );

#endif