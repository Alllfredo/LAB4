#pragma once
#include "../Header Files/HashTableItem.h"
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <iostream>

//! \brief Класс хеш-таблицы для хранения данных
class HashTable 
{
private:
    //! \brief Константа для начальной ёмкости хеш-таблицы (по умолчанию 8).
    static const int DEFAULT_CAPACITY = 8;

    //! \brief Текущая ёмкость хеш-таблицы.
    int _capacity;

    //! \brief Текущий размер хеш-таблицы.
    int _size;

    //! \brief Массив указателей на элементы хеш-таблицы.
    HashTableItem** _table;

    //! \brief Таблица Персона для хеширования.
    int* _pearsonTable;


    //! \brief Создание таблицы Пирсона для хеширования
    //! \return Указатель на таблицу
    int* СreatePearsonTable();

    //! \brief Функция хеширования для вычисления индекса
    //! \param key Ключ
    //! \return Индекс в хеш-таблице
    int Hash(const std::string& key);

    //! \brief Увеличить ёмкость хеш-таблицы
    //! \param newCapacity Новая ёмкость
    void Resize(int newCapacity);

public:
    //! \brief Конструктор хеш-таблицы
    //! \param cap Ёмкость хеш-таблицы
    HashTable(int cap = DEFAULT_CAPACITY);

    //! \brief Деструктор хеш-таблицы
    ~HashTable();

    //! \brief Получить ёмкость хеш-таблицы
    //! \return Ёмкость хеш-таблицы
    int GetCapacity() const { return _capacity; }

    //! \brief Получить хеш-таблиц
    //! \return Массив указателей
    HashTableItem** GetTable() const { return _table; }

    //! \brief Добавить пару ключ-значение в хеш-таблицу
    //! \param key Ключ
    //! \param value Значение
    void Add(const std::string& key, const std::string& value);

    //! \brief Удалить элемент по ключу
    //! \param key Ключ
    void Remove(const std::string& key);

    //! \brief Найти значение по ключу
    //! \param key Ключ
    //! \return Значение, если найдено, иначе пустая строка
    std::string Search(const std::string& key);

    //! \brief Отобразить содержимое хеш-таблицы
    void Display() const;
};
