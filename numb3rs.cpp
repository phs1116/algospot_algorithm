#include <iostream>
#include <vector>
using namespace std;

int testcase,n,d,p,t,q[50],A[50][50];
int route[50];//����� ������ �����ϴ� �迭 
double numb3rs(vector<int>& path,int city){
	double ret1 = 1;
	if(path.size()==d+1) {
		if(path.back() != city)
			return 0;
			//�����ϴ� ��ġ�� Ȯ���� ����� �ʿ䰡 ����. 
		for(int i = 0; i<path.size()-1;i++)
			ret1/=route[path[i]]; 
		return ret1;
	}
	
	double ret2 = 0;
	int curCity = path.back();
	for(int i = 0; i<n;i++){
		//���� ����� �����ϸ� 
		if(A[curCity][i]==1){
			//�� ���ø� ���Ϳ� �ְ� �����Ѵ�. 
			path.push_back(i);
			ret2 += numb3rs(path,city);
			//���� ������ ���� �ٽ� ������. 
			path.pop_back();
		}
	}	
	return ret2; 
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
		
		vector<int> path;// ��θ� ������ ���� 
		path.push_back(p);//������ ��ġ ���� 
		cout.precision(7);
		for(int i = 0; i<t;i++) 
			cout<<numb3rs(path,q[i])<<' ';
			
	}
}
