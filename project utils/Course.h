#ifndef PROJECT_TWO_COURSE_H
#define PROJECT_TWO_COURSE_H
#include <string>
#include <vector>

class Course {
private:
    std::string courseId;
    std::string courseName;
    std::vector<std::string> coursePrereqs;

public:
    Course() = default;
    Course(std::string &id, std::string &name, std::vector<std::string> &prereqs);
    std::string getCourseId();
    std::string getCourseName();
    std::vector<std::string> getCoursePrereqs();
    std::string parseCourse();
}

#endif