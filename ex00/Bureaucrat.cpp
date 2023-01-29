#include "Bureaucrat.hpp"

std::string	Bureaucrat::getName() const {
	return name;
}

void Bureaucrat::setName(std::string name) {
	this->name = name;
}

int Bureaucrat::getGrade() const {
	return grade;
}

void Bureaucrat::setGrade(int grade) {
	try {
		if (grade < 1)
			throw GradeTooHighException();
		else if (grade > 150)
			throw GradeTooLowException();
		else
			this->grade = grade;
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
}

void Bureaucrat::incrementGrade() {
	try {
		if (this->grade - 1 < 1)
			throw GradeTooHighException();
		else
			this->grade--;
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
}

Bureaucrat::Bureaucrat() {
	std::cout << "Bureaucrat default constructor" << std::endl;
	name = "default";
	grade = 150;
}

Bureaucrat::Bureaucrat(const Bureaucrat &src) {
	std::cout << "Bureaucrat copy constructor" << std::endl;
	*this = src;
}

Bureaucrat &Bureaucrat::operator = (const Bureaucrat &bureaucrat) {
	std::cout << "Bureaucrat copy assignment operator" << std::endl;
	if (this != &bureaucrat) {
		name = bureaucrat.name;
		grade = bureaucrat.grade;
	}
	return *this;
}

Bureaucrat::~Bureaucrat() {
	std::cout << "Bureaucrat destructor" << std::endl;
}

std::exception Bureaucrat::GradeTooHighException() {
	std::cout << "Grade too high" << std::endl;
	return std::exception();
}

std::exception Bureaucrat::GradeTooLowException() {
	std::cout << "Grade too low" << std::endl;
	return std::exception();
}
