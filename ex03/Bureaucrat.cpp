#include "Bureaucrat.hpp"
#include "Form.hpp"

std::string	Bureaucrat::getName() const {
	return this->name;
}

int Bureaucrat::getGrade() const {
	return this->grade;
}

void Bureaucrat::setGrade(int grade) {
	this->checkGrade(grade);
	this->grade = grade;
}

Bureaucrat::Bureaucrat() : name("default"), grade(150) {
	std::cout << "Bureaucrat default constructor" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : name(name) {
	std::cout << "Bureaucrat parameterized constructor" << std::endl;
	this->checkGrade(grade);
	this->grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &bureaucrat) : name(bureaucrat.getName()) {
	std::cout << "Bureaucrat copy constructor" << std::endl;
	*this = bureaucrat;
}

Bureaucrat &Bureaucrat::operator = (const Bureaucrat &bureaucrat) {
	std::cout << "Bureaucrat copy assignment operator" << std::endl;
	if (this != &bureaucrat)
		this->grade = bureaucrat.getGrade();
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

void Bureaucrat::signForm(Form &form) {
	try {
		form.beSigned(*this);
		std::cout << this->name << " signed " << form.getName() << "." << std::endl;
	}
	catch (const std::exception &e) {
		std::cout << *this << " cannot sign " << form.getName() << " because " << e.what() << std::endl;
	}
}

void Bureaucrat::executeForm(const Form &form) {
	try {
		form.execute(*this);
		std::cout << this->name << " executed " << form.getName() << "." << std::endl;
	}
	catch (const std::exception &e) {
		std::cout << *this << " cannot execute " << form.getName() << " because " << e.what() << std::endl;
	}
}

std::ostream &operator << (std::ostream &out, const Bureaucrat &bureaucrat) {
	out << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << ".";
	return out;
}
