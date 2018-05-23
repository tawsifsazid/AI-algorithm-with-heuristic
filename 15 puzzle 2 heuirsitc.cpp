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

/*int leap(int year){
   	if( year%4 == 0 && year%100 == !0 )
            return 1;
	else if (year%100 == 0 && year%400 == 0)
            return 1;
	else
        return 0;
}*/
int cases,ct = 0;

int dx[5] = {0,0,-1,1};
int dy[5] = {-1,1,0,0};
int path[1000][1000];
struct State{
    ///int node_no;
    int f_score,g_score,h_score,A[15][15];

    bool operator < (const State & a)const{
        return f_score > a.f_score;
    }

};

vector<State>closed;
map<string,string>M;

void print(State a){
    int i,j;
    for(i=0;i<4;i++){
        for(j=0;j<4;j++){
            printf("%d ",a.A[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}
int h1_func(State b){
   int i,j,k=0;
   for(i=0;i<4; i++){
        for(j=0; j<4; j++){
            if(b.A[i][j] == 1){
                if(i != 0 || j != 0){
                    k++;
                }
            }
            else if(b.A[i][j] == 2){
                if(i != 0 || j != 1){
                    k++;
                }
            }
            else if(b.A[i][j] == 3){
                if(i != 0 || j != 2){
                    k++;
                }
            }
            else if(b.A[i][j] == 4){
                if(i != 0 || j != 3){
                    k++;
                }
            }
            else if(b.A[i][j] == 5){
                if(i != 1 || j != 0){
                    k++;
                }
            }
            else if(b.A[i][j] == 6){
                if(i != 1 || j != 1){
                    k++;
                }            }
            else if(b.A[i][j] == 7){
               if(i != 1 || j != 2){
                    k++;
                }
            }
            else if(b.A[i][j] == 8){
               if(i != 1 || j != 3){
                    k++;
                }
            }
            else if(b.A[i][j] == 9){
               if(i != 2 || j != 0){
                    k++;
                }
            }
            else if(b.A[i][j] == 10){
              if(i != 2 || j != 1){
                    k++;
                }
            }
            else if(b.A[i][j] == 11){
                if(i != 2 || j != 2){
                    k++;
                }
            }
            else if(b.A[i][j] == 12){
               if(i != 2 || j != 3){
                    k++;
                }
            }
            else if(b.A[i][j] == 13){
               if(i != 3 || j != 0){
                    k++;
                }            }
            else if(b.A[i][j] == 14){
              if(i != 3 || j != 1){
                    k++;
                }
            }
            else if(b.A[i][j] == 15){
                ///printf("sss\n");
                if(i != 3 || j != 2){

                    k++;
                }
            }
        }
   }
   ///printf("sadasd %d\n",k);
   return k;
}

int h2_func(State b){
   int i,j,k,sum = 0,yoo;
   for(i=0;i<4;i++){
        for(j = 0; j<4; j++){
            if(b.A[i][j] == 1){
                  yoo = ((i - 0)*(i-0))  + ((j-0)*(j-0));
                  sum = sum + sqrt(yoo);
            }
            else if(b.A[i][j] == 2){
                  yoo = ((i - 0)*(i-0))  + ((j-1)*(j-1));
                  sum = sum + sqrt(yoo);
            }
            else if(b.A[i][j] == 3){
                yoo = ((i - 0)*(i-0))  + ((j-2)*(j-2));
                  sum = sum + sqrt(yoo);
            }
            else if(b.A[i][j] == 4){
                yoo = ((i - 0)*(i-0))  + ((j-3)*(j-3));
                  sum = sum + sqrt(yoo);
            }
            else if(b.A[i][j] == 5){
                yoo = ((i - 1)*(i-1))  + ((j-0)*(j-0));
                  sum = sum + sqrt(yoo);
            }
            else if(b.A[i][j] == 6){
                yoo = ((i - 1)*(i-1))  + ((j-1)*(j-1));
                  sum = sum + sqrt(yoo);
            }
            else if(b.A[i][j] == 7){
                yoo = ((i - 1)*(i-1))  + ((j-2)*(j-2));
                  sum = sum + sqrt(yoo);
            }
            else if(b.A[i][j] == 8){
                yoo = ((i - 1)*(i-1))  + ((j-3)*(j-3));
                  sum = sum + sqrt(yoo);
            }
            else if(b.A[i][j] == 9){
                yoo = ((i - 2)*(i-2))  + ((j-0)*(j-0));
                  sum = sum + sqrt(yoo);
            }
            else if(b.A[i][j] == 10){
                yoo = ((i - 2)*(i-2))  + ((j-1)*(j-1));
                  sum = sum + sqrt(yoo);
            }
            else if(b.A[i][j] == 11){
                yoo = ((i - 2)*(i-2))  + ((j-2)*(j-2));
                  sum = sum + sqrt(yoo);
            }
            else if(b.A[i][j] == 12){
                yoo = ((i - 2)*(i-2))  + ((j-3)*(j-3));
                  sum = sum + sqrt(yoo);
            }
            else if(b.A[i][j] == 13){
                yoo = ((i - 3)*(i-3))  + ((j-0)*(j-0));
                  sum = sum + sqrt(yoo);
            }
            else if(b.A[i][j] == 14){
                yoo = ((i - 3)*(i-3))  + ((j-1)*(j-1));
                  sum = sum + sqrt(yoo);
            }
            else if(b.A[i][j] == 15){
                yoo = ((i - 3)*(i-3))  + ((j-2)*(j-2));
                  sum = sum + sqrt(yoo);
            }

        }
   }
   return sum;
}

int isvalid(int x,int y){
    ///if(x == 2 && y == 2)printf("kire\n");
    if(x > 3 || y > 3 || x < 0 || y < 0) return 0;
    else{
        ///printf("haha\n");
        return 1;
    }
}
State next_state(int x,int y,int index,State c){
    State b;

    memset(b.A,0,sizeof b.A);



    ///printf("%d\n",b.f_score);

    for(int i = 0; i<4; i++){
        for(int j = 0; j<4; j++){
            b.A[i][j]  = c.A[i][j];
        }
    }

    int g = 0;


    for(int i = 0; i<4; i++){
        for(int j = 0; j<4; j++){
            if(b.A[i][j] == 0){
                /*if(index == 3){

                    printf("noww\n");
                    printf("%d %d\n",i,j);
                }*/
                swap(b.A[i][j],b.A[i + dx[index]][j + dy[index]]);
                g = 1;
                break;
            }
        }
        if(g == 1)break;
    }

    b.g_score = c.g_score + 1;
    ///b.h_score = h2_func(b);
    b.h_score = h1_func(b);
    b.f_score = b.g_score + b.h_score;
    ///print(b);
    return b;

}
int vis(State b){
    int node,i,j,k,fl = 0,haha = 0;
     ///print(b);
     ///print(closed[0]);
     ///printf("%d\n",closed.size());
    for(node=0;node<closed.size();node++){
        fl = 0;
        for(i=0;i<4;i++){
            for(j=0;j<4;j++){
                if(closed[node].A[i][j] !=  b.A[i][j]){
                    fl = 1;
                    ///printf("ha\n");
                }
            }
        }
        if(fl == 0){
            haha = 1;
            break;
        }
    }
    if(haha == 1){
        ///printf("yes\n");
        return 1;
    }
    else return 0;

}
string make_parent(State a){
   ostringstream oss;

  // Works just like cout
  int i,j,k;

  for(i = 0; i<4; i++){
    k = 0;
    for(j = 0; j<4; j++){
        if(k == 0){
            oss<<a.A[i][j];
            k = 1;
        }
        else{
            oss<<"  "<<a.A[i][j];
        }
    }
    oss<<"\n";
  }

  // Return the underlying string
  return oss.str();

}
stack<string>S;
void print_path(string last){
    if(M[last] == "a"){
        S.push(last);
        return;
    }
    ///cout<<last<<endl;
    S.push(last);
    last =  M[last];
    print_path(last);
}
void A_star(State start){

  M.clear();
  priority_queue<State>Q;
   start.g_score = 0;
   ///start.h_score = h2_func(start);
   start.h_score = h1_func(start);
   start.f_score  = start.g_score + start.h_score;
   ///printf("%d\n",start.f_score);
   Q.push(start);
   string a = make_parent(start);
   M[a] = "a";


   ///cout<<aa<<endl;

   closed.clear();

   memset(path,0,sizeof path);

   ///memset(vis,0,sizeof vis);

    int i,j,k;
   State v;
   while(!Q.empty()){
        //printf("s\n");
        State u = Q.top();
        Q.pop();
        closed.push_back(u);
         string uu = make_parent(u);
        ///print(u);


        if(u.f_score > 0 && u.h_score == 0){
                ///print(u);
                printf("Yes!!!!!!!\n");
                string last = make_parent(u);
                print_path(last);
                break;
        }

        for(i = 0 ; i<4 ; i++){
            for(j=0; j<4 ;j++){
                if(u.A[i][j] == 0){
                  for(k=0 ;k<4; k++){
                    ///swap(u.A[i][j] , u.A[i + dx[k]][j + dy[k]]);
                        if(isvalid(i  + dx[k], j + dy[k])){
                            ///printf("dhukse\n");
                            ///printf("ha ekhon u\n");
                            ///print(u);
                            State v = next_state(i,j,k,u);
                            ///print(v);
                            if(!vis(v)){
                               Q.push(v);
                               closed.push_back(v);
                               path[i][j] = k;
                               string vv = make_parent(v);
                               ///cout<<uu<<" -> \n"<<vv<<endl;
                               M[vv] = uu;
                               ///printf("dhukse\n");
                            }
                        }
                  }
                }
            }
        }

   }
   ///printf("looop end\n");
}

int main(){
    ///freopen("input.txt","r",stdin);
    ///freopen("output.txt","w",stdout);
   int i,j,k;
   State st;
   memset(st.A,0,sizeof st.A);
   for(i=0;i<4;i++){
        for(j=0; j<4; j++){
            scanf("%d",&st.A[i][j]);
        }
   }

   ///print(st);
   ///printf("%d\n",st.A[1][3]);
   A_star(st);
   ///printf("haaha\n");
   while(!S.empty()){
        string ans = S.top();
        S.pop();
        cout<<ans<<endl<<endl;

   }


}
