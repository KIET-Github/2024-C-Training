#include<bits/stdc++.h>
using namespace std;
int inv= 0; 
void merges(vector<int> &v, int s1, int c1,int s2, int c2 ,int tmp[]){
	int i =s1, j=s2,k=0; 
	while(i<=c1 && j<=c2){
		if(v[i]>v[j]){
			tmp[k] = v[j];
			j++; 
		}
		else{
			tmp[k] = v[i];
			i++;  
		}
		k++; 
	}
	while(i<=c1){
		tmp[k] = v[i];
		i++;
		k++; 
	}
	while(j<=c2){
		tmp[k] = v[j]; 
		j++;
		k++;
	}
	for(int i =s1; i<=c2;i++){
		v[i] = tmp[i-s1]; 
	}
}

void mergeSort(vector<int> &v, int lo,int hi,int tmp[]){
	if(lo<hi){
		int mid = lo+(hi-lo)/2;
		mergeSort(v,lo,mid,tmp); 
		mergeSort(v,mid+1,hi,tmp); 
		merges(v,lo,mid,mid+1,hi,tmp); 
	}
} 

int main(){
	int n; 
	cin>>n; 
	vector<int> v(n,0); 
	for(int i =0 ;i< n; i++){
		cin>>v[i]; 
	}
	int tmp[n]= {0}; 
	mergeSort(v,0,v.size()-1,tmp); 
	for(int i:v){
		cout<<i<<" ";
	}
	cout<<endl;
	cout<<inv<<endl;
	return 0; 
}