#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
// #include "RobotomyRequestForm.hpp"
// #include "PresidentialPardonForm.hpp"

int main () {
	try {
		Bureaucrat const bureaucrat("Bureaucrat", 1);
		ShrubberyCreationForm form("ShrubberyCreationForm");
		form.beSigned(bureaucrat);
		form.execute(bureaucrat);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	return 0;
}
