#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

struct heap{
	//int a[100000 + 5] = {0};	
	vector <int> a;	//vector��һ��Ҫ�ĵĵط�
	int cnt = 0;
	bool flag = 0;//true�������ѣ�false����С����
	
	heap(){	//���캯��
		//printf("������һ���ѣ�\n");
		a.push_back(0);	//vector���ĸ�Ҫ�ĵĵط�
	}
	
	bool cmp(int x,int y){
		if (flag)	
			return (x>y);
		else	
			return (x<y);
	}
	
	
	int size(){
		return cnt;
	}
	
	int top(){
		if (cnt>0)	return a[1];
		else return 0;//�Ƿ�
	}
	
	int push(int x){
		a.push_back(x),cnt++;	//vector�ڶ���Ҫ�ĵĵط�
		//a[++cnt] = x;
		int i = cnt;
		while (i>1 && cmp(a[i],a[i/2])){
			swap(a[i],a[i/2]);
			i/=2;
		}
	}
	
	int pop(){
		a[1] = a[cnt--];
		a.pop_back();		//vector������Ҫ�ĵĵط�
		int i = 1,j;
		while (i*2<=cnt) {
			j = i*2;
			if (j+1<=cnt && cmp(a[j+1],a[j]))
				j++;
			if (cmp(a[j],a[i])){
				swap(a[i],a[j]);
				i = j;
			}
			else break;
		}
	}
	
};

int n,k,x;

int main(){
	scanf("%d%d",&n,&k);
	heap h;
	h.flag = true;//��Ϊ�����
	for (int i=1;i<=n;i++){
		scanf("%d",&x);
		h.push(x);	//������
	}
	for (int i=1;i<=k;i++){
		x = h.top();
		h.pop();
		h.push(x- x/2);	//ȡ�����ʯ�Ӻ�Ż�һ��
	}
	int cnt = 0;
	while (h.size()>0){
		cnt += h.top();
		h.pop();
	}
	printf("%d",cnt);
}
//���ϵĶѶ�����д�ѣ�C++���Դ�������ģ��ѡ� 
