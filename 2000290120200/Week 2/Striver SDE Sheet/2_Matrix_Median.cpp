#include<bits/stdc++.h>

int getMedian(vector<vector<int>> &matrix)
{
    int start=INT_MAX, end=INT_MIN;
    int n=matrix.size(), m=matrix[0].size();

    for(int i=0; i<n; i++)
    {
        start = min(start, matrix[i][0]);

        end = max(end, matrix[i][m-1]);
    }

    int midpos = (n*m+1)/2;

    while(start<=end)
    {
        int mid = start+(end-start)/2, count = 0;

        for(int i=0; i<n; i++)
        {
            int index = upper_bound(matrix[i].begin(), matrix[i].end(), mid)-matrix[i].begin();
            count += index;
        }

        if(count < midpos)
            start = mid+1;
        else
            end = mid-1;
    }

    return start;
}