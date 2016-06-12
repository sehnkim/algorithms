#include <iostream>
#include <queue>
#include <vector>
#include <sstream>
#include <string>
using namespace std;


//void main()
//{
//	string Astring = "Hello My Baby Hello My Honey";
//	string temp;
//	istringstream words(Astring);
//	vector<string> parsed;
//	while (words)
//	{
//		words >> temp;
//		cout << temp << endl;
//		//parsed.push_back(temp);
//	}
//
//	/*for (int i = 0; i < parsed.size(); i++)
//		cout << "*" << parsed[i] << "*" << endl;*/
//
//	
//}

vector< vector<int> > getAllSubsets(vector<int> set, int index)
{
	vector< vector<int>> allsubsets;
	vector<int> empty;
	allsubsets.push_back(empty);

	/*if (set.size == index)
	{
		vector<vector<int>> allsubsets;
		allsubsets.push_back(new vector<int>());
	}	*/

	return allsubsets;
}


vector< vector<int> > getAllSubsets(vector<int> set)
{
	vector< vector<int> > subset;
	vector<int> empty;
	subset.push_back(empty);

	for (int i = 0; i < set.size(); i++)
	{
		vector< vector<int> > subsetTemp = subset;

		for (int j = 0; j < subsetTemp.size(); j++)
			subsetTemp[j].push_back(set[i]);

		for (int j = 0; j < subsetTemp.size(); j++)
			subset.push_back(subsetTemp[j]);
	}
	return subset;
}

void RecSubsets(string soFar, string rest) {
	for (int i = 0; i < rest.length(); i++) {
		string next = soFar + rest[i];
		string remaining = rest.substr(i + 1);
		RecSubsets(next, remaining);
	}
	if (soFar.size() > 0) 
		cout << soFar << endl;
}

/*Driver program to test printPowerSet*/
void main()
{
	/*vector<int> test =  { 1,2,3 };
	vector< vector<int> > res = getAllSubsets(test);
	for (vector<int> set : res)
		for (int set1 : set)
			cout << set1 << endl;*/		

	RecSubsets("", "abc");

}



