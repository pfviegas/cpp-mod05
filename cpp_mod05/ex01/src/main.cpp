// colocar o header 42

#include "../include/Bureaucrat.hpp"
#include "../include/Form.hpp"

int main()
{
	Bureaucrat b1("John", 1);
	Bureaucrat b2("Doe", 150);

	try
	{
		std::cout << b1 << std::endl;
		std::cout << b2 << std::endl;

		Form form1("House Rental", 20, 10);
		std::cout << form1 << std::endl;
		std::cout << std::endl;
		b1.executeForm(form1);
		
		std::cout << std::endl;

		b1.signForm(form1);
		b2.signForm(form1);
		
		std::cout << std::endl;

		b1.executeForm(form1);
		std::cout << std::endl;
		std::cout << std::endl;



		Form form2("House Bying", 10, 1);
		std::cout << form2 << std::endl;
		b1.signForm(form2);
		b2.signForm(form2);
		std::cout << form2 << std::endl;
		std::cout << form1 << std::endl;
	}
	catch(std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl;
	std::cout << std::endl;
	
	try
	{
		Form("Test 1", 0, 0);
	} catch(std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		Form("Test 2", 151, 151);
	} catch(std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	return (0);
 }
