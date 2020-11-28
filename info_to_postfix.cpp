#include <iostream>
#include <stack>
using namespace std;
int is_operand(char c){
    if (c>='a' && c<='z')
        return 1;
    return 0;
}
int precedence(char c){
    if (c=='+')
        return 1;
    if (c=='-')
        return 2;
    if (c=='*')
     return 3;
    if (c=='/')
        return 4;
    if (c=='^')
        return 5;
    return 0;
}
int main(){
    stack <char> g;
    int t;
    cin>>t;
    t=t+1;
    while(t--){
        string str;
        getline(cin,str);
        str="("+str+")";
        for(int i=0;i<str.size();i++){
            if (is_operand(str[i])){
                cout<<str[i];
            }else{
                if (str[i]=='('){
                    g.push(str[i]);
                }
                else if (str[i]==')' && !g.empty()){
                    while (g.top()!='('){
                        cout<<g.top();
                        g.pop();
                    }
                    g.pop();
                }else {
                    while (precedence(str[i])>=precedence(g.top()) && g.top()!='(') {
                        cout<<g.top();
                        g.pop();
                    }
                    g.push(str[i]);
                }
            }
        }
        while(!g.empty()){
            if (g.top()!='(')
            cout<<g.top();
            g.pop();
        }
        cout<<"\n";
    }
    return 0;
}
