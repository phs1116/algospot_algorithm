#include <cstdio>
#include <cmath>
int n, a[15], count=0;
//�� ��ġ�� ���ո��� ������ �ִ���, �� �������� üũ�Ѵ�. 
bool check(int cur) {
	//0���� �� ����� ��� �����Ѵ�. 
	for (int i = 0; i<cur; i++) {
		//���� ���� ���� �ְų�, �밢���������� ������ �Ұ����� ���Ƿ� false�� ��Ʈ. 
		if(a[i]==a[cur] || cur-i==std::abs(a[cur]-a[i])){
			return false;
		}	 
	}
	return true;
}
void nqueen(int cur) { 
	//������� : ���� ���޾����� ī���͸� ������Ű�� ��ȯ�Ѵ�. 
	if(cur==n-1) {
		count++;
		return; 
	}
	//���� ���� �������� �ʾ����� ���� ��ġ�� ã�´�. 
	for(int i=0;i<n;i++){
		a[cur+1] = i;
		//check�� ���̸� ���� ���ո��� ã��, ��ã���� ��Ʈ��ŷ�Ѵ�.
		if(check(cur+1)) nqueen(cur+1);

	} 
}
int main() {
	scanf("%d", &n);
	nqueen(-1);
	printf("%d",count);
}
