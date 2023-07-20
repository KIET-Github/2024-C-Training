#include<bits/stdc++.h>
using namespace std; 
/*

void f(int idx, string &s){
	if(idx == s.size()-1){
		cout<<s<<endl; 
		return; 
	}
	for(int i =idx; i<s.size(); i++){
		swap(s[idx],s[i]);
		f(idx+1,s); 
		swap(s[idx],s[i]); 
	}
}
void leftRotate(string &s,int strt,int las){
    	if(strt == las){
    		return; 
    	}
        char last = s[las]; 
        for(int i =las;i>strt;i--){
        	s[i] = s[i-1]; 
        }
        s[strt] = last;
    }
void rightRotate(string &s,int strt,int last){
    	if(strt == last){
    		return; 
    	}
        char first = s[strt]; 
        for(int i = strt; i<last; i++){
            s[i] = s[i+1];
        }
        s[last] = first; 
    }
void inSortedOrder(int idx,string &s){
	if(idx == s.size()-1){
		cout<<s<<endl; 
		return; 
	}
	for(int i =idx; i<s.size(); i++){
		leftRotate(s,idx,i);
		inSortedOrder(idx+1,s); 
		rightRotate(s,idx,i); 
	}
}
*/

void uniquePermutations(int idx,string &s, int hsh[]){ 
	if(idx == s.size()-1){
		cout<<s<<endl; 
		return; 
	}
	for(int i= idx; i<s.size(); i++){
		if(hsh[s[i]]==0){
			swap(s[idx],s[i]); 
		hsh[s[idx]] = 1; 
		uniquePermutations(idx+1,s,hsh); 
			swap(s[idx],s[i]);
		}
	}
}
int main(){
	string s; 
	cin>>s;
	int hsh[257] = {0};  
	//f(0,s); 
	uniquePermutations(0,s,hsh); 
	return 0; 
}