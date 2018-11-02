#include<iostream>
using namespace std;

int n,M;
int arr[1000010];
int main()
{
    int q,L,R,P,l,r;
    while(cin >> n >> M)
    {
        for(int i = 0;i<n;i++)
            cin >> arr[i];
        for(int i = 0;i<M;i++)
        {
            cin >> q>> L>>R>>P;
            for(int j = L;j<=R;j++)
            {
                if(q == 1) arr[j]-=P;
                else arr[j]+=P;
            }
        }
        cin >> l >> r;
        long long max = 0;
        for(int i = l;i<=r;i++)
            max += arr[i];
        cout << max << endl;
    }
    return 0;
}
