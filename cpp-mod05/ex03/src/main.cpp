/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pviegas <pviegas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 11:21:22 by pviegas           #+#    #+#             */
/*   Updated: 2024/04/26 14:01:18 by pviegas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/AForm.hpp"
#include "../include/Bureaucrat.hpp"
#include "../include/ShrubberyCreationForm.hpp"
#include "../include/RobotomyRequestForm.hpp"
#include "../include/PresidentialPardonForm.hpp"
#include "../include/Intern.hpp"

int main( void )
{
	{
		Intern someRandomIntern;
		AForm* rrf;


		rrf = someRandomIntern.makeForm("shrubbery creation", "Bender");
		delete rrf;
		rrf = someRandomIntern.makeForm("robotomy request", "Bender");
		delete rrf;
		rrf = someRandomIntern.makeForm("presidential pardon", "Bender");
		delete rrf;
		std::cout << std::endl;
		rrf = someRandomIntern.makeForm("robotomy", "Bender");
		delete rrf;
	}

	Bureaucrat bureau1("John", 1);
	Bureaucrat bureau2("Doe", 50);
	Intern intern;

	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "---------- Bureaucrat Info ----------" << std::endl;
	std::cout << bureau1;
	std::cout << bureau2;
	std::cout << std::endl;

	try
	{
		std::cout << std::endl << "--------------- Form 1 ( shrubbery creation ) ---------------" << std::endl;
		AForm* shrubbery = intern.makeForm("shrubbery creation", "home");
		ShrubberyCreationForm* form1 = dynamic_cast<ShrubberyCreationForm*>(shrubbery);
		if (form1 != NULL)
		{
			std::cout << " Form Name: " << form1->getName() << std::endl;  // Exibe _target
			std::cout << "    Target: " << form1->getTarget() << std::endl;  // Exibe _target
			std::cout << " Is Signed: " << form1->getIsSigned() << std::endl;  // Exibe _target
			std::cout << "Grade Exec: " << form1->getGradeToSign() << std::endl;  // Exibe _target
			std::cout << "Grade Exec: " << form1->getGradeToExecute() << std::endl;  // Exibe _target
			std::cout << std::endl;
			bureau1.signAForm(*form1);
			bureau2.executeAForm(*form1);
			std::cout << std::endl << " Is Signed: " << form1->getIsSigned() << std::endl;  // Exibe _target
			delete form1;
		}

		std::cout << std::endl << "--------------- Form 2 ( robotomy request ) ---------------" << std::endl;
		AForm* robotomy = intern.makeForm("robotomy request", "office");
		RobotomyRequestForm* form2 = dynamic_cast<RobotomyRequestForm*>(robotomy);
		if (form2 != NULL)
		{
			std::cout << " Form Name: " << form2->getName() << std::endl;  // Exibe _target
			std::cout << "    Target: " << form2->getTarget() << std::endl;  // Exibe _target
			std::cout << " Is Signed: " << form2->getIsSigned() << std::endl;  // Exibe _target
			std::cout << "Grade Exec: " << form2->getGradeToSign() << std::endl;  // Exibe _target
			std::cout << "Grade Exec: " << form2->getGradeToExecute() << std::endl;  // Exibe _target
			std::cout << std::endl;
			bureau1.signAForm(*form2);
			bureau2.executeAForm(*form2);
			std::cout << std::endl << " Is Signed: " << form2->getIsSigned() << std::endl;  // Exibe _target
			delete form2;
		}

		std::cout << std::endl << "--------------- Form 3 ( presidential pardon ) ---------------" << std::endl;
		AForm* presidential = intern.makeForm("presidential pardon", "palace");
		PresidentialPardonForm* form3 = dynamic_cast<PresidentialPardonForm*>(presidential);
		if (form3 != NULL)
		{
			std::cout << " Form Name: " << form3->getName() << std::endl;  // Exibe _target
			std::cout << "    Target: " << form3->getTarget() << std::endl;  // Exibe _target
			std::cout << " Is Signed: " << form3->getIsSigned() << std::endl;  // Exibe _target
			std::cout << "Grade Exec: " << form3->getGradeToSign() << std::endl;  // Exibe _target
			std::cout << "Grade Exec: " << form3->getGradeToExecute() << std::endl;  // Exibe _target
			std::cout << std::endl;
			bureau1.signAForm(*form3);
			bureau2.executeAForm(*form3);
			std::cout << std::endl << " Is Signed: " << form3->getIsSigned() << std::endl;  // Exibe _target
			delete form3;
		}

		std::cout << std::endl << "---------------------- Not Found Form  -----------------------" << std::endl;
		AForm* test = intern.makeForm("test", "test");
		delete test;

	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	return (0);
}
