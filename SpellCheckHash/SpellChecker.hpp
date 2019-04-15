//
//  SpellChecker.hpp
//  SpellCheckHash
//
//  Created by Michael Gosling on 2019-04-10.
//  Copyright © 2019 Michael Gosling. All rights reserved.
//

#ifndef SpellChecker_hpp
#define SpellChecker_hpp

#include <stdio.h>
#include <string>
#include "MyHashTable.hpp"

class SpellChecker {
private:
	MyHashTable *hashDict = new MyHashTable();
public:
	SpellChecker();
	void LoadDictionaryFile(std::string filePath);
	void SpellCheckFile(std::string filePath);
};

#endif /* SpellChecker_hpp */
