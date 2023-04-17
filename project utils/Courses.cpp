#include <iostream> 
#include <regex>

#include "Courses.h"

/* contruct and destruct */
Courses::Courses() {
    root = nullptr;
}

Courses::~Courses() {
    destroyRecursive(root);
}

/* order traversals */
void Courses::InOrder() {
	inOrder(root);
}

void Courses::PreOrder() {
	preOrder(root);
}

void Courses::PostOrder() {
	postOrder(root);
}

/* insert */
void Courses::Insert(Course course) {
	if(root==nullptr) {
        root = new Node(course);
    } else {
    this->addNode(root, course);
    }
}

/* remove */
void Courses::Remove(std::string courseId) {
    this->removeNode(root, courseId);
}

/* search */
Course Courses::Search(std::string courseId) {
	transform(courseId.begin(), courseId.end(), courseId.begin(), ::toupper);
	Node *curr = root;
	while (curr != nullptr) {
		if (curr->course.getCourseId().compare(courseId) == 0) {
			return curr->course;
		} else if (courseId.compare(curr->course.getCourseId()) < 0) {
			curr = curr->left;
		} else {
			curr = curr->right;
		}
	}
	Course course;
	return course;
}

/* add node */
void Courses::addNode(Node *node, Course course) {
	if (node != nullptr && (node->course.getCourseId().compare(course.getCourseId()) > 0)) {
		if (node->left == nullptr) {
			node->left = new Node(course);
			return;
		} else {
			this->addNode(node->left, course);
		}
	} else if (node != nullptr && (node->course.getCourseId().compare(course.getCourseId()) < 0)) {
		if (node->right == nullptr) {
			node->right = new Node(course);
			return;
		} else {
			this->addNode(node->right, course);
		}
	}
}

/* remove node */
Node *Courses::removeNode(Node *node, const std::string courseId) {
	if (node == nullptr) {
		return node;
	} else if (courseId.compare(node->course.getCourseId()) < 0) {
		node->left = removeNode(node->left, courseId);
	} else if (courseId.compare(node->course.getCourseId()) > 0) {
		node->right = removeNode(node->right, courseId);
	} else {
		if (node->left == nullptr && node->right == nullptr) {
			delete node;
			node = nullptr;
		} else if (node->left != nullptr && node->right == nullptr) {
			Node *temp = node;
			node = node->left;
			delete temp;
			temp = nullptr;
		} else if (node->left == nullptr && node->right != nullptr) {
			Node *temp = node;
			node = node->right;
			delete temp;
			temp = nullptr;
		} else {
			Node *temp = node;
			while (temp->left != nullptr) {
				temp = temp->left;
			}
			node->course = temp->course;
			node->right = removeNode(node->right, temp->course.getCourseId());
		}
	}
	return node;
}

/* in order */
void Courses::inOrder(Node *node) {
	if (node != nullptr) {
		inOrder(node->left);
		std::cout << node->course.getCourseId() << ", " << node->course.getCourseName() << std::endl;
		inOrder(node->right);
	}
}

/* pre order */
void Courses::preOrder(Node *node) {
	if (node != nullptr) {
		std::cout << node->course.getCourseId() << ", " << node->course.getCourseName() << std::endl;
		preOrder(node->left);
		preOrder(node->right);
	}
}

/* post order */
void Courses::postOrder(Node *node) {
	if (node != nullptr) {
		postOrder(node->left);
		postOrder(node->right);
		std::cout << node->course.getCourseId() << ", " << node->course.getCourseName() << std::endl;
	}
}

/* destory the recursion */
void Courses::destroyRecursive(Node *node) {
	if (node != nullptr) {
		destroyRecursive(node->left);
		destroyRecursive(node->right);
		delete node;
		node = nullptr;
	}
}