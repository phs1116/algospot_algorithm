#include <iostream>
#include <cstring>
#include <string>
#include <vector>
using namespace std;
int c, n, w;
typedef struct {
	string name;
	int vol;
	int need;
}item;
item I[100];
vector<string> items;
int cache[1000][100];
int packing(int capi, int cur) {
	if (cur == n) return 0;
	int& ret = cache[capi][cur];
	if (ret != -1) return ret;
	ret = packing(capi, cur+1);
	if (capi >= I[cur].vol)
		ret = max(ret, packing(capi - I[cur].vol, cur + 1) + I[cur].need);
	return ret;
}
void reconstruct(int cap,int item, vector<string>& picked){
	if(item == n)return;
	if(packing(cap,item)==packing(cap,item+1)
		reconstruct(cap,item+1,picked);
	else{
		picked.push_back(I[item].name);
		reconstruct(cap-I[item].vol,item+1,picked);
	}
}
int main() {
	cin >> c;
	while (c--) {
		items.clear();
		memset(cache, -1, sizeof(cache));
		cin >> n >> w;
		for (int i = 0; i<n; i++)
			cin >> I[i].name >> I[i].vol >> I[i].need;	
		
		int ret = packing(w, 0);
		reconstruct(w,0,items);	
		cout <<ret <<' '<<items.size()<<endl;
		for(int i = 0; i<items.size(); i++){
			cout<<items[i]<<endl;
		}
	}
}
