#include "PhoneBook.hpp"
#include <iostream>
#include <string>
#include <sstream>

static int	stringToInt(const std::string &str)
{
	std::istringstream iss(str);
	int num;

	num = 0;
	iss >> num;
	return num;
}

static bool getContactInput(Contact &contact)
{
	std::string input;

	std::cout << "Enter First Name: ";
	std::getline(std::cin, input);
	if (!contact.setFirstName(input))
		return false;
	std::cout << "Enter Last Name: ";
	std::getline(std::cin, input);
	if (!contact.setLastName(input))
		return false;
	std::cout << "Enter Nickname: ";
	std::getline(std::cin, input);
	if (!contact.setNickName(input))
		return false;
	std::cout << "Enter Phone Number: ";
	std::getline(std::cin, input);
	if (!contact.setPhoneNumber(input))
		return false;
	std::cout << "Enter Darkest Secret: ";
	std::getline(std::cin, input);
	if (!contact.setDarkestSecret(input))
		return false;
	return contact.isValid();
}

int	main(void)
{
	PhoneBook	phoneBook;
	std::string	command;

	std::cout << "I'm you're PhoneBook!\n";
	while (true)
	{
		std::cout << "Enter a command (only ADD, SEARCH, EXIT allowed): ";
		std::getline(std::cin, command);
		if (command == "EXIT")
		{
			break;
		}
		else if (command == "ADD")
		{
			Contact contact;
			if (getContactInput(contact))
			{
				phoneBook.addContact(contact);
				std::cout << "New contact added!\n";
			}
			else
			{
				std::cout << "All fields are required! Adding contact failed!\n";
			}
		}
		else if (command == "SEARCH")
		{
			if (phoneBook.getStoredContactsCount() == 0)
			{
				std::cout << "No contacts in the phonebook yet!\n";
				continue;
			}
			phoneBook.displayContactsSummary();
			std::cout << "Enter contact index to view the details: ";
			std::getline(std::cin, command);
			int indx = -1;
			indx = stringToInt(command);
			if (indx >= 0 && indx < phoneBook.getStoredContactsCount())
			{
				phoneBook.displayContactDetails(indx);
			}
			else
			{
				std::cout << "No such index!\n";
				continue;
			}
		}
		else
			std::cout << "Unknown command! (only ADD, SEARCH, EXIT allowed)\n";
	}
	std::cout << "Thank you! See you next time!\n";
	return (0);
}
