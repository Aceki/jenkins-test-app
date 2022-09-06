#include <iostream>
#include <sstream>
#include <string>

#include "main.hpp"

int main()
{
    std::string expected = "Hello, World!";
    std::string actual;
    std::stringstream os;

    helloworld(os);
    std::getline(os, actual);

    if (expected == actual)
    {
        printf("OK\n");
        std::cout << "OK" << std::endl;
        return 0;
    }
    printf("%s != %s\nFAIL\n", expected.c_str(), actual.c_str());
    return 1;
}
