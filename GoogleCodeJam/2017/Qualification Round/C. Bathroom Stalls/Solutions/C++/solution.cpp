#include<cstdio>
#include<cstring>
#include<algorithm>
#include<map>
using namespace std;
typedef long long ll;
map<ll,ll> s;
map<ll,ll>::reverse_iterator it;
ll n,m,i,j,k,a1,a2,t1,t2;
int tc,tests;
int main(){
	for (scanf("%d",&tests),tc=1;tc<=tests;tc++){
		scanf("%lld%lld",&n,&m);s.clear();
		s[n]=1;
		while (1){
			it=s.rbegin();j=it->first;k=it->second;
			t1=j/2;t2=(j-1)/2;
			if (m<=k){
				a1=t1;a2=t2;break;
			}
			m-=k;s.erase(j);
			if (s.count(t1)) s[t1]+=k;else s[t1]=k;
			if (s.count(t2)) s[t2]+=k;else s[t2]=k;
		}
		printf("Case #%d: %lld %lld\n",tc,a1,a2);
	}
	return 0;
}
