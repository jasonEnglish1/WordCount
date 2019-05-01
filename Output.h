
#ifndef OUTPUT_H
#define OUTPUT_H
#include <map>
#include <string>

using namespace std;


class Output
{	public:

	Output(map<string,int>);  //defines the method to generate the output


	friend ostream& operator<<(ostream&, const Output&); //defines the method to overide the output


	private:
	map<string, int> frequency; //creates a map
	int longest, most;			// creates variables to store the longest word and largest frequency
};

	#endif