
#include<iostream>
#include <vector>
#include <string>
using namespace std;

class StudentManager {
private:
    static StudentManager* instance;
    vector<string> students;

    // Private constructor
    StudentManager() {
        cout << "A new StudentManager object has been created." << endl;
    }

public:
static StudentManager* getInstance() {
        if (instance == nullptr) {
            instance = new StudentManager();
        }
        return instance;
    }

    void addStudent(const string& name) {
        students.push_back(name);
        cout << "Added student: " << name << endl;
    }

    void removeStudent(const string& name) {
        for (auto it = students.begin(); it != students.end(); ++it) {
            if (*it == name) {
                cout << "Removed student: " << name << endl;
                students.erase(it);
                return;
            }
        }
    }

    void displayStudents() {
        if (students.empty()) {
            cout << "No students to display." << endl;
            return;
        }
        cout << "List of students:" << endl;
        for (const auto& student : students) {
            cout << student << endl;
        }
    }
};

StudentManager* StudentManager::instance = nullptr;

int main() {
    StudentManager* obj1 = StudentManager::getInstance();
    StudentManager* obj2 = StudentManager::getInstance();

    obj1->addStudent("Biva");
    obj2->addStudent("Rayna");
    obj2->addStudent("Lamisha"); 

    obj1->displayStudents();

    obj2->removeStudent("Rayna");
    obj1->displayStudents(); 

    cout << "\nAre mgr1 and mgr2 the same instance? "
         << (obj1 == obj2 ? "Yes" : "No") << endl;

    return 0;
}
