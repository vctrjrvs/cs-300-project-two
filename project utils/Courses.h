#ifndef PROJECT_TWO_COURSES_H
#define PROJECT_TWO_COURSES_H
#include <string>
#include <vector>
#include "Course.h"

struct Node {
	Course course;
	Node *left;
	Node *right;

	Node() {
		left = nullptr;
		right = nullptr;
	}

	Node(Course newCourse) :
			Node() {
		course = newCourse;
	}
}

class Courses {
private:
	Node* root;
	void addNode(Node *node, Course course);
	Node *removeNode(Node *node, std::string courseId);
	void inOrder(Node *node);
	void preOrder(Node *node);
	void postOrder(Node *node);
    void destroyRecursive(Node *node);
public:
	Courses();
	virtual ~Courses();
	void InOrder();
	void PreOrder();
    void PostOrder();
	void Insert(Course course);
	void Remove(std::string courseId);
	Course Search(std::string courseId);
}

#endif