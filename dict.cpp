#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;
//파스칼의 법칙을 이용하여 이항계수를 구한다.
//파스칼의 법칙 (n,r) = (n-1,r) + (n-1,r-1)
const int M = 1000000000+100;
int c,n,m,s,bno[201][201];
void paskal(){
	memset(bno,0,sizeof(bno));
	for(int i = 1; i<201;i++){
		bno[i][0]=bno[i][i] = 1;
		for(int j = 1;j<i;j++){
			bno[i][j] = min(M,bno[i-1][j] + bno[i-1][j-1]);
		}
	}
} 
string dict(int n,int m,int s){
	if(n==0)return string(m,'b');
	if(m==0)return string(n,'a');
	
	if(s < bno[n+m-1][n-1]) return "a"+dict(n-1,m,s);
	return "b"+dict(n,m-1,s-bno[n+m-1][n-1]);
}
int main(){	
	cin>>c;
	paskal();
	while(c--){
	cin >> n >> m >> s;
	cout << (bno[n+m][n]<s?"NONE":dict(n,m,s-1))<<endl;
	}
}
