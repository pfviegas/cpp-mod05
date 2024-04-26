/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pviegas <pviegas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 11:20:43 by pviegas           #+#    #+#             */
/*   Updated: 2024/04/26 13:56:11 by pviegas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern
{
	public:
		Intern();
		Intern(const Intern& other);
		~Intern();

		Intern& operator=(const Intern& other);

		AForm* makeForm(const std::string& formName, const std::string& target) const;
		
	private:
		AForm* newShrubbery(const std::string& target) const;
		AForm* newRobotomy(const std::string& target) const;
		AForm* newPresidential(const std::string& target) const;
};

#endif