using namespace std;

#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <string>
#include <locale>
#include <map>
#include <iomanip>
#include <cmath>
#include "ReadWords.h"
#include "Output.h"



ReadWords::ReadWords(const char *filename){		//attempts to open the file with read in filename
	wordfile.open(filename);
	if (!wordfile)
	{
		cout << "Failed to open " << filename << endl;
		exit(1);
	}
}


void ReadWords::close(){		//closes the file with the read in filename
	if (wordfile.is_open()){
		wordfile.close();
	}
}

string ReadWords::getNextWord(){ //gets the next word from the text file, without punct
	string temp;

	while (wordfile >> temp){

		int start = -1;
		int end = -1;
		for ( int x = 0; start == -1 && x < temp.length(); x++){	//finds the first non punct char in the word
			if (!ispunct(temp[x])){
				start = x;
			}
		}
		for ( int y = temp.length() - 1; end == -1 && y >= 0; y --){ //finds the last non punct char in the word
			if (!ispunct(temp[y])){
				end = y - start + 1;
			}
		}


		if (start!= -1 && end != -1){
		temp = temp.substr(start, end);		//gets the substring containing only char
		} else {
			continue;
		}

		locale loc;
		for ( int i = 0; i<temp.length(); i++){	//converts all characters to lowercase
			temp[i] = tolower(temp[i],loc);
		}


		return temp;		//returns the word
	}
}


bool ReadWords::isNextWord(){		//checks if there is another word in the file
	if (wordfile.eof()) {
		return false;
	} else
	{
		return true;
	}
}




