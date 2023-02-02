#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
// #include "RobotomyRequestForm.hpp"
// #include "PresidentialPardonForm.hpp"

int main () {
	// try {
	// 	Bureaucrat const bureaucrat1("Bureaucrat1", 1);
	// 	ShrubberyCreationForm form1("ShrubberyCreationForm");
	// 	// form1.beSigned(bureaucrat1);
	// 	form1.execute(bureaucrat1);

	// } catch (std::exception &e) {
	// 	std::cout << e.what() << std::endl;
	// }

	try {
		ShrubberyCreationForm form2("ShrubberyCreationForm");
		Bureaucrat bureaucrat2("Bureaucrat2", 1);
		std::cout << bureaucrat2 << std::endl;
		std::cout << form2 << std::endl;
		bureaucrat2.signForm(form2);
		bureaucrat2.executeForm(form2);
		std::cout << form2 << std::endl;

	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	return 0;
}
