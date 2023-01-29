#include "Bureaucrat.hpp"

int main () {
	Bureaucrat	bureaucrat;

	bureaucrat.setName("John");
	bureaucrat.setGrade(1);
	std::cout << bureaucrat.getName() << " " << bureaucrat.getGrade() << std::endl;
	bureaucrat.incrementGrade();
	std::cout << bureaucrat.getName() << " " << bureaucrat.getGrade() << std::endl;
	bureaucrat.incrementGrade();
	std::cout << bureaucrat.getName() << " " << bureaucrat.getGrade() << std::endl;
	bureaucrat.setGrade(150);
	std::cout << bureaucrat.getName() << " " << bureaucrat.getGrade() << std::endl;
	bureaucrat.setGrade(0);
	std::cout << bureaucrat.getName() << " " << bureaucrat.getGrade() << std::endl;
	bureaucrat.setGrade(151);
	std::cout << bureaucrat.getName() << " " << bureaucrat.getGrade() << std::endl;
	bureaucrat.setGrade(-1);
	std::cout << bureaucrat.getName() << " " << bureaucrat.getGrade() << std::endl;
	
	return 0;
}
