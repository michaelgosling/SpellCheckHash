//
//  main.cpp
//  SpellCheckHash
//
//  Created by Michael Gosling on 2019-04-10.
//  Copyright © 2019 Michael Gosling. All rights reserved.
//

#include <iostream>
#include "SpellChecker.hpp"

int main(int argc, const char * argv[]) {
	// create new checker
	SpellChecker checker;
	// load the dictionary file
	checker.LoadDictionaryFile("dictionary.txt");
	// print the hash table
	checker.PrintHashTable();
	// spell check the mispelled file.
	checker.SpellCheckFile("mispelled.txt");
	return 0;
}
