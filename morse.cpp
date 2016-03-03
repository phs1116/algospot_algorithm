#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;
const int M = 1000000000+100;
int bino[201][201];

//파스칼의 삼각형으로 조합들을 미리 구해놓는다. 
void calcBino(){
	memset(bino,0,sizeof(bino));
	for(int i = 0; i<=200;++i){
		bino[i][0] = bino[i][i] = 1;
		for(int j = 1; j<i;++j)
			bino[i][j] = min(M, bino[i-1][j-1]+bino[i-1][j]); // 파스칼의 삼각형 
	}
}
int skip;
void gen(int n, int m, string s){
	//기저사례1 : skip이 0보다 작으면 범위를 벗어난 것이므로 리턴한다. 
	if(skip <0) return;
	//기저사례2 : 더이상 조합할 요소가 없으므로 부호 완성. 
	if(n==0&&m==0){
		cout<<s<<endl;
		--skip;
		return;
	}
	//찾고자 하는 수가 현재 조합할수 있는 갯수를 넘어서면, 
	//현재 부호에 존재하지 않으므로 뛰어넘고 반환한다. 
	if(bino[n+m][n]<=skip){
		skip-=bino[n+m][n];
		return;
	}
	//각 요소가 존재하면 조합한다.	
	if(n>0)gen(n-1,m,s+"-");
	if(m>0)gen(n,m-1,s+"o");
}
int main(){
	int n,m,k;
	cin>>n>>m>>k;
	skip = k-1;
	calcBino(); 
	gen(n,m,"");
}
