#include<iostream>
#include<cstdio>
#include<cstring>
//#include<vector>
#include<algorithm>
#include<utility>

#define U_DEBUG
#define L_JUDGE

#ifdef L_JUDGE
#pragma warning(disable:4996)
#endif

using namespace std;
const int MAXN=1e5+20;
const int INF=0x3f3f3f3f;
typedef pair<double,double> pdd;

pdd P[MAXN],X[MAXN],Y[MAXN];
int N;

bool CmpX(pdd p1,pdd p2){
    if(p1.first<p2.first)return true;
    else if((p1.first==p2.first)&&(p1.second<p2.second))
        return true;
    return false;
}

bool CmpY(pdd p1,pdd p2){
    if(p1.second<p2.second)return true;
    else if((p1.second==p2.second)&&(p1.first<p2.first))
        return true;
    return false;
}

double Dist(pdd p1,pdd p2){
     return (p1.first-p2.first)*(p1.first-p2.first)
         +(p1.second-p2.second)*(p1.second-p2.second);
}

double Solve(pdd *X,pdd *Y,int num){
    if(num<=3){
        double ret=INF;
        for(int i=0;i<num;i++){
            for(int j=i+1;j<num;j++){
                ret=min(ret,Dist(P[i],P[j]));
            }
        }
        return ret;
    }
    int lnum=num/2,rnum=num-lnum;
    double lmid=(X[lnum-1].first+X[lnum].first)/2;
    pdd *Xl=new pdd[lnum];
    pdd *Xr=new pdd[rnum];
    pdd *Yl=new pdd[lnum];
    pdd *Yr=new pdd[rnum];
    for(int i=0;i<lnum;i++){
        Xl[i]=P[i];
    }
    for(int i=0,j=lnum;i<rnum;i++){
        Xr[i]=P[j];
    }
    int yllen=0,yrlen=0;
    for(int i=0;i<num;i++){
        if(Y[i].first<lmid){
            Yl[yllen++]=Y[i];
            if(yllen==lnum)break;
        }
    }

}

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
		//freopen("out.txt","w",stdout);
	#endif
        while((EOF!=scanf("%d",&N))&&N){
            for(int ni=0;ni<N;ni++){
                scanf("%lf%lf",&P[ni].first,&P[ni].second);
            }
            memcpy(X,P,sizeof(P));
            memcpy(Y,P,sizeof(P));
            sort(X,X+N,CmpX);
            sort(Y,Y+N,CmpY);
            double ans=Solve(X,Y,N);
            printf("%.2lf\n",sqrt(ans));
        }

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
		system("out.txt");
	#endif

	return 0;
}
