#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "Form.hpp"

class ShrubberyCreationForm : public Form {

private:

	std::string	target;

public:

	std::string	getTarget() const;

	ShrubberyCreationForm();
	ShrubberyCreationForm(std::string target);
	ShrubberyCreationForm(const ShrubberyCreationForm &form);
	ShrubberyCreationForm &operator = (const ShrubberyCreationForm &form);
	~ShrubberyCreationForm();

	void	beSigned(const Bureaucrat &bureaucrat);
	void	execute(const Bureaucrat &executor) const;

};

#define ASCII_TREE "\
          .     .  .      +     .      .          .				\n\
     .       .      .     #       .           .					\n\
        .      .         ###            .      .      .			\n\
      .      .   '#:. .:##'##:. .:#'  .      .					\n\
          .      . '####'###'####'  .							\n\
       .     '#:.    .:#'###'#:.    .:#'  .        .       .	\n\
  .             '#########'#########'        .        .			\n\
        .    '#:.  '####'###'####'  .:#'   .       .			\n\
     .     .  '#######''##'##''#######'                  .		\n\
                .'##'#####'#####'##'           .      .			\n\
    .   '#:. ...  .:##'###'###'##:.  ... .:#'     .				\n\
      .     '#######'##'#####'##'#######'      .     .			\n\
    .    .     '#####''#######''#####'    .      .				\n\
            .     '      000      '    .     .					\n\
       .         .   .   000     .        .       .				\n\
.. .. ..................O000O........................ ...... ...\n\
"

#endif
