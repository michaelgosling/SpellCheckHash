//
//  MyHashTable.hpp
//  SpellCheckHash
//
//  Created by Michael Gosling on 2019-04-10.
//  Copyright © 2019 Michael Gosling. All rights reserved.
//

#ifndef MyHashTable_hpp
#define MyHashTable_hpp

#include <stdio.h>
#include <string>

/**
 * Linked List Node
 */
struct Node {
	std::string data = "";
	struct Node *next = nullptr;
};

/**
 * Custom Hash Table
 */
class MyHashTable {
private:
	int SIZE;
	Node *values;
	int hash(std::string);
public:
	MyHashTable();
	void Initialize(const int size);
	void Add(std::string str);
	bool Match(std::string str);
	void PrintTable();
};

#endif /* MyHashTable_hpp */
