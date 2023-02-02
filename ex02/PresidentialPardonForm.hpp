#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "Form.hpp"

class PresidentialPardonForm : public Form {

private:

	std::string	target;

public:

	std::string	getTarget() const;

	PresidentialPardonForm();
	PresidentialPardonForm(std::string target);
	PresidentialPardonForm(const PresidentialPardonForm &form);
	PresidentialPardonForm &operator = (const PresidentialPardonForm &form);
	~PresidentialPardonForm();

	void	execute(const Bureaucrat &executor) const;

};

#endif
