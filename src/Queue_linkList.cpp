#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node *next=NULL;
        Node *prev=NULL;
};

class Queue
{
private:
    Node *head,*tail;
public:
    Queue()
    {
        head=NULL;
        tail=NULL;
    }

    void enQ()
    {
        int data;
        cout<<"Enter Data"<<endl;
        try
        {
            cin>>data;
        }
        catch(const char* msg)
        {
            cerr << msg << '\n';
        }
        if (head==NULL)
        {
            head=new Node();
            head->data=data;
            tail=head;
        }
        else if (head!=NULL)
        {
            Node *temp=tail;
            tail->next=new Node();
            tail=tail->next;
            tail->data=data;
            tail->prev=temp;
        }
        
    }

    void deQ()
    {
        if(head!=NULL)
        {
            int data;
            cout<<"Enter Element To Delete: ";
            cin>>data;
            Node *temp=search(data);
            Node *tempPre=temp->prev;
            Node *tempNex=temp->next;
            if (temp->data==head->data && head->next==NULL)
            {
                head=NULL;
                delete temp;
            }
            
            else if(temp->data==head->data)
            {
                head=temp->next;
                head->prev=NULL;
                delete temp;
            }
            else if (temp->data==tail->data)
            {
                tail=tail->prev;
                tail->next=NULL;
                delete temp;
            }
            else
            {
                tempPre->next=tempNex;
                tempNex->prev=tempPre;
                delete temp;
            }
        }
        else
        {
            cout<<"List is Empty"<<endl;
        }
        
    }

    Node* search(int data)
    {
        if(head==NULL)
        {
            cout<<"List is Empty"<<endl;
            return NULL;
        }
        else{
            Node *temp=head;
            while(temp!=NULL)
            {
                if (temp->data==data)
                {
                    return temp;
                }
                else
                {
                    temp=temp->next;
                }
            }
            cout<<"No Value Found";
            return NULL;
        }
        
    }

    void printAll()
    {
        if (head!=NULL)
        {
            Node *temp=head;
            while(temp!=NULL)
            {
                cout<<temp->data<<"\t";
                temp=temp->next;
            }
            cout<<endl;
        }
        else
        {
            cout<<"List Is Empty"<<endl;
        }
        
        
    }
    void printAllRev()
    {
        if(head!=NULL)
        {
            Node *temp=tail;
            while(temp!=NULL)
            {
                cout<<temp->data<<"\t";
                temp=temp->prev;
            }
            cout<<endl;
        }
        else
        {
            cout<<"List Is Empty"<<endl;
        }
        
    }
};

int main()
{
    Queue n1;
    while (true)
    {
        char x;
        cout<<"Chose Option\n1. EnQueue\t2. DeQueue\n3. Search\t4. Print All\n5. Print All Reverse\t6. Exit"<<endl;
        cin>>x;
        switch (x)
        {
        case '1':
            n1.enQ();
            break;
        case '2':
            n1.deQ();
            break;
        case '3':
            int x;
            cout<<"Enter Value to Search: ";
            cin>>x;
            n1.search(x);
            break;
        case '4':
            n1.printAll();
            break;
        case '5':
            n1.printAllRev();
            break;
        case '6':
            return 0;
        default:
            cout<<"Wrong Input"<<endl;
            break;
        }
    }
    

}