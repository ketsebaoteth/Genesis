#include <iostream>
#include "./arguments/handle.cpp"

int main(int argc, char **kwargs)
{
    if (argc > 1)
    {
        handle(kwargs[1]);
    }
    else
    {
        std::cout << "Error: Incorrect Argument Setup" << std::endl;
    }
    return 0;
}