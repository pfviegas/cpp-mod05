/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pviegas <pviegas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 10:37:15 by pviegas           #+#    #+#             */
/*   Updated: 2024/04/26 10:50:39 by pviegas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ShrubberyCreationForm.hpp"

// Default Constructor
ShrubberyCreationForm::ShrubberyCreationForm()
{
}

// Parameterized Constructor
ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target) : AForm("Shrubbery Creation Form", 145, 137), _target( target)
{
}

// Copy Constructor
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& target) : AForm(target), _target(target._target)
{
}

// Copy assignment operator
ShrubberyCreationForm& ShrubberyCreationForm::operator=(ShrubberyCreationForm& other)
{
	if (this != &other)
		*this = other;
	return (*this);
}

// Destructor
ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

// Member functions
void ShrubberyCreationForm::execute(const Bureaucrat& executor) const
{
	if (this->getIsSigned() == false)
		throw AForm::NotSignedException();
	else if (executor.getGrade() > this->getGradeToExecute())
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