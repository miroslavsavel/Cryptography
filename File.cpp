
#include <iostream>
#include <fstream>
#include <string>
#include "File.h"
using namespace std;

//read text from file source.txt
string fnc_readStringFromFile()
{
	string textFromString, line;
	ifstream myfile("source.txt");
    if (myfile.is_open())
    {
        while (getline(myfile, line))
        {
            //cout << textFromString << '\n';
            textFromString = textFromString + line;
        }
        myfile.close();
    }
    else cout << "Unable to open file";
	return textFromString;
}


//write string to output.txt
void fnc_writeStringToFile(string output)
{
    string textFromString, line;
    ofstream myfile("output.txt");
    if (myfile.is_open())
    {
        myfile << output;
        myfile.close();
        cout << "Text has been succesfully written to output.txt" << endl;
    }
    else cout << "Unable to open file";
}