#pragma once
#ifndef LETTERFREQUENCYLIST_H
#define LETTERFREQUENCYLIST_H
#include "LetterNode.h"

struct LetterFrequencyList{
private:
	bool contains(char ltr);
public:
	LetterNode * HeadPtr;
	LetterFrequencyList(); 
	~LetterFrequencyList(); 
	void copy(const LetterFrequencyList & Other);
	void destroy(); //deletes the whole list
	void insert(char ltr, size_t freq, LetterNode * position);
	void insertInOrder(char ltr); 
	LetterFrequencyList(const LetterFrequencyList & Other);
	LetterFrequencyList & operator = (const LetterFrequencyList & Other);
	const string toString();
};
#endif
