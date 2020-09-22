#include<bits/stdc++.h>
using namespace std;
struct node{
    bool mark;
    node *arr[26];

    node(){
        for(int i=0;i<26;i++) arr[i]=NULL;
        mark=false;
    }
} *root;

void insert(string s){
    node *current = root;
    for(int i=0;i<s.size();i++){
        if(current->arr[s[i]-'a']==NULL){
            current->arr[s[i]-'a']=new node();
        }
        current=current->arr[s[i]-'a'];
    }
    current->mark=true;
}

bool search(string s){
    node *current= root;
    for(int i=0;i<s.size();i++){
        if(current->arr[s[i]-'a']==NULL) return false;
        current=current->arr[s[i]-'a'];
    }
    return current->mark;
}

void del(node *current){
    for(int i=0;i<26;i++){
        if(current->arr[i]!=0)
            del(current->arr[i]);
    }
    delete(current);
}

int main()
{
    string s; int n;
    root= new node();
    while(cin>>n){
        cin>>s;
        if(n==1) insert(s);
        else{
            if(search(s)) cout<<"Found"<<endl;
            else cout<<"Not Found"<<endl;
        }
    }

    return 0;
}
