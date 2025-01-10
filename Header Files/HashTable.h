#pragma once
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>

//! \brief ����� ���-������� ��� �������� ������
class HashTable 
{
private:
    //! \brief ��������� ��� �������� ��������� � ���-�������
    struct HashTableItem 
    {
        std::string key; //!< ���� ��������
        std::string value; //!< �������� ��������
        HashTableItem* next; //!< ��������� �� ��������� �������

        //! \brief ����������� �������� ���-�������
        //! \param k ����
        //! \param v ��������
        //! \param n ��������� �� ��������� �������
        HashTableItem(const std::string& k, const std::string& v, HashTableItem* n = nullptr)
            : key(k), value(v), next(n) {}
    };

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
