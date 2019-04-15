//
//  MyHashTable.cpp
//  SpellCheckHash
//
//  Created by Michael Gosling on 2019-04-10.
//  Copyright © 2019 Michael Gosling. All rights reserved.
//

#include "MyHashTable.hpp"
#include <iostream>
using namespace std;


MyHashTable::MyHashTable(){}

void MyHashTable::Initialize(const int size) {
	SIZE = size;
	values = new Node[size];
}

/**
 * Calculate hash address based on key string
 */
int MyHashTable::hash(string keyString){
	int sum;
	int address;

	sum = 0;
	int len = keyString.length();
	// cast each character of the string as
	// int to get ascii value
	for (auto i = 0; i < len; i++)
		sum += (int)keyString[i];

	// the modulus, or remainder, of integer division gives a result between
	// 0 and SIZE-1, perfect for an index
	address = sum % SIZE;

	return address;
}

/**
 * Add a string to the hash table
 */
void MyHashTable::Add(string str){
	// create a reference to the node at the hashed index
	Node *curr = &values[hash(str)];

	// go through the nodes until we find a nullptr on the next
	while (curr->next != nullptr) curr = curr->next;

	// if the current node's data is a blank string, set the current node to the str
	if (curr->data == ""){
		curr->data = str;
	} else {
		// otherwise set the next node to a new node and set that's data to the str
		curr->next = new Node;
		curr->next->data = str;
	}
}

/**
 * Check if given string matches anything in list
 */
bool MyHashTable::Match(std::string str){
	// get a reference to the node at the hashed index
	Node *curr = &values[hash(str)];
	// if the nodes data equals the string, return true
	// otherwise set current node to next node and check to see if it's null
	do {
		if (curr->data == str) return true;
		curr = curr->next;
	} while (curr != nullptr);

	// assume false if we didn't match
	return false;
}

/**
 * Print out the hash table
 */
void MyHashTable::PrintTable() {
	for (auto i = 0; i < SIZE; i++) {
		Node *curr = &values[i];
		bool breakLine = false;
		do {
			if (curr->data != "") {
				breakLine = true;
				cout << " [" << curr->data << "] ";
			}
			curr = curr->next;
		} while (curr != nullptr);
		if (breakLine) cout << endl;
	}
}
