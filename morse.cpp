#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;
const int M = 1000000000+100;
int bino[201][201];

//�Ľ�Į�� �ﰢ������ ���յ��� �̸� ���س��´�. 
void calcBino(){
	memset(bino,0,sizeof(bino));
	for(int i = 0; i<=200;++i){
		bino[i][0] = bino[i][i] = 1;
		for(int j = 1; j<i;++j)
			bino[i][j] = min(M, bino[i-1][j-1]+bino[i-1][j]); // �Ľ�Į�� �ﰢ�� 
	}
}
int skip;
void gen(int n, int m, string s){
	//�������1 : skip�� 0���� ������ ������ ��� ���̹Ƿ� �����Ѵ�. 
	if(skip <0) return;
	//�������2 : ���̻� ������ ��Ұ� �����Ƿ� ��ȣ �ϼ�. 
	if(n==0&&m==0){
		cout<<s<<endl;
		--skip;
		return;
	}
	//ã���� �ϴ� ���� ���� �����Ҽ� �ִ� ������ �Ѿ��, 
	//���� ��ȣ�� �������� �����Ƿ� �پ�Ѱ� ��ȯ�Ѵ�. 
	if(bino[n+m][n]<=skip){
		skip-=bino[n+m][n];
		return;
	}
	//�� ��Ұ� �����ϸ� �����Ѵ�.	
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
