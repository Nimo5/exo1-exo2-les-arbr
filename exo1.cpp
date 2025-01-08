#include <iostream>

using namespace std;
//struct to tree
struct node{
int key;
node* left;
node* right;
};
//struct to linked circuler list
struct nodelist{
int data ;
nodelist*next;
};
void inittree(node*&s){
s=0;
}
void insertnode(node*&s,int x){
if(s==0){
    s=new node;
    s->key=x;
    s->left=0;
    s->right=0;
}else{
if(x<s->key){
    insertnode(s->left,x);

}else{
insertnode(s->right,x);
}
}
}
void searchnode(node* root ,int val ,node* & position){
    if(root->key==val ){
        position=root;
    }else{
        if(val < root->key){
            searchnode(root->left,val ,position);

        }else{
            searchnode(root->right,val ,position);

        }
    }
}
void displaytree(node*root){
if(root!=0){
    displaytree(root->left);
    cout<<root->key<<endl;
    displaytree(root->right);
}


}
void insertbiginin(nodelist*&head,int val){
    nodelist*nov= new nodelist;
    nov->data=val;
    nov->next=head;
    head=nov;
}
void puttreeincurculrlist(node*root,nodelist*&head){
if(root!=0){
  puttreeincurculrlist(root->left,head);
  insertbiginin(head,root->key);
  puttreeincurculrlist(root->right,head);
}


}
void displaylist(nodelist*head){
while(head!=0){
    cout<<head->data<<endl;
    head=head->next;

}
}
int main()
{
 nodelist*L1=0;
 nodelist*L2=0;
 node*T1=0;
 node*T2=0;

int n;
cout<< "enter the number of element : ";
cin>>n;
cout<<"tree 1"<<endl;
for(int i=0;i<n;i++){
    int key;
    cout<<"enter the "<<i+1<<" key : ";
    cin>>key;
    insertnode(T1,key);
}
cout<<"tree 2"<<endl;
for(int i=0;i<n;i++){
    int key;
    cout<<"enter the "<<i+1<<" key : ";
    cin>>key;
    insertnode(T2,key);


}
cout<<"display tree number 1 "<<endl;
displaytree(T1);
cout<<"display tree number 2 "<<endl;
displaytree(T2);
puttreeincurculrlist(T1,L1);
puttreeincurculrlist(T2,L2);
cout<<"lisst 1 : "<<endl;
displaylist(L1);
cout<<"lisst 2 : "<<endl;
displaylist(L2);

    return 0;
}
