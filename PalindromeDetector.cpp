// PalindromeDetector.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
/***************************************************************
*file: PalendromeDetector.cpp
*author: Shiv Patel
*class: CS 2560 – C++
*assignment: Program 2/Palendrome Detector
*date last modified: 9/21/2019
*
*purpose: This program reads input from a file and checks if it is a palendrome or not.
If it is a palendrome, it will be written into an output file.
*
****************************************************************/
#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
using namespace std;
bool isPalindrome(string, int, int);
string takeOutCasing(string);

int main()
{
	string inputFile;
	string outputFile;
	ifstream inFile;
	ofstream outFile;
	string word;
	int counter = 1;
    cout << "Palindrome Detector:\n";
	cout << "---------------------------------\n";
	cout << "Enter a file for input to test for palindromes: ";
	cin >> inputFile;
	inFile.open(inputFile);
	//check if file is valid
	while (inFile.fail())
	{
		cout << "Enter a valid file name: ";
		cin >> inputFile;
		inFile.open(inputFile);
	}
	cin.ignore();
	cout << "\nEnter a file for output to write the results: ";
	cin >> outputFile;
	outFile.open(outputFile);
	//check if file is valid
	while (outFile.fail())
	{
		cout << "Enter a valid file name: ";
		cin >> outputFile;
		outFile.open(outputFile);
	}
	while (getline(inFile,word))
	{
		string newWord = takeOutCasing(word);
		int length = newWord.length() - 1;
		if (isPalindrome(newWord, 0, length))
		{
			outFile << "Line " << counter << " is a palindrome.\n";
		}
		else
		{
			outFile << "Line " << counter << " is not a palindrome.\n";
		}
		counter++;
	}
	inFile.close();
	outFile.close();
	cout << "Processing completed! Check outpute file for results.";
	return 0;
}

bool isPalindrome(string n, int first, int last)
{
	//checks if the string is a palindrome
	try {
		if (first == last)
			return true;
		if (n.at(first) != n.at(last))
			return false;
		if (n.at(first) == n.at(last))
			return isPalindrome(n, ++first, --last);
		return false;
	}
	catch (...){}
}

string takeOutCasing(string n)
{
	//remove all the characters that are not letters and numbers and return that result
	string noSpaces = "";
	int start = 0;
	int end = n.length() - 1;
	while (start <= end)
	{
		if ((n.at(start) >= 97 && n.at(start) <= 122) || (n.at(start) >= 48 && n.at(start) <= 57) || (n.at(start) >= 65 && n.at(start) <= 90))
		{
			if (isupper(n.at(start)) && !isdigit(n.at(start)))
			{
				noSpaces += tolower(n.at(start));
			}
			else
			{
				noSpaces += n.at(start);
			}
		}
		start++;
	}
	return noSpaces;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
