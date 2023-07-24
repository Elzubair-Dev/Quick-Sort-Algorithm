using namespace std;
#include<iostream>
int partition(int arr[], int begin, int end)
{
	int i = begin;
	int j = end;
	int pivot = i;
	while (true)
	{
		while (arr[pivot] <= arr[j] && pivot != j)
		{
			j--;
		}
		if (pivot == j)break;
		else if (arr[pivot] > arr[j])
		{
			swap(arr[pivot], arr[j]);
			pivot = j;
		}
		while (arr[pivot] >= arr[i] && pivot != i)
		{
			i++;
		}
		if (pivot == i)break;
		else if (arr[pivot] < arr[i])
		{
			swap(arr[pivot], arr[i]);
			pivot = i;
		}
	}
	return pivot;
}
void QSort(int arr[], int i, int h)
{
	if (i < h)
	{
		int p = partition(arr, i, h);
		QSort(arr, i, p - 1);
		QSort(arr, p + 1, h);
	}
}
void print(int arr[], int size)
{
	cout << "[ ";
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}
	cout << "]\n\n";
}
int main()
{
	int s[] = { 60,40,20,80,10,30,70,50 };
	int n = sizeof(s) / sizeof(s[0]);
	print(s, n);
	cout << "---------------After Quick Sort---------------\n\n";
	QSort(s, 0, n-1);
	print(s, n);
}