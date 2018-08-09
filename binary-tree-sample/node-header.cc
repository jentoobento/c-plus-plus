#pragma once
#ifndef LETTERNODE_H
#define LETTERNODE_H
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;
struct LetterNode{
	int frequency; 
	char letter;
	LetterNode * Next;
	LetterNode(char letter = '-', int frequency = 0, LetterNode * Next = nullptr);
	const string toString();
};
#endif
