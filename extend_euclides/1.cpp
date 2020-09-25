#include<bits/stdc++.h>
using namespace std;
pair<int,int> pzap;
pair<int,int> euc(int a,int b){
  if(b==0){
    return {1,0};
  }
  pzap=euc(b,a%b);
  return {pzap.second,pzap.first-a/b*pzap.second};
}
void test(){
  int a,b;
  pair<int,int>p;
  cin>>a>>b;
  p=euc(max(a,b),min(a,b));
  cout<<max(a,b)<<" * "<<p.first<<" + "<<min(a,b)<<" * "<<p.second<<" = "<<max(a,b)*p.first+min(a,b)*p.second<<'\n';
}

int main(){
  ios_base::sync_with_stdio(0);
  while(1)test();
}
