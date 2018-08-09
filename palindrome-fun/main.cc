#include "Palindrome.h"

int main(){
	cout << "\tPalindrome Tester\n"
	  << "============================================\n";
	cout << "How many times do you want to do the test? ";
	int numOfStrings;
	cin >> numOfStrings;

	for(int x = 0; x < numOfStrings; x++){
		cout << "Enter a word or sentence:" << endl;
		string input;
		cin.sync();
		getline(cin, input);
		Palindrome P(input); //create palindrome object with user input
		for(int x = 0; x < input.length(); x++){
			P.enqueue(input[x]);
		}
		while(!P.queueIsEmpty()){
			P.dequeue();
		}
		cout << "Converted Input: " << P.getConvertedInput() << endl;
		P.makeStack();
		P.findReverse();
		cout << "Reversed Input:  " << P.getReverseInput() << endl;
		P.isPalindrome();
	}
	cout << "Goodbye!\n";
return 0;
}
