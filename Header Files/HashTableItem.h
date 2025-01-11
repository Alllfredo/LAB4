#include <string>
//! \brief ��������� ��� �������� ��������� � ���-�������
struct HashTableItem
{
    //! \brief ���� ��������
    std::string key;

    //! \brief �������� ��������
    std::string value;

    //! \brief ��������� �� ��������� �������
    HashTableItem* next;

    //! \brief ����������� �������� ���-�������
    //! \param k ����
    //! \param v ��������
    //! \param n ��������� �� ��������� �������
    HashTableItem(const std::string& k, const std::string& v, HashTableItem* n = nullptr)
        : key(k), value(v), next(n) {}
};