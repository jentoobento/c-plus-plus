#include "LetterNode.h"

LetterNode::LetterNode(char ch, int freq, LetterNode * ptr) : letter(ch), frequency(freq), Next(ptr){}

const string LetterNode::toString(){
	string text = "";
	text += "Letter ";
	text += letter;
	text += " occurred: ";
	text += to_string(frequency);
	text += " times.\n";
	return text;
}
