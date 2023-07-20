#include<bits/stdc++.h>
using namespace std;
int concat(int a, int b)
{
 
    string s1 = to_string(a);
    string s2 = to_string(b);
    string s = s1 + s2; 
    int c = stoi(s);
    return c;
}
bool cmp(int a,int b){
	int x =concat(a,b); 
	int y = concat(b,a); 
	return x>y; 
}
int main(){
	int n ;
	cin>>n; 
	vector<int> v(n,-1);
	for(int i=0;i<n;i++){
		cin>>v[i]; 
	}
	sort(v.begin(),v.end(), cmp); 

	for(int i:v){
		cout<<i<<""; 
	}
	cout<<endl; 
	return 0; 
}