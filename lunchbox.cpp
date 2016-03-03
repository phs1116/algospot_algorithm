#include <iostream>
#include <algorithm>
#include <vector> 
#include <utility>
using namespace std;
int c,n,m[10000],e[10000];

int heat(){
	vector<pair<int,int> > order;
	for(int i=0; i<n; ++i){
		order.push_back(make_pair(-e[i],i));//-e[i]�� �������� �������� ������ �ؼ� e[i]�� ū���� �� �տ� ������ �Ѵ�. 
	}
	sort(order.begin(),order.end());
	int ret=0, beginEat=0;
	for(int i=0; i<n;i++){
		int box = order[i].second;
		beginEat +=m[box];
		ret = max(ret,beginEat +e[box]); //����� �Դ½ð����� �� ���� ���� �Դ� �ð��� �� �����ɸ���� ���. 
	}
	 return ret; 
} 
int main(){
	cin>>c;
	while(c--){
		int sum=0;
		cin >> n;
		for(int i=0; i<n;i++){
			cin>>m[i];
			sum+=m[i];
		}
		for(int i=0; i<n;i++)
			cin>>e[i];
			//�� �������� �Դ� ������ �Դ� �ð� + ��ü ����� �ð�(��ü ����� �ð��� �Ȱ����Ƿ�) 
			//�� ��� �ܿ� �Դµ� ���� �����ɸ��°� ���� ���� ���Ǵ� ����� �ִ�. 
		cout<<heat()<<endl;
	}
}
