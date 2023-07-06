#include<bits/stdc++.h>
using namespace std; 

int no_of_pairs_whose_sum_is_k(vector<int> &v, int k,int n){
	int i = 0, j = n-1;
	int ans = 0; 
	while(i<j){
		if((v[i]+v[j])>k){
			j--; 
		}
		else if(v[i]+v[j]<k){
			i++; 
		}
		else{
			if(v[i]!=v[j]){
			int x = v[i]; 
			int y = v[j]; 
			int ct= 0, ct2= 0; 
			while(v[i] == x){
				i++;
				ct++;
			}
			while(v[j] == y){
				j--;
				ct2++; 
			}
			ans+= ct*ct2; 
			}
			else{
				int ct =j-i+1; 
				ans+= (ct *(ct-1))/2; 
				break; 
			}
		}
	}
	return ans; 
}
int pair_whose_diff_is_k(vector<int> &v, int k ){
	int i = v.size()-2; 
	int j = v.size()-1; 
	while(i>=0){
		int diff = v[j] - v[i]; 
		if(k == diff){
			if(v[i] != v[j]){
			cout<<v[i] <<" "<<v[j]<<endl; 
			}
			else{
				i--; 
			}
			return 1; 
		}
		else if(k>diff){
			i--; 
		}else{
			j--; 
		}
	}
	return 0; 
}
int main(){
	
	int n,k; 
	cin>>n>>k; 
	vector<int> v(n,0); 
	for(int i =0; i<n ;i++){
		cin>>v[i]; 
	}
	pair_whose_diff_is_k(v,k);
	return 0;
}