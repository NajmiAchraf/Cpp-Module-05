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
	int			getGrade() const;

	void		setName(std::string name);
	void 		setGrade(int grade);

	Bureaucrat();
	Bureaucrat(std::string name, int grade);
	Bureaucrat(const Bureaucrat &src);
	Bureaucrat &operator = (const Bureaucrat &bureaucrat);
	~Bureaucrat();

	void	upGrade();
	void	downGrade();
	void	checkGrade(int grade);

	class GradeTooHighException : public std::exception {

	public:

		virtual const char	*what() const throw() {
			return "grade too high.";
		}

	};

	class GradeTooLowException : public std::exception {

	public:

		virtual const char	*what() const throw() {
			return "grade too low.";
		}

	};

};

std::ostream &operator << (std::ostream &out, const Bureaucrat &bureaucrat);

#endif
