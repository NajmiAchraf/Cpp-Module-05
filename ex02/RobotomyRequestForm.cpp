#include "RobotomyRequestForm.hpp"

std::string	RobotomyRequestForm::getTarget() const {
	return this->target;
}

RobotomyRequestForm::RobotomyRequestForm() : Form("RobotomyRequestForm", 72, 45) {
	std::cout << "RobotomyRequestForm default constructor" << std::endl;
	this->target = "default";
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : Form("RobotomyRequestForm", 72, 45), target(target) {
	std::cout << "RobotomyRequestForm parameterized constructor" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &form) : Form("RobotomyRequestForm", 72, 45) {
	std::cout << "RobotomyRequestForm copy constructor" << std::endl;
	*this = form;
}

RobotomyRequestForm &RobotomyRequestForm::operator = (const RobotomyRequestForm &form) {
	std::cout << "RobotomyRequestForm copy assignment operator" << std::endl;
	if (this != &form)
		this->target = form.getTarget();
	this->Form::operator=(form);
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {
	std::cout << "RobotomyRequestForm destructor" << std::endl;
}

void RobotomyRequestForm::execute(const Bureaucrat &executor) const {
	if (this->getSigned() == false) {
		throw Form::IsNotSignedException();
	}
	if (this->getGradeToExecute() < executor.getGrade() || this->getGradeToSign() < executor.getGrade()) {
		throw Form::GradeTooLowException();
	}
	srand(time(0)); // Initialize random number generator.
	int random = rand() % 10;
	for (int i = 0; i < random; i++) {
		random = rand() % 10;
	}
	std::cout << "* drilling noises * ";
	if ((random % 2) + 1 == 2) {
		std::cout << this->getTarget() << " has been robotomized successfully" << std::endl;
	} else {
		std::cout << this->getTarget() << " robotomization failed" << std::endl;
	}
}
