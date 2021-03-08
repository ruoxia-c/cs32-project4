#include "StudentTextEditor.h"
#include "Undo.h"
#include <string>
#include <vector>
#include <iostream>
#include <fstream>

TextEditor* createTextEditor(Undo* un)
{
	return new StudentTextEditor(un);
}

StudentTextEditor::StudentTextEditor(Undo* undo)
 : TextEditor(undo) {
	// TODO
     editCol = 0;
     editRow = 0;
     currentRow = fileText.begin();
}

StudentTextEditor::~StudentTextEditor()
{
	// TODO
    reset();
}

bool StudentTextEditor::load(std::string file) {
    std::ifstream infile(file);
    if (!infile )
        return false;
    reset();
    std::string s;
    while (getline(infile, s))
    {
        if(s[s.size()-1] == '\r'){
            s.erase(s.size()-1);
        }
        fileText.push_back(s);
    }
	return true;  // TODO
}

bool StudentTextEditor::save(std::string file) {
    std::ofstream outfile(file);   // outfile is a name of our choosing.
    if ( ! outfile ){
        return false;
    }
    std::list<std::string>::iterator it;
    it = fileText.begin();
    while(it !=fileText.end())
    {
        outfile << (*it) <<std::endl;
    }
	return true;  // TODO
}

void StudentTextEditor::reset() {
	// TODO
    fileText.clear();
    editCol = 0;
    editRow = 0;
}

void StudentTextEditor::move(Dir dir) {
	// TODO
    switch (dir) {
        case Dir::UP:
            if(editRow > 0){
                editRow--;
                currentRow--;
            }
            break;
        case Dir::DOWN:
            if(editRow != fileText.size()-1){
                editRow++;
                currentRow++;
            }
            break;
        case Dir::LEFT:
            if(editCol > 0)
                editCol--;
            else{
                if(editRow!=0){
                    editRow--;
                    currentRow--;
                    editCol = (*currentRow).size();
                }
            }
            break;
        case Dir::RIGHT:
            if(editCol < (*currentRow).size())
                editCol++;
            else{
                if(editRow!=fileText.size()-1){
                    editRow++;
                    currentRow++;
                    editCol = 0;
                }
            }
            break;
        case Dir::HOME:
            editCol = 0;
            break;
        case Dir::END:
            editCol = (*currentRow).size();
            break;
        default:
            break;
    }
}

void StudentTextEditor::del() {
	// TODO
}

void StudentTextEditor::backspace() {
	// TODO
}

void StudentTextEditor::insert(char ch) {
	// TODO
}

void StudentTextEditor::enter() {
	// TODO
}

void StudentTextEditor::getPos(int& row, int& col) const {
	row = editRow;
    col = editCol; // TODO
}

int StudentTextEditor::getLines(int startRow, int numRows, std::vector<std::string>& lines) const {
    if(startRow < 0 || numRows < 0 || startRow > fileText.size()){
        return -1;}
    lines.clear();
    //iterator points to the startRow
    std::list<std::string>::iterator it = currentRow;
    for(int i = editRow; i<startRow;i++){
        it ++;
    }
    //add to lines
    int i=0;
    for(; i<numRows;i++){
        if(it == fileText.end())
            break;
        lines.push_back(*it);
        it++;
    }
	return i; // TODO
}

void StudentTextEditor::undo() {
	// TODO
}
