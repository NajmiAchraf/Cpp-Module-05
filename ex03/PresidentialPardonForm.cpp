#include "PresidentialPardonForm.hpp"

std::string	PresidentialPardonForm::getTarget() const {
	return this->target;
}

PresidentialPardonForm::PresidentialPardonForm() : Form("PresidentialPardonForm", 145, 137) {
	std::cout << "PresidentialPardonForm default constructor" << std::endl;
	this->target = "default";
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : Form("PresidentialPardonForm", 145, 137), target(target) {
	std::cout << "PresidentialPardonForm parameterized constructor" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &form) : Form("PresidentialPardonForm", 145, 137) {
	std::cout << "PresidentialPardonForm copy constructor" << std::endl;
	*this = form;
}

PresidentialPardonForm &PresidentialPardonForm::operator = (const PresidentialPardonForm &form) {
	std::cout << "PresidentialPardonForm copy assignment operator" << std::endl;
	if (this != &form)
		this->target = form.getTarget();
	this->Form::operator=(form);
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm() {
	std::cout << "PresidentialPardonForm destructor" << std::endl;
}

void PresidentialPardonForm::execute(const Bureaucrat &executor) const {
	if (this->getSigned() == false) {
		throw Form::IsNotSignedException();
	}
	if (this->getGradeToExecute() < executor.getGrade() || this->getGradeToSign() < executor.getGrade()) {
		throw Form::GradeTooLowException();
	}
	std::cout << this->getTarget() << " has been pardoned by Zafod Beeblebrox." << std::endl;
}
