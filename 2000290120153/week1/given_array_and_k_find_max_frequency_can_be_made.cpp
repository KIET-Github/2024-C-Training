#include<bits/stdc++.h>
using namespace std; 
int bs(vector<int> &v,int k, int j,vector<int> &p ){
	int l= 0, h = j;
	while(l<=h){
		int mid = (l+h)/2;
		int val = v[j]*(j-mid+1) -(p[j]-p[mid]);
		if(val>k){
			l=mid+1; 
		}
		else{
			val =mid-1; 	
			if(val>k){
				return mid; 
			}
			else{
				h = mid-1; 
			}
		}
	}
	return j; 
}
int main(){
	int n,k; 
	cin>>n>>k; 
	vector<int> v(n,0);
	vector<int> prefix(n,0);  
	for(int i =0; i<n;i++){
		cin>>v[i]; 
	}
	prefix[0] = v[0]; 
	for(int i = 1;i<n ;i++){
		prefix[i] = v[i]+prefix[i-1]; 
	}

	sort(v.begin(), v.end());
	int ma = INT_MIN;  
	for(int j =0; j<n;j++){
		int i = bs(v,k,j, prefix); 
		ma = max(ma,j-i+1); 
	}
	cout<<ma<<endl; 

	return 0; 
}