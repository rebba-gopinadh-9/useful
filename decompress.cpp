#include <iostream>
using namespace std;
string mul(string s,int n){
    string e="";
    for (int i=0;i<n;i++){
        e=e+s;
    }
    return e;
}
int findNext(string s,int st,int end){
    int count=0;
    for (int i=st;i<end;i++){
        if (s[i]=='['){
            count++;
        }
        if (s[i]==']'){
            count--;
        }
        if (count==0){
            return i;
        }
    }
    return -1;
}
bool isNum(char k){
    if (k>='0' && k<='9'){
        return true;
    }
    return false;
}
bool isAlpha(char k){
    if (k>='a' && k<='z'){
        return true;
    }
    return false;
}
string f(string s,int st,int en){
    int i=st;
    string e="";
    while (i<en){
        if (isAlpha(s[i])){
            e=e+s[i];
        }
        if (isNum(s[i])){
            int j=i,t=0;
            while (isNum(s[j])){
                t=t*10+((int)(s[j]-'0'));
                j++;
            }
            i=j-1;
            int p=findNext(s,i+1,en);
            e=e+mul(f(s,i+1,p),t);
            i=p;
        }
        i++;
    }
    return e;
}
int main(){
    string s="12[13[a]b]14[c]";
    cout<<f(s,0,s.size())<<endl;
    return 0;
}
