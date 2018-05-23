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
#define read(type) readInt<type>()
#define win 10
#define lose -10
#define draw 0

/****** Template of some basic operations *****/

template<typename T, typename U> inline void amin(T &x, U y) { if(y < x) x = y; }
template<typename T, typename U> inline void amax(T &x, U y) { if(x < y) x = y; }

/**********************************************/

using namespace std;

///dir array for Queen int dxq[10] = {-1,-1,-1,1,1,1,0,0};
///dir array for Queen int dyq[10] = {-1,0,1,-1,0,1,-1,1};
///dir array for knight int dxk[10] = {-2,-2,-1,-1,1,1,2,2};
///dir array for knight int dyk[10] = {1,-1,-2,2,-2,2,-1,1};

/*int leap(int year){
   	if( year%4 == 0 && year%100 == !0 )
            return 1;
	else if (year%100 == 0 && year%400 == 0)
            return 1;
	else
        return 0;
      while(ct > 0){
        double  r = ((double) rand() / (RAND_MAX));
        cout<<r<<endl;
        ct--;
    }
}*/

int cases,ct = 10,r,c,y,cnt = 1;
char A[40][40];
struct Node{
    int row,col;
};
int board_full(){
    int i,j,k;
    for(i=1;i<=3;i++){
        for(j=1;j<=3;j++){
            if(A[i][j] == '.'){
                return 0;
            }
        }
    }
    return 1;
}
int evaluate(){

    for (int i = 1; i<=3; i++){
        if (A[i][1]==A[i][2] && A[i][2]==A[i][3]){
            if (A[i][1]=='O')
                return 10;
            else if (A[i][1]=='X')
                return -10;
        }
    }

    // Checking for Columns for X or O victory.
    for (int i = 1; i<=3; i++){
        if (A[1][i]==A[2][i] && A[2][i]==A[3][i]){
            if (A[1][i]=='O')
                return 10;

            else if (A[2][i]=='X')
                return -10;
        }
    }

    if (A[1][1]==A[2][2] && A[2][2]==A[3][3]){
        if (A[1][1]=='O')
            return 10;
        else if (A[1][1]=='X')
            return -10;
    }

    if (A[1][3]==A[2][2] && A[2][2]==A[3][1]){
        if (A[1][3]=='O')
            return 10;
        else if (A[1][3]=='X')
            return -10;
    }

    return 0;
}
int min_max(int turn){
    int check = evaluate();

    if(check == 10){
         return check;
    }
    if(check == -10){
         return check;
    }
    if(board_full()){
        return 0;
    }
    if(turn){
        int init = -1000;
        int i,j,k;
        for(i=1;i<=3;i++){
            for(j=1;j<=3;j++){
                if(A[i][j] == '.'){
                    A[i][j] = 'O';

                    //int aa = min_max(!turn);
                    init = max(init,min_max(!turn));

                    A[i][j] = '.';
                }
            }
        }
        return init;
    }
    else{
         int init = 1000;
        int i,j,k;
        for(i=1;i<=3;i++){
            for(j=1;j<=3;j++){
                if(A[i][j] == '.'){
                    A[i][j] = 'X';

                    init = min(init,min_max(!turn));

                    A[i][j] = '.';
                }
            }
        }
        return init;
    }


}
void ai_move(){
    int best = -10000;
    int i,j,k;
    for(i = 1; i<=3; i++){
        for(j=1;j<=3;j++){
            if(A[i][j] == '.'){
                A[i][j] = 'O';

                int new_val = min_max(0);

                A[i][j] = '.';

                if(new_val > best){
                    best = new_val;
                    r = i;
                    c = j;
                }
            }
        }
    }

}

void showboard(){
    int i,j,k;
    for(i=1;i<=3;i++){
        for(j=1;j<=3;j++){
            cout<<A[i][j];
        }
        cout<<endl;
    }
}
int valid(int x , int y){
    if(A[x][y] == '.' && x>=1 && x <=3 && y>=1 && y <= 3){
        return 1;
        //cout<<":/"<<endl;
    }
    else return 0;
}
int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
        int i,k=0,j,a,b,ai=0;
        memset(A,0,sizeof A);

        for(i=1;i<=3;i++){
            for(j=1;j<=3;j++){
                A[i][j] = '.';

            }
            //cout<<"heh"<<endl;
        }
        showboard();
        while(!board_full()){
            if(ai == 0){
                cout<<endl;
                cout<<"Human move enter cordinate :"<<endl;
                cin>>a>>b;

                   while(!valid(a,b)){
                        cout<<"Error enter another coordinate"<<endl;
                        cin>>a>>b;
                   }
               //cout<<"s"<<endl;
               A[a][b] = 'X';
                ai = 1;
                showboard();
            }
            else{
                cout<<endl;
                cout<<"Ai move :"<<endl;
                //Node new_move= min_max()
                ai = 0;
                ai_move();
                A[r][c] = 'O';
                showboard();
            }

            int check = evaluate();
            if(check == 10){
                cout<<"Ai wins!"<<endl;
            }
            else if(check == -10){
                cout<<"human wins"<<endl;
            }
            else if(board_full()){
                cout<<"Draw!!"<<endl;
            }
        }


}
