// 0-1 Knapsack
#include <iostream>
#include <climits>
using namespace std;
int knapSack(int v[], int w[], int n, int W) {
   if (W < 0)
      return INT_MIN;
   if (n < 0 || W == 0)
      return 0;
   int in = v[n] + knapSack(v, w, n - 1, W - w[n]);
   int ex = knapSack(v, w, n - 1, W);
   return max (in, ex);
}
int main() {
   int v[] = { 10, 20, 30, 40, 60, 70 };
   int w[] = { 1, 2, 3, 6, 7, 4 };
   int W = 7;
   int n = sizeof(v) / sizeof(v[0]);
   cout << "Knapsack value is " << knapSack(v, w, n - 1, W);
   return 0;
}

// Longest Common Subsequence
#include <iostream>
using namespace std;

void lcsAlgo(char *S1, char *S2, int m, int n) {
  int LCS_table[m + 1][n + 1];
  for (int i = 0; i <= m; i++) {
    for (int j = 0; j <= n; j++) {
      if (i == 0 || j == 0)
        LCS_table[i][j] = 0;
      else if (S1[i - 1] == S2[j - 1])
        LCS_table[i][j] = LCS_table[i - 1][j - 1] + 1;
      else
        LCS_table[i][j] = max(LCS_table[i - 1][j], LCS_table[i][j - 1]);
    }
  }
  int index = LCS_table[m][n];
  char lcsAlgo[index + 1];
  lcsAlgo[index] = '\0';

  int i = m, j = n;
  while (i > 0 && j > 0) {
    if (S1[i - 1] == S2[j - 1]) {
      lcsAlgo[index - 1] = S1[i - 1];
      i--;
      j--;
      index--;
    }
    else if (LCS_table[i - 1][j] > LCS_table[i][j - 1])
      i--;
    else
      j--;
  }
  cout << "S1 : " << S1 << "\nS2 : " << S2 << "\nLCS: " << lcsAlgo << "\n";
}

int main() {
  char S1[] = "ACADB";
  char S2[] = "CBDA";
  int m = strlen(S1);
  int n = strlen(S2);

  lcsAlgo(S1, S2, m, n);
}

// Matrix Chain Multiplication
#include<bits/stdc++.h>
using namespace std;
int MatrixChainOrder(int p[], int n) 
{ 
  int m[n][n]; 
  int i, j, k, L, q; 
  for (i=1; i<n; i++) 
    m[i][i] = 0; 
  for (L=2; L<n; L++) 
  { 
    for (i=1; i<n-L+1; i++) 
    { 
      j = i+L-1; 
      m[i][j] = INT_MAX; 
      for (k=i; k<=j-1; k++) 
      { 
        q = m[i][k] + m[k+1][j] + p[i-1]*p[k]*p[j]; 
        if (q < m[i][j]) 
          m[i][j] = q; 
      } 
    } 
  } 
return m[1][n-1]; 
} 
int main() 
{ 
  int arr[] = {5,4,6,2,7}; 
  int size = 5; 
    cout<<MatrixChainOrder(arr,size)<<" operations";
} 
