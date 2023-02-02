#ifndef FORM_HPP
#define FORM_HPP

#include <fstream>
#include "Bureaucrat.hpp"

class Form {

protected:

	const std::string	Name;
	bool				Signed;
	const int			gradeToSign;
	const int			gradeToExecute;

public:

	std::string	getName() const;
	bool		getSigned() const;
	int			getGradeToSign() const;
	int			getGradeToExecute() const;

	Form();
	Form(std::string name, int gradeToSign, int gradeToExecute);
	Form(const Form &form);
	Form &operator = (const Form &form);
	virtual ~Form();

	void			beSigned(const Bureaucrat &bureaucrat);
	virtual void	execute(const Bureaucrat &executor) const = 0;

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

	class IsNotSignedException : public std::exception {

	public:

		virtual const char *what() const throw() {
			return "is not signed";
		}
	};

};

std::ostream &operator << (std::ostream &out, Form &form);

#endif
