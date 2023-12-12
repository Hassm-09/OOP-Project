//#include "filehandler.h"
//class System {
//public:
//    Student* students;
//    int noofstudents = 0;
//    Course* courses;
//    int noofcourses = 0;
//    filehandler file;
//    // Constructor
//    System() {}
//    void alreadyEnrollStudent(RenderWindow& window, Font& font) {
//        if (noofstudents != 0) {
//            /*  window.clear(Color::Blue);*/
//            for (int i = 0; i < noofstudents; ++i) {
//                Text studentName(students[i].name, font, 24);
//                studentName.setFillColor(Color::Green);
//                studentName.setPosition(10, 10 + i * 30);
//                studentName.setFont(font);
//                // Draw the text object
//                window.draw(studentName);
//                // Display the contents of the window
//                window.display();
//            }
//            sleep(seconds(1));
//        }
//        else {
//            displayText("No student enrolled", font, window);
//        }
//    }
//    void markAttendance(RenderWindow& window, Font& font) {
//        string studentName, courseName;
//        // Ask for student name
//        displayText("Enter the student name:", font, window);
//        studentName = getstring(window, font);
//        // Find the student with the given name
//        int studentIndex = -1;
//        for (int i = 0; i < noofstudents; ++i) {
//            if (students[i].name == studentName) {
//                studentIndex = i;
//                i = noofstudents;
//            }
//        }
//        if (studentIndex == -1) {
//            displayText("Student not found: " + studentName, font, window);
//            return;
//        }
//        // Ask for the course name
//        displayText("Enter the course name to mark attendance:", font, window);
//        courseName = getstring(window, font);
//        // Display attendance for the specified course
//        students[studentIndex].markAttendance(window, font, courseName);
//    }
//    void addStudent(RenderWindow& window, Font& font) {
//        string name, roll_num, contact;
//        string age;
//        displayText("Enter student name:", font, window);
//        name = getstring(window, font);
//        displayText("Enter student roll number:", font, window);
//        roll_num = getstring(window, font);
//        displayText("Enter student age:", font, window);
//        age = getstring(window, font);
//        displayText("Enter student contact:", font, window);
//        contact = getstring(window, font);
//        Student newStudent(name, roll_num, age, contact);
//        Student* newStudents = new Student[noofstudents + 1];
//        for (int i = 0; i < noofstudents; ++i) {
//            newStudents[i] = students[i];
//        }
//        newStudents[noofstudents] = newStudent;
//        delete[] students;
//        students = newStudents;
//        ++noofstudents;
//        displayText("Student added successfully!", font, window);
//    }
//
//    void displayAttendanceBySubject(RenderWindow& window, Font& font) {
//        string studentName, courseName;
//        // Ask for student name
//        displayText("Enter the student name:", font, window);
//        studentName = getstring(window, font);
//        // Find the student with the given name
//        int studentIndex = -1;
//        for (int i = 0; i < noofstudents; ++i) {
//            if (students[i].name == studentName) {
//                studentIndex = i;
//                i = noofstudents;
//            }
//        }
//        if (studentIndex == -1) {
//            displayText("Student not found: " + studentName, font, window);
//            return;
//        }
//        // Ask for the course name
//        displayText("Enter the course name to display attendance:", font, window);
//        courseName = getstring(window, font);
//        // Display attendance for the specified course
//        students[studentIndex].displayAttendanceBySubject(window, font, courseName);
//    }
//    void registerCourse(RenderWindow& window, Font& font) {
//        string code, name, instructor;
//        int credits, capacity;
//        displayText("Enter course code:", font, window);
//        code = getstring(window, font);
//        displayText("Enter course name:", font, window);
//        name = getstring(window, font);
//        displayText("Enter course instructor:", font, window);
//        instructor = getstring(window, font);
//        displayText("Enter course credits:", font, window);
//        credits = keypressed(window, font);
//        displayText("Enter course capacity:", font, window);
//        capacity = stoi(getstring(window, font));
//        Course newCourse(code, name, instructor, credits, capacity);
//        // Resize the array and add the new course
//        Course* newCourses = new Course[noofcourses + 1];
//        for (int i = 0; i < noofcourses; ++i) {
//            newCourses[i] = courses[i];
//        }
//        newCourses[noofcourses] = newCourse;
//        delete[] courses;
//        courses = newCourses;
//        ++noofcourses;
//        displayText("Course added successfully!", font, window);
//    }
//    void enrollorwithdraw(RenderWindow& window, Font& font, int option)
//    {
//        string code;
//        displayText("Enter course code:", font, window);
//        code = getstring(window, font);
//        int courseIndex = -1;
//        for (int i = 0; i < noofcourses; ++i) {
//            if (courses[i].code == code) {
//                courseIndex = i;
//                i = noofcourses;
//            }
//        }
//        if (courseIndex != -1) {
//            string name;
//            displayText("Enter Student name:", font, window);
//            name = getstring(window, font);
//            int studentIndex = -1;
//            for (int i = 0; i < noofstudents; ++i) {
//                if (students[i].name == name) {
//                    studentIndex = i;
//                    i = noofstudents;
//                }
//            }
//            if (studentIndex != -1) {
//                if (option == 1)
//                    courses[courseIndex].addStudent(window, font, students[studentIndex]);
//                else
//                    courses[courseIndex].removeStudent(window, font, students[studentIndex]);
//            }
//            else {
//                displayText("Student not found", font, window);
//            }
//        }
//        else {
//            displayText("Course Not found ", font, window);
//        }
//    }
//    // Function to remove a course
//    void removeCourse(RenderWindow& window, Font& font) {
//        string code;
//        displayText("Enter course code:", font, window);
//        code = getstring(window, font);
//        int courseIndex = -1;
//        for (int i = 0; i < noofcourses; ++i) {
//            if (courses[i].code == code) {
//                courseIndex = i;
//                i = noofcourses;
//            }
//        }
//        if (courseIndex != -1) {
//            // Remove the course from the courses array
//            Course* newCourses = new Course[noofcourses - 1];
//            for (int i = 0, j = 0; i < noofcourses; ++i) {
//                if (i != courseIndex) {
//                    newCourses[j] = courses[i];
//                    ++j;
//                }
//            }
//            delete[] courses;
//            courses = newCourses;
//            // Decrement the total number of courses
//            --noofcourses;
//            displayText("Course removed successfully", font, window);
//        }
//        else {
//            displayText("Course not found", font, window);
//        }
//    }
//    void removestudent(RenderWindow& window, Font& font) {
//        string name;
//        displayText("Enter student name  to remove: ", font, window);
//        name = getstring(window, font);
//        int studentIndex = -1;
//        for (int i = 0; i < noofstudents; ++i) {
//            if (students[i].name == name) {
//                studentIndex = i;
//                i = noofstudents;
//            }
//        }
//        if (studentIndex != -1) {
//            // Remove the course from the courses array
//            Student* newstudent = new Student[noofstudents - 1];
//            for (int i = 0, j = 0; i < noofstudents; ++i) {
//                if (i != studentIndex) {
//                    newstudent[j] = students[i];
//                    ++j;
//                }
//            }
//            delete[] students;
//            students = newstudent;
//            // Decrement the total number of courses
//            --noofstudents;
//            displayText("Student removed successfully!", font, window);
//        }
//        else {
//            displayText("Student not found.", font, window);
//        }
//    }
//    // Function to edit student details
//    void editStudentDetails(RenderWindow& window, Font& font) {
//        string nameToEdit;
//        displayText("Enter student name to edit details: ", font, window);
//        nameToEdit = getstring(window, font);
//        int studentIndex = -1;
//        for (int i = 0; i < noofstudents; ++i) {
//            if (students[i].name == nameToEdit) {
//                studentIndex = i;
//                i = noofstudents;
//            }
//        }
//        if (studentIndex != -1) {
//            displayText("Select the information to modify:\n 1. Name\n2. Roll Number\n3. Age\n4. Contact", font, window);
//            int choice;
//            choice = keypressed(window, font);
//
//            if (choice == 1) {
//                displayText("Enter new name for student: ", font, window);
//                students[studentIndex].name = getstring(window, font);
//                displayText(" updated successfully!", font, window);
//            }
//            else if (choice == 2) {
//                displayText("Enter new roll number for student: ", font, window);
//                students[studentIndex].roll_num = getstring(window, font);
//                displayText(" updated successfully!", font, window);
//            }
//            else if (choice == 3) {
//                displayText("Enter new age for student: ", font, window);
//                students[studentIndex].age = stoi(getstring(window, font));
//                displayText(" updated successfully!", font, window);
//            }
//            else if (choice == 4) {
//                displayText("Enter new contact for student: ", font, window);
//                students[studentIndex].contact = getstring(window, font);
//                displayText(" updated successfully!", font, window);
//            }
//            else {
//                displayText("Invalid choice", font, window);
//            }
//        }
//        else {
//            displayText("Student not found.", font, window);
//        }
//    }
//    void displayMarks(RenderWindow& window, Font& font) {
//        string studentName, courseName;
//
//        // Ask for student name
//        displayText("Enter the student name: ", font, window);
//        studentName = getstring(window, font);;
//
//        // Find the student with the given name
//        int studentIndex = -1;
//        for (int i = 0; i < noofstudents; ++i) {
//            if (students[i].name == studentName) {
//                studentIndex = i;
//                i = noofstudents;
//            }
//        }
//        if (studentIndex == -1) {
//            displayText("Student not found.", font, window);
//            return;
//        }
//        // Ask for the course name
//        displayText("Enter the course name to display marks: ", font, window);
//        courseName = getstring(window, font);;
//        // Find the course index
//        int courseIndex = -1;
//        for (int i = 0; i < students[studentIndex].totalcourses; ++i) {
//            if (students[studentIndex].courses[i] == courseName) {
//                courseIndex = i;
//                i = students[studentIndex].totalcourses;
//            }
//        }
//        if (courseIndex == -1) {
//            displayText("Course not found: " + courseName, font, window);
//            return;
//        }
//        // Display marks for the specified course
//        string marks = students[studentIndex].marks[courseIndex];
//        if (marks[0] == -1) {
//            displayText("Marks for " + courseName + " have not been marked yet.", font, window);
//        }
//        else {
//            displayText("Marks for " + courseName + ": " + marks, font, window);
//        }
//    }
//    void assignMarks(RenderWindow& window, Font& font) {
//        string studentName, courseName;
//        // Ask for student name
//        displayText("Enter the student name: ", font, window);
//        studentName = getstring(window, font);
//        // Find the student with the given name
//        int studentIndex = -1;
//        for (int i = 0; i < noofstudents; ++i) {
//            if (students[i].name == studentName) {
//                studentIndex = i;
//                i + noofstudents;
//            }
//        }
//        if (studentIndex == -1) {
//            displayText("Student not found: " + studentName, font, window);
//            return;
//        }
//        // Ask for the course name
//        displayText("Enter the course name to assign marks: ", font, window);
//        courseName = getstring(window, font);
//        // Find the course index
//        int courseIndex = -1;
//        for (int i = 0; i < students[studentIndex].totalcourses; ++i) {
//            if (students[studentIndex].courses[i] == courseName) {
//                courseIndex = i;
//                break;
//            }
//        }
//        if (courseIndex == -1) {
//            displayText("Course not found: " + courseName, font, window);
//            return;
//        }
//        // Ask for the marks (ensure marks are non-negative)
//        int courseMarks;
//        do {
//            displayText("Enter  marks for " + courseName + ": ", font, window);
//            courseMarks = stoi(getstring(window, font));
//
//            if (courseMarks < 0) {
//                displayText("Invalid input. Marks cannot be negative.", font, window);
//            }
//
//        } while (courseMarks < 0);
//
//        // Update the marks for the specified course
//        students[studentIndex].marks[courseIndex] = courseMarks;
//
//        displayText("Marks assigned for " + courseName + ": " + to_string(courseMarks), font, window);
//    }
//    void displayAvailableCourses(RenderWindow& window, Font& font) {
//        window.clear(Color::Blue);
//        if (noofcourses == 0) {
//            displayText("No courses available.", font, window);
//            return;
//        }
//        for (int i = 0; i < noofcourses; ++i) {
//            Text courseText;
//            courseText.setFont(font);
//            courseText.setCharacterSize(18);
//            courseText.setPosition(10, 50 + i * 120);
//
//            courseText.setString(
//                "Course Code: " + courses[i].code +
//                "\nCourse Name: " + courses[i].name +
//                "\nInstructor: " + courses[i].instructor +
//                "\nCredits: " + to_string(courses[i].credits) +
//                "\nCapacity: " + to_string(courses[i].capacity) +
//                "\nEnrolled Students: " + to_string(courses[i].enrolledStudents) +
//                "\n------------------------"
//            );
//
//            window.draw(courseText);
//            window.display();
//        }
//        sleep(seconds(1));
//    }
//
//    // Function to display the main menu
//    void option1(RenderWindow& window, Font& font) {
//        Text title("Option 1", font, 24);
//        title.setFillColor(Color::Green);
//        title.setPosition(10, 10);
//
//        Text option1("1- Display already enrolled student", font, 24);
//        option1.setFillColor(Color::Green);
//        option1.setPosition(10, 40);
//        Text option2("2- Add a student", font, 24);
//        option2.setFillColor(Color::Green);
//        option2.setPosition(10, 70);
//        Text option3("3- Remove a student", font, 24);
//        option3.setFillColor(Color::Green);
//        option3.setPosition(10, 100);
//        Text option4("4- Edit student details", font, 24);
//        option4.setFillColor(Color::Green);
//        option4.setPosition(10, 130);
//        Text option5("5- Back", font, 24);
//        option5.setFillColor(Color::Green);
//        option5.setPosition(10, 160);
//        // Clear the window
//        window.clear(Color::Blue);
//        // Draw the text objects
//        window.draw(title);
//        window.draw(option1);
//        window.draw(option2);
//        window.draw(option3);
//        window.draw(option4);
//        window.draw(option5);
//        // Display the contents of the window
//        window.display();
//    }
//
//    void option2(RenderWindow& window, Font& font) {
//        Text title("Option 2", font, 24);
//        title.setFillColor(Color::Green);
//        title.setPosition(10, 10);
//        Text option1("1- Available course", font, 24);
//        option1.setFillColor(Color::Green);
//        option1.setPosition(10, 40);
//        Text option2("2- Register course", font, 24);
//        option2.setFillColor(Color::Green);
//        option2.setPosition(10, 70);
//        Text option3("3- Back", font, 24);
//        option3.setFillColor(Color::Green);
//        option3.setPosition(10, 100);
//        // Clear the window
//        window.clear(Color::Blue);
//
//        // Draw the text objects
//        window.draw(title);
//        window.draw(option1);
//        window.draw(option2);
//        window.draw(option3);
//
//        // Display the contents of the window
//        window.display();
//    }
//
//    void option3(RenderWindow& window, Font& font) {
//        Text title("Option 3", font, 24);
//        title.setFillColor(Color::Green);
//        title.setPosition(10, 10);
//
//        Text option1("1- Display attendance", font, 24);
//        option1.setFillColor(Color::Green);
//        option1.setPosition(10, 40);
//
//        Text option2("2- Mark attendance", font, 24);
//        option2.setFillColor(Color::Green);
//        option2.setPosition(10, 70);
//
//        Text option3("3- Back", font, 24);
//        option3.setFillColor(Color::Green);
//        option3.setPosition(10, 100);
//
//        // Clear the window
//        window.clear(Color::Blue);
//
//        // Draw the text objects
//        window.draw(title);
//        window.draw(option1);
//        window.draw(option2);
//        window.draw(option3);
//
//        // Display the contents of the window
//        window.display();
//    }
//
//    void option4(RenderWindow& window, Font& font) {
//        Text title("Option 4", font, 24);
//        title.setFillColor(Color::Green);
//        title.setPosition(10, 10);
//        Text option1("1- Display Marks", font, 24);
//        option1.setFillColor(Color::Green);
//        option1.setPosition(10, 40);
//        Text option2("2- Assign Marks", font, 24);
//        option2.setFillColor(Color::Green);
//        option2.setPosition(10, 70);
//        Text option3("3- Back", font, 24);
//        option3.setFillColor(Color::Green);
//        option3.setPosition(10, 100);
//        // Clear the window
//        window.clear(Color::Blue);
//        // Draw the text objects
//        window.draw(title);
//        window.draw(option1);
//        window.draw(option2);
//        window.draw(option3);
//
//        // Display the contents of the window
//        window.display();
//    }
//
//    void option5(RenderWindow& window, Font& font) {
//        Text title("Option 5", font, 24);
//        title.setFillColor(Color::Green);
//        title.setPosition(10, 10);
//
//        Text option1("1- Enrolled course", font, 24);
//        option1.setFillColor(Color::Green);
//        option1.setPosition(10, 40);
//
//        Text option2("2- Drop a course", font, 24);
//        option2.setFillColor(Color::Green);
//        option2.setPosition(10, 70);
//
//        Text option3("3- Back", font, 24);
//        option3.setFillColor(Color::Green);
//        option3.setPosition(10, 100);
//
//        // Clear the window
//        window.clear(Color::Blue);
//
//        // Draw the text objects
//        window.draw(title);
//        window.draw(option1);
//        window.draw(option2);
//        window.draw(option3);
//
//        // Display the contents of the window
//        window.display();
//    }
//
//    void displayMainMenu(RenderWindow& window, Font& font) {
//        Text title("Main Menu", font, 24);
//        title.setFillColor(Color::Green);
//        title.setPosition(10, 10);
//
//        Text option1("1- Enroll a student", font, 24);
//        option1.setFillColor(Color::Green);
//        option1.setPosition(10, 40);
//
//        Text option2("2- Course Registration", font, 24);
//        option2.setFillColor(Color::Green);
//        option2.setPosition(10, 70);
//
//        Text option3("3- Attendance", font, 24);
//        option3.setFillColor(Color::Green);
//        option3.setPosition(10, 100);
//
//        Text option4("4- Marks", font, 24);
//        option4.setFillColor(Color::Green);
//        option4.setPosition(10, 130);
//
//        Text option5("5- Course Withdraw", font, 24);
//        option5.setFillColor(Color::Green);
//        option5.setPosition(10, 160);
//
//        Text option6("6- Exit", font, 24);
//        option6.setFillColor(Color::Green);
//        option6.setPosition(10, 190);
//
//        // Clear the window
//        window.clear(Color::Blue);
//
//        // Draw the text objects
//        window.draw(title);
//        window.draw(option1);
//        window.draw(option2);
//        window.draw(option3);
//        window.draw(option4);
//        window.draw(option5);
//        window.draw(option6);
//
//        // Display the contents of the window
//        window.display();
//    }
//
//    void runSystem() {
//        int choice = 0;
//        RenderWindow window(VideoMode(800, 600), "Flex");
//        Font font;
//        if (!font.loadFromFile("CotaneBeach.otf")) {
//            cout << "Error loading font file." << endl;
//            return;
//        }
//        file.readCourseData(courses, noofcourses);
//        file.readStudentData(students, noofstudents);
//        while (choice != 6) {
//            displayMainMenu(window, font);
//            choice = keypressed(window, font);
//            if (choice == 1) {
//                int studentChoice = 0;
//                do {
//                    option1(window, font);
//                    studentChoice = keypressed(window, font);
//                    if (studentChoice == 1) {
//                        alreadyEnrollStudent(window, font);
//                    }
//                    else if (studentChoice == 2) {
//                        addStudent(window, font);
//                    }
//                    else if (studentChoice == 3) {
//                        removestudent(window, font);
//                    }
//                    else if (studentChoice == 4) {
//                        editStudentDetails(window, font);
//                    }
//                    else if (studentChoice == 5) {
//                        displayText("Returning to the main menu.", font, window);
//                    }
//                    else {
//                        displayText("Invalid choice. Please try again.", font, window);
//                    }
//                    file.writeStudentData(students, noofstudents);
//                    file.writeCourseData(courses, noofcourses);
//                } while (studentChoice != 5);
//            }
//            else if (choice == 2) {
//                int courseChoice = 0;
//                do {
//                    option2(window, font);
//
//                    courseChoice = keypressed(window, font);
//
//                    if (courseChoice == 1) {
//                        displayAvailableCourses(window, font);
//                    }
//                    else if (courseChoice == 2) {
//                        registerCourse(window, font);
//                    }
//                    else if (courseChoice == 3) {
//                        displayText("Returning to the main menu.", font, window);
//                    }
//                    else {
//                        displayText("Invalid choice. Please try again.", font, window);
//                    }
//                    file.writeStudentData(students, noofstudents);
//                    file.writeCourseData(courses, noofcourses);
//                } while (courseChoice != 3);
//            }
//            else if (choice == 3) {
//                int attendanceChoice = 0;
//                do {
//                    option3(window, font);
//                    attendanceChoice = keypressed(window, font);;
//
//                    if (attendanceChoice == 1) {
//                        displayAttendanceBySubject(window, font);
//                    }
//                    else if (attendanceChoice == 2) {
//                        markAttendance(window, font);
//                    }
//                    else if (attendanceChoice == 3) {
//                        displayText("Returning to the main menu.", font, window);
//                    }
//                    else {
//                        displayText("Invalid choice. Please try again.", font, window);
//                    }
//                    file.writeStudentData(students, noofstudents);
//                    file.writeCourseData(courses, noofcourses);
//                } while (attendanceChoice != 3);
//            }
//            else if (choice == 4) {
//                int marksChoice = 0;
//                do {
//                    option4(window, font);
//                    cout << "Enter your choice: ";
//                    marksChoice == keypressed(window, font);;
//
//                    if (marksChoice == 1) {
//                        displayMarks(window, font);
//                    }
//                    else if (marksChoice == 2) {
//                        assignMarks(window, font);
//                    }
//                    else if (marksChoice == 3) {
//                        displayText("Returning to the main menu.", font, window);
//                    }
//                    else {
//                        displayText("Invalid choice. Please try again.", font, window);
//                    }
//                    file.writeStudentData(students, noofstudents);
//                    file.writeCourseData(courses, noofcourses);
//                } while (marksChoice != 3);
//            }
//            else if (choice == 5) {
//                int withdrawChoice = 0;
//                do {
//                    option5(window, font);
//                    cout << "Enter your choice: ";
//                    withdrawChoice = keypressed(window, font);;
//
//                    if (withdrawChoice == 1) {
//                        enrollorwithdraw(window, font, 1);
//                    }
//                    else if (withdrawChoice == 2) {
//                        enrollorwithdraw(window, font, 2);
//                    }
//                    else if (withdrawChoice == 3) {
//                        displayText("Returning to the main menu.", font, window);
//                    }
//                    else {
//                        displayText("Invalid choice. Please try again.", font, window);
//                    }
//                    file.writeStudentData(students, noofstudents);
//                    file.writeCourseData(courses, noofcourses);
//                } while (withdrawChoice != 3);
//            }
//            else if (choice != 6) {
//                displayText("Invalid choice. Please try again.", font, window);
//            }
//            window.display();
//        }
//    }
//    // Destructor
//    ~System() {
//        delete[] students;
//        delete[] courses;
//    }
//
//};