/*
Name: Tanner Dryden
Class: CS131 2830
Section: A
Program 3: Word Counter
Description: This program is a word counter that takes the name of a text file
that is in the same folder as the .cpp and counts how many of each size
words there are. This program utilizes loops, function outside of main,
array, and of course file io.
*/
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;
void readAndProcessFiles();
int main()
{
	cout << endl << setw(47) << "My Name is Tanner" << endl << endl;
	cout << setw(50) << "Program 3: Word Counter" << endl;
	for (int i = 0; i <= 40; i++) // loop that creates a line to separate the header and the program output
	{
		cout << "- ";
	}
	cout << endl;
	readAndProcessFiles(); // the function that executes everyting outside of main
	return 0;
}
void readAndProcessFiles() {
	int reprompt = 1;
	while (reprompt == 1) { // loop that prompts again after one complete cycle
		ifstream fin; // create the input file stream variable
		string inputStr, strVar = "";
		int counter = 0, total = 0, i = 0;
		int arrWord[44] = { 0 }; // the longest word in the english language is 45 characters
		char answer;
		cout << "Please enter the file you would like to access or type \"quit\" to exit the program" << endl;
		do { // a do while for the menu
			if (fin.fail()) {
				cout << "Please try again or type \"quit\" to exit the program" << endl;
			}
			cin >> inputStr;
			if (inputStr == "quit")
			{
				exit(0);
			}
			fin.open(inputStr.c_str()); // tries to open the file
		} while (fin.fail()); // .fail() returns true if it could not open the file
		while (fin >> strVar) {
			total++;
			// gets the length of each word and increments
			// the corresponding count for the length
			arrWord[strVar.length() - 1] = arrWord[strVar.length() - 1] + 1;
		}
		fin.close(); // closes the stream
		fin.clear(); // cleans the stream
		for (i = 1; i < 35; i++) {
			arrWord[8] += arrWord[8 + i]; // adds all the words over 8 characters together in array 8
		}
		cout << "length:" << setw(10) << "count:" << endl; // user formatting ... etc
		for (i = 0; i < 8; i++) {
			cout << i + 1 << setw(11) << arrWord[i] << endl;
		}
		cout << ">8" << setw(10) << arrWord[i] << endl;
		cout << "total words in the file: " << total << endl << endl;
	}
}