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
#define max 60006
#define read(type) readInt<type>()


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

int cases,ct = 10;
double final_ans = 99999999.0;

struct node{
    double x,y;
    int node_no;
};

node A[max];   /// for first
node tmp[max];
node final[max];

int node_size = 0;
int sz=0;

void print(){
  int i,j,k;
  for(i=1;i<=sz;i++){
        cout<<tmp[i].node_no<<" and "<<tmp[i].x<<endl;
  }
  cout<<"THE END"<<endl;
}

void is_smaller(node mn[max],node tmp[max]){
    int i;

    ///for checking current and neighbour :)
    /*
    for(i=1;i<=sz;i++){
       cout<< A[i].node_no << " and " << tmp[i].node_no <<endl;
    }
    cout<<"Walter White"<<endl;
    */
    double j,k,res1 = 0,res2 = 0;
    for(i=1;i<=sz-1;i++){
        j = (mn[i].x - mn[i+1].x);
        k = (mn[i].y - mn[i+1].y);
        res1 = res1 +  sqrt(j*j + k*k);
    }
    j = mn[1].x - mn[sz].x;
    k = mn[1].y - mn[sz].y;
    res1 = res1 + sqrt(j*j + k*k);

    for(i=1;i<=sz-1;i++){
        j = (tmp[i].x - tmp[i+1].x);
        k = (tmp[i].y - tmp[i+1].y);
        res2 = res2 +  sqrt(j*j + k*k);
    }
    j = tmp[1].x - tmp[sz].x;
    k = tmp[1].y - tmp[sz].y;
    res2 = res2 + sqrt(j*j + k*k);

   final_ans = min(final_ans,min(res1,res2));
    ///cout<<res1<<" COST "<<res2<<endl;
    /*if(res1 >= res2){
        if(final_ans >= res2){
            final_ans = res2;
            return 2;
        }
            return 1;
    }
    else{
        return 0;
    }*/
}

void h1(){
    int i,j,k;
    node aa,bb;
    int r = (rand() % sz) + 1;
    ///cout<<r<<endl;
    int r2 = (rand() % sz) + 1;


    while(r2 == r){
        r2 = (rand() % sz) + 1;
    }
    ///cout<<r<<" Ekhonnn jabeeee! "<<r2<<endl;

    aa = A[r];
    bb = A[r2];

    if(r2 > r){
        ///r , r2 tey jabe!!!
        for(i = r; i<= r2 - 1 ; i++){
            tmp[i] = A[i+1];
        }
        tmp[r2] = aa;
    }
    else{
        for(i = r; i>= r2 + 1; i--){
            tmp[i] = A[i-1];
        }
        tmp[r2] = aa;
    }
    is_smaller(A,tmp);
    /*if(is_smaller(A,tmp) == 2){
        for(i=1;i<=sz;i++){
            final[i] = tmp[i];
        }
    }*/
    for(i=1;i<=sz;i++){
            A[i] = tmp[i];
    }
    ///print();
}
/*best_distance = calculateTotalDistance(existing_route)
       for (i = 1; i < number of nodes eligible to be swapped - 1; i++) {
           for (k = i + 1; k < number of nodes eligible to be swapped; k++) {
               new_route = 2optSwap(existing_route, i, k)
               new_distance = calculateTotalDistance(new_route)
               if (new_distance < best_distance) {
                   existing_route = new_route
                   goto start_again
               }
           }
       }
       2optSwap(route, i, k) {
       1. take route[0] to route[i-1] and add them in order to new_route
       2. take route[i] to route[k] and add them in reverse order to new_route
       3. take route[k+1] to end and add them in order to new_route
       return new_route;
        }
*/

void optswap_2(int i,int k){
    int j,l,iter = 1;
    ///cout<<"i = "<<i<<" k == "<<k<<endl;

    for(j=1;j<=i-1;j++){
        tmp[iter] = A[j];
        iter++;
    }
    for(j=k;j>=i;j--){
        tmp[iter] = A[j];
        iter++;
    }
    for(j=k+1; j<=sz; j++){
        tmp[iter] = A[j];
        iter++;
    }
    ///cout<<"yoo"<<endl;
    is_smaller(A,tmp);

    for(i=1;i<=sz;i++){
            A[i] = tmp[i];
    }
    ///cout<<"EKHON    V PRINT "<<endl;

    /*for(l=0;l<V.size();l++){
        cout<<V[l].node_no<<endl;
    }*/
    ///print();
}
void h2(){
    int i,j,k,res1 = 0,new_res = 0;
    ///cout<<"dhukse"<<endl;
    for(i=2;i<=sz-1; i++){
        for(k = i+1; k<=sz  ; k++){
             optswap_2(i,k);
        }
    }

}

void hill_climb(){
    int i,j,k,alpha=1000;
    memset(tmp,0,sizeof 0);

    for(i=1;i<=alpha;i++){
        double  r = ((double) rand() / (RAND_MAX));

        if(r < 0.5){
            ///cout<<"h1"<<endl;
            h1();
        }
        else{
            ///cout<<"h2"<<endl;
            h2();
        }

            ///h1();
            ///h2();
    }

}


int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int i,j,k,c;
    double a,b;
    while(scanf("%d %lf %lf",&c,&a,&b)!=EOF){
        if(c == 0 && a == 0 && b == 0)break;

        A[c].x = a;
        A[c].y = b;
        A[c].node_no = c;

        sz++;
        node_size++;
    }
    //for(i=1;i<=3;i++){
    //    cout<<A[i].x<<" "<<A[i].y<<endl;
    //}
     for(i=1;i<=sz;i++){
        tmp[i] = A[i];
     }

    ///print();
    ///print();
    ///cout<<node_size<<endl;
    ///cout<<"Before start"<<endl;
    hill_climb();

    cout<<"Finally "<<final_ans<<endl;
    ///print();


}
