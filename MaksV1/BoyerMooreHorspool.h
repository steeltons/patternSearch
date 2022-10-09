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
    map<char, int> charsMoveMap; // ������� ������� ��������
    const string pattern; // �������

    BoyerMooreHorspool() {}

public:

    BoyerMooreHorspool(string _pattern) : pattern(_pattern) {
        int pLength = pattern.length();
        for (int i = 1; i < pLength; i++) {
            if (!charsMoveMap.contains(pattern[pLength - i - 1])) {   //
                charsMoveMap.insert({ pattern[pLength - i - 1], i }); // ������ ������� ������� ��� ��������� ���.
            }                                                       //
        }
        if (!charsMoveMap.contains(pattern[pattern.length() - 1])) {  // ��������� ��������� ������ �������� � �������
            charsMoveMap.insert({ pattern[pLength - 1], pLength });   //
        }
    }

    /**
     * �������, ���������� ��� ��������� �������� � ������.
     * @param text - �����
     * @param uppercaseRequest - ���� �������� ��� ���������
     * @return
     */
    vector<int> search(string text) {
        vector<int> indexes; // ������, �������� ��� ������� ���������� � ���������
        if (text.empty() || pattern.empty() || pattern.length() > text.length()) // �������� �� ������������ �����
            return indexes;
        int pLength = pattern.length();

        int lastIndex = pLength - 1;
        int firstIndex = 0;
        while (lastIndex < text.length()) {
            int move = -1; // ����� �� ���-�� ��������
            if (text[lastIndex] - pattern[pLength - 1] == 0) { // ���������� �� ��������� ��� ������ �������, � ����� ��� ������
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

    // ��������� ���� ����� �� ����������, ��������� ��� ������ ������, ��� � ���
    bool compareStrings(string s1, string s2) {
        for (int i = s2.length() - 2; i >= 0; i--) {
            if (s1[i] != s2[i])
                return false;
        }
        return true;
    }
};
#endif //BMH_BOYERMOOREHORSPOOL_H
