#include <iostream>
#include <string>

using namespace std;

class Student {
protected:
    string lastName;
    string firstName;
    string groupNumber;
    double grade1;
    double grade2;
    double grade3;

public:
    Student(string last, string first, string group, double g1, double g2, double g3) {
        lastName = last;
        firstName = first;
        groupNumber = group;
        grade1 = g1;
        grade2 = g2;
        grade3 = g3;
    }

    void displayInfo() {
        cout << "Surname: " << lastName << endl;
        cout << "Name: " << firstName << endl;
        cout << "Number of group: " << groupNumber << endl;
        cout << "Marks: " << grade1 << ", " << grade2 << ", " << grade3 << endl;
    }

    double calculateAverage() {
        return (grade1 + grade2 + grade3) / 3.0;
    }
};

class ScienceStudent : public Student {
private:
    string major;
    int researchScore;

public:
    ScienceStudent(string last, string first, string group, double g1, double g2, double g3, string _major, int _researchScore)
        : Student(last, first, group, g1, g2, g3), major(_major), researchScore(_researchScore) {}

    void displayInfo() {
        Student::displayInfo();
        cout << "Major: " << major << endl;
        cout << "Research Score: " << researchScore << endl;
    }

};

int main() {
    ScienceStudent student1("Didula", "Victor", "KN-11", 79, 88, 90, "Physics", 95);

    student1.displayInfo();
    cout << "Average score: " << student1.calculateAverage() << endl;

    return 0;
}
