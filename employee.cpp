#include <iostream>
#include <string>
#include <vector>

// Class to represent an employee
class Employee {
public:
    std::string name;
    int age;
    int productivityScore;

    Employee(const std::string& name, int age)
        : name(name), age(age), productivityScore(0) {}
};

// AI Expert System class
class ExpertSystem {
public:
    void evaluateEmployeePerformance(Employee& employee) {
        std::cout << "Evaluating employee performance:\n";
        std::cout << "Employee name: " << employee.name << '\n';
        std::cout << "Age: " << employee.age << '\n';

        // Add AI-based logic to assess the employee's performance and calculate a productivity score
        int score = assessPerformance(employee);

        employee.productivityScore = score;

        std::cout << "Productivity score: " << employee.productivityScore << '\n';
    }

private:
    int assessPerformance(const Employee& employee) {
        // Placeholder logic, replace with actual AI algorithms
        int baseScore = 100;
        int ageScore = (employee.age > 30) ? 10 : 5;

        return baseScore + ageScore;
    }
};

int main() {
    ExpertSystem expertSystem;

    // Create an employee
    Employee employee("John Doe", 35);

    // Evaluate the employee's performance
    expertSystem.evaluateEmployeePerformance(employee);

    return 0;
}
