#include "Intern.hpp"

Intern::Intern() {
	std::cout << "Intern default constructor" << std::endl;
	ft_make_form[0] = &Intern::makeShrubberyCreationForm;
	ft_make_form[1] = &Intern::makeRobotomyRequestForm;
	ft_make_form[2] = &Intern::makePresidentialPardonForm;
}

Intern::Intern(const Intern &intern) {
	std::cout << "Intern copy constructor" << std::endl;
	ft_make_form[0] = &Intern::makeShrubberyCreationForm;
	ft_make_form[1] = &Intern::makeRobotomyRequestForm;
	ft_make_form[2] = &Intern::makePresidentialPardonForm;
	*this = intern;
}

Intern &Intern::operator = (const Intern &intern) {
	std::cout << "Intern copy assignment operator" << std::endl;
	if (this != &intern)
		return *this;
	return *this;
}

Intern::~Intern() {
	std::cout << "Intern destructor" << std::endl;
}

Form *Intern::makeForm(std::string FormName, std::string target) {
	std::string	forms[] = {"ShrubberyCreationForm", "RobotomyRequestForm", "PresidentialPardonForm"};

	for (int i = 0; i < 3; i++) {
		if (forms[i] == FormName) {
			return (this->*ft_make_form[i])(target);
		}
	}
	throw Intern::FormNotFoundException();
	return NULL;
}

Form *Intern::makeShrubberyCreationForm(std::string target) {
	return new ShrubberyCreationForm(target);
}

Form *Intern::makeRobotomyRequestForm(std::string target) {
	return new RobotomyRequestForm(target);
}

Form *Intern::makePresidentialPardonForm(std::string target) {
	return new PresidentialPardonForm(target);
}
