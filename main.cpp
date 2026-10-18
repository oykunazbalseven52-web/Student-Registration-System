#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

class Student
{
public:
    int number;
    std::string name;
    std::string surname;
};

int main()
{
    std::vector<Student> students;
    int choice;
    do
    {
        std::cout << "\n--- STUDENT REGISTRATION ---\n";
        std::cout << "1. Add Student\n";
        std::cout << "2. List Students\n";
        std::cout << "3. Sort Students\n";
        std::cout << "4. Delete Student\n";
        std::cout << "5. Insert Student\n";
        std::cout << "6. Search Student\n";
        std::cout << "0. Exit\n";

        std::cout << "Enter your choice: ";
        std::cin >> choice;

        if (choice == 1)
        {
            Student s;
            std::cout << "Student number: ";
            std::cin >> s.number;

            std::cout << "Student name: ";
            std::cin >> s.name;

            std::cout << "Student surname: ";
            std::cin >> s.surname;

            students.push_back(s);
        }

        if (choice == 2)
        {
            if (students.empty())
            {
                std::cout << "No students found!\n";
            }
            else
            {
                for (int i = 0; i < students.size(); i++)
                {
                    std::cout << "Number: " << students[i].number
                              << " Name: " << students[i].name
                              << " Surname: " << students[i].surname
                              << "\n";
                }
            }
        }

        if (choice == 3)
        {
            int sortChoice;

            std::cout << "1.Sort by Number\n";
            std::cout << "2.Sort by Name\n";
            std::cout << "3.Sort by Surname\n";
            std::cout << "Enter your choice: ";
            std::cin >> sortChoice;

            if (sortChoice == 1)
            {
                std::sort(students.begin(), students.end(),
                          [](const Student &a, const Student &b)
                          {
                              return a.number < b.number;
                          });
            }
            else if (sortChoice == 2)
            {
                std::sort(students.begin(), students.end(),
                          [](const Student &a, const Student &b)
                          {
                              return a.name < b.name;
                          });
            }
            else if (sortChoice == 3)
            {
                std::sort(students.begin(), students.end(),
                          [](const Student &a, const Student &b)
                          {
                              return a.surname < b.surname;
                          });
            }
            else
            {
                std::cout << "Invalid choice!\n";
            }
        }

        if (choice == 4)
        {
            int number;
            std::cout << "Student number: ";
            std::cin >> number;

            for (int i = 0; i < students.size(); i++)
            {
                if (students[i].number == number)
                {
                    students.erase(students.begin() + 1);

                    std::cout << "Student deleted!\n";
                    break;
                }
            }
        }

        if (choice == 5)
        {
            Student s;
            int position;

            std::cout << "Student number: ";
            std::cin >> s.number;

            std::cout << "Student name: ";
            std::cin >> s.name;

            std::cout << "Student surname: ";
            std::cin >> s.surname;

            std::cout << "Position: ";
            std::cin >> position;

            if (position >= 0 && position <= students.size())
            {
                students.insert(students.begin() + position, s);
                std::cout << "Student insterted!\n";
            }

            else
            {
                std::cout << "Invalid position!\n";
            }
        }

        if (choice == 6)
        {

            std::string search;

            std::cout << "Enter number, name or surname: ";
            std::cin >> search;

            for (int i = 0; i < students.size(); i++)
            {

                if (std::to_string(students[i].number).find(search) != std::string::npos ||
                    students[i].name.find(search) != std::string::npos ||
                    students[i].surname.find(search) != std::string::npos)
                {

                    std::cout << students[i].number << " "
                              << students[i].name << " "
                              << students[i].surname << "\n";
                }
            }
        }

    } while (choice != 0);

    return 0;
}
