#include <iostream>

using namespace std;
const int Max=100;
struct Stack{
 int element[Max];
 int top;
};
void posh(Stack&s,int val){
if(s.top==Max){

    cout<<"the stack is full";
}else{
    s.element[s.top]=val;
    s.top++;
}
}
void initstack(Stack&s){
s.top=0;
}
void pop(Stack s,int &val ){
    if(s.top==0){
        cout<<"the stack is empty";

    }else{
        s.top--;
        val=s.element[s.top];

    }
}
struct tree{
    int key ;
    tree*left;
    tree*right;
} ;
void inserttree(tree*&t,int x){
if(t==0){
    t=new tree;
    t->key=x;
    t->left=0;
    t->right=0;
}else{

if(x<t->key){
    inserttree(t->left,x);
}else{
    inserttree(t->right,x);
}
}
}
void margetree(tree*t1,tree*&t2){
    if(t1!=0){
        margetree(t1->left,t2);
        inserttree(t2,t1->key);
        margetree(t1->right,t2);
    }
}

void display(tree*t){
    if(t!=0){
        display(t->left);
        cout<<t->key<<endl;
        display(t->right);
    }
}
void treetostack(tree*t,Stack&s){
if(t!=0){
    treetostack(t->left,s);
    posh(s,t->key);
    treetostack(t->right,s);

}
}
void displaystack(Stack s){
    int  val;
    while(s.top>0){
        pop(s,val);
        cout<<val<<endl;
        s.top--;

    }


}
int main()
{
    Stack s;
    initstack(s);
    int n ;
    tree*T1=0;
    tree*T2=0;
cout<<"enter the n :";
cin>>n;
cout<<"tree one "<<endl;
for(int i=0;i<n;i++){
    int key;
    cout<<" key = ";
    cin>>key;
    inserttree(T1,key);

}
cout<<"tree two  "<<endl;
for(int i=0;i<n;i++){
    int key;
    cout<<" key = ";
    cin>>key;
    inserttree(T2,key);

}

margetree(T1,T2);
cout<<"the mare tree is : "<<endl;
display(T2);
cout<<"the result of the stack is "<<endl;
treetostack(T2,s);
displaystack(s);







    return 0;
}
