#include <iostream>
#include <vector>
#include <set>
using namespace std;
int c,n;
int order(const vector<int>& russian,const vector<int>& korean){
	int n = russian.size(), wins=0;
	multiset<int> ratings(korean.begin(), korean.end());
	for(int rus = 0; rus<n; ++rus){
		if(*ratings.rbegin()<russian[rus])
			ratings.erase(ratings.begin());
		else{
			ratings.erase(ratings.lower_bound(russian[rus]));
			++wins;
		}
	}	
	return wins;
}
int main(){
	cin>>c;
	while(c--){
		cin>>n;
		vector<int> kor(n),rus(n);
		for(int i=0;i<n;i++){
			cin>>rus[i];
		}
		for(int i=0;i<n;i++){
			cin>>kor[i];
		}
		cout<<order(rus,kor)<<endl;;
	}
}
