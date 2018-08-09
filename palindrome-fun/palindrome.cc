#include "Palindrome.h"

Palindrome::Palindrome(string ip, int ft, int re, int ct, int tp) : input(ip), front(0), rear(-1), count(0), top(-1){}

void Palindrome::enqueue(char a){
    if(queueIsFull()){
        cout << "Queue is full. Item not added.\n";
    }else{
        rear = (rear + 1) % MAX; 
        queue[rear] = a; 
        count++; 
    }
}

void Palindrome::dequeue(){
    if(queueIsEmpty()) {
        cout << "Queue is empty.\n";
    } else{
        convert(queue[front]); 
        front = (front + 1) % MAX; 
        count--; 
    }
}

void Palindrome::convert(char s){
	if (isalpha(s)) {
         convertedInput += toupper(s); 
    }
}

void Palindrome::makeStack(){
    for(int x = 0; x < convertedInput.length(); x++){
        push(convertedInput[x]); 
    }
}

void Palindrome::findReverse(){
    while(!stackIsEmpty()){
        reverseInput += stack[top]; 
        pop(); 
    }
}

void Palindrome::isPalindrome(){
    cout << input << endl;
    if(convertedInput == reverseInput){
        cout << "This is a Palindrome!\n";
    }else {
        cout << "This is not a Palindrome!\n";
    }
}

void Palindrome::push(char a){
    if(!stackIsFull()){
        top++; 
        stack[top] = a; 
    }
}

void Palindrome::pop(){
    if(!stackIsEmpty()) {
        top--;
    }
}

bool Palindrome::queueIsEmpty(){
    return (count == 0);
}
bool Palindrome::queueIsFull(){
    return (count == MAX);
}
bool Palindrome::stackIsEmpty(){
    return (top == -1);
}
bool Palindrome::stackIsFull(){
    return (top == MAX -1);
}
string Palindrome::getConvertedInput(){
    return convertedInput;
}
string Palindrome::getReverseInput(){
    return reverseInput;
}
