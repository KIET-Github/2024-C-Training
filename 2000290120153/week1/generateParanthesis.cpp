#include<bits/stdc++.h> 
using namespace std;
vector<string> v; 
void f(string &par,int n,int op,int cl){
	if(idx == 2*n){
		v.push_back(par); 
		return; 
	}
	if(cl<op){
		return; 
	}

	if(op<cl){

		f(par+="(",n,op-1,cl); 
		par.pop_back(); 
		f(par+=")",n,op,cl-1); 
	}
	else if(op== cl){
		f(par+=")",n,op-1,cl); 
	}

} 
int main(){
	int n; 
	cin>>n; 
	string p="";
	f(p,n,n,n); 
	return 0; 
}