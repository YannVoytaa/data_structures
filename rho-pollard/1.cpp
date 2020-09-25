#include<bits/stdc++.h>
#define pb push_back
using namespace std;
vector<long long>factors;

long long multiply(long long x,long long y,long long mod){
  long long wynik=0;
  x%=mod;
  while(y){
    if(y%2)wynik+=x;
    wynik%=mod;
    y/=2;
    x*=2;
    x%=mod;
  }
  return wynik;
}

long long random_number(long long x,long long mod){
  return (multiply(x,x,mod)+3)%mod;
}

long long power(long long sub, long long sup, long long mod){
  long long res=1;
  while(sup){
    if(sup%2)res=multiply(res,sub,mod);
    sub=multiply(sub,sub,mod);
    sup/=2;
  }
  return res;
}

bool miller_rabin(long long x,long long truex, long long r){
  long long res=power(r,x,truex);
  if(res==1)return true;
  while(x<=truex){
    if(res+1==truex)return true;
    res=multiply(res,res,truex);
    x*=2;
  }
return false;
}
void rho(long long x);
void div(long long x){
  long long sqr=sqrt(x);
  long long a=rand()%sqr,b=rand()%sqr;
  while(a==b||__gcd(abs(a-b),x)==1){
    a=random_number(a,x);
    b=random_number(random_number(b,x),x);
    if(a==b)break;
  }
  if(a==b)div(x);
  else {rho(__gcd(abs(a-b),x));rho(x/__gcd(abs(a-b),x));}
}

bool prime(long long x){
  if(x==2)return true;
  long long truex=x;
  x--;
  while(x%2==0)x/=2;
  long long r=rand()%truex;
  for(int i=1;i<=10;i++){
    r=random_number(r,truex-2)+2;
    if(miller_rabin(x,truex,r))return true;
  }
  return false;
}

void rho(long long x){
  if(x!=1 && !prime(x)){
    div(x);
  }
  else if(x!=1)factors.pb(x);
}



void test(){
  long long n;
  cin>>n;
  rho(n);
  for(int i=0;i<factors.size();i++)cout<<factors[i]<<((i==factors.size()-1)?"":" * ");
}

int main(){
  ios_base::sync_with_stdio(0);
  srand(time(NULL));
  test();
}
