#include "ShrubberyCreationForm.hpp"

std::string	ShrubberyCreationForm::getTarget() const {
	return this->target;
}

ShrubberyCreationForm::ShrubberyCreationForm() : Form("ShrubberyCreationForm", 145, 137) {
	std::cout << "ShrubberyCreationForm default constructor" << std::endl;
	this->target = "default";
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : Form("ShrubberyCreationForm", 145, 137), target(target) {
	std::cout << "ShrubberyCreationForm parameterized constructor" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &form) : Form("ShrubberyCreationForm", 145, 137) {
	std::cout << "ShrubberyCreationForm copy constructor" << std::endl;
	*this = form;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator = (const ShrubberyCreationForm &form) {
	std::cout << "ShrubberyCreationForm copy assignment operator" << std::endl;
	if (this != &form)
		this->target = form.getTarget();
	this->Form::operator=(form);
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
	std::cout << "ShrubberyCreationForm destructor" << std::endl;
}

void ShrubberyCreationForm::execute(const Bureaucrat &executor) const {
	if (this->getSigned() == false) {
		throw Form::IsNotSignedException();
	}
	if (this->getGradeToExecute() < executor.getGrade() || this->getGradeToSign() < executor.getGrade()) {
		throw Form::GradeTooLowException();
	}
	std::fstream file;
	file.open(this->target + "_shrubbery", std::fstream::out);
	if (!file.is_open()) {
		throw std::fstream::failure("Can't open file" + this->target + "_shrubbery");
	}
	file << ASCII_TREE;
	file.close();
}
