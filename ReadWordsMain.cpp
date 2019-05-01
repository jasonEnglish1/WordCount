#include "ReadWords.h"
#include "Output.h"
#include <iostream>
#include <string>
#include <map>

int main (){

	cout<<"enter the file containing the script" <<endl;
	string hamlet;			 //reads in the name of the text file to read
	getline(cin, hamlet);

	cout<<"enter the file containing the search words" <<endl;
	string testWords;		//reads in the name of the words to search for
	getline(cin, testWords);

	cout<<"enter the file to output" <<endl;
	string resultFile;		//reads in the name of the file to be output to
	getline(cin, resultFile);


	map<string,int> frequency;

	ofstream out(resultFile.c_str());	//attempts to open the files
	ReadWords array1(hamlet.c_str());	//converts to c_str to mach the type needed
	ReadWords check(testWords.c_str());


	while (check.isNextWord()){		//generates the map
		string temp = check.getNextWord();
		if(temp[0] == '\0') continue; //skips adding the eof char to the map
		frequency[temp] = 0; //creates the map with the testwords
	}


	while (array1.isNextWord()){ //counts the frequency of the words in the text file
		string word = array1.getNextWord();
		if(frequency.count(word) != 0)
		{
			frequency[word]++;
		}
	}

	array1.close(); //closes the open files
	check.close();

	Output o(frequency); //uses the map to generate the output
	cout << o ; //output to cmd
	out << o;  //output to file

	out.close();
}