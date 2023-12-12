//#include"student.h"
//class Course {
//public:
//    string code;
//    string name;
//    string instructor;
//    int credits;
//    int capacity;
//    string* students;
//    int enrolledStudents;
//    // Constructor
//    Course() : students(nullptr), enrolledStudents(0) {}
//    Course(string courseCode, string courseName, string courseInstructor, int courseCredits, int courseCapacity)
//        : code(courseCode), name(courseName), instructor(courseInstructor), credits(courseCredits), capacity(courseCapacity), students(nullptr), enrolledStudents(0) {}
//    // Destructor
//    ~Course() {
//        delete[] students;
//    }
//
//    void addStudent(RenderWindow& window, Font& font, Student& student) {
//        // Check if there is space for another student
//        if (enrolledStudents < capacity) {
//            // Allocate memory for the new array of students
//            string* newStudents = new string[enrolledStudents + 1];
//            // Copy existing students to the new array
//            for (int i = 0; i < enrolledStudents; ++i) {
//                newStudents[i] = students[i];
//            }
//            // Add the new student
//            newStudents[enrolledStudents] = student.name;
//            // Delete the old array
//            delete[] students;
//            // Update the pointer to the new array
//            students = newStudents;
//            // Increment the count of enrolled students
//            ++enrolledStudents;
//            student.enroll(window, font, name);
//            displayText("Student " + student.name + " added to the course " + name, font, window);
//        }
//        else {
//            displayText("Course is full. Cannot add more students.", font, window);
//        }
//    }
//    void removeStudent(RenderWindow& window, Font& font, Student& student) {
//        // Find the index of the student in the array
//        int studentIndex = -1;
//        for (int i = 0; i < enrolledStudents; ++i) {
//            if (students[i] == student.name) {
//                studentIndex = i;
//                i = enrolledStudents;
//            }
//        }
//        // Check if the student is found
//        if (studentIndex != -1) {
//            // Allocate memory for the new array of students
//            string* newStudents = new string[enrolledStudents - 1];
//            // Copy students before the removed student
//            for (int j = 0, i = 0; i < studentIndex; ++i) {
//                if (j != studentIndex) {
//                    newStudents[j] = students[i];
//                    j++;
//                }
//            }
//            // Delete the old array
//            delete[] students;
//            // Update the pointer to the new array
//            students = newStudents;
//            // Decrement the count of enrolled students
//            --enrolledStudents;
//            student.withdraw(window, font, name);
//            displayText("Student with roll number " + student.roll_num + " removed from the course " + name, font, window);
//        }
//        else {
//            displayText("Student not found in the course.", font, window);
//        }
//    }
//    void displayStudents(RenderWindow& window, Font& font) {
//        window.clear(Color::Blue);
//        // Display the list of students
//        for (int i = 0; i < enrolledStudents; ++i) {
//            Text studentName("Name: " + students[i], font, 24);
//            studentName.setFillColor(Color::Green);
//            studentName.setPosition(10, 10 + i * 30);
//            // Draw the text object
//            window.draw(studentName);
//            window.display();
//        }
//        sleep(seconds(1));
//    }
//};