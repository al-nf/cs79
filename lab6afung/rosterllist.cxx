/*
 * CSEN 79 Lab
 * <YOUR NAME HERER>
 */
#include <string>
#include <iostream>
#include <iomanip>
#include "person.h"
#include "roster.h"
#include "rosterllist.h"

namespace csen79 {
	// STUDENT WORKS
	// IMPLEMENT ALL THESE FUNCTIONS
	// These are code only to make the program compile.  They do not work!
	RosterLList::RosterLList() {
		head = nullptr;
	}
	RosterLList::~RosterLList() {
		delete head;
	}
	RosterLList::Node::Node(){
		next = nullptr;
	}
	RosterLList::Node::Node(T &t){
		data = t;
		next = nullptr;
	}
	RosterLList::Node::~Node(){
		delete this->next;
	}
	RosterLList::iterator RosterLList::begin(){
		return RosterLList::iterator(head); 
	}
	RosterLList::iterator RosterLList::end(){
		return RosterLList::iterator(nullptr); 
	}
	bool RosterLList::insert(T &rec) {
		Node* n = new Node(rec);
		n->next = head;
		head = n;
		return true;
	}
	void RosterLList::erase(Person::ID_t id) {
		Node* n = head;
		Node* p = nullptr;
		while (n != nullptr) {
			if (n->data.getID() == id) {
				p->next = n->next;
				n->next = nullptr;
				delete n;
				break;
			}
			p = n;
			n = n->next;
		}
	}

	RosterLList::iterator::iterator(Node *t) {
		ptr = t;
	}
	bool RosterLList::iterator::operator !=(const iterator &rhs) {
		if (ptr != rhs.ptr) {
			return true;
		}
		return false;
	}

	Roster::T &RosterLList::iterator::operator *() { 
		return ptr->data; 
	}
	RosterLList::iterator &RosterLList::iterator::operator++() {
		ptr = ptr->next;
		return *this; 
	}
}
