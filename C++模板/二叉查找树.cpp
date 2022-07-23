#include <cstdio>
#include <iostream>

using namespace std;

const int MAXN = 1e5 + 10;

int f[MAXN];			//f[i]��¼i�ĸ���
int l[MAXN],r[MAXN];	//l[i],r[i]��¼i�����Ҷ���
int root;				//root��¼��
int a[MAXN];			//a[i]��¼��i�����ֵ
int n,m=0;
int x;

void insert(int x,int key){	//��key���뵽��xΪ���Ķ����������
	int t = (key>a[x]?r[x]:l[x]);
	if (t==0){
		if (key>a[x])
			r[x] = m;
		else
			l[x] = m;
	}
	else 
		insert(t,key);
}


void midTrav(int x){
	if (x==0)	return;
	midTrav(l[x]);
	cout << a[x] << " ";
	midTrav(r[x]);
}
void lastTrav(int x){
	if (x==0)	return;
	lastTrav(l[x]);
	lastTrav(r[x]);
	cout << a[x] << " ";
	
}

int main(){
	cin >> n;
	for (int i=1;i<=n;i++){
		m++;
		cin >> a[m];
		if (m==1){
			root = 1;
			continue;		//�Ը�����
		}
		else
			insert(root,a[i]);
	}
	
	midTrav(root);
	cout << endl;
	lastTrav(root);
}


//�����������ʵ��map���棬�׳ƶ�������� 
