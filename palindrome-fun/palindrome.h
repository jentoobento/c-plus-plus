#pragma once
#ifndef PALINDROME_H
#define PALINDROME_H
#include <iostream>
#include <string> //getline
#include <cctype> //isalpha and isupper
using namespace std;
const int MAX = 1000;  

class Palindrome{
private:
    int front; 
    int rear; 
    int count; 
    int top;
    string input; 
    string convertedInput; 
    string reverseInput; 
    char queue[MAX];
    char stack[MAX];
public:
    Palindrome(string input = "", int front = 0, int rear = -1, int count = 0, int top = -1); 
    void enqueue(char a); 
    void dequeue(); 
    void convert(char s); 
    void makeStack(); 
    void findReverse(); 
    void isPalindrome(); 
    void push(char a); 
    void pop(); 
    bool queueIsEmpty();
    bool queueIsFull();
    bool stackIsEmpty();
    bool stackIsFull();
    string getConvertedInput();
    string getReverseInput();
};
#endif
