#include <cstdio>
#include <cmath>
int n, a[15], count=0;
//이 위치에 여왕말을 놓을수 있는지, 즉 유망한지 체크한다. 
bool check(int cur) {
	//0부터 이 행까지 모두 조사한다. 
	for (int i = 0; i<cur; i++) {
		//열이 같은 것이 있거나, 대각선범위내에 있으면 불가능한 경우므로 false로 셋트. 
		if(a[i]==a[cur] || cur-i==std::abs(a[cur]-a[i])){
			return false;
		}	 
	}
	return true;
}
void nqueen(int cur) { 
	//기저사례 : 끝에 도달았으면 카운터를 증가시키고 반환한다. 
	if(cur==n-1) {
		count++;
		return; 
	}
	//아직 끝에 도달하지 않았으면 다음 위치를 찾는다. 
	for(int i=0;i<n;i++){
		a[cur+1] = i;
		//check이 참이면 다음 여왕말을 찾고, 못찾으면 백트래킹한다.
		if(check(cur+1)) nqueen(cur+1);

	} 
}
int main() {
	scanf("%d", &n);
	nqueen(-1);
	printf("%d",count);
}
