#include "StudentSpellCheck.h"
#include <string>
#include <vector>
#include <iostream>
#include <fstream>

SpellCheck* createSpellCheck()
{
	return new StudentSpellCheck;
}

StudentSpellCheck::~StudentSpellCheck() {
	// TODO
}

bool StudentSpellCheck::load(std::string dictionaryFile) {
    std::ifstream infile(dictionaryFile);
    if (!infile )
        return false;
    std::string s;
    while (getline(infile, s))
    {
        if(s[s.size()-1] == '\r'){
            s.erase(s.size()-1);
        }
        dict.insert(s);
    }
    return true;  // TODO
}

bool StudentSpellCheck::spellCheck(std::string word, int max_suggestions, std::vector<std::string>& suggestions) {
	return false; // TODO
}

void StudentSpellCheck::spellCheckLine(const std::string& line, std::vector<SpellCheck::Position>& problems) {
	// TODO
}
