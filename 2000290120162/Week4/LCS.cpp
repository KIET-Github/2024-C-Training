#include <bits/stdc++.h>
using namespace std;

void lcs(char *S1, char *S2, int m, int n) {
  int LCS_t[m + 1][n + 1];
  for (int i = 0; i <= m; i++) {
    for (int j = 0; j <= n; j++) {
      if (i == 0 || j == 0)
        LCS_t[i][j] = 0;
      else if (S1[i - 1] == S2[j - 1])
        LCS_t[i][j] = LCS_t[i - 1][j - 1] + 1;
      else
        LCS_t[i][j] = max(LCS_t[i - 1][j], LCS_t[i][j - 1]);
    }
  }
  int index = LCS_t[m][n];
  char lcs[index + 1];
  lcs[index] = '\0';

  int i = m, j = n;
  while (i > 0 && j > 0) {
    if (S1[i - 1] == S2[j - 1]) {
      lcs[index - 1] = S1[i - 1];
      i--;
      j--;
      index--;
    }
    else if (LCS_t[i - 1][j] > LCS_t[i][j - 1])
      i--;
    else
      j--;
  }
  cout << "S1 : " << S1 << "\nS2 : " << S2 << "\nLCS: " << lcs << "\n";
}

int main() {
  char s1[] = "BCDAACD";
  char s2[] = "ACDBAC";
  int m = strlen(s1);
  int n = strlen(s2);

  lcs(s1, s2, m, n);
}
