#include<bits/stdc++.h>
using namespace std;
string s,wzorzec[100005];
int n,nodes=0,fail[100005],koniec[100005],exists[100005],newind,a;
map<char,int>m[100005];
char litera[100005];
queue<int>q;
void go(){
  //for(int j=0;j<=nodes;j++)cout<<j<<' '<<fail[j]<<' '<<koniec[j]<<'\n';
  int ind=0;
  for(int j=0;j<s.size();j++){
    while(ind!=0&&m[ind][s[j]]==0){
      ind=fail[ind];
      if(koniec[ind])exists[koniec[ind]]=1;
    }
    if(m[ind][s[j]]!=0)ind=m[ind][s[j]];
    if(koniec[ind])exists[koniec[ind]]=1;
  }
  for(int i=1;i<=n;i++)if(exists[i])cout<<wzorzec[i]<<'\n';
}

void push(int x){
  int ind=0;
  for(int j=0;j<wzorzec[x].size();j++){
    if(m[ind][wzorzec[x][j]]!=0)ind=m[ind][wzorzec[x][j]];
    else{
      newind=++nodes;
      m[ind][wzorzec[x][j]]=newind;
      litera[newind]=wzorzec[x][j];
      ind=newind;
    }
  }
  koniec[ind]=x;
}
void fails(int x){
  int ind=0;
  q.push(x);
  while(!q.empty()){
    a=q.front();q.pop();
    for(map<char,int>::iterator it=m[a].begin();it!=m[a].end();it++){
        newind=(*it).second;
        ind=a;
        if(ind!=0){
          ind=fail[ind];
          while(ind!=0&&m[ind][litera[newind]]==0)ind=fail[ind];
          if(m[ind][litera[newind]]!=0)fail[newind]=m[ind][litera[newind]];
        }
        q.push((*it).second);
    }
  }
  /*int ind=0;
  for(int j=0;j<wzorzec[x].size();j++){
    newind=m[ind][wzorzec[x][j]];
    if(ind!=0){
      ind=fail[ind];
      while(ind!=0&&m[ind][wzorzec[x][j]]==0)ind=fail[ind];
      if(m[ind][wzorzec[x][j]]!=0)fail[newind]=m[ind][wzorzec[x][j]];
    }
    ind=newind;
  }
  koniec[ind]=x;*/
}

void aho(){
  cout<<"DONE"<<'\n';
  for(int i=1;i<=n;i++){
    push(i);
  }
  fails(0);
  /*for(int i=1;i<=n;i++){
    fails(i);
  }*/
  go();
}


int main(){
  ios_base::sync_with_stdio(0);
  cin>>n;
  cout<<flush;
  cin>>s;
  cout<<flush;
  for(int i=1;i<=n;i++){
    cin>>wzorzec[i];
    cout<<flush;
  }
aho();
return 0;
}
