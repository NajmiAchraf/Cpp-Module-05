#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <exception>

class Bureaucrat {

private:

	std::string	name;
	int			grade;

public:

	std::string	getName() const;
	void		setName(std::string name);
	int			getGrade() const;
	void 		setGrade(int grade);
	void		incrementGrade();

	Bureaucrat();
	Bureaucrat(const Bureaucrat &src);
	Bureaucrat &operator = (const Bureaucrat &bureaucrat);
	~Bureaucrat();

	std::exception	GradeTooHighException();
	std::exception	GradeTooLowException();

};

std::ostream &operator << (std::ostream &out, const Bureaucrat &bureaucrat);

#endif
