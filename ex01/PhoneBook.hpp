#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"
# include <iostream>

class PhoneBook {
private:
	Contact contact[8];
	int		_contact_count;

public:
	PhoneBook(void);
	~PhoneBook(void);

	int	add(void);
	int	search(int index, std::string name);
	int	exit(void);
};

#endif