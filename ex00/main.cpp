#include "Bureaucrat.hpp"

int main () {
	Bureaucrat	bureaucrat;

	try {
		bureaucrat.setName("John");
		std::cout << bureaucrat << std::endl << std::endl;
		bureaucrat.setGrade(1);
		std::cout << bureaucrat << std::endl << std::endl;
		bureaucrat.upGrade();
		std::cout << bureaucrat << std::endl << std::endl;
		bureaucrat.upGrade();
		std::cout << bureaucrat << std::endl << std::endl;
		bureaucrat.setGrade(94);
		std::cout << bureaucrat << std::endl << std::endl;
		bureaucrat.setGrade(0);
		std::cout << bureaucrat << std::endl << std::endl;
		bureaucrat.setGrade(151);
		std::cout << bureaucrat << std::endl << std::endl;
		bureaucrat.setGrade(-1);
		std::cout << bureaucrat << std::endl << std::endl;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	return 0;
}
