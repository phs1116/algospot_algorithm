#include <iostream>
#include <cstring>
using namespace std;
const int MOD = 10000000;
int cache[101][101],t,n;
//����Ž��, �ؿ������� �׾Ƴ�����. 
//num�� ���� ����, upper�� ���� �ִ� ���� ���� 
int poly(int num, int upper){
	//������� 
	if(upper == num) return 1;
	int& ret = cache[num][upper];
	if(ret!=-1) return ret;
	ret = 0;
	//1������ num������  
	for(int i=1; i<=num-upper; i++){
		ret +=poly(num-upper,i)*(upper+i-1)%MOD;
		ret%=MOD;
	}
	return ret; 
	
	
}
int main(){
	cin>>t;
	memset(cache,-1,sizeof(cache));
	while(t--){
		cin>>n;
		int ret = 0;
		for(int i=1;i<=n;i++){
			ret+=poly(n,i)%MOD;
		}
		cout<<ret%MOD<<endl;
		
		//cout<<poly(n,0)<<endl;
		
	}
}
