#include <iostream>
#include <string>
#include <cctype>

class UpperCase
{
private:
	std::string value;

public:
	UpperCase(const std::string &str) : value(str) {}

	std::string to_upper_case() const
{
		std::string result = value;
		for (size_t i = 0; i < result.length(); ++i)
		{
			if (std::islower(result[i]))
				result[i] = std::toupper(result[i]);
}
		return result;
	}
};

int main(int argc, char **argv)
{
	int i;

	if (argc < 2)
	{
		std::cerr << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
		return 1;
	}
	i = 1;
	while (i < argc)
	{
		UpperCase word(argv[i]);
		std::cout << word.to_upper_case();
		++i;
	}
	std::cout << std::endl;
	return 0;
}
