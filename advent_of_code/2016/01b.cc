#include <unordered_set>
#include <utility>
#include <iostream>
#include <string>
#include <sstream>
using namespace std;
long long comb(long a,long b){
  return(a<<sizeof(long))+b;
}
int main(){
  string s;
  unordered_set<long long>m;
  int x=0,y=0,i;
  m.insert(comb(x,y));
  enum dir{N,E,S,W}d=N;
  while(getline(cin,s,',')){
    size_t k=s.find_last_not_of("0123456789");
    istringstream ss(s.substr(k+1));
    ss>>i;
    d=static_cast<enum dir>((d+\
      ((s.find('L')!=string::npos)?3:1))%4);
    for(int k=0;k<i;k++){
      x+=(E==d)?1:(W==d)?-1:0;
      y+=(N==d)?1:(S==d)?-1:0;
      auto t=comb(x,y);
      if(m.count(t)){
        cout<<(x<0?-x:x)+(y<0?-y:y)<<endl;
        return 0;
      }
      m.insert(t);
    }
  }
  return 0;
}
