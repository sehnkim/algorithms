#include <iostream>
#include <vector>
#include <set>
using namespace std;

void findSubsets(vector<int> soFar, vector<int> rest)
{
	// corner case
	if (rest.size() == 0) {
		for (auto n : soFar)
			cout << n << " ";
		cout << endl;
		return;
	}

	// TODO: somehow, need to improve this since it's O(N).
	// Get first elem from rest
	int elem = rest.front();
	// Remove it from rest with O(N)
	rest.erase(rest.begin());

	// add it to soFar
	vector<int> newSoFar(soFar);
	newSoFar.push_back(elem);
	findSubsets(newSoFar, rest);
	findSubsets(soFar, rest);
}

void findSubsetsW(vector<int> nums)
{
	vector<int> soFar;
	findSubsets(soFar, nums);
}

int main()
{
	vector<int> nums = { 1,2,3};
	findSubsetsW(nums);

	return 0;
}