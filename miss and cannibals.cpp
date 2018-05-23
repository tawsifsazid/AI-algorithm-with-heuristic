/**
	* Author   : Muhammad Tawsif Sazid
	* Military Institute and Science and Technology
	*
	*
**/
#include <bits/stdc++.h>
#define pii acos(-1)
#define ll long long
#define pare pair<int,int>
#define eps 1e-9

using namespace std;

///dir array for Queen int dxq[10] = {-1,-1,-1,1,1,1,0,0};
///dir array for Queen int dyq[10] = {-1,0,1,-1,0,1,-1,1};
///dir array for knight int dxk[10] = {-2,-2,-1,-1,1,1,2,2};
///dir array for knight int dyk[10] = {1,-1,-2,2,-2,2,-1,1};
int dxm[10] = {1,0,1,0,2};
int dxc[10] = {1,1,0,2,0};
stack<int>S;
int counter = 0;
/*int leap(int year){
   	if( year%4 == 0 && year%100 == !0 )
            return 1;
	else if (year%100 == 0 && year%400 == 0)
            return 1;
	else
        return 0;
}*/
int cases,ct = 0;
int path[6][6][6][6][6],vis[6][6][6][6][6];

struct State{
    ///int node_no;
    int rm,rc,lm,lc,side;
};



int legal(State s){
    if((s.rm>=s.rc || s.rm == 0) && (s.lm>=s.lc || s.lm == 0) && s.rm>=0 && s.rm<=3 && s.rc>=0 && s.rc<=3 && s.lm>=0 && s.lm<=3 && s.lc>=0 && s.lc<=3) return 1;
    return 0;
}
void print_path(int rm,int rc,int lm ,int lc, int side){

     if(rm == 3 && rc == 3 && lm == 0 && lc == 0 && side == 1) return;
     int direction = path[rm][rc][lm][lc][side];


     if(direction <= 4){
        rm = rm + dxm[direction];
        rc = rc + dxc[direction];
        lm = lm - dxm[direction];
        lc = lc - dxc[direction];
        side  =  1;
     }
     else{
        rm = rm - dxm[direction % 5];
        rc = rc - dxc[direction % 5];
        lm = lm + dxm[direction % 5];
        lc = lc + dxc[direction % 5];
        side  = 0;
     }
     S.push(direction);
     print_path(rm,rc,lm,lc,side);

}
void print(int s){
    if(s == 0){
        printf("1 missionary and 1 cannibal will go from right to left\n");
    }
    else if(s == 1){
        printf("0 missionary and 1 cannibal will go from right to left\n");
    }
    else if(s == 2){
         printf("1 missionary and 0 cannibal will go from right to left\n");
    }
    else if(s == 3){
         printf("0 missionary and 2 cannibal will go from right to left\n");
    }
    else if(s == 4){
         printf("2 missionary and 0 cannibal will go from right to left\n");
    }
    else if(s == 5){
         printf("1 missionary and 1 cannibal will go from left to right\n");
    }
    else if(s == 6){
        printf("0 missionary and 1 cannibal will go from left to right\n");
    }
    else if(s == 7){
        printf("1 missionary and 0 cannibal will go from left to right\n");
    }
    else if(s == 8){
        printf("0 missionary and 2 cannibal will go from left to right\n");
    }
    else if(s == 9){
        printf("2 missionary and 0 cannibal will go from left to right\n");
    }
}
void bfs(){
    State node,u,v;
    node.lc = 0;
    node.lm = 0;
    node.rm = 3;
    node.rc = 3;
    node.side = 1;

    memset(vis,0,sizeof vis);

    vis[node.rm][node.rc][node.lm][node.lc][node.side] = 1;
    queue<State>Q;

    Q.push(node);

    while(!Q.empty()){

        u = Q.front();
        Q.pop();

        if(u.lm == 3 && u.lc == 3 && u.rm == 0 && u.rc == 0 && u.side == 0){
            ///printf("haha\n");
            break;
        }

        int i,j,k;
        if(u.side == 1){
            for(i=0;i<5;i++){
                v.lm = u.lm + dxm[i];
                v.lc = u.lc + dxc[i];
                v.rm = u.rm - dxm[i];
                v.rc = u.rc - dxc[i];
                v.side = 0;

                if( legal(v) &&  vis[v.rm][v.rc][v.lm][v.lc][v.side]== 0){
                    vis[v.rm][v.rc][v.lm][v.lc][v.side] = 1;
                    path[v.rm][v.rc][v.lm][v.lc][v.side] = i;
                    Q.push(v);
                    //printf("yoo\n");
                    //printf("%d %d %d %d %d\n",v.rm,v.rc,v.lm,v.lc,v.side);
                }

            }
        }
        else{
            for(i=0;i<5;i++){
                v.lm = u.lm - dxm[i];
                v.lc = u.lc - dxc[i];
                v.rm = u.rm + dxm[i];
                v.rc = u.rc + dxc[i];
                v.side = 1;

                if( legal(v) &&  vis[v.rm][v.rc][v.lm][v.lc][v.side] == 0){
                     vis[v.rm][v.rc][v.lm][v.lc][v.side] = 1;
                    path[v.rm][v.rc][v.lm][v.lc][v.side] = i+5;
                    Q.push(v);
                    //printf("yoo2\n");
                    //printf("%d %d %d %d %d\n",v.rm,v.rc,v.lm,v.lc,v.side);
                }

            }
        }
    }
}

int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
     bfs();
     print_path(0,0,3,3,0);

    while(!S.empty()){
        int p = S.top();
        S.pop();
        print(p);
    }

}
