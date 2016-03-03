#include <iostream>
#include <vector>

using namespace std;

template<typename T>
void merge(T array[], int h, int m) {

	int i = 0;
	int j = h;
	int k = 0;

	T* result = new T[h + m];

	while (i < h && j < m+h) {

		if (array[i] < array[j]) {
			result[k++] = array[i++];
		}
		else {
			result[k++] = array[j++];
		}
	}


	while (j < m+h) {
		result[k++] = array[j++];

	}

	while (i <= h) {
		result[k++] = array[i++];
	}


	for (int i = 0; i < m+h; i++) {
		array[i] = result[i];
	}	

}



//분할
template<typename T>
void merge_sort(T array[], int size) {

	if (size > 1)
	{

		int h = size / 2;//중간값.
		int m = size - h;


		merge_sort(array, h);//왼쪽 분할
		merge_sort(array+h, m);//오른쪽 분할.


		merge(array, h,m);


	}

}



int main(void)
{
	int array[] = { 3, 8, 0, 2, 1, 4 };
	merge_sort(array, sizeof(array) / sizeof(int));




	for (int i = 0; i < sizeof(array) / sizeof(int); i++) {
		printf("%d ", array[i]);
	}

	return 0;
}
