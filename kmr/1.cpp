#include<bits/stdc++.h>
#define pb push_back
using namespace std;
priority_queue<pair<int,int> >q;
map<char,int>m;
map<pair<int,int>,int>mp;
string s,sorted_s;
int ind,kmr[100005][20];
vector<pair<int,int> >g;
vector<int>comp;

bool cmp(int x,int y){
  int lngth,xlen,ylen,lg,power;
  lngth=s.size();
  xlen=lngth-x;
  ylen=lngth-y;
  lg=0;
  power=1;
  while(power<=min(xlen,ylen)){
    power*=2;
    lg++;
  }
  power/=2;
  lg--;
  if(kmr[x][lg]<kmr[y][lg])return true;
  else if(kmr[x][lg]>kmr[y][lg])return false;
  else{
    if(kmr[x-power+1][lg]<kmr[y-power+1][lg])return true;
    else if(kmr[x-power+1][lg]>kmr[y-power+1][lg])return false;
    else{
      //same prefix
      if(xlen<ylen)return true;
      else return false;
    }
  }
}


void test(){
  cin>>s;
  sorted_s=s;
  sort(sorted_s.begin(),sorted_s.end());
  for(int j=0;j<sorted_s.size();j++){
    if(j==0)m[sorted_s[j]]=++ind;
    else if(sorted_s[j]==sorted_s[j-1])continue;
    else m[sorted_s[j]]=++ind;
  }
  for(int j=0;j<s.size();j++){
    kmr[j][0]=m[s[j]];
    //cout<<kmr[j][0]<<' ';
  }
  //cout<<'\n';
  for(int i=1,lngth=2;lngth<=s.size();i++,lngth*=2){
    g.clear();
    for(int j=0;j+lngth-1<s.size();j++){
      g.pb({kmr[j][i-1],kmr[j+lngth/2][i-1]});
    }
    sort(g.begin(),g.end());
    ind=0;
    mp.clear();
    for(int j=0;j<g.size();j++){
      if(j==0)mp[g[j]]=++ind;
      else if(g[j]==g[j-1])continue;
      else mp[g[j]]=++ind;
    }
    for(int j=0;j+lngth-1<s.size();j++){
      kmr[j][i]=mp[{kmr[j][i-1],kmr[j+lngth/2][i-1]}];
      //cout<<kmr[j][i]<<' ';
    }
    //cout<<'\n';
  }
for(int i=0;i<s.size();i++)comp.pb(i);
sort(comp.begin(),comp.end(),cmp);
for(int i=0;i<comp.size();i++)cout<<comp[i]+1<<'\n';
}

int main(){
  ios_base::sync_with_stdio(0);
  srand(time(NULL));
  test();
}
