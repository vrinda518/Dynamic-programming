/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*****************************************************************************/
int mcm(int *p, int n)
{
	// n is number of matrices
    // dimensions of p is hence n+1  
    int matrix[n+1][n+1];
    
    for (int i = 1; i<=n ; i++)
        matrix[i][i] = 0;
    for (int h = 1 ; h<n ; h++)
    {
        for (int i = 1; i<=n-h; i++)
    	{
        int j = i + h;
        int min = INT_MAX;
        for (int k = i; k<j; k++)
        {
            int val = matrix[i][k]+matrix[k+1][j] + (p[i-1]*p[k]*p[j]);
            if (val<min)
                min = val;
        }
        matrix[i][j] = min;
        }
    }
    
    /*for (int i = 0 ; i<=n ; i++)
    {
        for (int j = 0; j<=n ; j++)
        {
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }*/
    
    return matrix[1][n];
}
