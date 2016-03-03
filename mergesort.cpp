#include <iostream>
#include <vector>

using namespace std;

template<typename T>
void merge(vector<T>& array, int start, int mid, int end) {

	int i = start;
	int j = mid + 1;
	int k = 0;


	vector<T> result;
	result.resize(end - start + 1);



	while (i <= mid && j <= end) {

		if (array[i] < array[j]) result[k++] = array[i++];
		else result[k++] = array[j++];
	}


	while (j <= end) {
		result[k++] = array[j++];
	}

	while (i <= mid) {
		result[k++] = array[i++];
	}


	k = 0;
	for (int i = start; i <= end; i++, k++) {
		array[i] = result[k];
	}

}



//분할
template<typename T>
void merge_sort(vector<T>& array, int start, int end) {

	int mid; // 중간값


	//if (start >= end) return;//start가 end보가 더 커지면 리턴.


	if (start < end) {

		mid = (end + start) / 2;//중간값.

		merge_sort(array, start, mid);//왼쪽으로 계속 분할
		merge_sort(array, mid + 1, end);//오른쪽 분할. 중위순회 방식.


		merge(array, start, mid, end);
	}

}



int main(void)
{
	vector<double> array = { 3.4, 8.2, 0.4, 2.1, 1, 4 };
	merge_sort(array, 0, array.size() - 1);




	for (int i = 0; i < (int)array.size(); i++) {
		printf("%lf ", array[i]);
	}

	return 0;
}
