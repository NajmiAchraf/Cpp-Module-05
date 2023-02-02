#ifndef INTERN_HPP
#define INTERN_HPP

#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern {

private:

	Form	*makeShrubberyCreationForm(std::string target);
	Form	*makeRobotomyRequestForm(std::string target);
	Form	*makePresidentialPardonForm(std::string target);

	Form	*(Intern::*ft_make_form[3])(std::string target);

public:

	Intern();
	Intern(const Intern &intern);
	Intern &operator = (const Intern &intern);
	~Intern();

	Form	*makeForm(std::string FormName, std::string target);

	class FormNotFoundException : public std::exception {

	public:

		virtual const char *what() const throw() {
			return "Form not found.";
		}
	};
};

#endif