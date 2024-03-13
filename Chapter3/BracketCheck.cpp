/*
括号匹配规则：
1、最后出现的左括号最先被匹配（LIFO）
2、每出现一个右括号，就“消耗”一个左括号（类似出栈）
*/
#include<iostream>
#include<stack>
#include<string>
using namespace std;
// 该程序只包含了左括号版本，可自行扩展
int main(){
    // 使用C++模板定义Char类型栈
    stack<char> SqStack;
    string str;
    cin >> str;
    // 遍历输入字符串
    for(int i=0; i<str.length(); i++){
        // 获取当前字符括号形式，若为左括号则进栈
        if(str[i]=='(')
            SqStack.push(str[i]);
        // 如果栈空则无法出现与str[i]相匹配的符号，匹配失败
        else{
            // 同时，若不是左括号则出栈一个元素，判断两个是否匹配，若不匹配则匹配失败
            if(str[i]==')'&&(!SqStack.empty()))
                SqStack.pop();
            else{
                cout << "The style of the str is wrong!" << endl;
                return 0;
            }
        }
    }
    if(SqStack.empty())
        cout << "The str's style is right!" << endl;
    else
        // 如果栈中还有未匹配的左括号则匹配失败
        cout << "The style of the str is wrong!" << endl;
    return 0;
}