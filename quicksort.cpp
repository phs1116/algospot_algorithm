#include <iostream>
#include <vector>


using namespace std;

template<typename T>
void quickSort(vector<T>& array, int left, int right) {
	
	int& pivot = array[left];

	int b_left = left, b_right = right;


	//left�� right���� ����������
	while (left < right) {

		//left�� �ִ� ������ ��ĭ�� ���������� �̵�, pivot���� ū ���� ���ö�����.
		while (array[left] < pivot&&right > left)
			left++;



		//right�� ��ĭ�� �������� �̵�, pivot���� �������� ���ö�����.
		while (array[right] > pivot && right>left)
			right--;



		//pivot���� �������� ū���� ���� ã�Ұ�, left�� right���� ������ �� ���� ����
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


	//�̶�left = right�̰� pivot�� ��ġ�� ���̴�.

	//������ left�� �ǹ� ��ġ���� ������� ����.
	if (b_left < pivot_point)
		quickSort(array, b_left, pivot_point-1);

	//������ right�� �ǹ� ��ġ���� Ŭ ��� ����.
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
