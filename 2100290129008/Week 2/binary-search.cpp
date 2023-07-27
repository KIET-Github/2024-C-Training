#include <bits/stdc++.h>
using namespace std;

// Iterative Binary Search
int binarySearch(int arr[], int len, int find){
	int low = 0;
	int high = len - 1;

	while(low <= high){
		int mid = low + (high - low)/2;
		if(arr[mid] == find)
			return mid;
		else if(arr[mid] < find)
			low = mid + 1;
		else
			high = mid - 1;
	}
	return -1;
}


// Recursive Binary Search
int recursiveBinarySearch(int arr[], int low, int high, int find){
	int mid = low + (high - low)/2;

	while(low <= high){
		if(arr[mid] == find)
			return mid;
		else if(arr[mid] < find)
			return recursiveBinarySearch(arr,mid + 1,high,find);
		else if(arr[mid] > find)
			return recursiveBinarySearch(arr,low,mid - 1,find);
	}
	return -1;
}


int main()
{
	int arr[10] = {1,2,3,4,5,7,8,9,11,15};
	int len = 10;
	int find = 7;
	if(binarySearch(arr,len,find) == -1)
		cout << "Element not found\n";
	else
		cout << "Element found at index " << binarySearch(arr,len,find) << endl;

	cout << "Calling Recursive Binary Search Function" << endl;

	int low = 0;
	int high = len - 1;
	if(recursiveBinarySearch(arr,low,high,find) == -1)
		cout << "Element not found\n";
	else
		cout << "Element found at index " << recursiveBinarySearch(arr,low,high,find) << endl;

    return 0;
}
