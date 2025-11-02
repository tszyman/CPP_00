#include "PhoneBook.hpp"
#include <iomanip>

PhoneBook::PhoneBook(void) : _count(0), _oldestIndex(0) {}
PhoneBook::~PhoneBook(void) {}

void PhoneBook::addContact(const Contact& contact)
{

}
const Contact* PhoneBook::getContact(int index) const
{

}

int PhoneBook::getStoredContactsCount(void) const
{
	return _count;
}

void PhoneBook::displayContactsSummary(void) const
{

}

void PhoneBook::displayContactDetails(int index) const
{

}

std::string PhoneBook::_formatField(const std::string& str)
{

}
