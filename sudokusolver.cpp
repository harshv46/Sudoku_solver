#include<iostream>
#include<math.h>
using namespace std;

bool iscorrect(int sudoku[][16],int n,int i,int j,int k)
{
    //check in row
    for(int itr=0;itr<n;itr++)
    {
        if(itr!=j&&sudoku[i][itr]==k)
            return false;
    }
    //check in coloumn
    for(int itr=0;itr<n;itr++)
    {
        if(itr!=i&&sudoku[itr][j]==k)
            return false;
    }
    //check in subgrid
    int x=((int)(j/(int)sqrt(n)))*(int)sqrt(n);
    int y=((int)(i/(int)sqrt(n)))*(int)sqrt(n);
    for(int l=0;l<sqrt(n);l++)
    {
        for(int m=0;m<sqrt(n);m++)
        {
            if((x+m)!=j&&(y+l)!=i&&sudoku[y+l][x+m]==k)
                return false;
        }
    }
    return true;
}

bool solveSudoku(int sudoku[][16],int n,int i,int j)
{
    if(i==n)
    {
        //print sol
        cout<<"\nSolved!"<<endl;
        for(int l=0;l<n;l++)
        {
            for(int m=0;m<n;m++)
                cout<<sudoku[l][m]<<" ";
            cout<<endl;
        }
        return true;
    }
    if(sudoku[i][j]!=0)
    {
        if(j!=n-1)
            return solveSudoku(sudoku,n,i,j+1);
        else
            return solveSudoku(sudoku,n,i+1,0);
    }
    else if(j!=n-1)
    {
        int k;
        for( k=1;k<10;k++)
        {
            if(iscorrect(sudoku,n,i,j,k))
            {
                //cout<<"true for "<<k<<endl;
                sudoku[i][j]=k;
                bool flag=solveSudoku(sudoku,n,i,j+1);
                if(flag)
                    return true;
                //cout<<"wrong step at"<<i<<" "<<j<<"putting "<<k<<endl;
                sudoku[i][j]=0;
             }
            //cout<<"false for "<<k<<endl;
        }
        return false;
    }
    else if(j==n-1)
    {
        int k;
        for( k=1;k<10;k++)
        {
            if(iscorrect(sudoku,n,i,j,k))
            {
                sudoku[i][j]=k;
                bool flag=solveSudoku(sudoku,n,i+1,0);
                if(flag)
                    return true;
                sudoku[i][j]=0;
            }
        }
        return false;
    }
}

int main()
{
    int n;
    cin>>n;
    int sudoku[16][16]={0};
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            cin>>sudoku[i][j];
    bool sol=solveSudoku(sudoku,n,0,0);
    if(!sol)
        cout<<"Could not find solution!"<<endl;
    return 0;
}
/* Sample Input::

9
0 8 0 7 0 1 0 3 0
4 0 9 0 0 0 0 0 0
0 5 0 0 6 0 4 1 8
7 0 0 0 0 9 0 0 0
8 0 0 6 1 0 5 0 0
0 3 5 0 0 0 0 2 9
0 6 0 4 0 7 0 9 0
1 0 0 0 0 8 0 0 4
0 2 0 0 5 0 0 7 0

*/
