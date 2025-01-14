#include<iostream>
#include<cstdio>
#include<cstring>
//#include<vector>
#include<algorithm>

#define U_DEBUG
#define L_JUDGE

#ifdef L_JUDGE
#pragma warning(disable:4996)
#endif

using namespace std;
const int MAXN=210;

typedef long long int LL;

int T,N,Q,D,M;
LL a[MAXN];
LL dp[22][12][22];
LL f[12][22],g[12][22];

void Call(int mod){
    int b[202];
    for(int i=1;i<=N;i++)b[i]=(a[i]%mod+mod)%mod;
    memset(f,0,sizeof(f));
    memset(g,0,sizeof(g));
    f[0][0]=1;
    for(int i=1;i<=N;i++){
        memset(g,0,sizeof(g));
        for(int j=0;j<=10;j++){
            for(int k=0;k<mod;k++){
                g[j][k]+=f[j][k];
                g[j+1][(k+b[i])%mod]+=f[j][k];
            }
        }
        swap(f,g);
    }
}

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
//		freopen("out.txt","w",stdout);
	#endif
    scanf("%d",&T);
    for(int ti=1;ti<=T;ti++){
        printf("Case %d:\n",ti);
         scanf("%d%d",&N,&Q);
         for(int i=1;i<=N;i++){
             scanf("%lld",a+i);
         }
         memset(dp,0,sizeof(dp));
         for(int i=1;i<=20;i++){
              Call(i);
              for(int j=0;j<=10;j++){
                  for(int k=0;k<i;k++){
                      dp[i][j][k]=f[j][k];
                  }
              }
         }
         while(Q--){
              scanf("%d%d",&D,&M);
              printf("%lld\n",dp[D][M][0]);
         }
    }

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
//		system("out.txt");
	#endif

	return 0;
}
