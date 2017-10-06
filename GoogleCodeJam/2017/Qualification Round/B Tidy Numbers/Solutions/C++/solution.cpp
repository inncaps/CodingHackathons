#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
char s[51];
int i,j,k,n,m,a[51],tests,tc;
int main(){
	for (scanf("%d",&tests),tc=1;tc<=tests;tc++){
		scanf("%s",s);n=strlen(s);
		for (i=1;i<=n;i++) a[i]=s[i-1]-'0';
		for (i=1,k=0;i<n;i++)
		 if (a[i]>a[i+1]){
		 	k=i;break;
		 }
		if (!k){
			printf("Case #%d: %s\n",tc,s);
			continue;
		}
		for (i=k;i>1&&a[i-1]==a[i];i--);
		a[i]--;
		for (i++;i<=n;i++) a[i]=9;
		printf("Case #%d: ",tc);
		for (i=((!a[1])?2:1);i<=n;i++) printf("%d",a[i]);
		puts("");
	}
	return 0;
}
