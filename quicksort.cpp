#include <iostream>
#include <vector>


using namespace std;

template<typename T>
void quickSort(vector<T>& array, int left, int right) {
	
	int& pivot = array[left];

	int b_left = left, b_right = right;


	//left가 right보다 작을때까지
	while (left < right) {

		//left에 있는 값으르 한칸씩 오른쪽으로 이동, pivot보다 큰 값이 나올때까지.
		while (array[left] < pivot&&right > left)
			left++;



		//right를 한칸씩 왼쪽으로 이동, pivot보다 작은값이 나올때까지.
		while (array[right] > pivot && right>left)
			right--;



		//pivot보다 작은값과 큰값을 각각 찾았고, left가 right보다 작으면 두 값을 스왑
		if (left < right) {
			T temp = array[left];
			array[left] = array[right];
			array[right] = temp;
		}

	}

	T temp = pivot;
	pivot = array[left];
	array[left] = temp;

	int pivot_point = left; //left = right


	//이때left = right이고 pivot이 위치한 값이다.

	//기존의 left가 피벗 위치보다 작을경우 실행.
	if (b_left < pivot_point)
		quickSort(array, b_left, pivot_point-1);

	//기존의 right가 피벗 위치보다 클 경우 실행.
	if (b_right > pivot_point)
		quickSort(array, pivot_point + 1, b_right);

}



int main() {

	vector<int> array = { 3,8,5,5,1,9,6,4 };
	
	quickSort(array, 0, (int)array.size()-1);

	for (int i = 0; i < (int)array.size(); i++) {
		cout << array[i] <<" ";
	}

	return 0;
}
