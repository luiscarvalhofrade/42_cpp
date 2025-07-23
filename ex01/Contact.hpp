#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <iostream>

class Contact {
private:
	std::string	_first_name;
	std::string	_last_name;
	int		_phone_number;
public:
	Contact(void);
	~Contact( void );

	void	getData(void);
	void	setData(void);
};

#endif