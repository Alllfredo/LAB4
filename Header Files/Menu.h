#pragma once

#include "dictionary.h"
#include <iostream>
#include <string>
#include <limits>

using namespace std;

//! \brief ������� ��� ����������� � ���������� ���� �������.
void MenuController();

//! \brief ���� ������� � ���������.
//! \return �������� ������.
char ValidInputChar();

//! \brief ���� ������ � ���������.
//! \return �������� ������.
string ValidInputString();

//! \brief ������� ��� ����������� ����������� �������.
void ShowDictionary(const Dictionary* dictionary);

//! \brief ������� ��� ����������� ��������� ���-�������.
void ShowHashTable(const Dictionary* dictionary);
