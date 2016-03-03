#include <iostream>
#include <cstring>
using namespace std;

int testcase,n,d,p,t,q[51],A[51][51];
int route[51];//����� ������ �����ϴ� �迭 
double cache[51][101];
double numb3rs(int here,int day,int city){
	if(day==d) {
		if(here != city)
			return 0;
		
		return 1;
	}
	double& ret = cache[here][day];
	if(ret!=-1) return ret;
	
	ret = 0;
	for(int next = 0; next<n;next++){
		//���� ����� �����ϸ� 
		if(A[here][next]==1){
			//�� ���ø� ���Ϳ� �ְ� �����Ѵ�. 
			ret += numb3rs(next,day+1,city)/route[here];
			//���� ������ ���� �ٽ� ������. 
		}
	}	
	return ret; 
}
int main(){
	cin >>testcase;
	while(testcase--){
		cin >> n >> d >> p;
		
		//�迭 �ʱ�ȭ 
		for(int i = 0; i< n; i++){
			route[i] = 0;//�ش� ������ ��� ���� �ʱ�ȭ 
			for(int j = 0; j<n;j++){
				cin>>A[i][j];
				if(A[i][j] == 1)
					route[i]+=1;//��� ���� �߰� 
			}
		}

		cin>>t; // Ȯ���� ���� ���� 
		for(int i = 0; i<t;i++)
			cin>>q[i];//Ȯ���� ���� �ʱ�ȭ
			
		cout.precision(8);
		for(int i = 0; i<t;i++) {
			for(int j = 0; j<51; j++){
				for(int k = 0 ; k<101;k++)
					cache[j][k]=-1;
			} 
	 		cout<<numb3rs(p,0,q[i])<<' ';
		}
		cout<<endl;
	}
}
