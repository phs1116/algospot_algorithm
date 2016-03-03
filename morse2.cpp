#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

const int M = 1000000000+100;
int n,m,k,c,bino[201][201];
//�Ľ�Į�� �ﰢ���� ���� ������ ���س��´�. 
void calcBino(){
	memset(bino,0,sizeof(bino));
	for(int i = 0; i<=200;++i){
		bino[i][0] = bino[i][i] = 1;
		for(int j = 1; j<i;++j)
			bino[i][j] = min(M, bino[i-1][j-1]+bino[i-1][j]); // �Ľ�Į�� �ﰢ�� ��ȭ�� 
	}
}

int skip = 3;
string gen(int n, int m, int skip){
	//n�� ���̻� ������, o�� �����ϹǷ� m�� ��ȯ�Ѵ�. 
	if(n==0) return string(m,'o');
	
	//'-'�� ������������� ������ ���� ����  ���ϰ��� �ϴ� ��ȣ�� ���ԵǸ�
	//'-'�� �߰��ϰ� ���ȣ���Ѵ�. 
	if(skip<bino[n-1+m][n-1])
		return "-"+gen(n-1,m,skip);
	//���Ե��� ������ 'o'�� �߰��ϰ�, '-'�� ������ ����ŭ �н��Ͽ� �ٽ� �˻��Ѵ�. 
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
