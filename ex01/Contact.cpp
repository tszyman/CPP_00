#include "Contact.hpp"

Contact::Contact(void){}; //Constructor prototype
Contact::~Contact(void){}; //Destructor prototype

const std::string	&Contact::getFirstName(void) const
{
	return _firstName;
}

const std::string &Contact::getLastName(void) const
{
	return _lastName;
}

const std::string &Contact::getNickName(void) const
{
	return _nickName;
}

const std::string &Contact::getPhoneNumber(void) const
{
	return _phoneNumber;
}

const std::string &Contact::getDarkestSecret(void) const
{
	return _darkestSecret;
}

bool Contact::setFirstName(const std::string& firstName)
{
	if (firstName.empty())
		return false;
	_firstName = firstName;
	return true;
}

bool Contact::setLastName(const std::string& lastName)
{
	if (lastName.empty())
		return false;
	_lastName = lastName;
	return true;
}

bool Contact::setNickName(const std::string& nickName)
{
	if (nickName.empty())
		return false;
	_nickName = nickName;
	return true;
}

bool Contact::setPhoneNumber(const std::string& phoneNumber)
{
	if (phoneNumber.empty())
		return false;
	_phoneNumber = phoneNumber;
	return true;
}

bool Contact::setDarkestSecret(const std::string& darkestSecret)
{
	if (darkestSecret.empty())
		return false;
	_darkestSecret = darkestSecret;
	return true;
}

bool Contact::isValid(void) const
{
	if (!_firstName.empty() &&
			!_lastName.empty() &&
			!_nickName.empty() &&
			!_phoneNumber.empty() &&
			!_darkestSecret.empty())
		return true;
	else
		return false;
}
