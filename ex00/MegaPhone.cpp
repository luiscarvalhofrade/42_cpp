#include <iostream>
#include <cctype>

int main(int argc, char** argv)
{
    if (argc > 1)
    {
		for (int i = 1; i < argc; ++i)
        {
			std::string str = argv[i];
            for (int j = 0; str[j]; ++j)
            {
                std::cout << (char)std::toupper(str[j]);
            }
        }
        std::cout << std::endl;
    }
    else
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
    return (0);
}
