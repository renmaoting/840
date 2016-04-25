/*************************************************************************
	> File Name: game.cpp
	> Author:Maoting Ren 
	> Mail: mren@g.clemson.edu
	> Created Time: Sun 24 Apr 2016 07:00:31 PM EDT
 ************************************************************************/

#include<iostream>
#include<vector>
#include<algorithm>
#include<time.h>
using namespace std;

bool dp(const vector<int>& nums)
{
    int n = nums.size();
    vector<int> sum(n+1,0);
    vector<vector<int> > M(n,vector<int>(n));
    for(int i =0; i< n; i++)
        M[i][i] = nums[i];
    for(int i =0; i< n; i++)
        sum[i+1] = sum[i]+ nums[i];    
    for(int i = 1; i< n; i++)
        for(int j = 0; j < n-i; j++)
            M[j][j+i] = sum[j+i+1] - sum[j] - min(M[j+1][j+i], M[j][j+i-1]); 

    cout << "sum = "<<sum[n] << "  gain = " << M[0][n-1] << endl;
    return M[0][n-1]>sum[n]/2?true:false;
}

bool dp2( const vector<int>& nums)
{
    int n = nums.size();
    vector<int> sum(n+1,0);
    for(int i =0; i< n; i++)
        sum[i+1] = sum[i]+ nums[i];    
    vector<vector<int> > M(n,vector<int>(n));
    for(int i =0; i< n; i++)
    {
        M[i][i] = nums[i];
        if(i !=0)
            M[i][i-1] = 0;
    }
    for(int i =1; i< n; i++)
    {
        for(int j =0; j < n-i; j++)
        {
            if(i+j-2 < 0 || j+2 >= n) continue;
            M[j][i+j] = max(nums[j] + min(M[j+2][i+j], M[j+1][i+j-1]), nums[i+j] + min(M[j][i+j-2], M[j+1][i+j-1]) );    
        }
    }
    cout << "sum = "<<sum[n] << "  gain = " << M[0][n-1] << endl;
    return M[0][n-1]>sum[n]/2?true:false;
}

int main()
{
    srand(time(NULL));
    //for(int k = 0; k < 100; k++)
    //{
    vector<int> nums;
    int n = 5;
    nums.reserve(n);
    for(int i =0; i< n; i++)
        nums.push_back(rand()%200);
    for(int i =0; i< n; i++)
        cout << nums[i] << " ";
    cout << endl;
    cout << dp(nums) << endl;
    //}
    cout << dp2(nums) << endl;


    return 0;
}
