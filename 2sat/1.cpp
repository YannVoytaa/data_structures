#include<bits/stdc++.h>
#define pb push_back
using namespace std;
vector<int>g[100005],rev[100005];
int n,m,base,odw[100005],master[100005],logic[100005],v,a,b,nie,sss_ind;
stack<int>st;


int neg(int x){
  return base-x;
}
void dfs(int x){
  odw[x]=1;
  for(int j=0;j<g[x].size();j++){
    v=g[x][j];
    if(!odw[v]){
      dfs(v);
    }
  }
  st.push(x);
}


void sss(int a,int ind){
  odw[a]=1;
  master[a]=ind;
//  cout<<a<<' '<<master[a]<<'\n';
  for(int j=0;j<rev[a].size();j++){
    v=rev[a][j];
    if(!odw[v]){
      sss(v,ind);
    }
  }
}
void dfscheck(int x){
  if(x==n)return;
  if(logic[master[x]]==logic[master[neg(x)]])nie=1;
}

void sat(int x){
  if(logic[master[neg(x)]]!=0){
    logic[master[x]]=-logic[master[neg(x)]];
    return;
  }
  if(logic[master[x]]!=0){
    logic[master[neg(x)]]=-logic[master[x]];
    return;
  }
  odw[x]=1;
  for(int j=0;j<rev[x].size();j++){
    v=rev[x][j];
    if(!odw[v])sat(v);
    if(logic[master[v]]==1)logic[master[x]]=1;
  }
  if(logic[master[x]]==0)logic[master[x]]=-1;
  logic[master[neg(x)]]=-logic[master[x]];
}


void sata2(){
  for(int i=0;i<=2*n;i++){
    if(!odw[i])dfs(i);
  }
  for(int i=0;i<=2*n;i++){
    odw[i]=0;
  }
  while(!st.empty()){
    a=st.top();st.pop();
    if(!odw[a])sss(a,++sss_ind);
  }
  for(int i=0;i<=2*n;i++){
    odw[i]=0;
  }
  for(int i=0;i<=2*n;i++){
    if(!odw[i])sat(i);
  }
}


//#define val(x) cout<<#x<<":"<<master[x]<<'\n';

void sata2check(){
  for(int i=0;i<=2*n;i++){
    odw[i]=0;
  }
  for(int i=0;i<=2*n;i++){
    if(!odw[i])dfscheck(i);
  }
}

void test(){
  cin>>n>>m;
  base=2*n;
  for(int i=1;i<=m;i++){
    cin>>a>>b;
    a+=n;
    b+=n;
    g[neg(a)].pb(b);
    g[neg(b)].pb(a);
    //cout<<neg(a)<<' '<<b<<'\n'<<neg(b)<<' '<<a<<'\n';
    rev[b].pb(neg(a));
    rev[a].pb(neg(b));
  }
  sata2();
  sata2check();
  if(nie)cout<<"NOOO"<<'\n';
//  for(int i=1;i<=2*n;i++){val(i)}
  for(int i=n+1;i<=2*n;i++){
    cout<<logic[master[i]]<<' ';
  }
  cout<<'\n';
}

int main(){
  ios_base::sync_with_stdio(0);
  test();
}
