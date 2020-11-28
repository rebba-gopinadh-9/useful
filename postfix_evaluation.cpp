#include <iostream>
#include <stack>
using namespace std;
int is_operand(char a){
    if (a>='0' && a<='9')
        return 1;
    return 0;
}
int main(){
    stack <int> g;
    string s;
    getline(cin,s);
    int t=0,x,y;
    for (int i=0;i<s.size();i++){
        if (is_operand(s[i])){
            t=0;
            while(is_operand(s[i])){
                t=t*10+((int)s[i]-'0');
                i++;
            }
            g.push(t);
        }else{
            if (s[i]=='+'){
                x=g.top();
                g.pop();
                y=g.top();
                g.pop();
                g.push(x+y);
            }
            if (s[i]=='-'){
                x=g.top();
                g.pop();
                y=g.top();
                g.pop();
                g.push(y-x);
            }
            if (s[i]=='*'){
                x=g.top();
                g.pop();
                y=g.top();
                g.pop();
                g.push(x*y);
            }
            if (s[i]=='/'){
                x=g.top();
                g.pop();
                y=g.top();
                g.pop();
                g.push(y/x);
            }
        }
    }
    cout<<g.top()<<endl;
    return 0;
}
