#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include <stdlib.h>
#include "Form.hpp"

class RobotomyRequestForm : public Form {

private:

	std::string	target;

public:

	std::string	getTarget() const;

	RobotomyRequestForm();
	RobotomyRequestForm(std::string target);
	RobotomyRequestForm(const RobotomyRequestForm &form);
	RobotomyRequestForm &operator = (const RobotomyRequestForm &form);
	~RobotomyRequestForm();

	void	execute(const Bureaucrat &executor) const;

};

#endif
