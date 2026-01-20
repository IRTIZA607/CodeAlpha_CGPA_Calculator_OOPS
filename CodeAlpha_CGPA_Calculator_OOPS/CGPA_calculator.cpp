#include <iostream>
#include <vector> // For using the vector container to store Course objects
using namespace std;

// Class representing a single course with grade and credit hours
class Course
{
private:
    char grade;
    int credit_hours;

public:
    // Constructor to initialize a Course object with grade and credit hours
    Course(char g, int c)
    {
        grade = g;
        credit_hours = c;
    }

    // Returns the credit hours of the course
    int get_credit()
    {
        return credit_hours;
    }

    // Returns the grade points based on the grade (A=10, B=8, C=6, D=4, F=0)
    int get_gradepoints()
    {
        switch (grade)
        {
        case 'A':
            return 10;
            break;
        case 'B':
            return 8;
            break;
        case 'C':
            return 6;
            break;
        case 'D':
            return 4;
            break;
        case 'F':
            return 0;
            break;

        default:
            return 0; // Default case for invalid grades
            break;
        }
    }

    // Calculates and returns the total points for the course (grade points * credit hours)
    int get_totalpoints()
    {
        return get_gradepoints() * credit_hours;
    }
};

// Class representing a student who can have multiple courses
class Student
{
private:
    vector<Course> courses; // Vector to store all courses taken by the student

public:
    // Adds a course to the student's list of courses
    void add_course(Course &c)
    {
        courses.push_back(c);
    }

    // Calculates and returns the total credit hours across all courses
    int get_TotalCredits()
    {
        int sum = 0;
        for (int i = 0; i < courses.size(); i++)
        {
            sum += courses[i].get_credit();
        }
        return sum;
    }

    // Calculates and returns the total grade points across all courses
    int get_Totalgradepoints()
    {
        int sum = 0;
        for (int i = 0; i < courses.size(); i++)
        {
            sum += courses[i].get_totalpoints();
        }
        return sum;
    }

    // Calculates and returns the CGPA (Cumulative Grade Point Average)
    double CGPA_calculator()
    {
        return (double)get_Totalgradepoints() / get_TotalCredits();
    }
};

int main()
{
    Student s; // Create a Student object to manage courses and calculate CGPA
    int number_of_courses;
    char grade;
    int credit;

    do
    {
        cout << "Enter number of courses: ";
        cin >> number_of_courses;

        if (number_of_courses <= 0)
            cout << "Invalid input! Number of courses must be greater than 0.\n";

    } while (number_of_courses <= 0);

    // Input course details
    for (int i = 1; i <= number_of_courses; i++)
    {
        cout << "\nCourse " << i << endl;

        // Grade validation
        do
        {
            cout << "Enter Grade (A/B/C/D/F): ";
            cin >> grade;

            if (grade != 'A' && grade != 'B' && grade != 'C' &&
                grade != 'D' && grade != 'F')
            {
                cout << "Invalid grade! Please enter A, B, C, D, or F.\n";
            }

        } while (grade != 'A' && grade != 'B' && grade != 'C' &&
                 grade != 'D' && grade != 'F');

        // Credit hour validation
        do
        {
            cout << "Enter Credit Hours: ";
            cin >> credit;

            if (credit <= 0)
                cout << "Invalid credit hours! Must be greater than 0.\n";

        } while (credit <= 0);

        Course c(grade, credit);
        s.add_course(c);
    }
    // Output the total credits, total grade points, and final CGPA
    cout << "\nTotal Credits: " << s.get_TotalCredits() << endl;
    cout << "Total Grade Points: " << s.get_Totalgradepoints() << endl;
    cout << "Final CGPA: " << s.CGPA_calculator() << endl;

    return 0;
}