#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

const int M = 1000000000+100;
int n,m,k,c,bino[201][201];
//파스칼의 삼각형을 통해 조합을 구해놓는다. 
void calcBino(){
	memset(bino,0,sizeof(bino));
	for(int i = 0; i<=200;++i){
		bino[i][0] = bino[i][i] = 1;
		for(int j = 1; j<i;++j)
			bino[i][j] = min(M, bino[i-1][j-1]+bino[i-1][j]); // 파스칼의 삼각형 점화식 
	}
}

int skip = 3;
string gen(int n, int m, int skip){
	//n이 더이상 없으면, o만 존재하므로 m을 반환한다. 
	if(n==0) return string(m,'o');
	
	//'-'를 선택했을경우의 조합의 범위 내에  구하고자 하는 부호를 포함되면
	//'-'를 추가하고 재귀호출한다. 
	if(skip<bino[n-1+m][n-1])
		return "-"+gen(n-1,m,skip);
	//포함되지 않으면 'o'를 추가하고, '-'가 가능한 수만큼 패스하여 다시 검사한다. 
	return "o"+gen(n,m-1,skip-bino[n+m-1][n-1]);
}
int main(){
	cin>>c;
	while(c--){
	cin>>n>>m>>k;
	skip = k-1;
	calcBino(); 
	cout<<gen(n,m,skip)<<endl;
	}
}
