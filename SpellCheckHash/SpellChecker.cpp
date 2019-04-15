//
//  SpellChecker.cpp
//  SpellCheckHash
//
//  Created by Michael Gosling on 2019-04-10.
//  Copyright © 2019 Michael Gosling. All rights reserved.
//

#include "SpellChecker.hpp"
#include <fstream>
#include <iostream>

using namespace std;

SpellChecker::SpellChecker() {}

/**
 * Load a dictionary file
 */
void SpellChecker::LoadDictionaryFile(string filePath){
	ifstream file;
	string line;
	int lineCount = 0;
	string fileWord;
	try {
		file.open(filePath);
		if (file.is_open()){
			// count lines
			while (getline(file, line))
				lineCount++;
			// init hash table based on line count
			hashDict->Initialize(lineCount);
			file.clear();
			file.seekg(0, ios::beg);
			// load words into dictionary hash
			while (getline(file, line))
				hashDict->Add(line);
			file.close();
		}
	} catch (exception e){
		cout << e.what() << endl;
	}
}

/**
 * Check a text file for mispelled words
 */
void SpellChecker::SpellCheckFile(string filePath) {
	cout << endl << "Mispelled words: " << endl;
	ifstream file;
	string fileWord;
	try {
		file.open(filePath);
		if (file.is_open()){
			// we read each word and iterate through the characters to remove
			// characters which aren't letters and convert them to lowercase
			// if the words length is longer than 0 and is spelled wrong,
			// print to the console
			while (file >> fileWord){
				string word;
				for (auto i : fileWord)
					if (isalpha(i) && !isspace(i)) word += tolower(i);
				if (word.length() > 0 && !hashDict->Match(word)) cout << word << endl;
			}
			file.close();
		}
	} catch (exception e) {
		cout << e.what() << endl;
	}
}

/**
 * Print out the SpellChecker's Hash Table
 */
void SpellChecker::PrintHashTable() {
	hashDict->PrintTable();
}
