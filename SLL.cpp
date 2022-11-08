#include<bits/stdc++.h>
using namespace std;
class linkedList{
    struct node
    {
        int item;
        node * next=NULL;
    };
    node *head;
    public:
    linkedList(){
        head->next=NULL;
    }
    void transverse();
    void insert();
    void delete_Linklist();
};
void linkedList:: transverse(){
    if(head->next==NULL){
        cout<<"There is no node in list";
        return;
    }
    node *temp;
    temp=head->next;
    while(1){
        cout<<endl<<(temp->item);
        if(temp->next==NULL){
            return;
        }
        temp=temp->next;
    }
}
void linkedList :: delete_Linklist(){
    if(head->next==NULL){
        cout<<"No node to delete in list.";
        return;
    }
    int choice;
    cout<<" 1:At Beginning \n 2:At End \n 3: After a node\n";
    cout<<"Enter the choice: ";
    cin>>choice;
    switch (choice)
    {
    case (1):{
        node* ptr=head->next;
        head->next=ptr->next;
        delete ptr;
        cout<<"NODE DELETED SUCCESSFULLY";
        transverse();
        break;
    }
    case(2):{
        node *ptr=head->next;
        node *prev=head;
        while(ptr->next!=NULL){
            prev=ptr;
            ptr=ptr->next;
        }
    if(prev==head){
        head->next=NULL;
    }
    else{
        prev->next=NULL;
    }
    delete ptr;
    transverse();
    break;
    }
    case(3):{
        int index;
        node *temp;
        node *ptr;
        temp=head->next;
        cout<<"Enter node Number: ";
        cin>>index;
        if(index<=0){
            cout<<"Invalid Node Number.";
            return;
        }
        for(int i=0;i<index;i++){
            if(temp->next==NULL){
                cout<<"Invalid Node Number.";
                return;
            }
            ptr=temp;
            temp=temp->next;
        }
        ptr->next=temp->next;
        delete temp;
         transverse();
        break;
    }
    default:{
        cout<<"Invalid choice.";
        break;
    }
        
    }
}
void linkedList :: insert(){
    int choice;
    cout<<" 1:At Beginning \n 2:At End \n 3: After a node\n";
    cout<<"Enter the choice: ";
    cin>>choice;
    switch (choice)
    {
    case (1):{
        node *temp;
        int item;
        temp=new node;
        if((head->next)==NULL){
            temp->next=NULL;
        }
        else{
            temp->next=head->next;
        }
        cout<<"Enter the item: ";
        cin>>item;
        temp->item=item;
        // head=temp;
        head->next=temp;
        cout<<endl<<"Data Stored Successfully.";
        transverse();
        return;
    }
    case (2):{
        node *temp;
        // if((head->next)==NULL){
        //     temp->next=NULL;
        // }
        // else{
        //     temp->next=head->next;
        // }
        temp=head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=new node;
        cout<<"Enter the item: ";
        cin>>(temp->next->item);
        transverse();
        return;
    }
    case(3):{
        int index;
        int item;
        node *temp;
        node *ptr;
        temp=head->next;
        cout<<"Enter node Number: ";
        cin>>index;
        for(int i=0;i<(index-1);i++){
            if(temp->next==NULL || index<0){
                cout<<"Invalid Node Number.";
                return;
            }
            temp=temp->next;
        }
        ptr=new node;
        ptr->next=temp->next;
        temp->next=ptr;
        cout<<"Enter the item";
        cin>>ptr->item;
        transverse();
        return;
    }
    default:
    {
        cout<<"invalid choice";
    }
    }
    return;

}
int main(){
    linkedList l1;
    bool cons=true;
    int choice;
    while(cons){
    cout<<endl<<"********* MENU **************";
    cout<<endl<<" 1:INSERTION \n 2: DELETION \n 3: PRINT \n 4: End\n";
    cout<<"CHOOSE A OPTION: ";
    cin>> choice;
    switch (choice){
        case(1):{
            l1.insert();
            break;
        }
        case(2):{
            l1.delete_Linklist();
            break;
        }
        case(3):{
            l1.transverse();
            break;
        }
        case(4):{
            cons=false;
            break;
        }
        default:{
            cout<<"INVALID CHOICE."<<endl;
            break;
        }
    }
  }
}
