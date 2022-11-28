// LinkedList.cpp : Defines the exported functions for the DLL application.
//

// Comment to modify file for lab11

#include "LinkedList.h"
#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>
#include <sstream>

using namespace std;

// Comment conflict

ILinkedList::ILinkedList() : m_count(0)
{

}

Node::Node() : m_value(-1), m_next(nullptr)
{

}
Node::Node(int val) : m_value(val), m_next(nullptr)
{

}
Node::Node(int val, Node * nextNode) : m_value(val), m_next(nextNode)
{

}
void Node::setItem(const int& val)
{
	m_value = val;
}
void Node::setNext(Node* nextNodePtr)
{
	m_next = nextNodePtr;
}
int Node::getItem() const
{
	return m_value;
}
Node * Node::getNext() const
{
	return m_next;
}
Node::~Node()
{
	std::cout << "Deleting node with value " << m_value << std::endl;
	//TODO - hint, you can recursively handle this which would require some code
	// Otherwise you need to delete each node individuall in the owner of the Nodes (i.e. the LinkedList)
}

PointerBasedLinkedList::PointerBasedLinkedList() : ILinkedList(), m_head(nullptr)
{

}
/** Returns true  if list is empty, otherwise false */
bool PointerBasedLinkedList::isEmpty() const
{
	if(m_head == NULL){
		return true;
	}
	return false;
	//TODO
}
/** Adds a value to the LinkedList.  Return true if able to, otherwise false */
bool PointerBasedLinkedList::add(int val)
{	
	Node* newNode = new Node(val);
	Node* temp = m_head;
	if(m_head == nullptr){
		m_head = newNode;
		return true;
	}
	else{
		//traverse to end of list then add the node there
		while(temp->getNext()) temp = temp->getNext();
		temp->setNext(newNode);
		return true;
	}
	return false;
	//TODO
}
/** Remove a value to the LinkedList.  Return true if able to, otherwise false.
Will only remove one entry if there are multiple entries with the same value */
bool PointerBasedLinkedList::remove(int val) // needs heavy work
{
	if(m_head == nullptr) return false;

	Node * cur = m_head;
	Node * prev = nullptr;
	if(val == m_head->getItem()){
		Node* temp = m_head;
		m_head = m_head->getNext();
		delete temp;
		return true;
	}
	do{
		prev = cur;
		cur = cur->getNext();

		if(cur->getItem() == val){
			prev->setNext(cur->getNext());
			delete cur;
			return true;
		}				
	}while(cur->getNext());
	return false;
}

/** Remove  all elements from LinkedList */
void PointerBasedLinkedList::clear()
{
	Node * cur = nullptr;
	if (m_head == nullptr)	{
		return;
	}
	else {
		while(m_head != nullptr){
			cur = m_head;
			m_head = m_head->getNext();
			free(cur);
		}
	}
	return;
    //TODO
}
PointerBasedLinkedList::~PointerBasedLinkedList()
{
	//TODO - maybe not depending on how you implement Node::~Node
	delete m_head;
}

std::string PointerBasedLinkedList::toString() const
{
	string str = "";
	Node* buff = m_head;
	if(!buff){
		return str;
	}
	
	while(buff != nullptr){ // inf looping (adds the right values but never stops -- due to add function)
			if(str == ""){
				str += to_string(buff->getItem());
			}else{
				str += " " + to_string(buff->getItem());
			}
			buff = buff->getNext();
	}
    //TODO
	return str;
}

ArrayBasedLinkedList::ArrayBasedLinkedList() : ILinkedList()
{
    m_count = 0;
	// you got it for free :)
}

bool ArrayBasedLinkedList::isEmpty() const
{
	if (m_count <= 0){
		return true;
	}
	else {
		return false;
	}
	//TODO
}
bool ArrayBasedLinkedList::add(int val)
{	
	m_count++;
	if (m_count == 11) {
			m_count--;
			return false;
		}
	for (int i = 0; i < m_count; i++) {
		
		if (i == m_count - 1) {
			m_values[i] = val;
			return true;
		}
		
	};
	
	//TODO
	return false;
}
bool ArrayBasedLinkedList::remove(int val)
{
	for (int i = 0; i < m_count; i++){
		if (m_values[i] == val) {
			if (i != m_count - 1) {
				for(i;i < m_count-1; i++){
					m_values[i] = m_values[i+1];
				}
				m_values[i] = 0;
			}
			else {
				m_values[m_count - 1] = 0;
			}
			m_count--;
			return true;
		}
	}
	//TODO
	return false;
}
void ArrayBasedLinkedList::clear()
{
	for (int i = 0; i < m_count; i++) {
		m_values[i] = 0;
	}
	m_count = 0;
	//TODO
}
ArrayBasedLinkedList::~ArrayBasedLinkedList()
{

}

std::string ArrayBasedLinkedList::toString() const
{	
	string str = "";
	for (int i = 0; i < m_count; i++) {
		if (str == "") {
			str += to_string(m_values[i]);
			//cout << str << endl;
		} else {
			str += " " + to_string(m_values[i]);
			//cout << str << endl;
		}
	}

	//TODO
	return str;
}
