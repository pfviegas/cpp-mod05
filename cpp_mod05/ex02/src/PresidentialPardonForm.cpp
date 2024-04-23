// colocar o header 42

#include "../include/PresidentialPardonForm.hpp"

// Default Constructor
PresidentialPardonForm::PresidentialPardonForm(const std::string& target) : AForm("Presidential Pardon Form", 25, 5), _target(target)
{
}

// Parameterized Constructor
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& target) : AForm(target), _target(target._target)
{
}

// Copy assignment operator
PresidentialPardonForm& PresidentialPardonForm::operator=(PresidentialPardonForm& other)
{
	if ( this != &other )
		*this = other;
	return (*this);
}

// Destructor
PresidentialPardonForm::~PresidentialPardonForm()
{
}

// Member functions
void PresidentialPardonForm::execute(const Bureaucrat& executor) const
{
	if ( executor.getGrade() > this->getGradeToExecute() )
		throw AForm::GradeTooLowException();
	else
		std::cout << "Informs that " << this->_target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}