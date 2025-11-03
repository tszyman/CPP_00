#include "PhoneBook.hpp"
#include <iomanip>

PhoneBook::PhoneBook(void) : _count(0), _oldestIndex(0) {}
PhoneBook::~PhoneBook(void) {}

void PhoneBook::addContact(const Contact& contact)
{
	if (_count < 8)
	{
		_contacts[_count] = contact;
		_count++;
	}
	else
	{
		_contacts[_oldestIndex] = contact;
		_oldestIndex = (_oldestIndex + 1) % 8;
	}
}
const Contact* PhoneBook::getContact(int index) const
{
	if (index < 0 || index >= _count)
	{
		return 0;
	}
	else
	{
		return &_contacts[index];
	}
}

int PhoneBook::getStoredContactsCount(void) const
{
	return _count;
}

void PhoneBook::displayContactsSummary(void) const
{
	int	i;

	std::cout << "     Index|First Name| Last Name|  Nickname|\n";
	i = 0;
	while (i < _count)
	{
		std::cout << std::right << std::setw(10) << i << '|'
				<< std::right << std::setw(10) << _formatField(_contacts[i].getFirstName()) << '|'
				<< std::right << std::setw(10) << _formatField(_contacts[i].getLastName()) << '|'
				<< std::right << std::setw(10) << _formatField(_contacts[i].getNickName()) << "|\n";
		i++;
	}
}

void PhoneBook::displayContactDetails(int index) const
{
	if (index < 0 || index >= _count)
	{
		std::cout << "Invalid index\n";
		return;
	}
	else
	{
		const Contact& c = _contacts[index];
		std::cout << "First Name: " << c.getFirstName() << '\n'
				<< "Last Name: " << c.getLastName() << '\n'
				<< "Nickname: " << c.getNickName() << '\n'
				<< "Phone number: " << c.getPhoneNumber() << '\n'
				<< "Darkest secret: " << c.getDarkestSecret() << '\n';
	}
}

std::string PhoneBook::_formatField(const std::string& str)
{
	if (str.length() > 10)
		return str.substr(0,9) + ".";
	else
		return str;
}
