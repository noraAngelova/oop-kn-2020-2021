#include<iostream>

class Student {
private:
    int ID;
    double GPA;
    char gender;
public:
    Student();
    Student(int ID, double GPA, char gender);

    // operator =, copy constructor, move, деструктор могат да бъдат пропуснати
    // липсва динамично заделяне на памет и специфичино поведение

    // сетър, който променя всички полета
    void setStudent(int ID, double GPA, char gender);

    // гетъри за всички полета на класа
    int getID() const;
    double getGPA() const;
    char getGender() const;

    void print() const;
};

Student::Student() {
    ID = 0;
    GPA = 0;
    gender = ' ';
}

Student::Student(int ID, double GPA, char gender) {
    this->ID = ID;
    this->GPA = GPA;
    this->gender = gender;
}

void Student::setStudent(int ID, double GPA, char gender) {
    this->ID = ID;
    this->GPA = GPA;
    this->gender = gender;
}

int Student::getID() const {
    return ID;
}

double Student::getGPA() const {
    return GPA;
}

char Student::getGender() const {
    return gender;
}

void Student::print() const {
    std::cout << "ID : " << ID << std::endl;
    std::cout << "GPA : " << GPA << std::endl;
    std::cout << "Gender : " << gender << std::endl;
}