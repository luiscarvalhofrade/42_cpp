#include <iostream>
#include <cctype> // For std::toupper

int main(int argc, char** argv)
{
    if (argc > 1)
    {
        for (int i = 1; i < argc; ++i)
        {
            for (char* c = argv[i]; *c; ++c)
            {
                std::cout << (char)std::toupper(*c);
            }
        }
        std::cout << std::endl;
    }
    else
    {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
    }
    return 0;
}
