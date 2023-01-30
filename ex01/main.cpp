#include "Bureaucrat.hpp"

int main () {
	Bureaucrat	bureaucrat;

	bureaucrat.setName("John");
	std::cout << bureaucrat << std::endl << std::endl;
	bureaucrat.setGrade(1);
	std::cout << bureaucrat << std::endl << std::endl;
	bureaucrat.incrementGrade();
	std::cout << bureaucrat << std::endl << std::endl;
	bureaucrat.incrementGrade();
	std::cout << bureaucrat << std::endl << std::endl;
	bureaucrat.setGrade(94);
	std::cout << bureaucrat << std::endl << std::endl;
	bureaucrat.setGrade(0);
	std::cout << bureaucrat << std::endl << std::endl;
	bureaucrat.setGrade(151);
	std::cout << bureaucrat << std::endl << std::endl;
	bureaucrat.setGrade(-1);
	std::cout << bureaucrat << std::endl << std::endl;
	
	return 0;
}
