#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main () {
	try {
		Form *form1;
		Bureaucrat bureaucrat1("Bureaucrat1", 140); // sign 145, exec 137
		form1 = Intern().makeForm("ShrubberyCreationForm", "ShrubberyCreationForm");
		std::cout << bureaucrat1 << std::endl;
		std::cout << *form1 << std::endl;
		bureaucrat1.signForm(*form1);
		bureaucrat1.executeForm(*form1);
		std::cout << *form1 << std::endl;

	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	try {
		Form *form2;
		Bureaucrat bureaucrat2("Bureaucrat2", 40); // sign 72, exec 45
		form2 = Intern().makeForm("RobotomyRequestForm", "RobotomyRequestForm");
		std::cout << bureaucrat2 << std::endl;
		std::cout << *form2 << std::endl;
		bureaucrat2.signForm(*form2);
		bureaucrat2.executeForm(*form2);
		std::cout << *form2 << std::endl;

	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	try {
		Form *form3;
		Bureaucrat bureaucrat3("Bureaucrat3", 20); // sign 25, exec 5
		form3 = Intern().makeForm("PresidentialPardonForm", "PresidentialPardonForm");
		std::cout << bureaucrat3 << std::endl;
		std::cout << *form3 << std::endl;
		bureaucrat3.signForm(*form3);
		bureaucrat3.executeForm(*form3);
		std::cout << *form3 << std::endl;

	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	return 0;
}
