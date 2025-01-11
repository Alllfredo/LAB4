#pragma once

#include "dictionary.h"
#include <iostream>
#include <string>
#include <limits>

using namespace std;

//! \brief Функция для отображения главного меню.
void MenuController();

//! \brief Функция для корректного ввода символа.
//! \return Введённый символ.
char ValidInputChar();

//! \brief Функция для корректного ввода строки.
//! \return Введённая строка.
string ValidInputString();

//! \brief Функция для отображения содержимого словаря.
void ShowDictionary(const Dictionary* dictionary);

//! \brief Функция для отображения содержимого хеш-таблицы.
void ShowHashTable(const Dictionary* dictionary);
