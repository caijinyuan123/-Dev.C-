#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=2e5+5;
typedef long long LL;
int a[MAXN],b[MAXN],idA[MAXN],ans;
bool vis[MAXN];

int main() {
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        b[i]=a[i];
    }
    sort(b+1,b+1+n);
    int p=unique(b+1,b+1+n)-b-1;
    //for(int i=1;i<=p;i++) printf("%d ",b[i]);printf("\n");
    for(int i=1;i<=n;i++){
        idA[i]=lower_bound(b+1,b+1+p,a[i])-b;
        //printf("%d ",idA[i]);
    }
    int l=1,r=n;
    memset(vis,0,sizeof(vis));
    while(r>=1 && !vis[idA[r]]){
        vis[idA[r]]=1;
        r--;
    }
    if(r==0){
        printf("0\n");
        return 0;
    }
    ans=r-l+1;
    //����l��������r������������˿��ó�ȡ��
    while(l<r){		//���Բ���ɾ����l��Ԫ��
        if(vis[idA[l]]){		//�����l��Ԫ��ԭ���ѳ���
            while(r<n && vis[idA[l]]){	//�Ҷ���Ҫɾ����l��Ԫ����ʧΪֹ
                r++;
                vis[idA[r]]=0;
            }
        }
        if(r==n && vis[idA[l]]){	//���r�Ѿ����������Բ���������l��Ԫ�أ����޽�
            break;
        }
        vis[idA[l]]=1;
        l++;
        ans=min(ans,r-l+1);			//���´�
    }
    printf("%d\n",ans);
    return 0;
}
