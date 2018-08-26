#include "LetterFrequencyList.h"

LetterFrequencyList::LetterFrequencyList() : HeadPtr(new LetterNode('-', 0, nullptr)) {
	cout << "From constructor.\n";
}

bool LetterFrequencyList::contains(char ltr) {
	LetterNode * current = HeadPtr->Next; 
	while (current->Next != nullptr) {
		if (current->letter == ltr) {
			return true; 
		}
		current = current->Next; 
	}
	return false; 
}

void LetterFrequencyList::copy(const LetterFrequencyList & Other){
	LetterNode * current = Other.HeadPtr->Next; 
	LetterNode * iterator = HeadPtr = new LetterNode('-', 0, nullptr); 
	while (current != nullptr) {
		iterator->Next = new LetterNode(current->letter, current->frequency, nullptr);
		current = current->Next; 
		iterator = iterator->Next; 
	}
}
LetterFrequencyList::~LetterFrequencyList() {
	destroy(); 
	cout << "From destructor.\n";
}
void LetterFrequencyList::destroy() {
	LetterNode * current = HeadPtr; 
	while (current != nullptr) {
		LetterNode * temp = current; 
		current = current->Next; 
		delete temp; 
	}
}
void LetterFrequencyList::insert(char ltr, size_t freq, LetterNode * front, LetterNode * back){
	HeadPtr->Next = new LetterNode(ltr, freq, nullptr);
	if(HeadPtr->Next == front) {	
		HeadPtr->Next = new LetterNode(ltr, freq, current);
	}else if(back->Next == nullptr) {
		front->Next = new LetterNode(ltr, freq, nullptr);
	}else if {
		front->Next = new LetterNode(ltr, freq, back);
	}
}
void LetterFrequencyList::insertInOrder(char ltr) {
	if (contains(ltr)) {
		LetterNode * current = HeadPtr->Next; 
		while (current->letter != ltr){
			current = current->Next; 
		}
		int f = current->frequency;
		f = f + 1;
		current->frequency = f; 
	}else{
		LetterNode * current = HeadPtr->Next; 
		while (current->letter > ltr) {
			current = current->Next; 
		}
		insert(ltr, 1, current, current->Next);
		if (current == HeadPtr->Next){
			cout << "insert at head\n";
			insert(ltr, 1); 
		}else if (current == nullptr) {
			cout << "insert at end\n";
			current->Next = new LetterNode(ltr, 1, nullptr);
		}else {
			cout << "insert in middle\n";
			LetterNode * nodeBehind = current->Next;
			current->Next = new LetterNode(ltr, 1, nodeBehind);
		}
	}
}
LetterFrequencyList::LetterFrequencyList(const LetterFrequencyList & Other){
	if (this == &Other){
		cout << "Cannot self copy.\n";
		exit(0);
	}
	copy(Other); 
}
LetterFrequencyList & LetterFrequencyList::operator = (const LetterFrequencyList & Other){
	if (this == &Other){
		return *this; 
	}
	destroy(); 
	copy(Other); 
}
const string LetterFrequencyList::toString(){
	if (HeadPtr->Next != nullptr){
		string text = "";
		LetterNode * iterator = HeadPtr->Next;
		while (iterator != nullptr) {
			text += iterator->toString(); 
			iterator = iterator->Next; 
		}
		return text;
	}else{
		return "Nothing in list.\n";
	}
}
