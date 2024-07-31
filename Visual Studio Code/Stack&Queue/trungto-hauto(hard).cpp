// Biểu thức trung tố (Infix) : (A+B)*(C-D)
// Biểu thức tiền tố (Prefix) : *+AB-CD
// Biểu thức hậu tố (Postfix) : AB+CD-*
// Duyệt biểu thức trung tố từ đầu tới cuối
// - Nếu là toán hạng thì thêm vào xâu kết quả
// - Nếu là dấu ‘(‘ thì thêm vào ngăn xếp
// - Nếu là dấu ‘)’ thì lần lượt pop các kí tự trong ngăn xếp và đưa vào xâu kết quả cho tới khi
// gặp dấu ‘)’ tương ứng.
// - Nếu là toán hạng: Lần lượt pop các toán hạng ở đỉnh ngăn xếp nếu thứ tự ưu tiên của nó lớn
// hơn hoặc bằng thứ tự ưu tiên của kí tự đang xét. Đẩy toán hạng này vào ngăn xếp.
// Lần lượt đưa mọi ký tự trong ngăn xếp và thêm vào cuối xâu kết quả.

#include <bits/stdc++.h>
using namespace std;
int pre(char c){   // thu tu uu tien thuat toan
    if(c=='+' || c=='-') return 1;
    if(c=='*' || c=='/') return 2;
    return 0;  // neu la dau ngoac
}
void solve(string s){
    stack<char> st;
    string res="";
    for(char x:s){
        if(x=='(') st.push(x);
        else if(isalpha(x)){
            res+=x;
        }
        else if(x==')'){
            while(st.top()!='('){
                res+=st.top();
                st.pop();
            }
            st.pop();
        }
        else{
            while(!st.empty()  && pre(st.top())>=pre(x)){
                res+=st.top();
                st.pop();
            }
            st.push(x);
        }
    }
    while(!st.empty()){
        res+=st.top();
        st.pop();
    }
    cout<<res<<" ";

}
int main(){
    string s ;cin>>s;
    solve(s);
    return 0;
}