#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
char s[2001];
int i,j,k,n,m,tests,tc,a[2001],ans;
int main(){
	for (scanf("%d",&tests),tc=1;tc<=tests;tc++){
		scanf("%s%d",s,&m);n=strlen(s);
		for (i=1;i<=n;i++) a[i]=(s[i-1]=='+')?1:0;
		for (i=1,ans=0;i<=n-m+1;i++)
		 if (!a[i]){
		 	ans++;
		 	for (j=i;j<=i+m-1;j++) a[j]^=1;
		 }
		for (i=1;i<=n;i++)
		 if (!a[i]) ans=-1;
		printf("Case #%d: ",tc);
		if (ans==-1) puts("IMPOSSIBLE");else printf("%d\n",ans);
	}
	return 0;
}
