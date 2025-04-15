#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include <algorithm>

using namespace std;

// Component Interface
class UniversityMember {
public:
    virtual void showDetails() const = 0;
    virtual ~UniversityMember() {}
};

// Leaf: Professor
class Professor : public UniversityMember {
private:
    string name;
    string subject;
public:
    Professor(const string& name, const string& subject)
        : name(name), subject(subject) {}

    void showDetails() const override {
        cout << "Professor: " << name << ", Subject: " << subject << endl;
    }
};

// Leaf: Course
class Course : public UniversityMember {
private:
    string courseName;
public:
    Course(const string& courseName)
        : courseName(courseName) {}

    void showDetails() const override {
        cout << "Course: " << courseName << endl;
    }
};

// Composite: Department
class Department : public UniversityMember {
private:
    string departmentName;
    vector<shared_ptr<UniversityMember>> members;
public:
    Department(const string& departmentName)
        : departmentName(departmentName) {}

    void addMember(shared_ptr<UniversityMember> member) {
        members.push_back(member);
    }

    void removeMember(shared_ptr<UniversityMember> member) {
        members.erase(remove(members.begin(), members.end(), member), members.end());
    }

    void showDetails() const override {
        cout << "Department: " << departmentName << endl;
        for (const auto& member : members) {
            member->showDetails();
        }
    }
};

// Client Code
int main() {
    // Create Professors
    shared_ptr<UniversityMember> prof1 = make_shared<Professor>("Dr. Rahman", "Mathematics");
    shared_ptr<UniversityMember> prof2 = make_shared<Professor>("Dr. Karim", "Physics");

    // Create Courses
    shared_ptr<UniversityMember> course1 = make_shared<Course>("Calculus");
    shared_ptr<UniversityMember> course2 = make_shared<Course>("Quantum Mechanics");

    // Create Departments
    shared_ptr<UniversityMember> mathDept = make_shared<Department>("Mathematics Department");
    dynamic_pointer_cast<Department>(mathDept)->addMember(prof1);
    dynamic_pointer_cast<Department>(mathDept)->addMember(course1);

    shared_ptr<UniversityMember> physicsDept = make_shared<Department>("Physics Department");
    dynamic_pointer_cast<Department>(physicsDept)->addMember(prof2);
    dynamic_pointer_cast<Department>(physicsDept)->addMember(course2);

    // Create Faculty
    shared_ptr<Department> scienceFaculty = make_shared<Department>("Faculty of Science");
    scienceFaculty->addMember(mathDept);
    scienceFaculty->addMember(physicsDept);

    // Display the structure
    cout << "University Structure:" << endl;
    scienceFaculty->showDetails();

    return 0;
}
