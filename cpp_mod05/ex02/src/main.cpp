// colocar o header 42

#include "../include/Bureaucrat.hpp"
#include "../include/AForm.hpp"
#include "../include/ShrubberyCreationForm.hpp"
#include "../include/RobotomyRequestForm.hpp"
#include "../include/PresidentialPardonForm.hpp"

int main()
{
	Bureaucrat b1("John", 1);
	Bureaucrat b2("Doe", 150);

	try
	{
		std::cout << std::endl;
		std::cout << "---------- Bureaucrat Info ----------" << std::endl;
		std::cout << b1;
		std::cout << b2;

		AForm Form1("House Rental", 20, 10);
		std::cout << Form1 << std::endl;
		std::cout << std::endl;
		b1.executeForm(Form1);
		
		std::cout << std::endl;

		b1.signAForm(Form1);
		b2.signAForm(Form1);
		
		std::cout << std::endl;

		b1.executeForm(Form1);
		std::cout << std::endl;

		AForm Form2("House Bying", 10, 1);
		std::cout << Form2 << std::endl;
		std::cout << std::endl;
		b1.signAForm(Form2);
		std::cout << std::endl;
		b2.executeForm(Form2);
		std::cout << Form2 << std::endl;
		std::cout << Form1 << std::endl;
	}
	catch(std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl;
	std::cout << std::endl;
	
	try
	{
		AForm("Test 1", 0, 0);
	}
	catch(std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		AForm("Test 2", 151, 151);
	}
	catch(std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	return (0);
 }
