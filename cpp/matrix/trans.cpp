/*************************************************************************
	> File Name: trans.cpp
	> Author: Maoting Ren
	> Mail: mren@g.clemson.edu
	> Created Time: Wed 27 Jan 2016 09:14:47 PM EST
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

inline int prePos(int m, int n, int index)
{
    return (index%m)*n + index/m; 
}

inline int nextPos(int m, int n, int index)
{
    return (index%n)*m + index/n;
}

void trans(vector<int>& matrix, int m, int n)
{
    int len = matrix.size();
    for(int i = 0; i< len; i++)
    {
        int pre = prePos(m,n,i), next = nextPos(m,n,i); 
        //指针向两方向同时移动
        while(pre > i && next > i && pre!= next && prePos(m, n, pre) != next) 
        {
            pre = prePos(m,n,pre);
            next = nextPos(m,n,next); 
        }
        if(pre < i || next < i) 
            continue;
        int cur =i, val = matrix[i];
        pre = prePos(m, n, cur);
        while(pre != i)
        {
            matrix[cur] = matrix[pre];
            cur = pre;
            pre = prePos(m, n, cur);
        }
        matrix[cur] = val;
    } 
}
int main()
{
    vector<int> vec;
    int m = 2, n = 5;
    for(int i = 0; i< 10; i++)
       vec.push_back(i);
    for(int i = 0; i< m; i++)
    {
        for(int j = 0; j< n; j++)
            cout << vec[i*n+j] << " ";
        cout << endl;
    }
    cout << endl;
    trans(vec, m, n); 
    for(int i = 0; i< n; i++)
    {
        for(int j = 0; j< m; j++)
            cout << vec[i*m+j] << " ";
        cout << endl;
    }

    return 0;
}





