#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

const int MAXN = 1e3 + 10;
int w[MAXN];//w[i]�����i��Ԫ�ص����
int v[MAXN];//v[i]�����i��Ԫ�صļ�ֵ
int f[MAXN][MAXN];//f[i][j]����ǰi����Ʒ,ռ��j���ʱ������ֵ
int n,m;

int main() {
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++)
		scanf("%d%d",&w[i],&v[i]);
	//��ʼ���Ͷ���
	
	f[0][0] = 0;
	for (int i=1;i<=n;i++)
		for (int j=0;j<=m;j++) {
			if (j-w[i]<0)
				f[i][j] = f[i-1][j];
			else
				f[i][j] = max(f[i-1][j] , f[i-1][j-w[i] ] + v[i]);
		}
	//���Ƽ���f[i][j]
	printf("%d",f[n][m]);
	//�����
    return 0;
}
