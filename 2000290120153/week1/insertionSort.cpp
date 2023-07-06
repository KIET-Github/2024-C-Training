#include <bits/stdc++.h>
using namespace std;

void insertionSort(vector<int> &v, int n){
	
	for(int i =1;i<n;i++){
		int k2 = v[i]; 
		int j = i-1; 
		while( j>=0 && v[j]>k2 ){
			v[j+1] = v[j];  
			j--; 
		}
		v[j+1] = k2;
	}
}

int main(){
	int n;
	cin>>n; 
	vector<int> v(n,0); 
	for(int i =0; i<n;i++){
		cin>>v[i]; 
	}
	insertionSort(v,n); 
	for(int i : v){
		cout<<i<<" "; 
	}
	return 0; 
}