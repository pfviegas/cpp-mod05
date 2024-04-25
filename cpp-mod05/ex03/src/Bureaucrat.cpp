// colocar o header 42

#include "../include/Bureaucrat.hpp"
#include "../include/AForm.hpp"

// Default Constructor
Bureaucrat::Bureaucrat() : _name(""), _grade(1) {}

// Parameterized Constructor
Bureaucrat::Bureaucrat(const std::string& name, int grade) : _name(name), _grade(grade)
{
	if (this->_grade < Bureaucrat::MAX_GRADE)
		throw Bureaucrat::GradeTooHighException();
	else if (this->_grade > Bureaucrat::MIN_GRADE)
		throw Bureaucrat::GradeTooLowException();
}

// Copy Constructor
Bureaucrat::Bureaucrat(const Bureaucrat& other) : _name(other._name), _grade(other._grade)
{
}

// Copy assignment operator
Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
	if ( this != &other )
		_grade = other.getGrade();
	return (*this);
}

// Destructor
Bureaucrat::~Bureaucrat()
{
}

// Getters
const std::string& Bureaucrat::getName() const
{
	return (this->_name);
}

int Bureaucrat::getGrade() const
{
	return (this->_grade);
}

// Member functions
void Bureaucrat::incrementGrade()
{
	if ( _grade - 1 < MAX_GRADE )
		throw Bureaucrat::GradeTooHighException();
	_grade--;
}

void    Bureaucrat::decrementGrade()
{
	if ( _grade + 1 > MIN_GRADE )
		throw Bureaucrat::GradeTooLowException();
	_grade++;
}

void Bureaucrat::signAForm(AForm& AForm)
{
	try
	{
		AForm.beSigned(*this);
		std::cout << this->_name << " signed " << AForm.getName() << " form." << std::endl;
	}
	catch (AForm::GradeTooLowException &e)
	{
		std::cout << this->_name << " coulnd't sign " << AForm.getName() << " because " << e.what() << std::endl;
	}
}

void Bureaucrat::executeAForm(const AForm& AForm)
{
	try
	{
		AForm.beExecuted(*this);
		std::cout << this->getName() << " executed " << AForm.getName() << " form." << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << this->getName() << " couldn't execute " << AForm.getName() << " form because " << e.what() << std::endl;
	}
}

// Exception Member functions
const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("the Grade is too high !!");
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("the Grade is too low !!");
}

// insertion operator overload
std::ostream& operator<<(std::ostream& os, const Bureaucrat& value)
{
	os << value.getName() << ", bureaucrat with grade " << value.getGrade() << std::endl;
	return (os);
}