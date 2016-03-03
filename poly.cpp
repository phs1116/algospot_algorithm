#include <iostream>
#include <cstring>
using namespace std;
const int MOD = 10000000;
int cache[101][101],t,n;
//완전탐색, 밑에서부터 쌓아나가자. 
//num은 블럭의 갯수, upper은 위에 있는 블럭의 갯수 
int poly(int num, int upper){
	//기저사례 
	if(upper == num) return 1;
	int& ret = cache[num][upper];
	if(ret!=-1) return ret;
	ret = 0;
	//1개부터 num개까지  
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
