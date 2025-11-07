#include "Account.hpp"
#include <iostream>
#include <ctime>

int Account::_nbAccounts;
int Account::_totalAmount;
int Account::_totalNbDeposits;
int Account::_totalNbWithdrawals;

void Account::_displayTimestamp(void)
{
	char buf[20];

	std::time_t now = std::time(0);
	struct std::tm *t = std::localtime(&now);
	std::strftime(buf, sizeof(buf), "[%Y%m%d_%H%M%S] ", t);
	std::cout << buf;
}

	Account::Account( int initial_deposit )
	{
		this->_accountIndex = _nbAccounts;
		this->_amount = initial_deposit;
		this->_nbDeposits = 0;
		this->_nbWithdrawals = 0;
		++_nbAccounts;
		_totalAmount += initial_deposit;
		_displayTimestamp();
		std::cout << "index:" << _accountIndex
					<< ";amount: " << _amount
					<< "; created" << std::endl;
	};

	Account::~Account( void )
	{
		_displayTimestamp();
		std::cout << "index:" << _accountIndex
					<< ";amount: " << _amount
					<< "; closed" << std::endl;
	};


