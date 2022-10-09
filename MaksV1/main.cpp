#include "Student.h"
#include "PatternSearcher.h"
#include "StudentManipulator.h"

int main() {
    Student* students = readStudentsFromFile("students.txt");
    findStudentsByPatterns(students, 1000, "Martin", 1, "Applied_mathematics_and_computer_science", 3);
    findStudentsByBMHPattern(students, 1000, "Martin", 1, "Applied_mathematics_and_computer_science", 3);
    findStudentsByRKPattern(students, 1000, "Martin", 1, "Applied_mathematics_and_computer_science", 3);
    //string text = "Lorem ipsum, dolor sit amet consectetur adipisicing elit. Accusamus, fuga deleniti sed ut repudiandae porro cupiditate in saepe est veniam, optio aliquam! Earum molestias atque, nulla nobis sunt cupiditate! Iste. Lorem ipsum, dolor sit amet consectetur adipisicing elit. Accusamus, fuga deleniti sed ut repudiandae porro cupiditate in saepe est veniam, optio aliquam! Earum molestias atque, nulla nobis sunt cupiditate! Iste.";
    //string pattern = "sit";
    //findIndexesInStringByBMH(text, pattern);
    delete[] students;

    return 0;
}