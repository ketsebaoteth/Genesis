#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include "../createvuejs/cvuejs.cpp"
#include "../tailwind/addtailwindvue.cpp"
#include "../vueComponents/addShadcn.cpp"

std::vector<std::string> splitString(const std::string &str, char delimiter)
{
    std::vector<std::string> tokens;
    std::stringstream ss(str);
    std::string token;

    while (std::getline(ss, token, delimiter))
    {
        tokens.push_back(token);
    }

    return tokens;
}

void handle(std::string argument)
{
    std::vector<std::string> arguments = splitString(argument, '+');
    std::string projectName = "vuejs-project";
    std::cout << "Enter project name: ";
    std::cin >> projectName;

    for (int i = 0; i < arguments.size(); i++)
    {
        if (arguments[i] == "vuejs")
        {
            std::cout << "Creating Vue.js Project..." << std::endl;
            createVueJsProject(projectName);
        }
        else if (arguments[i] == "tailwind")
        {
            if (arguments[0] == "vuejs")
            {
                std::cout << "Adding tailwind to Vue.js project..." << std::endl;
                addTailwindToVueJs(projectName);
            }
        }
        else if (arguments[i] == "shadcn")
        {
            if (arguments[0] == "vuejs")
            {
                std::cout << "Adding Shadcn to Vue.js project..." << std::endl;
                addShadcnToVueJs(projectName);
            }
        }
        else if (arguments[i] == "run")
        {
            std::string command = "cd " + projectName + " && npm install && npm run dev";
            system(command.c_str());
        }
    }
}