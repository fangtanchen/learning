//notice:
//judge the repeat the num by:
//    -1.the former one is pn-th  and the now one nn-th, count from pn+1-th to nn-th
//    if there is some num equal to num[nn], then ignore the nn-th;
//how to pruning:
//		1.when then P_cnt is equal to P, then break;
//		2.when cannot find any dfs_level length sequence, then we donot search dfs_level+1
//		anymore.
#include<iostream>
#include<cstdio>
#include<cstring>
//#include<vector>
#include<algorithm>

//#define U_DEBUG
//#define L_JUDGE

#ifdef L_JUDGE
#pragma warning(disable:4996)
#endif

using namespace std;


int n, P;
int num_len;
int num[1010];
bool isrecord[1010];
int level[1010];
int path[1010];
bool visited[1010];
int dfs_size;
int P_cnt;

int DFS(int ssize){
	if (ssize > dfs_size){
		printf("%d", num[path[1]]);
		for (int i = 2; i <= dfs_size; i++){
			printf(" %d", num[path[i]]);
		}
		printf("\n");
		P_cnt++;
		return 0;
	}
	int imax = n - dfs_size + ssize;
	for (int ni = path[ssize - 1] + 1; (ni <= imax) && (P_cnt < P); ni++){
		int nn = num[ni];
		int pn = num[path[ssize - 1]];
		if ((!visited[ni]) && (pn <= nn)){
			bool pflag=true;
			for(int tempi=path[ssize-1]+1;tempi<ni;tempi++){
				if(num[tempi]==num[ni]){
					pflag=false;
					break;
				}
			}
			if(pflag){
				visited[ni] = true;
				path[ssize] = ni;
				DFS(ssize + 1);
				visited[ni] = false;
			}
		}
	}
	return 0;
}

int main(){
#ifdef L_JUDGE
	freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
#endif
	while (EOF != scanf("%d%d", &n, &P)){
		memset(isrecord, false, sizeof(isrecord));
		num_len = 0;
		P_cnt = 0;
		dfs_size = 1;
		for (int ni = 1; ni <= n; ni++){
			scanf("%d", &num[ni]);
			if (!isrecord[num[ni]]){
				isrecord[num[ni]] = true;
				level[num[ni]] = num_len;
				num_len++;
			}
		}
		path[0] = 0;
		level[num[0]] = 0;
		memset(visited, false, sizeof(visited));
		for (dfs_size = 1; dfs_size<n; dfs_size++){
			int temp=P_cnt;
			DFS(1);
			if ((P_cnt >= P)||(temp==P_cnt))
				break;
		}
		printf("\n");
	}


#ifdef L_JUDGE
	fclose(stdin);
	//fclose(stdout);
	//system("out.txt");
#endif

	return 0;
}
