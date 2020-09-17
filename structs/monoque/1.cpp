#include<bits/stdc++.h>
#define f first
#define s second
using namespace std;
pair<int,int>vec[1000005];
int pocz=0,kon=-1;
void que(int*t,int n,int*war,int k){
  for(int i=0;i<n;i++){
    while(pocz<=kon&&vec[kon].f>=*t)kon--;
    kon++;
    *(vec+kon)=make_pair(*t,i);
    while(pocz<=kon&&vec[pocz].s<=i-k)pocz++;
    t++;
    *war=vec[pocz].f;
    war++;
  }
t-=n;
war-=n;
}



int main(){
  ios_base::sync_with_stdio(0);
  int n,k;
  cout<<"Print number of elements: ";
  cin>>n;
  cout<<"Print k- number of elements in every range: ";
  cin>>k;
  int* t=(int*)malloc(n*sizeof(int));
  int* war=(int*)malloc(n*sizeof(int));
  for(int i=0;i<n;i++){
    cin>>*t;
    t++;
  }
  t-=n;
  que(t,n,war,k);
  for(int i=k-1;i<n;i++){
    cout<<"Minimum value between index "<<i-k+2<<" and "<<i+1<<" is "<<*(war+i)<<'\n';
  }
  free(t);
  free(war);
}
//time: O(n)
//memory: O(n)
