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
const int MAXN=70;

typedef long long int ll;

ll dp[70][2],num[70][2];
ll P,Q;

ll Top(ll x){// this part is easy to error
    if(0==x)return 0;
    ll ret=63;
    for(;((x>>ret)&0x01)==0;ret--);
    return ret;
}

ll Cal(ll up){
    ll digit[70];
    ll cntd=0;
    ll tmp=up;
    while(tmp){
        if(tmp&0x1)digit[cntd]=1;
        else digit[cntd]=0;
        cntd++;
        tmp>>=1;
    }
    reverse(digit,digit+cntd);
    memset(dp,0,sizeof(dp));
    memset(num,0,sizeof(num));
    dp[0][1]=num[0][1]=1;

    ll cmax=cntd-1;
    for(ll ci=0;ci<cmax;ci++){
        for(ll j=0;j<2;j++){
            if(num[ci][j]){
                ll nt=digit[ci+1];
                ll kmax=(j==1?nt:1);
                for(ll k=0;k<=kmax;k++){
                    ll g=((j==1)&&(k==kmax));
                    ll off=(k==1)&&(num[ci][j]&0x01);
                    num[ci+1][g]+=(num[ci][j]);
                    dp[ci+1][g]^=((dp[ci][j]<<1)^off);
                }
            }
        }
    }
    return dp[cntd-1][0]^dp[cntd-1][1];
}

ll Call(ll x){
    if(0==x)return 0;
    __int128 q=1;//ll q=1;//
    ll ret=0;
    while(q<x){
        ret=(ret<<1)^Cal(q);
        q=(q<<1)^1;
    }
    ret=(ret<<1)^Cal(x);
    return ret;
}

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
//		freopen("out.txt","w",stdout);
	#endif
    int T;
    scanf("%d",&T);
    for(ll ti=1;ti<=T;ti++){
         scanf("%lld%lld",&P,&Q);
         ll offset=Top(Q)-Top(P-1);
         ll a=Call(Q);
         ll b=Call(P-1);
         printf("Case %d: %lld\n",ti,Call(Q)^(Call(P-1)<<offset));
    }

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
//		system("out.txt");
	#endif

	return 0;
}
