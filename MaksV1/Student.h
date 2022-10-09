//
// Created by User on 29.05.2022.
//

#ifndef BMH_STUDENT_H
#define BMH_STUDENT_H

#include <string>
#include <execution>
#include <ostream>

using std::string;
using std::wstring;

class Student {
private:
    string firstname;
    string surname;
    string lastname;
    string domain;
    int groupNumber;
    string birthDate;

public:
    Student() : firstname(), surname(), lastname(), domain(), groupNumber(-1), birthDate() {}

    Student(string firstname, string surname, string lastname, string domain, int groupNumber, string date)
        : firstname(firstname), surname(surname), lastname(lastname), domain(domain), birthDate(date) {
        if (groupNumber < 0)
            throw new std::invalid_argument("Номер группы не может быть меньше нуля");
        this->groupNumber = groupNumber;
    }

    const string& getFirstname() const {
        return firstname;
    }

    void setFirstname(const string& firstname) {
        Student::firstname = firstname;
    }

    const string& getSurname() const {
        return surname;
    }

    void setSurname(const string& surname) {
        Student::surname = surname;
    }

    const string& getDomain() const {
        return domain;
    }

    void setDomain(const string& domain) {
        Student::domain = domain;
    }

    int getGroupNumber() const {
        return groupNumber;
    }

    void setGroupNumber(int groupNumber) {
        Student::groupNumber = groupNumber;
    }

    const string& getBirthDate() const {
        return birthDate;
    }

    void setBirthDate(const string& birthDate) {
        Student::birthDate = birthDate;
    }

    friend std::ostream& operator<<(std::ostream& os, const Student& student) {
        os << "firstname: " << student.firstname << " surname: " << student.surname << " domain: " << student.domain
            << " groupNumber: " << student.groupNumber << " birthDate: " << student.birthDate;
        return os;
    }

    const string& getLastname() const {
        return lastname;
    }

    void setLastname(const string& lastname) {
        Student::lastname = lastname;
    }
};
#endif //BMH_STUDENT_H
