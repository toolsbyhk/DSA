#include<iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
};
class LinkedList
{
    Node* head = NULL ;
public:
    void Insert(int data,unsigned int pos)
    {   
        Node* temp1 = new Node;             //New node created

        temp1->data = data;                 //Data stored of new node
        temp1->next=NULL;

        Node* temp2=head;                   //New node pointer created,acts as head pointer, gets manipulated for change

        if(head==NULL || pos==1)            //Executes if 'position=1' or inserting in an empty list
        {
            temp1->next=head;
            head = temp1;
            return;
        }

        if(pos==0)                         //Executes if inserting at end
        {
            while(temp2->next!=NULL)        //Traversing
            {
                temp2=temp2->next;
            }
            temp2->next=temp1;
            return;
        }

        for(int i=0; i<pos-2; i++)          // Traversing till (position-1)...-2 as starting from head
        {
            if(temp2->next==NULL)           //Executes if given position is not in list, element entered at end of list
            {
                temp2->next=temp1;
                return;
            }
            else
            {
                temp2=temp2->next;
            }
        }
        temp1->next=temp2->next;
        temp2->next=temp1;
        return;
    }

    void Print ()
    {
        Node* temp = head;                        //New node pointer created,acts as head pointer, gets manipulated for change

        cout<<endl<<"List is: ";
        while(temp!=NULL)                         // Traversing and printing till end of list
        {
            cout<<temp->data<<" ";
            temp = temp->next;
        }
        cout<<endl;
    }

    void Delete(unsigned int pos)
    {
        Node* temp = head;                  //New node pointer created,acts as head pointer, gets manipulated for change
        Node* temp1;                        //New node created for manipulating nodes
        if(head==NULL)                         //executes if list is empty
        {
            cout<<endl<<"Empty list"<<endl<<endl;
        }
        else if(pos==1)                         //Executes to delete the first element
        {
            head = temp->next;
            delete temp;
        }
        else
        {
            for(int i=0; i<pos-2; i++)          // Traversing till (position-1)...-2 as starting from head
            {
                if(temp->next==NULL)           //Executes if given position is not in list, element entered at end of list
                {
                    temp1->next=temp->next;
                    delete temp;
                    return;
                }
                else
                {
                    temp1=temp;
                    temp=temp->next;
                }
            }
            temp1=temp;
            temp1=temp1->next;
            temp->next=temp1->next;

            delete temp1;                           //Deletes node
            return;
        }

    }
    void Search(int data)
    {
        Node* temp = head;                             //New node pointer created,acts as head pointer, gets manipulated for change
        unsigned int count=0;                           //For counting position

        if(head == NULL)                                //Executes if list is empty
        {
            cout<<"Empty list"<<endl<<endl;
            return;
        }
        while(temp->next!=NULL)                         //Executes till end of list reached
        {
            count++;                                    //Counting positions
            if(temp->data==data)                        // Executes if element found
            {
                cout<<"Position is: "<<count;
                return;
            }
            temp=temp->next;
        }
        if(temp->next == NULL)                      // Executes if element not found
        {
            cout<<"Element not found!";
        }
    }
    void Sort()                                 //Sorts in increasing order
    {
        int temp;

        Node* temp1;                      //Node pointers
        Node* temp2;

        temp1=head;                       //New node pointers created,acts as head pointer, gets manipulated for change
        temp2=head;

        temp2=temp2->next;
        while(temp1->next!=NULL)                // Sort
        {
            temp2=temp1->next;
            while(temp2->next!=NULL)
            {
                if(temp2->data<temp1->data)
                {
                    temp=temp2->data;
                    temp2->data=temp1->data;
                    temp1->data=temp;
                }
                temp2=temp2->next;
            }
            if(temp2->next==NULL)
            {
                if(temp2->data<temp1->data)
                {
                    temp=temp2->data;
                    temp2->data=temp1->data;
                    temp1->data=temp;
                }
            }
            temp1=temp1->next;
        }
    }
};

int main()
{
    LinkedList obj;

    cout<<"Press Ctrl+C to exit"<<endl<<endl<<endl;
    cout<<"What do you want to do?"<<endl<<endl;
    cout<<"1) Insert"<<endl;
    cout<<"2) Delete"<<endl;
    cout<<"3) Search"<<endl;
    cout<<"4) Sort"<<endl;
    cout<<"5) Print"<<endl;
    while(1)
    {
        unsigned int x,pos;
        int data;

        cout<<"Enter your choice: ";
        cin>>x;
        switch(x)
        {
        case 1:
            cout<<"Enter element: ";
            cin>>data;
            cout<<"Enter position: ";
            cin>>pos;
            obj.Insert(data,pos);
            obj.Print();
            continue;

        case 2:
            cout<<"Enter position: ";
            cin>>pos;
            obj.Delete(pos);
            obj.Print();
            continue;
        case 3:
            cout<<"Enter element: ";
            cin>>data;
            obj.Search(data);
            continue;
        case 4:
            obj.Sort();
            obj.Print();
            continue;
        case 5:
            obj.Print();
            continue;
        }
    }
}
