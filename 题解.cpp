#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;
const int mx = 1e5 + 10;
int n, m;
struct T {
    int l, r;        //ÿ��ͬѧ�ġ������֡� 
    int d;          //��ʾͬѧ�Ƿ���� 
}t[mx] = { 0 };
void add(int i, int k, int f)       //����ͬѧ 
{
    if (f == 1)         //�� 
    {
        t[k].r = t[i].r;
        t[k].l = i;
        t[i].r = k;
        t[t[k].r].l = k;
    }
    else             //�� 
    {
        t[k].r = i;
        t[k].l = t[i].l;
        t[i].l = k;
        t[t[k].l].r = k;
    }
}
int main()
{
    int x, k, f;
    cin >> n;
    t[0].r = 0, t[0].l = 0;
    add(0, 1, 1);
    for (int i = 2; i <= n; i++)
    {
        cin >> x >> f;
        add(x, i, f);
    }
    cin >> m;
    while (m--)
    {
        cin >> x;
        t[x].d = 1;         //����ͬѧ���Ϊ����� 
    }
    for (int i = t[0].r; i; i = t[i].r)
    {
        if (t[i].d == 0)    //���δ��ǵ� 
            cout << i << " ";
    }
    return 0;
}