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

#define WIDTH 30

map<string,int> frequency;


Output::Output(map<string,int> freq){ //finds the longest word and most occurrences of test words
	frequency = freq;
	longest = 0;
	most = 0;
	for(map<string, int>::iterator iterator = frequency.begin(); iterator != frequency.end(); iterator++) {
			if (iterator->first.length() > longest) longest = iterator->first.length();							// iterates through the map
			if (iterator->second > most) most = iterator->second;
	}
}



ostream& operator<<(ostream& o, const Output& f){ //overrides the output operator to allow a unique output for objects of the Output class
	int scale = ceil((double) f.most/WIDTH); //finds out what each '*' is worth

	for(map<string, int>::const_iterator iterator = f.frequency.begin(); iterator != f.frequency.end(); iterator++){  //iterates through the map to generate each part of the output
		o << setw(f.longest+1) << left << iterator->first << setw(ceil((double)f.most/scale)+1) << string(ceil((double)iterator->second/scale),'*') << iterator->second << endl;
	}
	o << "scale: * includes up to " << scale << endl;
	return o;
}
