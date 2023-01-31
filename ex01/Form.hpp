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

	std::string	getName() const;
	bool		getSigned() const;
	int			getGradeToSign() const;
	int			getGradeToExecute() const;
	
	void	setName(std::string name);
	void	setSigned(bool sign);
	void	setGradeToSign(int newGradeToSign);
	void	setGradeToExecute(int newGradeToExecute);

	Form();
	Form(std::string name, int gradeToSign, int gradeToExecute);
	Form(const Form &form);
	Form &operator = (const Form &form);
	~Form();

	void	beSigned(const Bureaucrat &bureaucrat);

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
