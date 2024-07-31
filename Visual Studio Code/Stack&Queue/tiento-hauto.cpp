// Biểu thức trung tố (Infix) : (A + B) * (C - D)
// Biểu thức tiền tố (Prefix) : *+AB-CD
// Biểu thức hậu tố (Postfix) : AB+CD-*


#include <bits/stdc++.h>
using namespace std;
void chuyendoi(string s){
    stack<string> st;
    for(int i=s.length()-1;i>=0;i--){
        if(isalpha(s[i])){
            st.push(string(1,s[i]));
        }
        else{ 
            string th1 =st.top();st.pop();
            string th2 =st.top();st.pop(); 
            string t = th1+th2+s[i];
            st.push(t);
        }
    }
    cout<<st.top()<<endl;
}


int main(){
    string s ;cin>>s;
    chuyendoi(s);
    return 0;
}