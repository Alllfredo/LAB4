#pragma once

#include "dictionary.h"
#include <iostream>
#include <string>
#include <limits>

using namespace std;

//! \brief Функция для отображения и управления меню словаря.
void MenuController();

//! \brief Ввод символа с проверкой.
//! \return Введённый символ.
char ValidInputChar();

//! \brief Ввод строки с проверкой.
//! \return Введённая строка.
string ValidInputString();

//! \brief Функция для отображения содержимого словаря.
void ShowDictionary(const Dictionary* dictionary);

//! \brief Функция для отображения состояния хеш-таблицы.
void ShowHashTable(const Dictionary* dictionary);
