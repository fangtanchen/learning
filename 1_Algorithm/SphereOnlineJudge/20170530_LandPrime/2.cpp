#include<iostream>
#include<cstring>
#include<cmath>
#include<cstdio>

#define MAXN 100
#define MAXM 10001
#define MAXP 40000
#define MAX 400000
#define clr(ar) memset(ar,0,sizeof(ar))
#define read() freopen("in.txt","r",stdin)
#define dbg(x) cout<<#x<<" = "<<x<<endl
#define chkbit(ar,i) (((ar[(i)>>6])&(1<<(((i)>>1)&31))))
#define setbit(ar,i) (((ar[(i)>>6])|=(1<<(((i)>>1)&31))))
#define isprime(x) (( (x)&&((x)&1)&&(!chkbit(ar,(x))) )||((x)==2))

using namespace std;

namespace pcf{
     long long dp[MAXN][MAXM];
     unsigned int ar[(MAX>>6)+5]={0};
     int len,primes[MAXP],counter[MAX];
     void Sieve(){
          setbit(ar,0),setbit(ar,1);
          for(int i=3;i*i<MAX;i+=2){
              if(!chkbit(ar,i)){
                  int k=i<<1;
                  for(int j=(i*i);j<MAX;j+=k)setbit(ar,j);
              }
          }
          for(int i=1;i<MAX;i++){
               counter[i]=counter[i-1];
               if(isprime(i))primes[len++]=i,counter[i]++;
          }
     }
     void Init(){
         Sieve();
         for(int n=0;n<MAXN;n++){
             for(int m=0;m<MAXM;m++){
                 if(!n)dp[n][m]=m;
                 else dp[n][m]=dp[n-1][m]-dp[n-1][m/primes[n-1]];
             }
         }
     }

     long long phi(long long m,int n){
          if(0==n)return m;
          if(primes[n-1]>=m)return 1;
          if(m<MAXM&&n<MAXN)return dp[n][m];
          return phi(m,n-1)-phi(m/primes[n-1],n-1);
     }
     long long Lehmer(long long m){
          if(m<MAX)return counter[m];
          long long w,res=0;
          int i,a,s,c,x,y;
          s=sqrt(0.9+m),y=c=cbrt(0.9+m);
          a=counter[y],res=phi(m,a)+a-1;
          for(int i=a;primes[i]<=s;i++)
              res=res-Lehmer(m/primes[i])+Lehmer(primes[i])-1;
          return res;
     }
}

int main(){
    pcf::Init();
    long long n,res,L,R,M,ca=1;
    while(scanf("%lld",&n)!=EOF){
        if(!n)break;
        L=2;R=1e8;
        while(L<R){
            M=(L+R)/2;
            res=pcf::Lehmer(M);
            if(res<n)L=M+1;
            else R=M;
        }
        printf("Case %lld: %lld\n",ca++,L);
    }
}
