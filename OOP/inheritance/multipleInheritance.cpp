// "She had inherited the beauty of her mother"
#include <iostream>
using namespace std;

//base class
class Person {
	protected:
		string phoneNumber;

	public:
		string _name;
		int _YoB;

		Person(string name, int year) {
			this->_name = name;
			this->_YoB = year;
		}

		void print() {
			cout << "Last name:\t " << this->_name << endl;
			cout << "Year of birth:\t " <<  this->_YoB << endl;
		}
};

//derived class
class Student : public Person {
	public:
		string _university;

		//will call default constructor of base class automatically
		Student(string name, int year, string university) : Person(name, year) {
			this->_university = university;
		}

		void print(){
			Person::print();
			cout << "University:\t " << this->_university << endl;
		}
};

int main(){
	Student* Luan = new Student("Luan Pham", 2015, "Bach Khoa University");

	Luan->print();

	return 0;
}
