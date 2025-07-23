#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"
# include <iostream>

class PhoneBook {

public:
	Contact Contact[8];
	PhoneBook(void);
	~PhoneBook(void);

	void	add(void);
	void	search(int	index, std::string fn, std::string ln);
	void	exit(void);
};

#endif