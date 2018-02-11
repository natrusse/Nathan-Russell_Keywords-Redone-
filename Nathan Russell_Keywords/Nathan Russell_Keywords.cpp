// Nathan Russell_Keywords.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace::std;


int main()
{
	enum fields { WORD, HINT, NUM_FIELDS };
	const int NUM_WORDS = 5;
	const string WORDS[NUM_WORDS][NUM_FIELDS] =
	{
		{"Wall", "Do you feel you're head banging against something?"},
		{"glasses", "These might help you see the answer."},
		{"labored", "Going slowly, is it?"},
		{"persistent", "Keep at it."},
		{"jumble", "It's what the game is all about."}
	};

	srand(static_cast<unsigned int>(time(0)));
	int choice = (rand() % NUM_WORDS);
	string theWord = WORDS[choice][WORD];
	int choice2 = (rand() % NUM_WORDS / 2);
	string theWord2 = WORDS[choice2][WORD];
	string theHint = WORDS[choice][HINT];
	string theHint2 = WORDS[choice2][HINT];

	string jumble = theWord;
	int length = jumble.size();
	for (int i = 0; i < length; ++i)
	{
		int index1 = (rand() % length);
		int index2 = (rand() % length);
		char temp = jumble[index1];
		jumble[index1] = jumble[index2];
		jumble[index2] = temp;

	}

	string jumble2 = theWord2;
	int length2 = jumble2.size();
	for (int i = 0; i < length2; ++i)
	{
		int index1 = (rand() % length2);
		int index2 = (rand() % length2);
		char temp = jumble2[index1];
		jumble2[index1] = jumble2[index2];
		jumble2[index2] = temp;
		
	}

	cout << "\t\tInitiating Encoded Scramble protocols......\n\n";
	cout << "Decrypt three codes to proceed.\n";
	cout << "Enter 'hint' if you require assistance.\n";
	cout << "Enter 'quit' to shut down the decryption program.\n\n";
	cout << "The first code is: " << jumble;

	string guess;
	cout << "\n\nYour guess: ";
	cin >> guess;

	while ((guess != theWord) && (guess != "quit"))
	{
		if (guess == "hint")
		{
			cout << theHint;
		}
		else {
			cout << "Sorry, that's not it.";
		}

		cout << "\n\nYour guess: ";
		cin >> guess;
	}

	if (guess == theWord)
	{
		cout << "\nAccess code decryption 01 accepted. \n";
	}

	cout << "The second code is: " << jumble2;
	
	string guess2;
	cout << "\n\nYour guess: ";
	cin >> guess2;

	while ((guess2 != theWord2) && (guess2 != "quit"))
	{
		if (guess2 == "hint")
		{
			cout << theHint2;
		}
		else {
			cout << "Sorry, that's not it.";
		}

		cout << "\n\nYour guess2: ";
		cin >> guess2;
	}

	if (guess2 == theWord2)
	{
		cout << "\nAccess code decryption 02 accepted. \n";
	}

	system("pause");
    return 0;
}
