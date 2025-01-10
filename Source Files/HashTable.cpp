#include "../Header Files/HashTable.h"
#include <iostream>

int* HashTable::ÑreatePearsonTable() 
{
    int* table = new int[256];
    for (int i = 0; i < 256; ++i) {
        table[i] = i;
    }

    std::srand(std::time(0));
    for (int i = 0; i < 256; ++i) {
        int j = std::rand() % 256;
        std::swap(table[i], table[j]);
    }

    return table;
}

int HashTable::Hash(const std::string& key) 
{
    int h = 0;
    for (char c : key) {
        h = _pearsonTable[(h + c) % 256];
    }

    return h % _capacity;
}

HashTable::HashTable(int cap) : _capacity(cap), _size(0) 
{
    _table = new HashTableItem * [_capacity]();
    _pearsonTable = ÑreatePearsonTable();
}

HashTable::~HashTable() 
{
    for (int i = 0; i < _capacity; ++i) 
    {
        HashTableItem* current = _table[i];
        while (current) {
            HashTableItem* toDelete = current;
            current = current->next;
            delete toDelete;
        }
    }

    delete[] _table;
    delete[] _pearsonTable;
}

void HashTable::Add(const std::string& key, const std::string& value)
{
    int index = Hash(key); 
    HashTableItem* current = _table[index];

    while (current)
    {
        if (current->key == key) 
        {
            current->value = value;
            return;
        }
        current = current->next;
    }

    HashTableItem* newItem = new HashTableItem(key, value, nullptr);
    if (_table[index] == nullptr) {
        _table[index] = newItem;
    }
    else 
    {
        HashTableItem* last = _table[index];
        while (last->next) {
            last = last->next;
        }
        last->next = newItem;
    }

    ++_size;
    if (_size >= _capacity)
    {
        Resize(_capacity * 2);  
    }
}

void HashTable::Remove(const std::string& key) 
{
    int index = Hash(key);
    HashTableItem* current = _table[index];
    HashTableItem* prev = nullptr;
    while (current) 
    {
        if (current->key == key) 
        {
            if (prev) 
            {
                prev->next = current->next;
            }
            else 
            {
                _table[index] = current->next;
            }

            delete current;
            --_size;
            return;
        }

        prev = current;
        current = current->next;
    }
}

std::string HashTable::Search(const std::string& key) 
{
    int index = Hash(key);
    HashTableItem* current = _table[index];
    while (current) 
    {
        if (current->key == key) {
            return current->value;
        }
        current = current->next;
    }

    return "";
}

void HashTable::Display() const 
{
    for (int i = 0; i < _capacity; ++i) 
    {
        std::cout << "[" << i << "]: ";
        HashTableItem* current = _table[i];
        while (current) 
        {
            std::cout << "{" << current->key << ": " << current->value << "} -> ";
            current = current->next;
        }

        std::cout << "nullptr\n";
    }
}

void HashTable::Resize(int newCapacity) 
{
    HashTableItem** oldTable = _table;
    int oldCapacity = _capacity;
    _capacity = newCapacity;
    _table = new HashTableItem * [_capacity]();
    _size = 0;

    for (int i = 0; i < oldCapacity; ++i) 
    {
        HashTableItem* current = oldTable[i];
        while (current) 
        {
            Add(current->key, current->value);
            HashTableItem* toDelete = current;
            current = current->next;
            delete toDelete;
        }
    }

    delete[] oldTable;
}
