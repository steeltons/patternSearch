//
// Created by User on 29.05.2022.
//

#ifndef BMH_RABINKARP_H
#define BMH_RABINKARP_H

#include <string>
#include <map>
#include <vector>

using std::string;
using std::map;
using std::vector;
using std::string;

// ��� ��� ������� ��������� ��� �������������� ��� ��� ������, ���� � ������.
// ����� q = 31 ����� �� � �������. �.�. 31 ��������� � ���� �����(���������), �� ��� x86 ������ �����������
// ����� ����������� �������� � ���, �.�. q ��������� � �������, ��-�� ���� ������� �������� �������������� ��������.
// x - ����� ��� ���������� ���� �������, ����� �� ��� � � �������������� ���� ������, ������� � ��������� �� 1 �� 31 - 2,
// ���������� ���� �� ���� ����� ���������� ���� �������.
class RabinCarp{
private:
    map<char, int> charsHashMap; // ������� ����� ��������
    const int q = 31; // ����� ��� ������ �������.
    int x; // �����, ��� ��������� ���� �� ������� �� x.
    const string pattern; // �������
    int patternHash = 0; // ��� ��������
    RabinCarp() : pattern(){}

public:
    RabinCarp(string _pattern) : pattern(_pattern), x((rand() % q - 2) + 1){
        for(int i = 0; i < pattern.length(); i++){
            patternHash += hashValue(pattern[i]); // ���������� ��������� ��� ��������, ���� �� ������� �����.
        }
    }

    /**
     * �������, ���������� ��� ��������� �������� � ������.
     * @param text - �����
     * @param uppercaseRequest - ���� �������� ��� ���������
     * @return
     */
    vector<int> search(string text){
        vector<int> indexes;
        if(text.empty() || pattern.empty() || pattern.length() > text.length()) // ���������� � ���
            return indexes;

        int currentTextHash = 0; // ��� ��� ������
        int pLength = pattern.length();
        for(int i = 0; i < pLength; i++){ // ��������� ��� ��� n-������ �������� � ������, ��� n - ������ ��������
            currentTextHash += hashValue(text[i]);
        }
        if(patternHash == currentTextHash && compareStrings(text.substr(0, pLength), pattern)){ // ������ �������� �� ����������
            indexes.push_back(1);
        }
        for(int i = pLength; i < text.length(); i++){ // �������� ���������� �������� � ������, ��� ��� ��� ��������� ���, ���
            currentTextHash += hashValue(text[i]); // �� ��������� ��������� ������
            currentTextHash -= hashValue((text[i - pLength])); // � �������� ����������
            if(currentTextHash == patternHash && compareStrings(text.substr(i - pLength + 1, i+1), pattern)){
                indexes.push_back(i - pLength + 2);
            }
        }
        return indexes;
    }

private:

    // ��������� � ���������� ��� ������� ������������ ��������� ��� � �������.
    int hashValue(wchar_t c){
        if(charsHashMap.contains(c)) // ���� ��� ��� ������� ��� ����
            return charsHashMap.find(c)->second;
        else {
            int hash = c * x % q; // ��������� ���
            x *= x;
            charsHashMap.insert({c, hash});
            return hash;
        }
    }

    // ���������� ������
    bool compareStrings(string s1, string s2){
        for(int i = 0; i < s2.length() ; i++){
            if(s1[i] != s2[i])
                return false;
        }
        return true;
    }
};
#endif //BMH_RABINKARP_H