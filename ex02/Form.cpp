#include "Form.hpp"

std::string Form::getName() const {
	return this->Name;
}

bool Form::getSigned() const {
	return this->Signed;
}

int Form::getGradeToSign() const {
	return this->gradeToSign;
}

int Form::getGradeToExecute() const {
	return this->gradeToExecute;
}

void Form::setSigned(bool sign) {
	this->Signed = sign;
}

Form::Form() : Name("default"), Signed(true), gradeToSign(1), gradeToExecute(1) {
	std::cout << "Form default constructor" << std::endl;
}

Form::Form(std::string name, int newgradeToSign, int newgradeToExecute) : Name(name), Signed(true), gradeToSign(newgradeToSign), gradeToExecute(newgradeToExecute) {
	std::cout << "Form parameterized constructor" << std::endl;
}

Form::Form(const Form &form) : Name(form.getName()), Signed(form.getSigned()), gradeToSign(form.getGradeToSign()), gradeToExecute(form.getGradeToExecute()) {
	std::cout << "Form copy constructor" << std::endl;
}

Form &Form::operator = (const Form &form) {
	std::cout << "Form copy assignement operator" << std::endl;
	if (this != &form)
		this->Signed = form.getSigned();
	return *this;
}

Form::~Form() {
	std::cout << "Form destructor" << std::endl;
}

void Form::beSigned(const Bureaucrat &bureaucrat) {
	try {
		if (bureaucrat.getGrade() <= this->gradeToSign)
			this->Signed = true;
		else
			throw Form::GradeTooLowException();
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
}

std::ostream &operator << (std::ostream &out, Form &form) {
	out << std::endl << "Form name: " << form.getName() << std::endl;
	out << "Form signed: " << form.getSigned() << std::endl;
	out << "Form grade to sign: " << form.getGradeToSign() << std::endl;
	out << "Form grade to execute: " << form.getGradeToExecute() << std::endl;
	return out;
}
