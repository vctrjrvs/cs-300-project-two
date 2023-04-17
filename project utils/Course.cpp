#include "Course.h"

/*Constructor*/
Course::Course(std::string &id, std::string &name std::vector<std::string> &prereqs) {
    this->courseId = id;
    this->courseName = name;
    this->coursePrereqs = prereqs;
}

/*getters*/
std::string Course::getCourseId() {
    return this->courseId;
}

std::string Course::getCourseName() {
    return this->courseName;
}

std::string Course::getCoursePrereqs() {
    return this->coursePrereqs;
}

/*parse to string*/
std::string Course::parseCourse() {
    return this->courseId + ", " + this->courseName;
}