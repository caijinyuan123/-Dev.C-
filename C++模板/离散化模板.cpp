#include<cstdio>
#include<cstring>
#include<iostream>
#include<cmath>
#include<string>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>
using namespace std;
typedef long long LL;
const int MR=1e5+10;
int n,m;
int a[MR],b[MR];
int d[MR*2],all[MR*2],idA[MR],idB[MR];
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d%d",a+i,b+i);
        all[i]=a[i];
        all[i+n]=b[i];
    }
    sort(all+1,all+1+2*n);
    int p=unique(all+1,all+1+2*n)-all-1;
    for(int i=1;i<=n;i++){
        idA[i]=lower_bound(all + 1, all + p + 1, a[i]) - all;
        idB[i]=lower_bound(all + 1, all + p + 1, b[i]) - all;
        d[idA[i]]++;
        d[idB[i]+1]--;
    }
    int ans=0;
    for(int i=1;i<=p;i++){
        d[i]+=d[i-1];
        ans=max(ans,d[i]);
    }
    printf("%d\n",ans);
    return 0;
}
/*��ɢ����ʵֻ��������ô��unique��lower-bound�����ˣ����ģ�����ҵ�һ����Ŀ����Ϊ�Ƚ�
 ���������Ե���ģ������*/
