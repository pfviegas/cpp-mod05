/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pviegas <pviegas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 10:36:58 by pviegas           #+#    #+#             */
/*   Updated: 2024/04/26 10:37:00 by pviegas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Bureaucrat.hpp"
#include "../include/AForm.hpp"
#include "../include/ShrubberyCreationForm.hpp"
#include "../include/RobotomyRequestForm.hpp"
#include "../include/PresidentialPardonForm.hpp"

int main()
{
	Bureaucrat b1("John", 1);
	Bureaucrat b2("Doe", 150);
	Bureaucrat b3("Elvis", 5);

	ShrubberyCreationForm ShrubForm("Shrubbery");
	RobotomyRequestForm RobotForm("Robotomy");
	PresidentialPardonForm PardonFrom("President");

	try
	{
		std::cout << std::endl;
		std::cout << "---------- Bureaucrat Info ----------" << std::endl;
		std::cout << b1;
		std::cout << b2;
		std::cout << b3;

		std::cout << ShrubForm << std::endl;
		std::cout << RobotForm << std::endl;
		std::cout << PardonFrom << std::endl;

		std::cout << std::endl;

		b1.executeForm(ShrubForm);
		b2.executeForm(RobotForm);
		b3.executeForm(PardonFrom);
		
		std::cout << std::endl;

		b2.signAForm(ShrubForm);
		b3.signAForm(RobotForm);
		b1.signAForm(PardonFrom);

		std::cout << std::endl;
		
		b2.executeForm(ShrubForm);
		b1.executeForm(RobotForm);
		b3.executeForm(PardonFrom);

		std::cout << std::endl;

		b1.signAForm(ShrubForm);
		b3.executeForm(ShrubForm);
	}
	catch(std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl;
	std::cout << std::endl;
 }
