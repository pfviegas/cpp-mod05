// colocar o header 42

#include "../include/Bureaucrat.hpp"

int main()
{
	Bureaucrat b1("John", 1);
	Bureaucrat b2("Doe", 150);

	try
	{
		std::cout << b1 << std::endl;
		b1.decrementGrade();
		std::cout << b1 << std::endl;
		
		std::cout << b2 << std::endl;
		b2.incrementGrade();
		std::cout << b2 << std::endl;
		b2.decrementGrade();
		std::cout << b2 << std::endl;
		b2.decrementGrade();
		// the following code it's not executed because an exception was catch
		b1.incrementGrade();
		b1.incrementGrade();
		b1.incrementGrade();
		b1.incrementGrade();
		std::cout << b1 << std::endl;
	}
	catch(std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl;
	
	try
	{
		Bureaucrat b3("Alice", 0);
	}
	catch(std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		Bureaucrat b3("Bob", 151);
	}
	catch(std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	return (0);
 }
