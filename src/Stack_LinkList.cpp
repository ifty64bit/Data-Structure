#include<iostream>

using namespace std;

class Node{
    public:
        int data;
        Node *up=NULL;
        Node *down=NULL;
};

class Stack{
    private:
        Node *top=NULL;
        Node *bottom=NULL;
    public:
        void push()
        {
            int data;
            cout<<"Enter Data"<<endl;
            cin>>data;
            if(top==NULL)
            {
                top=new Node();
                bottom=top;
                top->data=data;
            }
            else if(top!=NULL)
            {
                Node *temp=new Node();
                temp->data=data;
                temp->down=top;
                top->up=temp;
                top=top->up;
            }
        }
        void pop()
        {
            if(top==NULL)
            {
                cout<<"List is Empty"<<endl;
            }
            else if(top->down==NULL)
            {
                top=NULL;
                delete top;
            }
            else if(top!=NULL)
            {
                Node *temp=top;
                top=top->down;
                top->up=NULL;
                delete temp;
            }
        }
        void printAll()
        {
            if(top!=NULL)
            {
                Node *temp=bottom;
                while(temp!=NULL)
                {
                    cout<<temp->data<<"\t";
                    temp=temp->up;
                }
                cout<<endl;
            }
            else{
                cout<<"List Is Empty"<<endl;
            }
        }
        void printAllRev()
        {
            if(top!=NULL)
            {
                Node *temp=top;
                while(temp!=NULL)
                {
                    cout<<temp->data<<"\t";
                    temp=temp->down;
                }
                cout<<endl;
            }
        }
        void search()
        {
            if(top!=NULL)
            {
                int value;
                cout<<"Enter Value to Search"<<endl;
                cin>>value;
                Node *temp=bottom;
                int count=0;
                while (temp!=NULL)
                {
                    if(temp->data==value)
                    {
                        cout<<"Value Exiest "<<++count<<endl;
                    }
                }    
            }
        }
};

int main()
{
    Stack n1;
    while (true)
    {
        char x;
        cout<<"Chose Option:\n1. Push\t2. Pop\n3. Print All\t4. Search \n5. Print All Reverse\t6. Exit"<<endl;
        cin>>x;
        switch (x)
        {
        case '1':
            n1.push();
            break;
        case '2':
            n1.pop();
            break;
        case '3':
            n1.printAll();
            break;
        case '4':
            n1.search();
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