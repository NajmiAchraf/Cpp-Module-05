#include "Bureaucrat.hpp"
#include "Form.hpp"

int main () {
	try {
		Bureaucrat bureaucrat("bureaucrat1", 10);
		Form form("form1", 9, 1);
		form.beSigned(bureaucrat);
		bureaucrat.signForm(form);
	}
	catch(const std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	try {
		Bureaucrat bureaucrat("bureaucrat2", 10);
		Form form("form2", 10, 1);
		form.beSigned(bureaucrat);
		bureaucrat.signForm(form);
	}
	catch(const std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	return 0;
}
