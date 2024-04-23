// colocar o header 42

#include "../include/RobotomyRequestForm.hpp"

// Default Constructor
RobotomyRequestForm::RobotomyRequestForm(const std::string& target) : AForm("Robotomy Request Form", 72, 45), _target(target)
{
}

// Parameterized Constructor
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& target) : AForm(target), _target(target._target)
{
}

// Copy assignment operator
RobotomyRequestForm& RobotomyRequestForm::operator=(RobotomyRequestForm& other)
{
	if ( this != &other )
		*this = other;
	return (*this);
}

// Destructor
RobotomyRequestForm::~RobotomyRequestForm()
{
}

// Member functions
void RobotomyRequestForm::execute(const Bureaucrat& executor) const
{
	if ( executor.getGrade() > this->getGradeToExecute() )
		throw AForm::GradeTooLowException();
	else
	{
		static int  i;
		if ( i % 2 == 0 )
		{
			std::cout << "Bzzzzz... " << std::endl;
			std::cout << "Vrrrrr... " << std::endl;
			std::cout << "Whirrr... " << std::endl;
			std::cout << "Trrrrr... " << std::endl;
			std::cout << this->_target << " has been robotomized !!" << std::endl;
		}
		else
			std::cout << this->_target << "'s Robotomy Failed !! "  << std::endl;
		i++;
	}
}