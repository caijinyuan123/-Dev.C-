#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 1e5 + 10;

int f[MAXN];//f[i]�洢i�Žڵ�ĸ���
int h[MAXN];//h[i]�洢i�Žڵ�����
int l[MAXN],r[MAXN];//l[i],r[i]�洢i�Žڵ�����Ҷ���
int g[MAXN][4];	//g[i][j]�洢i�Žڵ��j�����ӵ��λ��
bool used[MAXN];
int num[MAXN];//num[i]�洢��i��Ŀ��
int root;//root�洢�������ĸ��ڵ�
int n,ans;


void dfs(int x){//��Ӹ���x�����
	if (x==0) return;		//�Ը�����
	if (h[x]!=0)	return;	//���仯����
	dfs(f[x]);				//�����׵����
	h[x] = h[ f[x] ]+1;
}

bool build(int x){
	if (used[x]||x==0)	return false;//���仯
	used[x] = true;
	bool left = false;
	for (int i=1;i<=g[x][0];i++){
		int y = g[x][i];
		if (build(y) ){
			if (!left){	//�ҵ������
				l[x] = y;
				f[y] = x;
				left = true;
			}
			else {		//�ҵ��Ҷ���
				r[x] = y;
				f[y] = x;
			}
		}
	}
		
}

int main(){
	scanf("%d",&n);
	for (int i=1;i<=n-1;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		g[x][ ++g[x][0] ] = y;
		g[y][ ++g[y][0] ] = x;
	}
	root = 1;
	build(1);
	f[0] = 0;
	int depth = 0,width = 0;//��ȣ����
	for (int i=1;i<=n;i++) {
		dfs(i);
		num[ h[i] ]++;
		depth = max(depth,h[i]);
		width = max(width, num[ h[i] ]);
	}		
	int cnt = 0;//�������
	int u,v;
	scanf("%d%d",&u,&v);
	while (u!=v){
		if ( h[u]>h[v] )
			u = f[u];
		else
			v = f[v];
		cnt++;
	}
	printf("%d\n%d\n%d",depth,width,cnt);
	
}
