//
// Created by User on 29.05.2022.
//

#ifndef BMH_BOYERMOOREHORSPOOL_H
#define BMH_BOYERMOOREHORSPOOL_H

#include <string>
#include <map>
#include <vector>

using std::string;
using std::map;
using std::vector;
using std::wstring;

class BoyerMooreHorspool {
private:
    map<char, int> charsMoveMap; // таблица сдвигов символов
    const string pattern; // паттерн

    BoyerMooreHorspool() {}

public:

    BoyerMooreHorspool(string _pattern) : pattern(_pattern) {
        int pLength = pattern.length();
        for (int i = 1; i < pLength; i++) {
            if (!charsMoveMap.contains(pattern[pLength - i - 1])) {   //
                charsMoveMap.insert({ pattern[pLength - i - 1], i }); // Создаём таблицу сдвигов для алгоритма БМХ.
            }                                                       //
        }
        if (!charsMoveMap.contains(pattern[pattern.length() - 1])) {  // добавляем последний символ паттерна в таблицу
            charsMoveMap.insert({ pattern[pLength - 1], pLength });   //
        }
    }

    /**
     * Функция, возвращает все вхождения паттерна в тексте.
     * @param text - текст
     * @param uppercaseRequest - учёт регистра при сравнении
     * @return
     */
    vector<int> search(string text) {
        vector<int> indexes; // вектор, хранящий все индексы совпадений с паттерном
        if (text.empty() || pattern.empty() || pattern.length() > text.length()) // проверки на корректность ввода
            return indexes;
        int pLength = pattern.length();

        int lastIndex = pLength - 1;
        int firstIndex = 0;
        while (lastIndex < text.length()) {
            int move = -1; // сдвиг на кол-во символов
            if (text[lastIndex] - pattern[pLength - 1] == 0) { // сравниваем по алгоритму БМХ первые символы, а потом всю строку
                if (compareStrings(text.substr(lastIndex - pLength + 1, lastIndex + 1), pattern)) {
                    indexes.push_back(lastIndex - pLength + 2);
                }
            }
            if (move == -1 && charsMoveMap.contains(text[lastIndex])) {
                move = charsMoveMap.find(text[lastIndex])->second;
            }
            else {
                move = pLength;
            }
            firstIndex += move;
            lastIndex += move;
        }
        return indexes;
    }

private:

    // сравнение двух строк на совпадение, сравнение идёт справа налево, как в БМХ
    bool compareStrings(string s1, string s2) {
        for (int i = s2.length() - 2; i >= 0; i--) {
            if (s1[i] != s2[i])
                return false;
        }
        return true;
    }
};
#endif //BMH_BOYERMOOREHORSPOOL_H
