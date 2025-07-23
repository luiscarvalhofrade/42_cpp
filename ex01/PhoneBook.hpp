#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"
# include <iostream>

class PhoneBook {
private:
	Contact contact[8];

public:
	PhoneBook(void);
	~PhoneBook(void);

	int	add(void);
	int	search(int index, std::string fn, std::string ln);
	int	exit(void);
};

#endif