//#include"course.h"
//class filehandler {
//public:
//    void writeStudentData(Student* students, int size) {
//        ofstream outFile("students.txt");
//
//        if (!outFile.is_open()) {
//            cout << "Error opening students.txt for writing." << endl;
//            return;
//        }
//        outFile << size << endl;;
//        for (int i = 0; i < size; ++i) {
//            outFile << students[i].name << endl
//                << students[i].roll_num << " "
//                << students[i].age << " "
//                << students[i].contact << " "
//                << students[i].totalcourses << "\n";
//
//            for (int j = 0; j < students[i].totalcourses; ++j) {
//                outFile << students[i].courses[j] << " "
//                    << students[i].numLectures[j] << " "
//                    << students[i].marks[j] << " ";
//
//                for (int k = 0; k < students[i].numLectures[j]; ++k) {
//                    outFile << students[i].attendance[j][k] << " ";
//                }
//                outFile << "\n";
//            }
//        }
//
//        outFile.close();
//    }
//
//    void writeCourseData(Course* courses, int size) {
//        ofstream outFile("courses.txt");
//
//        if (!outFile.is_open()) {
//            cout << "Error opening courses.txt for writing." << endl;
//            return;
//        }
//        outFile << size << endl;
//        for (int i = 0; i < size; ++i) {
//            outFile << courses[i].name << endl
//                << courses[i].code << " "
//                << courses[i].instructor << " "
//                << courses[i].credits << " "
//                << courses[i].capacity << " "
//                << courses[i].enrolledStudents << "\n";
//
//            for (int j = 0; j < courses[i].enrolledStudents; ++j) {
//                outFile << courses[i].students[j] << " ";
//            }
//            outFile << "\n";
//        }
//
//        outFile.close();
//    }
//
//    // Read data from files
//    void readStudentData(Student*& students, int& size) {
//        ifstream inFile("students.txt");
//
//        if (!inFile.is_open()) {
//            cout << "Error opening students.txt for reading." << endl;
//            return;
//        }
//
//        inFile >> size;
//
//        students = new Student[size];
//
//        for (int i = 0; i < size; ++i) {
//            getline(inFile, students[i].name);
//            inFile >> students[i].roll_num
//                >> students[i].age
//                >> students[i].contact
//                >> students[i].totalcourses;
//
//            students[i].courses = new string[students[i].totalcourses];
//            students[i].numLectures = new int[students[i].totalcourses];
//            students[i].attendance = new bool* [students[i].totalcourses];
//            students[i].marks = new string[students[i].totalcourses];
//
//            for (int j = 0; j < students[i].totalcourses; ++j) {
//                inFile >> students[i].courses[j]
//                    >> students[i].numLectures[j]
//                    >> students[i].marks[j];
//
//                students[i].attendance[j] = new bool[students[i].numLectures[j]];
//
//                for (int k = 0; k < students[i].numLectures[j]; ++k) {
//                    inFile >> students[i].attendance[j][k];
//                }
//            }
//        }
//
//        inFile.close();
//    }
//
//    void readCourseData(Course*& courses, int& size) {
//        ifstream inFile("courses.txt");
//
//        if (!inFile.is_open()) {
//            cout << "Error opening courses.txt for reading." << endl;
//            return;
//        }
//
//        inFile >> size;
//
//        courses = new Course[size];
//
//        for (int i = 0; i < size; ++i) {
//            getline(inFile, courses[i].name);
//            inFile >> courses[i].code
//                >> courses[i].instructor
//                >> courses[i].credits
//                >> courses[i].capacity
//                >> courses[i].enrolledStudents;
//
//            courses[i].students = new string[courses[i].enrolledStudents];
//
//            for (int j = 0; j < courses[i].enrolledStudents; ++j) {
//                inFile >> courses[i].students[j];
//            }
//        }
//
//        inFile.close();
//    }
//};