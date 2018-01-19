#include <iostream>//deals with input output
using namespace std;
int size=0;
struct node{
public:
    int data;
    node *n;
};
class Linkedlist{
private:
    node *head;
    node *tail;
public:
    Linkedlist(){
        head=NULL;
        tail=NULL;
    }
    void addnode(int a)//adding elements to the linkedlist
    {
        node *temp=new node;//a temperory node
        temp->data=a;
        temp->n=NULL;
        if(head==NULL)
        {
            head=temp;
            tail=temp;
        }
        else{
            tail->n=temp;
            tail=temp;
            size++;
        }
    }
    void insert(int a)
    {
        node *temp=new node;
        temp->data=a;
        tail->n=temp;
        temp->n=NULL;
        size++;
    }
    void insertat(int a,int b){//insert an element at a specified position
        size++;
        node *p=new node;
        node *q=new node;
        node *temp=new node;
        q=head;
        for(int i=0;i<a;i++){
            p=q;
            q=q->n;
        }
        temp->data=b;
        p->n=temp;
        temp->n=q;
    }
    void delet()//deletes the element at the end
    {
        size--;
        node *t=new node;
        node *p=new node;
        t=head;
        while(t->n!=NULL)
        {
            p=t;
            t=t->n;
        }
        tail=p;
        p->n=NULL;
        delete t;
    }
    void deleteat(int a)//function to deleate at aparticular position
    {
        size--;
        node *t=new node;//temperory node
        node *p=new node;
        t=head;
        for(int i=0;i<a;i++)
        {
            p=t;
            t=t->n;
        }
        tail=p;
        p->n=t->n;
    }
    void display()//function to display the elements of linkedlist
    {
        if(head==NULL)
            cout<<"nothing";
        else
        {
            node *temp;
            temp=head;
            while(temp!=NULL)
            {
                cout<<temp->data<<"->";
                temp=temp->n;
            }
            cout<<"NULL";
        }
    }
    int sizee(){return(size);}
};
int main()
{
    Linkedlist obj1;//object creation
    obj1.addnode(1);
    obj1.addnode(2);
    obj1.addnode(3);
    obj1.display();
    cout<<"after adding at start\n";
    obj1.insert(10);
    obj1.display();
    cout<<"after adding at a position";
    obj1.insertat(2,50);
    obj1.display();
    cout<<"after deleting at end";
    obj1.delet();
    obj1.display();
    cout<<"after deleting at mid";
    obj1.deleteat(2);
    obj1.display();
    cout<<"size="<<obj1.sizee();
}
