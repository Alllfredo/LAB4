#include "../Header Files/Menu.h"
#include <iostream>
// TODO: Полетела кодировка (посмотреть все файлы)
char ValidInputChar()
{
    char value;
    while (!(std::cin >> value)) 
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid input. Please enter a valid character: ";
    }

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return value;
}

std::string ValidInputString()
{
    std::string value;
    while (!(std::cin >> value))
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid input. Please enter a valid string: ";
    }

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return value;
}

void MenuController() 
{
    const std::string menu =
        "Choose one of the following:\n"
        "1 - Add\n"
        "2 - Search\n"
        "3 - Delete\n"
        "q - Quit\n"
        "Your choice: ";

    Dictionary dictionary; 
    char mode;

    while (true) 
    {
        dictionary.Display();
        std::cout << menu;
        mode = ValidInputChar();

        if (mode == 'q') break;

        std::string key, value;
        switch (mode) 
        {
        case '1':
        {
            std::cout << "Enter key to add: ";
            key = ValidInputString();
            std::cout << "Enter value: ";
            value = ValidInputString();
            dictionary.Add(key, value);
            break;
        }
        case '2':
        {
            std::cout << "Enter key to search: ";
            key = ValidInputString();
            value = dictionary.Search(key);
            std::cout << (value.empty()
                ? "No such key in the dictionary!\n"
                : "Key \"" + key + "\" contains value \"" + value + "\"\n");
            break;
        }
        case '3':
        {
            std::cout << "Enter key to delete: ";
            key = ValidInputString();
            dictionary.Remove(key);
            break;
        }
        default:
            std::cout << "Invalid choice. Try again.\n";
        }
    }
}
