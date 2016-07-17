#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
#include<map>

#define U_DEBUG
#define L_JUDGE

#ifdef L_JUDGE
#pragma warning(disable:4996)
#endif

using namespace std;
const int MAXN=10010;
const int MAXC=1000010;



int n,m,c;
char vis[MAXN];
int depth[MAXN];
short in[MAXN];
vector<pair<short ,int> > G[MAXN];// the next node, the length
short fa[MAXN];
int ans[MAXC];

vector<pair<short,int> > sta[MAXN];//the next node, the questionth

void Init(){
     memset(vis,0,sizeof(vis));
     memset(in,0,sizeof(in));
     memset(depth,0,sizeof(depth));
     for(int i=1;i<MAXN;i++){
         G[i].clear();
         sta[i].clear();
         fa[i]=i;
     }
     memset(ans,-1,sizeof(ans));
}

short Find(short x){
    short fx=fa[x];
    if(x==fx)return fx;
    fa[x]=Find(fx);
    return fa[x];
}

void PostOrder(short id){
    vis[id]=1;
    for(int i=sta[id].size()-1;i>=0;i--){
        short k=sta[id][i].first;
        if(vis[k]==1){
            ans[sta[id][i].second]=depth[id]-depth[k];
        }else if(vis[k]==2){
            short tt=Find(k);
            ans[sta[id][i].second]=depth[id]+depth[k]-2*depth[tt];
        }
    }
    for(int i=G[id].size()-1;i>=0;i--){
        short k=G[id][i].first;
        depth[k]=depth[id]+G[id][i].second;
        PostOrder(k);
        fa[k]=id;
    }
    vis[id]=2;
}

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
		//freopen("out.txt","w",stdout);
	#endif
    while(EOF!=scanf("%d%d%d",&n,&m,&c)){
        Init();
        for(int t=0;t<m;t++){
            short i,j;
            int k;
             scanf("%d%d%d",&i,&j,&k);
             if((i<1||i>n||j<1||j>n))continue;
             if(i>j)swap(i,j);
             in[j]++;
             G[i].push_back(make_pair(j,k));
        }
        for(int i=1;i<=c;i++){
             short a,b;
             scanf("%d%d",&a,&b);
             if((a<1||a>n||b<1||b>n)){
                 continue;
             }
             if(a>b)swap(a,b);
             if(a==b){
                 ans[i]=0;
             }else{
                 sta[a].push_back(make_pair(b,i));
                 sta[b].push_back(make_pair(a,i));
             }
        }
        for(int i=1;i<=n;i++){
            if(in[i]==0) {
                memset(vis,0,sizeof(vis));
                depth[i]=1;
                PostOrder(i);
            }
        }
        for(int i=1;i<=c;i++){
            if(ans[i]==-1)printf("Not connected\n");
            else printf("%d\n",ans[i]);
        }
    }

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
		system("out.txt");
	#endif

	return 0;
}