//#include "sfmlfunctions.h"
//class Student {
//public:
//    string name;
//    string roll_num;
//    string age;
//    string contact;
//    string* courses;
//    int totalcourses = 0;
//    int* numLectures;  // Array to store the number of lectures for each course
//    bool** attendance;  // 2D array to store attendance for each course
//    string* marks;
//    // Constructor
//    Student() {}
//    Student(string n, string r, string A, string c) :name(n), roll_num(r), age(A), contact(c) {}
//
//    // Destructor
//    ~Student() {
//        delete[] courses;
//    }
//    void displayAttendanceBySubject(RenderWindow& window, Font& font, string& course) {
//        // Find the index of the course
//        int courseIndex = -1;
//        for (int i = 0; i < totalcourses; ++i) {
//            if (courses[i] == course) {
//                courseIndex = i;
//                i = totalcourses;
//            }
//        }
//        // Check if the course is found
//        if (courseIndex == -1) {
//            displayText("Course not found: " + course, font, window);
//            return;
//        }
//        displayText("Attendance for course " + course + ":", font, window);
//        showAttendance(window, font, attendance[courseIndex], numLectures[courseIndex]);
//    }
//    void enroll(RenderWindow& window, Font& font, string& course) {
//        for (int i = 0; i < totalcourses; ++i) {
//            if (courses[i] == course) {
//                displayText("Already enrolled in the course: " + course, font, window);
//                return;
//            }
//        }
//        // Enroll in the course
//        string* newCourses = new string[totalcourses + 1];
//        int* newNumLectures = new int[totalcourses + 1];
//        string* newMarks = new string[totalcourses + 1];
//        bool** newAttendance = new bool* [totalcourses + 1];
//        for (int i = 0; i < totalcourses; ++i) {
//            newCourses[i] = courses[i];
//            newNumLectures[i] = numLectures[i];
//            newAttendance[i] = attendance[i];
//            newMarks[i] = marks[i];
//        }
//        newCourses[totalcourses] = course;
//        newNumLectures[totalcourses] = 0;
//        newMarks[totalcourses][0] = -1;
//        // Delete the old arrays
//        delete[] courses;
//        delete[] marks;
//        delete[] numLectures;
//        delete[] attendance;
//        // Update pointers to the new arrays
//        courses = newCourses;
//        numLectures = newNumLectures;
//        attendance = newAttendance;
//        marks = newMarks;
//        totalcourses++;
//        displayText("Enrolled in the course: " + course, font, window);
//    }
//
//    void markAttendance(RenderWindow& window, Font& font, string& course) {
//        // Find the index of the course
//        int courseIndex = -1;
//        for (int i = 0; i < totalcourses; ++i) {
//            if (courses[i] == course) {
//                courseIndex = i;
//                i = totalcourses;
//            }
//        }
//        // Check if the course is found
//        if (courseIndex == -1) {
//            displayText("Course not found: " + course, font, window);
//            return;
//        }
//        int choice = 0;
//        do {
//            // Ask the user for action
//            Text actionPrompt("Do you want to:", font, 24);
//            actionPrompt.setFillColor(Color::Green);
//            actionPrompt.setPosition(10, 10);
//            Text option1("1. Change attendance of existing lecture (absent to present or present to absent)", font, 24);
//            option1.setFillColor(Color::Green);
//            option1.setPosition(10, 40);
//            Text option2("2. Add a new lecture and mark attendance \n 3-Go back ", font, 24);
//            option2.setFillColor(Color::Green);
//            option2.setPosition(10, 70);
//            // Clear the window
//            window.clear(Color::Blue);
//            // Draw the text objects
//            window.draw(actionPrompt);
//            window.draw(option1);
//            window.draw(option2);
//            // Display the contents of the window
//            window.display();
//            choice = keypressed(window, font);
//            if (choice == 1) {
//                int lectureNumber = -1;
//                displayText("Enter lecture Number", font, window);
//                showAttendance(window, font, attendance[courseIndex], numLectures[courseIndex]);
//                lectureNumber = keypressed(window, font);
//                // Check if the lectureNumber is within bounds
//                if (lectureNumber <= 0 || lectureNumber > numLectures[courseIndex]) {
//                    displayText("Invalid lecture number", font, window);
//                    return;
//                }
//                // Change attendance of existing lecture
//                attendance[courseIndex][lectureNumber - 1] = !attendance[courseIndex][lectureNumber - 1];
//                showAttendance(window, font, attendance[courseIndex], numLectures[courseIndex]);
//            }
//            else if (choice == 2) {
//                // Add a new lecture and mark attendance
//                bool* newAttendance = new bool[numLectures[courseIndex] + 1];
//                for (int i = 0; i < numLectures[courseIndex]; ++i) {
//                    newAttendance[i] = attendance[courseIndex][i];
//                }
//                // Delete the old attendance array
//                delete[] attendance[courseIndex];
//                // Update the attendance pointer to the new array
//                attendance[courseIndex] = newAttendance;
//                int option = -1;
//                displayText("New lecture added for course: \n press 1 to Mark Absent and press any number key to mark present for new lecture", font, window);
//                option = keypressed(window, font);
//                if (option == 1)
//                    attendance[courseIndex][numLectures[courseIndex]] = false;
//                else
//                    attendance[courseIndex][numLectures[courseIndex]] = true;
//                // Increment the number of lectures
//                ++numLectures[courseIndex];
//            }
//            else {
//                displayText("Invalid choice", font, window);
//            }
//        } while (choice != 3);
//    }
//    void withdraw(RenderWindow& window, Font& font, string& course) {
//        int courseIndex = -1;
//        for (int i = 0; i < totalcourses; ++i) {
//            if (courses[i] == course) {
//                courseIndex = i;
//                i = totalcourses;
//            }
//        }
//        if (courseIndex == -1) {
//            displayText("Course not found: " + course, font, window);
//            return;
//        }
//        // Remove the course from the courses array
//        string* newCourses = new string[totalcourses - 1];
//        int* newNumLectures = new int[totalcourses - 1];
//        string* newMarks = new string[totalcourses - 1];
//        bool** newAttendance = new bool* [totalcourses - 1];
//        for (int i = 0, j = 0; i < totalcourses; ++i) {
//            if (i != courseIndex) {
//                newCourses[j] = courses[i];
//                newNumLectures[j] = numLectures[i];
//                newAttendance[j] = attendance[i];
//                newMarks[j] = marks[i];
//                ++j;
//            }
//        }
//        // Update pointers to the new arrays
//        delete[] courses;
//        delete[] numLectures;
//        delete[] attendance;
//        delete[] marks;
//        courses = newCourses;
//        numLectures = newNumLectures;
//        attendance = newAttendance;
//        marks = newMarks;
//        // Decrement the total number of courses
//        --totalcourses;
//        displayText("Withdrawn from the course: " + course, font, window);
//    }
//    void assignMarks(RenderWindow& window, Font& font, string& course) {
//        int courseIndex = -1;
//        for (int i = 0; i < totalcourses; ++i) {
//            if (courses[i] == course) {
//                courseIndex = i;
//                i = totalcourses;
//            }
//        }
//        if (courseIndex == -1) {
//            displayText("Course not found: " + course, font, window);
//            return;
//        }
//        // Ask for the marks
//        string courseMarks;
//        displayText("Enter marks for the course " + course + ": ", font, window);
//        courseMarks = getstring(window, font);
//        // Update the marks for the course
//        marks[courseIndex] = courseMarks;
//        displayText("Marks assigned for the course " + course + ": " + courseMarks, font, window);
//    }
//    void showAttendance(RenderWindow& window, Font& font, bool* attendance, int size) {
//        Text attendanceText("Attendance: ", font, 24);
//        attendanceText.setFillColor(Color::Green);
//        attendanceText.setPosition(10, 40);
//        string attendanceStr = "Attendance: ";
//        for (int i = 0; i < size; ++i) {
//            if (attendance[i]) {
//                attendanceStr += "Present ";
//            }
//            else {
//                attendanceStr += "Absent ";
//            }
//        }
//        Text attendanceDetails(attendanceStr, font, 24);
//        attendanceDetails.setFillColor(Color::Green);
//        attendanceDetails.setPosition(10, 70);
//        // Draw the text objects
//        window.draw(attendanceText);
//        window.draw(attendanceDetails);
//        // Display the contents of the window
//        window.display();
//    }
//};