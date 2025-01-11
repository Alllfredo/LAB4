#pragma once
#include "../Header Files/HashTableItem.h"
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <iostream>

//! \brief ����� ���-������� ��� �������� ������
class HashTable 
{
private:
    //! \brief ��������� ��� ��������� ������� ���-������� (�� ��������� 8).
    static const int DEFAULT_CAPACITY = 8;

    //! \brief ������� ������� ���-�������.
    int _capacity;

    //! \brief ������� ������ ���-�������.
    int _size;

    //! \brief ������ ���������� �� �������� ���-�������.
    HashTableItem** _table;

    //! \brief ������� ������� ��� �����������.
    int* _pearsonTable;


    //! \brief �������� ������� ������� ��� �����������
    //! \return ��������� �� �������
    int* �reatePearsonTable();

    //! \brief ������� ����������� ��� ���������� �������
    //! \param key ����
    //! \return ������ � ���-�������
    int Hash(const std::string& key);

    //! \brief ��������� ������� ���-�������
    //! \param newCapacity ����� �������
    void Resize(int newCapacity);

public:
    //! \brief ����������� ���-�������
    //! \param cap ������� ���-�������
    HashTable(int cap = DEFAULT_CAPACITY);

    //! \brief ���������� ���-�������
    ~HashTable();

    //! \brief �������� ������� ���-�������
    //! \return ������� ���-�������
    int GetCapacity() const { return _capacity; }

    //! \brief �������� ���-������
    //! \return ������ ����������
    HashTableItem** GetTable() const { return _table; }

    //! \brief �������� ���� ����-�������� � ���-�������
    //! \param key ����
    //! \param value ��������
    void Add(const std::string& key, const std::string& value);

    //! \brief ������� ������� �� �����
    //! \param key ����
    void Remove(const std::string& key);

    //! \brief ����� �������� �� �����
    //! \param key ����
    //! \return ��������, ���� �������, ����� ������ ������
    std::string Search(const std::string& key);

    //! \brief ���������� ���������� ���-�������
    void Display() const;
};
