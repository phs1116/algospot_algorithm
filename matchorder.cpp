#include <iostream>
#include <vector>
using namespace std;
int c,n,R[100],K[100],T[100];
vector<int> sq,kor;
int match(vector<int>& sq){
	if(n==sq.size()) return 0;
	
	int ret=0;
	//���� ���� ������ �� �������� ������ 1���� 
	if(K[sq.back()]>R[ru])
		ret+=1;
	//�ϳ��� �־�� �ִ� ������ ���Ѵ�. 
	for(int i = 0; i<n; ++i){
		sq.push_back();
		ret = max(ret,match(sq));
		sq.pop_back();
	}
	
	return ret;
}

int main(){
	cin>>c;
	while(c--){
		cin>>n;
		for(int i = 0; i<n;++i)
			cin>>R[i];
		for(int i = 0; i<n;++i){
			cin>>K[i];
			T[i] == 0;
		}
		
		cout<<match(sq)<<endl;
	}
}
