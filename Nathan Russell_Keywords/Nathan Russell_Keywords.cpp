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
	const int NUM_WORDS = 10;
	const string WORDS[NUM_WORDS][NUM_FIELDS] =
	{
		{ "computer", "You're sitting at one." },
		{ "fourty-two", "The answer to the ultimate question of life, the universe, and everything." },
		{ "existence", "The meaning of this is asked by philosophers everywhere." },
		{ "potato", "A starchy vegetable that tastes good when baked." },
		{ "decrypt", "Means to read a code that is written in a way that hides its true meaning" },
		{ "insane", "A state of mind requiring mental help." },
		{ "reproduce", "To make again." },
		{ "space", "The final frontier..." },
		{ "mississippi", "A state with a famous river." },
		{ "coffee", "Wakes you up in the morning." }
	};

	srand(static_cast<unsigned int>(time(0)));
	//choice is the formula that picks a rwo to use
	int choice = (rand() % NUM_WORDS);
	//theWord picks the word
	string theWord = WORDS[choice][WORD];
	//picks new choice
	int choice2 = (rand() % NUM_WORDS / 2);
	//assigns new word
	string theWord2 = WORDS[choice2][WORD];
	//picks new choice
	int choice3 = (rand() % NUM_WORDS / 3);
	//picks new word
	string theWord3 = WORDS[choice3][WORD];
	//hints tie picked word to corresponding hints and tie them to a command
	string theHint = WORDS[choice][HINT];
	string theHint2 = WORDS[choice2][HINT];
	string theHint3 = WORDS[choice3][HINT];

	//mixes up the letters of the chosen word
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
	//mixes second word
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
	//mixes third word
	string jumble3 = theWord3;
	int length3 = jumble3.size();
	for (int i = 0; i < length3; ++i)
	{
		int index1 = (rand() % length3);
		int index2 = (rand() % length3);
		char temp = jumble3[index1];
		jumble3[index1] = jumble3[index2];
		jumble3[index2] = temp;

	}

	//opening scripts
	cout << "\t\tInitiating Decoding Program......\n\n";
	cout << "Decrypt tion of three codes required.\n";
	cout << "Enter 'hint' if you require assistance.\n";
	cout << "Enter 'quit' to shut down the decryption program.\n\n";
	cout << "The first code is: " << jumble;

	//begins first scramble
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
		cout << "\nAccess code decryption 01 confirmed. \n";
	}

	cout << "The second code is: " << jumble2;
	//todo ask teacher how to remove items from a list that were already used
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

		cout << "\n\nYour guess: ";
		cin >> guess2;
	}

	if (guess2 == theWord2)
	{
		cout << "\nAccess code decryption 02 confirmed. \n";
	}

	cout << "The third code is: " << jumble3;

	string guess3;
	cout << "\n\nYour guess: ";
	cin >> guess3;

	while ((guess3 != theWord3) && (guess3 != "quit"))
	{
		if (guess3 == "hint")
		{
			cout << theHint3;
		}
		else {
			cout << "Sorry, that's not it.";
		}

		cout << "\n\nYour guess: ";
		cin >> guess3;
	}

	if (guess3 == theWord3)
	{
		cout << "\nAccess code decryption 03 confirmed. \n";
	}
	cout << "\nAll available codes decrypted! Have a nice day.\n";
	system("pause");
	return 0;
}

//todo figure out what "display stats" means and make system to do so
//todo make replay loop that doesn't break the game
