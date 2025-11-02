#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP
#include "Contact.hpp"
#include <iostream>

class	PhoneBook
{
public:
	PhoneBook(void);
	~PhoneBook(void);

	void			addContact(const Contact& contact);
	const Contact*	getContact(int index) const;
	int				getStoredContactsCount(void) const;

	void			displayContactsSummary(void) const;
	void			displayContactDetails(int index) const;

private:
	Contact _contacts[8];
	int		_count;
	int		_oldestIndex;

	static	std::string	_formatField(const std::string& str);
};
#endif
