#include "LetterFrequencyList.h"

int main(){
	cout << "Enter full path to file you wish to read from:\n";
	string input;
	cin.sync();
	getline(cin, input);
	ifstream inputfile(input);
	if (!inputfile){
		cout << "Cannot open file.\n";
	}else{
		LetterFrequencyList L; 
		char letter; 
		while (inputfile.peek() != EOF) 
		{
			inputfile.get(letter); 
			if (isalpha(letter)) {
				letter = toupper(letter); 
				L.insertInOrder(letter); 
			}
		}
		cout << L.toString();
	}
	return 0;
}
