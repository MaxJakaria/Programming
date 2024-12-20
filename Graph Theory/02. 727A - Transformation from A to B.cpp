#include <bits/stdc++.h>
using namespace std;

int main(){
    int64_t a, b; cin>>a>>b;
    std::vector<int64_t> v;
    v.push_back(b);

    int64_t tem, tem2, lastDigit;
    while(b>a){
    	lastDigit = b%10;
    	if(lastDigit%2 == 1 && lastDigit>1) break;

    	if(lastDigit == 1) b = (b-1)/10, v.push_back(b);
    	else b = b/2, v.push_back(b);
    	
    	
    }
    
    if(b==a){
    	cout<< "YES\n"<< v.size()<< '\n';
    	for(int i=v.size()-1;i>=0;i--) cout<< v[i]<< ' '; 
    }
    else cout<<"NO\n";

    return 0;
}
