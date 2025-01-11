#include <string>

//! \brief Структура для хранения элементов в хеш-таблице
struct HashTableItem
{
    //! \brief Ключ элемента
    std::string key;

    //! \brief Значение элемента
    std::string value;

    //! \brief Указатель на следующий элемент
    HashTableItem* next;

    //! \brief Конструктор элемента хеш-таблицы
    //! \param k Ключ
    //! \param v Значение
    //! \param n Указатель на следующий элемент
    HashTableItem(const std::string& k, const std::string& v, HashTableItem* n = nullptr)
        : key(k), value(v), next(n) {}
};
