#ifndef BMH_STUDENTMANIPULATOR_H
#define BMH_STUDENTMANIPULATOR_H
#include "Student.h"
#include <fstream>
#include <filesystem>
#include <string>
#include <Windows.h>

namespace fs = std::filesystem;
using std::string;
using std::string;

/**
 * �������, ��������� ������ �������� �� ������
 * @param line - �������� ������ � ��������
 * @return Student - ������ ��������
 */
Student createStudentFromString(string line) {
    string temp;
    string* words = new string[6];
    int counter = 0;
    for (int i = 0; i < line.length(); i++) {
        if (line[i] == L' ') {
            words[counter++] = temp;
            temp.erase();
        }
        else {
            temp += line[i];
        }
    }
    //words[counter++] = temp;
    string firstname = words[1];
    string surname = words[2];
    string lastname = words[3];
    string domain = words[4];
    int group = std::stoi(words[0]);
    string birthDate = temp;
    Student s(firstname, surname, lastname, domain, group, birthDate);
    delete[] words;
    return s;
}

/**
 * �������, ����������� �� ����� ������ � ���������
 * @param fileName - ��� �����, ������������ � ����� ����� � StudentManipulator.cpp
 * @return Student* - ������ ������� � ���������
 */
Student* readStudentsFromFile(string filename) {
    std::ifstream reader(filename);
    if (!reader) {
        return new Student[0];
    }
    string line;                                    //
    std::getline(reader, line);                     // ��������� ������ ������, �.�. ���-�� �������
    Student* array = new Student[std::stoi(line)];  //
    int counter = 0;
    while (std::getline(reader, line)) {// ��������� ������
        Student s = createStudentFromString(line);
        array[counter++] = s;
    }
    reader.close();
    return array;
}

/**
 * �������, ������������ ��������� � ����
 * @param array - ������ ���� Student
 * @param arraySize - ������ �������
 * @param outputFilename - ��� ����� ��� ������ ���������, ����� ��������� ����� � StudentManipulator.cpp
 */
void writeStudentsToFile(Student* array, int arraySize, string outputFilename) {
    std::ofstream writer(outputFilename);
    for (int i = 0; i < arraySize; i++) {
        string out = array[i].getFirstname() + " "
            + array[i].getSurname() + " " + array[i].getLastname() + " " + array[i].getBirthDate() + " "
            + array[i].getDomain();

        writer << std::to_string(array[i].getGroupNumber()) << " " << out << "\n";
        writer.flush();
    }
    writer.close();
}
#endif //BMH_STUDENTMANIPULATOR_H
