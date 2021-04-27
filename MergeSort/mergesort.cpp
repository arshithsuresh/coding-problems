#include <iostream>
using namespace std;


void merge(int a[],int low,int mid, int high)
{
	int i=low;
	int j=mid+1;

	while(i<=mid && j<=high)
	{
		if(a[i]<=a[j])
		{
			i++;
			j--;
			mid--;
		}
		else
		{
			int tmp = a[i];
			a[i] = a[j];
			a[j] = tmp;
			mid++;
			i++;
			j++;
		}
	}
}


void mergeSort(int a[], int low,int high)
{
	if(low>=high)
		return;

	int mid =low+(high-low)/2;

	mergeSort(a,low,mid);
	mergeSort(a,mid+1,high);
	merge(a,low,mid,high);


}


void printarray(int A[], int size)
{
	for(int i=0;i<size;i++)
	{
		cout << A[i] << " ";
	}
}

int main(){

	int arr[] = {50,1,4,5,12,5,6,7,36};
	int arr_size = sizeof(arr)/sizeof(arr[0]);

	cout << "Given array is \n";
	printarray(arr, arr_size);

	mergeSort(arr,0,arr_size-1);

	cout <<"Sorted array is \n";
	printarray(arr, arr_size);

}
