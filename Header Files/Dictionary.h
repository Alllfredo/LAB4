#pragma once
#include "../Header Files/HashTable.h"

//! \brief Класс для работы со словарем, использующим хеш-таблицу.
//! Класс предоставляет методы для добавления, удаления, поиска и отображения элементов.
class Dictionary
{
private:
    //! \brief Хеш-таблица, хранящая элементы словаря.
    HashTable hashTable;

public:
    //! \brief Добавить пару ключ-значение в словарь.
    //! \param key Ключ элемента.
    //! \param value Значение элемента.
    void Add(const std::string& key, const std::string& value);

    //! \brief Удалить элемент по ключу из словаря.
    //! \param key Ключ элемента для удаления.
    void Remove(const std::string& key);

    //! \brief Найти значение по ключу в словаре.
    //! \param key Ключ для поиска.
    //! \return Значение, связанное с ключом. Если ключ не найден, возвращается пустая строка.
    std::string Search(const std::string& key);

    //! \brief Вывести текущее состояние словаря на экран.
    void Display() const;
};
