/* main file */

#include <iostream>
#include <fstream>
#include <sstream>

#include <regex>

#include "project utils/Courses.h"

/*course display*/
void displayCourse(Course course) {
    std::vector<std::string> prereqs = course.getPrereqs();
    std::string prereqs;

    if(prereqs.size() == 1) {
        prereqs = course.getPrereqs()[0];
    } else if (prereqs.size() > 1) {
        for (int i = 0; i < prereqs.size() - 1; i++){
            prereqs += prereqs[i] + ", ";
        }
        prereqs += prereqs.back();
    } else {
        prereqs = "None.";
    }
    /*print details*/
    std::cout << course.getCourseId() << ", " course.getCourseName() << std::endl;
    std::cout << "Prerequisites: " << prereqs << std::endl;
}

/*course load*/
void loadCourses(const std::string& inputFilePath, Courses* coursesTree) {
    std::cout << "Loading..." <<inputFilePath << std::endl;
    std::ifstream file(inputFilePath);
    std::string current;
    /*try catch for errors*/
    try {
        while (std::getline(file, current)) {
            std::stringstream streamline (current);
            std::string word, id, name;
            std::vector<std::string> prereqs;
            int index = 0;
            while() {
                getline(streamline, word, ",");
                word = std:regex_replace(word, std::regex(R"(\r\n|\r|\n)"),"");
                if(index == 0) {
                    id = word;
                } else if(index == 1) {
                    name = word;
                } else {
                    prereqs.push_back(word);
                }
                index++;
            }
            Course course = Course(id, name, prereqs);
            courseTree->Insert(course);
        }
    } catch (std::ifstream::failure& e) {
        std:cerr << e.what() << std::endl;
    }
    file.close();
}

/*main*/
/*menu inputs and outputs from sample doc*/
int main() {    
    Course course;
    Courses *courseTree;
    courseTree = new Courses();
    std::string inputPath, courseKey;

    std::cout << "Welcome to the course planner." << std::endl << std::endl;

    int userInput = 0;
    /*while loop and switch to traverse menu*/
    while (userInput != 9) {
        std::cout << "1. Load Data Structure." << std::endl;
        std::cout << "2. Print Course List." << std::endl;
        std::cout << "3. Print Course." << std::endl;
        std::cout << "9. Exit." << std::endl << std::endl;
        std::cout << "What would you like to do?";
        std::cin >> userInput;

        switch(userInput) {
            case 1:
                std::cout << "Enter Path: ";
                std::cin >> inputPath;
                loadCourses(inputPath, courseTree);
                break;
            case 2:
                std::cout << "Here is a sample schedule:" << std::endl << std::endl;
                courseTree->InOrder();
                break;
            case 3:
                std::cout << "What course do you want to know about?";
                std::cin >> courseKey;
                course = courseTree->Search(courseKey);
                if (!course.getCourseId().empty()) {
					displayCourse(course);
				} else {
					std::cout << "Course " << courseKey << " not found." << std::endl;
				}
                break;
            case 9:
                std::cout << "Thank you for using the course planner!" << std::endl;
                break;
            default:
                std::cout << userInput << " is not a valid option." << std::endl;
                std::cin.clear();
                break;
        }
        std::cout << std::endl;
    }
    return 0;
}