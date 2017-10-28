#include <iostream>
#include <cstring>
using namespace std;
char str[101];
int result;
int basic_operate(int a,int b,char c)
{
    if(c=='+')return a+b;
    if(c=='-')return a-b;
    if(c=='*')return a*b;
    else return a/b;
}
bool check_bracket(int l,int r)
{
    int cnt=0;
    for(int i=l;i<=r;i++){
        if(str[i]=='(') cnt++;
        if(str[i]==')') cnt--;
    }
    if(cnt==0) return 1;
    return 0;
}
int calculate(int l,int r)
{
    int cnt=0;
    if(str[l]=='('&&str[r]==')') {
        for(int i=l+1;i<r;i++){
            if(str[i]=='(') cnt++;
            if(str[i]==')') cnt--;
            if(cnt<0) break;
        }
        if(cnt==0) return calculate(l+1,r-1);
    }
    int target=-1;
    for(int i=r;i>=l;i--){
        if(check_bracket(i,r)){
            if(str[i]=='+'||str[i]=='-'){
                target=i;
                return basic_operate(calculate(l,i-1),calculate(i+1,r),str[target]);
            }
        }
    }
    for(int i=r;i>=l;i--){
        if(check_bracket(i,r)){
            if(str[i]=='*'||str[i]=='/'){
                target=i;
                return basic_operate(calculate(l,i-1),calculate(i+1,r),str[target]);
            }
        }
    }
    int ans=0;
    if(target<0){
        for(int i=l;i<=r;i++){
            ans=ans*10+str[i]-'0';
        }
    }
    return ans;
}

int main()
{
    cin>>str;
    result=calculate(0,strlen(str)-1);
    cout <<result<< endl;
    return 0;
}
