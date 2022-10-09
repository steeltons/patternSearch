//
// Created by User on 30.05.2022.
//

#ifndef BMH_PATTERNSEARCHER_H
#define BMH_PATTERNSEARCHER_H

#include "BoyerMooreHorspool.h"
#include "RabinKarp.h"
#include "Student.h"
#include "StudentManipulator.h"
#include <string>
#include <iostream>

    /**
     * �������, ������ � ����� firstname, surname, lastname, �� �������� ��� ��� � �� ���� domain �� �������� ��, ����
     * ���-�� ���������� �� �������� ���(��) ������ ��� ����� ���-�� ���������� �� ���(��), �� ��������� � ����.
     * @param students - ������ ���������
     * @param studentsArraySize - ������ �������
     * @param BMHPattern - ������� ��� ���
     * @param BMHMatcherCount - ���-�� ���������� ��� ��������� ���
     * @param RKPattern - ������� ��� ��
     * @param RKMatcherCount - ���-�� ���������� ��� ��
     */
void findStudentsByPatterns(Student* students, int studentsArraySize, string BMHPattern, int BMHMatcherCount,
    string RKPattern, int RKMatcherCount) {
    //string wBMHPattern = utf8_to_string(BMHPattern);
    BoyerMooreHorspool bmh(BMHPattern);
    //string wRKPattern = utf8_to_string(RKPattern);
    RabinCarp rk(RKPattern);
    vector<Student> result;
    for (int i = 0; i < studentsArraySize; i++) {
        int bmhMatcherCounter = 0;
        bmhMatcherCounter += bmh.search(students[i].getFirstname()).size();
        bmhMatcherCounter += bmh.search(students[i].getSurname()).size();
        bmhMatcherCounter += bmh.search(students[i].getLastname()).size();
        if (bmhMatcherCounter >= BMHMatcherCount || rk.search(students[i].getDomain()).size() >= RKMatcherCount) {
            result.push_back(students[i]);
        }
    }
    if (result.size() > 0) {
        writeStudentsToFile(&result[0], result.size(), "searchResult");
    }
    else {
        std::cout << "Nothing was founded" << std::endl;
    }
}

/**
 * �������, ������ � ����� firstname, surname, lastname, domain � �������� ��� ���, ���� ���-�� ���������� ��
 * ��� >= ����� ���������� ��� ���-�� ���������� �� ����������� >= ����� ��������� �� �����������, �� ����������
 * � ����.
 * @param students - ������ ���������
 * @param studentsArraySize - ������ �������
 * @param BMHPattern_1 - ������� ��� ���
 * @param fioMatcherCounter - ���-�� ���������� �� ���
 * @param BMHPattern_1 - ������� ��� ���
 * @param domainMatcherCounter - ���-�� ���������� �� �����������
 */
void findStudentsByBMHPattern(Student* students, int studentsArraySize, string BMHPattern_1, int fioMatcherCounter,
    string BMHPattern_2, int domainMatcherCounter) {
    //string pattern1 = utf8_to_string(BMHPattern_1);
    BoyerMooreHorspool bmh1(BMHPattern_1);
    //string pattern2 = utf8_to_string(BMHPattern_2);
    BoyerMooreHorspool bmh2(BMHPattern_2);
    vector<Student> result;
    for (int i = 0; i < studentsArraySize; i++) {
        int bmhMatcherCounter = 0;
        bmhMatcherCounter += bmh1.search(students[i].getFirstname()).size();
        bmhMatcherCounter += bmh1.search(students[i].getSurname()).size();
        bmhMatcherCounter += bmh1.search(students[i].getLastname()).size();
        if (bmhMatcherCounter >= fioMatcherCounter || bmh2.search(students[i].getDomain()).size() >= domainMatcherCounter) {
            result.push_back(students[i]);
        }
    }
    if (result.size() > 0) {
        writeStudentsToFile(&result[0], result.size(), "BMHSearchResult");
    }
    else {
        std::cout << "Nothing was founded" << std::endl;
    }
}

/**
 * �������, ������ � ����� firstname, surname, lastname, domain � �������� ��� ��, ���� ���-�� ���������� ��
 * ��� >= ����� ���������� ��� ���-�� ���������� �� ����������� >= ����� ��������� �� �����������, �� ����������
 * � ����.
 * @param students - ������ ���������
 * @param studentsArraySize - ������ �������
 * @param RKPattern_1 - ������� ��� ���
 * @param fioMatcherCounter - ���-�� ���������� �� ���
 * @param RKPattern_2 - ������� ��� ������
 * @param domainMatcherCounter - ���-�� ���������� �� �����������
 */
void findStudentsByRKPattern(Student* students, int studentsArraySize, string RKPattern_1, int fioMatcherCounter, string RKPattern_2
    , int domainMatcherCounter) {
    //string firstPattern = utf8_to_string(RKPattern_1);
    RabinCarp rk1(RKPattern_1);
    //string secondPattern = utf8_to_string(RKPattern_2);
    RabinCarp rk2(RKPattern_2);
    vector<Student> result;
    for (int i = 0; i < studentsArraySize; i++) {
        int bmhMatcherCounter = 0;
        bmhMatcherCounter += rk1.search(students[i].getFirstname()).size();
        bmhMatcherCounter += rk1.search(students[i].getSurname()).size();
        bmhMatcherCounter += rk1.search(students[i].getLastname()).size();
        if (bmhMatcherCounter >= fioMatcherCounter || rk2.search(students[i].getDomain()).size() >= domainMatcherCounter) {
            result.push_back(students[i]);
        }
    }
    if (result.size() > 0) {
        writeStudentsToFile(&result[0], result.size(), "RKSearchResult");
    }
    else {
        std::cout << "Nothing was founded" << std::endl;
    }
}

/**
 * �������, ��������� �� ����� ������� ���������� �� ���.
 * @param text - ����
 * @param pattern - �������
 */
void findIndexesInStringByBMH(string text, string pattern) {
    BoyerMooreHorspool bmh(pattern);
    auto result = bmh.search(text);
    int counter = 0;
    if (result.size() > 0) {
        for (auto i : result) {
            std::cout << i << std::endl;
        }
    }
    else {
        std::cout << "Nothing was founded" << std::endl;
    }
}

/**
 * �������, ��������� �� ����� ������� ���������� �� ��.
 * @param text - ����
 * @param pattern - �������
 */
void findIndexesInStringByRK(string text, string pattern) {
    RabinCarp rk(pattern);
    auto result = rk.search(text);
    int counter = 0;
    if (result.size() > 0) {
        for (auto i : result) {
            std::cout << i << std::endl;
        }
    }
    else {
        std::cout << "Nothing was founded" << std::endl;
    }
}
#endif //BMH_PATTERNSEARCHER_H
