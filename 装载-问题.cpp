#include <iostream>  
  
using namespace std;  
  
int c1, c2;         //�ֱ�������  
int n;              //��װ������  
int w[100];         //��װ������  
int cw;             //c1��ǰ������  
int bestw;          //c1��ǰ����������  
int r;              //ʣ�༯װ������  
int x[100];         //��ǰ��  
int bestx[100];      //��ǰ���Ž�  
  
void Backtrack(int i)  
{  
    if(i > n)  
    {  
        //��ǰ���������Ž⣬����֮  
        if(cw > bestw)  
        {  
            for(int j = 1; j <= n; j++)  
                bestx[j] = x[j];  
            bestw = cw;  
        }  
        return;  
    }  
  
    //��������,����򲻷���  
    r -= w[i];              //ʣ����������ȥ��w[i]  
    if(cw + w[i] <= c1)     //�ɷ��룬�ҷ���  
    {  
        x[i] = 1;           //����  
        cw += w[i];  
        Backtrack(i+1);  
  
        cw -= w[i];  
    }  
    if(cw + r > bestw)      //ʣ������������Ȼ��ȥ��w[i],��Ϊw[i]������  
    {  
        x[i] = 0;  
        Backtrack(i+1);  
    }  
  
    r += w[i];              //����  
}  
  
int main()  
{  
    while((cin >> c1 >> c2 >> n) && n)  
    {  
        cw = 0;             //ÿ��������ʼ��  
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
