#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>

class Contact
{
public:
	Contact(void);
	~Contact(void);

	// Getters
	const std::string& getFirstName(void) const;
	const std::string& getLastName(void) const;
	const std::string& getNickName(void) const;
	const std::string& getPhoneNumber(void) const;
	const std::string& getDarkestSecret(void) const;

    // Setters: set only if non-empty input
	bool setFirstName(const std::string& firstName);
	bool setLastName(const std::string& lastName);
	bool setNickName(const std::string& nickName);
	bool setPhoneNumber(const std::string& phoneNumber);
	bool setDarkestSecret(const std::string& darkestSecret);

	// Check if contact is valid (no empty fields)
	bool isValid(void) const;

private:
	std::string _firstName;
	std::string _lastName;
	std::string _nickName;
	std::string _phoneNumber;
	std::string _darkestSecret;
};

#endif
