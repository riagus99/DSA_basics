// source code from https://m.blog.naver.com/ndb796/221228004692 and modified

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;
/*
int main(void){
	vector<pair<int, string> > v; // instantiate vector with each elements are pair<int, string>
	v.push_back(pair<int, string>(90, "Amy"));
	v.push_back(pair<int, string>(85, "Ben"));
	v.push_back(pair<int, string>(84, "Caroline"));
	v.push_back(pair<int, string>(93, "David"));
	v.push_back(pair<int, string>(94, "Emile"));
	
	sort(v.begin(), v.end());
	for (int i = 0; i < v.size(); i++){
		cout << v[i].second << ' ';
	}
}
*/

bool compare(pair<string, pair<int, int> > a, pair<string, pair<int, int> > b){
	if(a.second.first == b.second.first) {          // if first criteria is same, check for the second criteria
		return a.second.second > b.second.second;
	}
	else {
		return a.second.first > b.second.first;
	}
}

int main(void){
	vector<pair<string, pair<int, int> > > v;
	v.push_back(pair<string, pair<int, int> >("Amy", make_pair(90, 19961222)));
	v.push_back(pair<string, pair<int, int> >("Ben", make_pair(97, 19990831)));
	v.push_back(pair<string, pair<int, int> >("Caroline", make_pair(95, 19941225)));
	v.push_back(pair<string, pair<int, int> >("David", make_pair(90, 19930709)));
	v.push_back(pair<string, pair<int, int> >("Emile", make_pair(83, 19900607)));
	
	sort(v.begin(), v.end(), compare);
	for (int i = 0; i < v.size(); i++){
		cout << v[i].first << ' ';
	}
	cout << endl;
}
