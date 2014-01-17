#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

// works like induction
// let first element be Set[0] then solve for Set[1..n] and generate
// more subsets by appending Set[0] to all the subsets of Set[1..n]
vector<string> getSubset(string set, int index) {
	vector<string> allSubsets;

	if(index == set.size()) {
		allSubsets.push_back("");
	} else {
		allSubsets = getSubset(set, index + 1);
		vector<string> moreSubsets;
		for(auto oldSubset: allSubsets) {
			moreSubsets.push_back(oldSubset + set[index]);
		}
		copy(moreSubsets.begin(), moreSubsets.end(), std::back_inserter(allSubsets));
	}
	return allSubsets;
}

// another version to generate subset via backtracking
void recSubsets(string soFar, string rest) {
	if(rest.empty())
		cout<<"{" << soFar<< "}" << endl;
	else {
		recSubsets(soFar + rest[0], rest.substr(1));
		recSubsets(soFar, rest.substr(1));
	}
}

int main() {
	//vector<string> allSubsets = getSubset("1234", 0);
	//for(auto subset: allSubsets)
	//	cout<< "{" << subset << "}" <<endl;
	recSubsets("", "1234");
	return 0;
}
