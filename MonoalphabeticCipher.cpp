//8.1.2020 monoalphabetic cipher program according book
//Practical Cryptography: Algorithms and Implementations Using C++ 1st Edition Saiful Azad, Al-Sakib Khan Pathan ISBN-10: 1482228890
//I have made input from source.txt and save as cipher.txt
//-------------------------------------------------------------------

#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>
#include "File.h"

using namespace std;

typedef vector <char>CharVec;		//STL vector that hold characters
CharVec Plain;
CharVec Cipher;


//display source/cipher alphabet
void PutCharInVec()
{
	cout << "Plain: " << endl;
	for (int i = 0; i < 26; i++) {
		Plain.push_back(i + 97);		//Assigning the plain characters in Vector
	}

	for (int i = 0; i < 26; i++) {		//assigning the random character in vector to use as key
		cout << Plain[i] << "\t";
	}
	cout << endl;

	cout << "Cipher: " << endl;
	bool exist = true;				//??? on ju neinicializuje
	int num;

	for (int i = 0; i < 26; i++)
	{
		//Generating unique random numbers as keys
		while (exist)
		{
			exist = false;
			num = rand() % 26 + 1;

			for (vector <char> ::iterator it = Cipher.begin(); it != Cipher.end(); it++)
			{
				if ((*it) == num)
				{
					exist = true;
					break;
				}
			}
		}

		Cipher.push_back(((i + num) % 26) + 65);
	}

	for (int i = 0; i < 26; i++) {
		cout << Cipher[i] << "\t";
	}
	cout << endl;
}


char Monoalphabetic(char c)
{
	//encryption
	if (c != toupper(c))
	{
		for (int i = 0; i < 26; i++)
		{
			if (Plain[i] == c)
			{
				return Cipher[i];
			}
		}
	}

	//decryption
	else {
		for (int i = 0; i < 26; i++)
		{
			if (Cipher[i] == c)
			{
				return Plain[i];
			}
		}
	}
	return 0;
}




int main()
{
	
	//
	//vector<double> vec(5, 8.8);
	//cout << "Size of vec is " << vec.size();

	//cout << "vec: ";
	//for (int i = 0; i < vec.size(); i++)
	//	cout << vec[i] << " ";
	//
	
	int number = 15;

	string input, output;


	PutCharInVec();
	int choice = 0;
	while (choice != 3)
	{
		//menu for user
		cout << endl << "Press 1: Encryption/Decryption "<<endl
			<< "Press 2: Load text from source.txt" << endl
			<< "Press 3: QUIT "<<endl			
			<<">>";


		try {
			cin >> choice;
			cin.ignore();					//http://www.cplusplus.com/forum/beginner/9148/
			if (choice != 1 && choice != 2 && choice != 3)
				throw "Incorrect choice";
		}
		catch (const char* chc)
		{
			cerr << "INCORRECT CHOICE !!!!" << endl;
			return 1;
		}

		if (choice == 1)
		{
			try {
				cout << endl << "NOTE: Put LOWER CASE letters for encryption and" << endl;
				cout << "UPPER CASE letters for decryption" << endl;
				cout << endl << "Enter ciphertext (only alphabets) and press enter to continue: ";
				getline(cin, input);

				for (int i = 0; i < input.size(); i++)
				{
					if ((!(input[i] >= 'a' && input[i] <= 'z')) && (!(input[i] >= 'A' && input[i] <= 'Z')))
						throw "Incorrect string";
				}
			}
			catch (const char* str)
			{
				cerr << "YOUR STRING MAY HAVE DIGITS OR SPECIAL SYMBOLS!!" << endl;
				cerr << "PLEASE PUT ONLY ALPHABETS !!!" << endl;
				return 1;
			}

			for (unsigned int x = 0; x < input.length(); x++)
			{
				output += Monoalphabetic(input[x]);
			}
			cout << output << endl;
			output.clear();
		}
		if (choice == 2)
		{
			int test = 0;
			//read string from source.txt
			input = fnc_readStringFromFile();
			try
			{
				for (int i = 0; i < input.size(); i++)
				{
					if ((!(input[i] >= 'a' && input[i] <= 'z')) && (!(input[i] >= 'A' && input[i] <= 'Z')) && (input[i] != ' '))
					{
						test = 5;			//because of conditional breakpoint debug on unusual character in string
						throw "Incorrect string";		//set here conditional breakpoint test == 5;
						
					}
						
				}
			}
			catch (const char* str)
			{
				cerr << "YOUR FILE MAY HAVE DIGITS OR SPECIAL SYMBOLS!!" << endl;
				cerr << "PLEASE PUT ONLY ALPHABETS !!!" << endl;
				return 1;
			}

			for (unsigned int x = 0; x < input.length(); x++)
			{
				output += Monoalphabetic(input[x]);
			}
			
			fnc_writeStringToFile(output);
			output.clear();
		}
	}




	std::cout << endl;
	std::cout << endl;
	std::cout << endl;
	return 0;
}


