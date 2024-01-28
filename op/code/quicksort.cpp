#include<iostream>

using namespace std;

const int N = 1e6+10;
int n , q[N];

void qsr(int *q , int l , int r)
{
	if(l >= r)return ;
	int x = q[l + r + 1 >> 1 ] , i = l - 1 , j = r + 1;
	while(i < j )
	{
		while(q[++ i ] < x );
		while(q[-- j ] > x );
		if(i < j )swap(q[i] , q[j]);
	}
	qsr( q , l ,i - 1 );
	qsr( q , i , r );
}

int main(void)
{
	int x ;
	while(cin >> x)q[n ++] = x;
	qsr(q , 0 , n - 1 );
	for(int i = 0 ; i < n ; i ++)printf("%d ",q[i]);
	return 0;
}

