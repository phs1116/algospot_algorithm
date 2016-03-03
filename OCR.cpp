#include <iostream>
#include <string>
using namespace std;
int m,q,B[501],T[501][501],M[501][501];
char word[501][10];
int n,input[101][10];

int ocr(int seg, int prev){
	if(seg == m) return 0;
	for(int next = seg)
}


int main(){
	
	cin>>m>>q;
	for(int i=1; i<=m;i++)
		cin>>word[i];
	for(int i=1; i<=m;i++){
		cin>>B[i];
		T[1][i] = B[i];
	}
	for(int i=1; i<=m;i++)
		for(int j=1; j=<m;j++)
			cin>>T[i][j];
	for(int i=1; i=<m;i++)
		for(int j=0; j<m;j++)
			cin>>M[i][j];
			
	for(int i =0;i<q;i++){
		cin>>n;
		for(int j = 0; j<n;j++)
			cin>>input[j];
			
		
	}
}
