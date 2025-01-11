#include "../Header Files/Dictionary.h"
#include <iostream>

void Dictionary::Add(const std::string& key, const std::string& value) 
{
    hashTable.Add(key, value);
}

void Dictionary::Remove(const std::string& key) 
{
    hashTable.Remove(key);
}

std::string Dictionary::Search(const std::string& key) 
{
    return hashTable.Search(key);
}

// TODO: Не должно быть ввода/вывода в логических классах
void Dictionary::Display() const
{
    hashTable.Display();

    std::cout << "{";
    bool first = true;
    for (int i = 0; i < hashTable.GetCapacity(); ++i)
    {
        HashTableItem* current = hashTable.GetTable()[i];
        while (current)
        {
            if (!first)
            {
                std::cout << ",";
            }
            std::cout << current->key << ":" << current->value;
            first = false;
            current = current->next;
        }
    }
    std::cout << "}\n";
}
