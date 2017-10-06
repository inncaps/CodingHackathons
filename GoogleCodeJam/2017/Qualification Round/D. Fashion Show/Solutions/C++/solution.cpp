#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct edge{
	int t,next;
}g[200001];
char ch[11];
int tot,v[511],a[211][211],b[211][211],i,j,k,n,m,d[511],tests,tc,h[511],ans,q[21001][2],cot;
int p1[511],p2[511],w1[511],w2[511],ct1[511],ct2[511];
void addedge(int x,int y){
	g[++tot].t=y;g[tot].next=h[x];h[x]=tot;
}
bool find(int x){
	int i;
	for (i=h[x];i;i=g[i].next)
	 if (!v[g[i].t]){
	 	v[g[i].t]=1;
	 	if (!d[g[i].t]||find(d[g[i].t])){
	 		d[g[i].t]=x;return 1;
		 }
	 }
	return 0;
}
bool check(){
	int i,j,k;
	memset(ct1,0,sizeof(ct1));memset(ct2,0,sizeof(ct2));
	for (i=1,k=0;i<=n;i++)
	 for (j=1;j<=n;j++){
	 	if (b[i][j]) k++;
	 	if (b[i][j]==3) k++;
	 	if ((a[i][j]&b[i][j])!=a[i][j]) return 0;
		if (b[i][j]&1) ct1[i]++,ct2[j]++;
	 }
	if (k!=ans) return 0;
	for (i=1;i<=n;i++)
	 if (ct1[i]>1||ct2[i]>1) return 0;
	memset(ct1,0,sizeof(ct1));memset(ct2,0,sizeof(ct2));
	for (i=1,k=0;i<=n;i++)
	 for (j=1;j<=n;j++)
	  if (b[i][j]>=2) ct1[n+i-j]++,ct2[i+j-1]++;
	for (i=1;i<=2*n-1;i++)
	 if (ct1[i]>1||ct2[i]>1) return 0;
	return 1;
}
int main(){
	//freopen("t1.in","r",stdin);
	for (scanf("%d",&tests),tc=1;tc<=tests;tc++){
		scanf("%d%d",&n,&m);
		memset(b,0,sizeof(b));memset(a,0,sizeof(a));
		memset(w1,0,sizeof(w1));memset(w2,0,sizeof(w2));memset(p1,0,sizeof(p1));memset(p2,0,sizeof(p2));ans=0;
		tot=0;memset(h,0,sizeof(h));memset(d,0,sizeof(d));
		for (i=1;i<=m;i++){
			scanf("%s%d%d",ch,&j,&k);
			if (ch[0]=='+') a[j][k]=2,p2[n+j-k]=j+k-1,w2[j+k-1]=1;
			if (ch[0]=='x') a[j][k]=1,p1[j]=k,w1[k]=1;
			if (ch[0]=='o') a[j][k]=3,p1[j]=k,p2[n+j-k]=j+k-1,w1[k]=1,w2[j+k-1]=1;
		}
		for (i=1;i<=n;i++)
		 if (p1[i]) addedge(i,p1[i]);
		 else{
		 	for (j=1;j<=n;j++)
			  if (!w1[j]) addedge(i,j);
		 }
		for (i=1;i<=n;i++){
			memset(v,0,sizeof(v));
			if (find(i)) ans++;
		}
		for (i=1;i<=n;i++)
		 if (d[i]) b[d[i]][i]=1;
		tot=0;memset(h,0,sizeof(h));memset(d,0,sizeof(d));
		for (i=1;i<=2*n-1;i++)
		 if (p2[i]) addedge(i,p2[i]);
		for (i=1;i<=n;i++)
		 for (j=1;j<=n;j++)
		  if (!p2[n+i-j]&&!w2[i+j-1]) addedge(n+i-j,i+j-1);
		for (i=1;i<=2*n-1;i++){
			memset(v,0,sizeof(v));
			if (find(i)) ans++;
		}
		for (i=1;i<=2*n-1;i++)
		 if (d[i]) b[(i+d[i]+1-n)/2][(i-d[i]+1+n)/2]+=2;
		for (i=1,cot=0;i<=n;i++)
		 for (j=1;j<=n;j++)
		  if (a[i][j]!=b[i][j]) q[++cot][0]=i,q[cot][1]=j;
		printf("Case #%d: %d %d\n",tc,ans,cot);
		for (i=1;i<=cot;i++)
		 if (!a[q[i][0]][q[i][1]]){
		 	if (b[q[i][0]][q[i][1]]==1) printf("x %d %d\n",q[i][0],q[i][1]);
		 	if (b[q[i][0]][q[i][1]]==2) printf("+ %d %d\n",q[i][0],q[i][1]);
		 	if (b[q[i][0]][q[i][1]]==3) printf("o %d %d\n",q[i][0],q[i][1]);
		 }else printf("o %d %d\n",q[i][0],q[i][1]);
		if (!check()) puts("!!!!!FAILED!!!!!!");
	}
	return 0;
}
