#include<cstdio>
#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>

using namespace std;

struct heap{
	int a[100000 + 5] = {0};
	int cnt = 0;
	bool flag = 0;//false��ʾС���ѣ�true��ʾ�����
	
	bool cmp(int x,int y){//���x���ȼ���y֮�ϣ�����true
		if (!flag) 
			return x<y;//С����
		else
			return x>y;//�����
	}
	
	int size(){
		return cnt;
	}
	
	int top(){
		return a[1];
	}
	
	int push(int x){
		a[++cnt] = x;
		int i = cnt;
		while (i>1){
			if (cmp(a[i],a[i/2])){
				swap(a[i],a[i/2]);
				i = i/2;
			}
			else break;
		}
	}
	
	int pop(){
		a[1] = a[cnt--];
		int i = 1,j;
		while (i*2<=cnt){
			j = i*2;
			if (j+1<=cnt && cmp(a[j+1],a[j]))
				j = j+1;
			if ( cmp(a[j],a[i]) ){
				swap(a[j],a[i]);
				i = j;
			} 
			else break;
		}
	}
};

//heap h;
priority_queue <int, vector<int>, greater<int>   > h;

int main(){
	int n,x;
	//h.flag = 1;
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
		scanf("%d",&x),h.push(x);
	for (int i=1;i<=n;i++)
		printf("%3d",h.top()), h.pop();
	return 0;
}
//���ϵĶѶ�����д�ѣ�C++���Դ�������ģ��ѡ� 
