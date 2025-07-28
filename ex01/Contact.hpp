#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <iostream>

class Contact {
private:
	std::string	_first_name;
	std::string	_last_name;
	std::string	_phone_number;
public:
	Contact(void);
	~Contact( void );

	void		getData(void);
	std::string	getFirstName(void);
	std::string	getLastName(void);
	std::string	getPhoneNUmber(void);
	std::string	setFirstName(void);
	std::string setLastName(void);
	std::string	setPhoneNumber(void);
	int			setContact(std::string fn, std::string ln, std::string pn);
};

#endif