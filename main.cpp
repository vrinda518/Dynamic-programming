/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*****************************************************************************/
#include <bits/stdc++.h>
#include <iostream>
using namespace std;

// Complete the longestCommonSubsequence function below.
vector<int> longestCommonSubsequence(vector<int> a, vector<int> b) {

int m = a.size(); // size of first string
int n = b.size(); // size of second string


int arr[m+1][n+1];    
for (int i = 0; i<=m ; i++)
{
    for (int j = 0; j<=n ; j++)
    {
        if (i==0 || j==0)
        arr[i][j] = 0;
        
        else if (a[i-1] == b[j-1])
        arr[i][j] = 1+arr[i-1][j-1];
        
        else
        arr[i][j] = max(arr[i-1][j],arr[i][j-1]);
    }
}
vector<int> lcs;
int i = m;
int j = n;

while(i>0 && j>0)
{
    if (a[i-1]==b[j-1])
        {
            lcs.push_back(a[i-1]);
            i--;
            j--;
        }
    else if (arr[i-1][j]>arr[i][j-1])
        i--;
    else
        j--;
}
reverse(lcs.begin(),lcs.end());

    for (int i = 0; i<lcs.size()-1; i++)
    cout<<lcs[i]<<" ";
    cout<<lcs[i];

return lcs;
}


int main()
{
    int m,n;
    cin>>m>>n;
    vector<int> a;
    vector<int> b;
    int x;
    for (int i = 0; i<m; i++)
    {
        cin>>x;
        a.push_back(x);
    }
    for (int i = 0; i<n; i++)
    {
        cin>>x;
        b.push_back(x);
    }
    vector <int> res = longestCommonSubsequence(a,b);

    return 0;
}
