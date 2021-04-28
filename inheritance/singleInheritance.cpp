#define _CRT_SECURE_NO_WARNINGS // visual studio-specific

#include <iostream>

// Клас за човек 
// Държи информация за име и егн
class Person {
public:
	Person(const char* = "", const char* = "");
	~Person();
	Person(Person const&);
	Person& operator=(Person const& p);
	
	// Член-функция за извеждане
	void print() const;
private:
	char* name; // име
	char* ucn; // ЕГН
	// Помощни член-функции за копиране и изтриване
	void copyPerson(const char*, const char*);
	void delPerson();
};

// Unlike strncpyand strcpy_s, strcpy doesn't do any length 
// checking of the destination buffer which may cause stack overflow 
// allowing an attacker to execute malicious code if exploited or just 
// crach your application.
void Person::copyPerson(const char* nameStr, const char* ucnStr) {
	name = new char[strlen(nameStr) + 1];
	strcpy(name, nameStr);

	ucn = new char[strlen(ucnStr) + 1];
	strcpy(ucn, ucnStr);
}

void Person::delPerson() {
	delete[] name;
	delete[] ucn;
}

Person::Person(const char* nameStr, const char* ucnStr) {
	copyPerson(nameStr, ucnStr);
}

Person::~Person() {
	delPerson();
}

Person::Person(Person const& p) {
	copyPerson(p.name, p.ucn);
}

Person& Person::operator=(Person const& p) {
	if (this != &p) {
		delPerson();
		copyPerson(p.name, p.ucn);
	}
	return *this;
}

void Person::print() const {
	std::cout << "Name: " << name << std::endl;
	std::cout << "UCN: " << ucn << std::endl;
}



// Клас за студент
// Държи информация за факултетен номер и адрес
class Student : public Person {
public:
	Student(const char* = "", const char* = "", const char* = "", const char* = "");
	~Student();
	Student(Student const&);
	Student& operator=(Student const&);
	
	// Член-функция за извеждане
	void print() const;
private:
	char* facNumb; // факултетен номер
	char* addr;    // адрес
	
	// Помощни член-функции за копиране и изтриване
	void copyStudent(const char*, const char*);
	void delStudent();
};

void Student::copyStudent(const char* fNumb, const char* addrStr) {
	facNumb = new char[strlen(fNumb) + 1];
	strcpy(facNumb, fNumb);

	addr = new char[strlen(addrStr) + 1];
	strcpy(addr, addrStr);
}

void Student::delStudent() {
	delete[] facNumb;
	delete[] addr;
}

Student::Student(const char* nameStr, const char* ucnStr, const char* fNumb, const char* addrStr) : Person(nameStr, ucnStr) {
	copyStudent(fNumb, addrStr);
}

Student::~Student() {
	delStudent();
}

Student::Student(Student const& st) : Person(st) {
	copyStudent(st.facNumb, st.addr);
}

Student& Student::operator=(Student const& st) {
	if (this != &st) {
		Person::operator=(st);
		delStudent();
		copyStudent(st.facNumb, st.addr);
	}
	return *this;
}

void Student::print() const {
	Person::print();
	std::cout << "Fac. nomer: " << facNumb << std::endl;
	std::cout << "Address: " << addr << std::endl;
}





// Клас за работещ студент в платена форма на обучение
// Държи информация за такса и месторабота
class PStudent : public Student {
public:
	PStudent(const char* = "", const char* = "", const char* = "", const char* = "", double = 0, const char* = "");
	~PStudent();
	PStudent(PStudent const&);
	PStudent& operator=(PStudent const&);
	
	// Член-функция за извеждане
	void print() const;
private:
	double fee;      // Такса
	char* workplace; // Месторабота

	// Помощни член-функции за копиране и изтриване
	void copyPStudent(double, const char*);
	void delPStudent();
};

void PStudent::copyPStudent(double feeData, const char* workplaceStr) {
	fee = feeData;
	workplace = new char[strlen(workplaceStr) + 1];
	
	strcpy(workplace, workplaceStr);
}

void PStudent::delPStudent() {
	delete[] workplace;
}

PStudent::PStudent(const char* nameStr, const char* ucnStr, const char* fNumb, const char* addrStr, double feeData, const char* workplaceStr)
	: Student(nameStr, ucnStr, fNumb, addrStr) {
	copyPStudent(feeData, workplaceStr);
}

PStudent::~PStudent() {
	delPStudent();
}

PStudent::PStudent(PStudent const& ps) : Student(ps) {
	copyPStudent(ps.fee, ps.workplace);
}

PStudent& PStudent::operator=(PStudent const& ps) {
	if (this != &ps) {
		Student::operator=(ps);
	
		delPStudent();
		copyPStudent(ps.fee, ps.workplace);
	}
	return *this;
}

void PStudent::print() const {
	Student::print();
	std::cout << "Fee: " << fee << std::endl;
	std::cout << "Workplace: " << workplace << std::endl;
}

int main() {
	// Тестване на йерархията
}
