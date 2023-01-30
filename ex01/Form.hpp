#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp" 

class Form {

private:

	std::string	Name;
	bool		Signed;
	int			gradeToSign;
	int			gradeToExecute;

public:

	std::string	getName();
	bool		getSigned();
	int			getGradeToSign();
	int			getGradeToExecute();
	
	std::string	setName(std::string name);
	int			setGradeToSign(int newGradeToSign);
	int			setGradeToExecute(int newGradeToExecute);

	Form();
	Form(std::string name, int gradeToSing, int gradeToExecute);
	Form(const Form &form);
	Form &operator = (const Form &form);
	~Form();

	class GradeTooHighException : public std::exception {
	
	public:

		virtual const char *what() const throw() {
			return "grade too high";
		}
	};

	class GradeTooLowException : public std::exception {
	
	public:

		virtual const char *what() const throw() {
			return "grade too low";
		}
	};

};

std::ostream &operator << (std::ostream &out, Form &form);

#endif
