// colocar o header 42

#include "../include/Intern.hpp"
#include "../include/RobotomyRequestForm.hpp"
#include "../include/ShrubberyCreationForm.hpp"
#include "../include/PresidentialPardonForm.hpp"

// Default Constructor
Intern::Intern()
{
}

// Parameterized Constructor

// Copy Constructor
Intern::Intern(const Intern& other)
{
  *this = other;
}

// Copy assignment operator
Intern& Intern::operator=(const Intern& other)
{
	if ( this != &other )
		*this = other;
	return (*this);
}

// Destructor
Intern::~Intern()
{
}

// Getters

// Exception classes

// Member functions
AForm* Intern::makeForm(const std::string& formName, const std::string& target) const
{
	std::string formNames[] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	for (int i = 0; i < 3; ++i)
	{
		if (formName == formNames[i])
		{
			switch (i)
			{
				case 0:
					std::cout << "Intern creates " << formName << std::endl;
					return (new ShrubberyCreationForm(target));
				case 1:
					std::cout << "Intern creates " << formName << std::endl;
					return (new RobotomyRequestForm(target));
				case 2:
					std::cout << "Intern creates " << formName << std::endl;
					return (new PresidentialPardonForm(target));
			}
		}
	}
	std::cout << "Intern cannot create " << formName << " form" << std::endl;
	return (NULL);
}

// insertion operator overload
