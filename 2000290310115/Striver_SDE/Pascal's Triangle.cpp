vector<int> generaterow(int row)
{
    long long ans=1;
    vector<int>resrow;
    resrow.push_back(1);
    for(int col=1;col<row;col++)
    {
        ans=ans*(row-col);
        ans=ans/col;
        resrow.push_back(ans);
    }
    return resrow;
}
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>pascal;
        for(int i=1;i<=numRows;i++)
        {
            pascal.push_back(generaterow(i));
        }
        return pascal;
    }
