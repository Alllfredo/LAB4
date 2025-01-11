#pragma once
#include "../Header Files/HashTable.h"

//! \brief ����� ��� ������ �� ��������, ������������ ���-�������.
class Dictionary
{
private:
    //! \brief ���-�������, �������� �������� �������.
    HashTable hashTable;

public:
    //! \brief �������� ���� ����-�������� � �������.
    //! \param key ���� ��������.
    //! \param value �������� ��������.
    void Add(const std::string& key, const std::string& value);

    //! \brief ������� ������� �� ����� �� �������.
    //! \param key ���� �������� ��� ��������.
    void Remove(const std::string& key);

    //! \brief ����� �������� �� ����� � �������.
    //! \param key ���� ��� ������.
    //! \return ��������, ��������� � ������. ���� ���� �� ������, ������������ ������ ������.
    std::string Search(const std::string& key);

    //! \brief ������� ������� ��������� ������� �� �����.
    void Display() const;
};
