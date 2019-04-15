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
	SpellChecker checker;
	checker.LoadDictionaryFile("dictionary.txt");
//	checker.PrintHashTable();
	checker.SpellCheckFile("mispelled.txt");
	return 0;
}
