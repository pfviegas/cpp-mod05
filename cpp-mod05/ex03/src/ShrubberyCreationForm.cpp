// colocar o header 42

#include "../include/ShrubberyCreationForm.hpp"

// Default Constructor
ShrubberyCreationForm::ShrubberyCreationForm() : AForm("shrubbery creation", 145, 137), _target("")
{
}

// Parameterized Constructor
ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target) : AForm("shrubbery creation", 145, 137), _target(target)
{
}

// Copy Constructor
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& target) : AForm(target), _target(target._target)
{
}

// Copy assignment operator
ShrubberyCreationForm& ShrubberyCreationForm::operator=(ShrubberyCreationForm& other)
{
	if ( this != &other )
		*this = other;
	return (*this);
}

// Destructor
ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

// Getters
std::string ShrubberyCreationForm::getTarget() const
{
	return (_target);
}

// Member functions
void ShrubberyCreationForm::beExecuted(const Bureaucrat& executor) const
{
	if ( this->getIsSigned() == false )
		throw AForm::NotSignedException();
	else if ( executor.getGrade() > this->getGradeToExecute() )
		throw AForm::GradeTooLowException();

	std::ofstream file((this->_target + "_shrubbery" ).c_str());

	file << "                                                                                                                                                                                           " << std::endl;
	file << "                                                     .:--:::-:                                                                                                                             " << std::endl;
	file << "                                        :.::-:      .+**+*+*++=:                                                                                                                           " << std::endl;
	file << "                                  :=+*+++******+--=++**++++*++++++=:                                                                                                                       " << std::endl;
	file << "                                -++*+*+*****+++***+++++*#*++*##*##*++-:-:                                                                                                                  " << std::endl;
	file << "                            .:.:+*****####**+*#%%%#*+++++*##**#%%####**++:                                                                        --==--=-                                 " << std::endl;
	file << "                         .:=***##**###%%%***#####%##%%%%#****++**#%%####**=:                                                       :-:--==*+-.  :-+**++***+-.                              " << std::endl;
	file << "                        :******+++*%%%@%***#%%%###%%%%%%%%#***+++#%%*#**#**-                                                    .=+*#++*#**=+=++++*****+*+****+=:                          " << std::endl;
	file << "                     :+*#***##*+*#*#%#####%%%%##%%######%%%%%#%##*##%%%%%##*=                                                  .+****#####+*#%%#*++++*####%%#%#***+-                       " << std::endl;
	file << "                     -**####%####%%######%%%%#****####%%#######*+*##*%%%###*=                                             .:+*+#**####%##*####%###%%#****++**%%###**+:                     " << std::endl;
	file << "                     :*#%%%%%%%%%%%%%##%%%%%@##%##**+#%%%#*#*##%%#**#**+**#*+-                                          .-**#**++*#%%@#**##%%##%%%%%%%%#**++*#%*#**#*=                     " << std::endl;
	file << "                    .-*###%%###%%%%%%%%%%%%**##%%%%%%%%%##%+#%%%#*+*####*##*#*+:                                      .*##**##*+#####*#%#%%%%#%####%%%%%%#%####%%%%%##=                    " << std::endl;
	file << "                  :=+==+*##*#####%%#*######%%%%%%%%%%%##%%%%%%%**%%##%#####%#**+-.                                    :+##%%%#%%%%%%####%%%#**####%%%####*#***#*%%%##*+                    " << std::endl;
	file << "                 :+*+**##%#%%####%%##**####%%%%%%%%%%%%#%%%%@###%%%%####*##%%##+-                                     :*#%%%%%%%%%%%%%%%#%#*#####%%@#***##%%##******#*#+:                  " << std::endl;
	file << "                 :+*#%##%%##%%##%%#**##*###%#%%%%#%#####%#%%#%%%%%%%%#####*****#**+=-.                               .-.+*%%*###%@%#***#%%@%%#%%%%%##%%%%%%**#*+#%##%##*+:                 " << std::endl;
	file << "              :-:-++**#%%%%%%%%%%###@@%%%%%%%%#######%%#%%%##%%%%%%%####***+*#**++++:                              -*++*##%#%%###%###*####%%%%%%%#%%%%%%@%##%%%####*#%%%#+.                " << std::endl;
	file << "            =+++*######***#%%%%%%%%%@%%%%%%%%#####%%%%#**#*###%%%#####%%%####%%%%%#***+:                           -*#%##%%#%%##%#**##*##%#%%%%%%#####%%#%%%%%%%####*****#**=-.            " << std::endl;
	file << "           -*#####%%%%##%######*##%%%%%%%%#%%%%#######*##**#*#%%%%%#*###*##*##%%%#*+*#*:                       .:=-++**#%%%%%%%%%##%@%@%%%%%######%%#%%##%%%%%#%###***##**++*..            " << std::endl;
	file << "           .**==*##%%**#%##%%###%%%%%@%#%%%%%%%%**+*+*#%%%%%%%%%%%#*%%%%###*####**+*#%#+:                     =**+*%%%%####%%#%%%%%%%%@%%%%###%##%%***##%#%%%%%%##%%###%%%%###**:          " << std::endl;
	file << "               .*###*+**#%*-:#%#*##*%%%%%%%%*=#***#*##%%%##**#%%*###%@%%####%%%%######+-                      +###*#%%###%%######%%%%%%%%%%%%###***#######%%%%##*%######%%##+*#+:          " << std::endl;
	file << "                :..:+-:.*#=-=+=. =#%#*#%%%#*=.-#%--%%%***+***+:  .-:.-*#**##*##%##**+-                        .. :####**+%##*##*#%%%%%%%%%##%***####%%##*#%%#%%%%%%%%########%%*=          " << std::endl;
	file << "                               .=*#*==:.=-.:*#*#%%%#. =+   .:     .=-=*%%***++=+*##+=:                            -.:=-.:*#*-:=:.+%#=*%%%+:.+%*.*%%###*==#-  ::.=##+*#*#%%###+:            " << std::endl;
	file << "                                    -          +###:.=+            -*+***   :+=.   .                                 .         .=##+=::=:.+#*#%%%:.=+  .:     ---*%#**++++*#+=:            " << std::endl;
	file << "                                                =##*+.              .                                                              :         =##+:==          :***+:  .=-                  " << std::endl;
	file << "                                                -##+                                                                                          +##=                                         " << std::endl;
	file << "                                                :*#+                                                                                          =#*.                                         " << std::endl;
	file << "                                                -*#*.                                                                                         =##.                                         " << std::endl;
	file << "                                                =*##:                                                                                         =*#-                                         " << std::endl;
	file << "                                        .....:-=+++++-:::...                                                                            ...:=+****=:::                                     " << std::endl;

	file.close();
}