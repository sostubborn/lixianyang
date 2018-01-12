#include <iostream>  
  
using namespace std;  
  
int c1, c2;         //分别载重量  
int n;              //集装箱数量  
int w[100];         //集装箱重量  
int cw;             //c1当前载重量  
int bestw;          //c1当前最优载重量  
int r;              //剩余集装箱重量  
int x[100];         //当前解  
int bestx[100];      //当前最优解  
  
void Backtrack(int i)  
{  
    if(i > n)  
    {  
        //当前解由于最优解，更新之  
        if(cw > bestw)  
        {  
            for(int j = 1; j <= n; j++)  
                bestx[j] = x[j];  
            bestw = cw;  
        }  
        return;  
    }  
  
    //搜索子树,放入或不放入  
    r -= w[i];              //剩余容量集合去掉w[i]  
    if(cw + w[i] <= c1)     //可放入，且放入  
    {  
        x[i] = 1;           //放入  
        cw += w[i];  
        Backtrack(i+1);  
  
        cw -= w[i];  
    }  
    if(cw + r > bestw)      //剩余容量集合依然是去掉w[i],因为w[i]不放入  
    {  
        x[i] = 0;  
        Backtrack(i+1);  
    }  
  
    r += w[i];              //回溯  
}  
  
int main()  
{  
    while((cin >> c1 >> c2 >> n) && n)  
    {  
        cw = 0;             //每组样例初始化  
        r = 0;  
        bestw = 0;  
  
        for(int i = 1; i <= n; i++)  
        {  
            cin >> w[i];  
            r += w[i];  
        }  
        Backtrack(1);  
        if(r-bestw <= c2)  
            cout << "Yes" << endl;  
        else  
            cout << "No" << endl;  
    }  
  
    return 0;  
}
