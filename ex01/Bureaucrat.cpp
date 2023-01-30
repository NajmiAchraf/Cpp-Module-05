#include "Bureaucrat.hpp"

std::string	Bureaucrat::getName() const {
	return this->name;
}

void Bureaucrat::setName(std::string name) {
	this->name = name;
}

int Bureaucrat::getGrade() const {
	return this->grade;
}

void Bureaucrat::setGrade(int grade) {
	this->checkGrade(grade);
	this->grade = grade;
}

Bureaucrat::Bureaucrat() {
	std::cout << "Bureaucrat default constructor" << std::endl;
	this->name = "default";
	this->grade = 150;
}

Bureaucrat::Bureaucrat(std::string name, int grade){
	std::cout << "Bureaucrat parameterized constructor" << std::endl;
	this->checkGrade(grade);
	this->name = name;
	this->grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &src) {
	std::cout << "Bureaucrat copy constructor" << std::endl;
	*this = src;
}

Bureaucrat &Bureaucrat::operator = (const Bureaucrat &bureaucrat) {
	std::cout << "Bureaucrat copy assignment operator" << std::endl;
	if (this != &bureaucrat) {
		this->name = bureaucrat.name;
		this->grade = bureaucrat.grade;
	}
	return *this;
}

Bureaucrat::~Bureaucrat() {
	std::cout << "Bureaucrat destructor" << std::endl;
}

void Bureaucrat::upGrade() {
	this->checkGrade(this->grade - 1);
	this->grade--;
}

void Bureaucrat::downGrade() {
	this->checkGrade(this->grade + 1);
	this->grade++;
}

void Bureaucrat::checkGrade(int grade) {
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
}

std::ostream &operator << (std::ostream &out, const Bureaucrat &bureaucrat) {
	out << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << ".";
	return out;
}
