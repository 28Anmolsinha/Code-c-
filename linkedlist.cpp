SINGLY LINKED LIST IMPLEMENTATION

#include<iostream>
using namespace std;

class Node{
    public:
    int value;
    Node* next;

    Node(int value){
        this->value= value;
        this->next= NULL;
    }
};

int main(){
    Node* node1= new Node(25);
    cout<<node1->value<<endl;
    cout<<node1->next<<endl;
}


INSERT AT HEAD



#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int data){
        this->data=data;
        this->next=NULL;
    }
};

void insertathead(Node* &head,int d){
    Node* temp = new Node(d);
    temp->next= head;
    head= temp;


}
void print(Node* &head){
    Node* temp= head;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

INSERT AT TAIL


#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;


    Node(int data){
        this->data=data;
        this->next= NULL;
    }    
};

void insertattail(Node* &tail, int d){
    Node* temp = new Node(d);
    tail->next= temp;
    tail= temp;
}

void print(Node* &head){
    Node* temp= head;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;


}

int  main(){
    Node* node1= new Node(80);
    Node* head= node1;

    Node* tail= node1;
    insertattail(tail,70);
    print(head);
    insertattail(tail,90);
    print(head);
    insertattail(tail,80);
    print(head);
    insertattail(tail,100);
    print(head);
}

INSERT AT ANY POSITION


#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int data){
        this->data=data;
        this->next= NULL;

    }
};

void insertathead(Node* &head,int d){
    Node* temp= new Node(d);
    temp->next=head;
    head=temp;
}

void insertatposition(Node* &head, int position,int d){
    Node* temp= head;
    int count=1;

    while(count<position-1){
        temp=temp->next;
        count++;
    }

    Node* nodetoinsert= new Node(d);
    nodetoinsert->next=temp->next;
    temp->next= nodetoinsert; 
    }


void print(Node* &head){
    Node* temp= head;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp= temp->next;
    }
    cout<<endl;
}


int main(){
    Node* node1= new Node(10);
    cout<<node1->data<<endl;

    Node* head= node1;
    insertathead(head,70);
    print(head);
    insertathead(head,52);
    print(head);
    insertathead(head,13);
    print(head);
    insertatposition(head,4,55);
    print(head);

}

INSERTION AT ANY POSITION (WITH FIRST AND LAST ELEMENT AND UPDATION AS WELL)


#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int data){
        this->data=data;
        this->next=NULL;
    }
};

void insertathead(Node* &head, int d){
    Node* temp= new Node(d);
    temp->next=head;
    head=temp;

}

void insertattail(Node* &tail, int d){
    Node* temp= new Node(d);
    tail->next=temp;
    tail=temp;

}

void insertatposition(Node* &head, Node* &tail, int position , int d){
    if(position==1){
        insertathead(head,d);
        return;
    }
    Node* temp= head;
    int count=1;

    while(count<position-1){
        temp= temp->next;
        count++;
    }
    if(temp->next== NULL){
    insertattail(tail,d);
    return;
    }

    Node* nodetoinsert= new Node(d);
    nodetoinsert->next= temp->next;
    temp->next= nodetoinsert;



}


void print(Node* &head){
    Node* temp= head;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp= temp->next;

    }
    cout<<endl;
    }



int main(){
    Node* node1= new Node(10);
    cout<<node1->data<<endl;
    Node* head= node1;
    Node* tail= node1;


    insertathead(head,70);
    print(head);
    insertattail(tail,80);
    print(head);
    insertathead(head,55);
    print(head);
    insertattail(tail,25);
    print(head);
    insertatposition(head,tail,6,23);
    print(head);
    insertatposition(head,tail,1,100);
    print(head);

    cout<<"head is "<<head->data<<endl;
     cout<<"tail is "<<tail->data<<endl;
}



// DELETION IN LINKED LIST


#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int data){
        this->data=data;
        this->next= NULL;
    }

    Node(){
        int value= this->data;
        // MEMORY FREE HO RHA HAI
        if(this->next != NULL){
            delete next;
            this->next= NULL;
        }
        cout<<"Memory is free for value "<<value<<endl;

    }
};

void insertathead(Node* &head, int data){

    Node* temp = new  Node (data);
    temp->next=head;
    head= temp;
}

void insertattail(Node* &tail, int data){
    Node* temp = new  Node (data);
    tail->next=temp;
    tail= temp;
}

void insertatposition(Node* &head, Node* &tail,int position, int data){
    if(position==1){
        insertathead(head,data);
        return;
    }
    Node* temp= head;
    int count=1;
    while(count < position-1){
        temp= temp->next;
        count++;
    }
    if(temp->next== NULL){
        insertattail(tail,data);
        return;
    }



    Node* insertintonode= new Node(data);
    insertintonode->next= temp->next;
    temp->next=insertintonode;

}

void print(Node* &head){
    Node* temp=head;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp= temp->next;
    }
    cout<<endl;
}

void deletenode(Node* &head,int position){
    if(position==1){
        Node* temp= head;
        head= head->next;
        // MEMORY FREE KRWANA HOGA
        temp->next=NULL;
        delete temp;
    }else{
        Node* current = head;
        Node* prev= NULL;

        int count=1;
        while(count<position){
            prev=current;
            current= current->next;
            count++;
            
        }
        prev->next= current->next;
        current->next=NULL;
        delete current;
    }
}




int main(){
    Node* node1= new Node(10);
    cout<<node1->data<<endl;

    Node* head= node1;
    Node* tail= node1;

    insertathead(head, 20);
    print(head);
    insertattail(tail,30);
    print(head);
    insertathead(head, 50);
    print(head);
    insertatposition(head,tail,1,92);
    print(head);
    insertatposition(head,tail,6,62);
    print(head);

    cout<<"head is "<<head->data<<endl;
    cout<<"tail is"<<tail->data<<endl;

    deletenode(head,5);
    print(head);

}


#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int data){
        this->data=data;
        this->next=NULL;
    }

    ~Node(){
        int value= this->data;
        if(this->next != NULL){
            delete next;
            this->next= NULL;
        }
        cout<<"the deleted value is "<<value<<endl;
    }
};

void insertathead(Node* &head, int d){
    Node* temp= new Node(d);
    temp->next=head;
    head=temp;
}
void deletenode(Node* &head,int position){
    if(position==1){
        Node* temp= head;
        head= head->next;
        temp->next=NULL;
        delete temp;
    }else{
        Node* previous=NULL;
        Node* Current=head;

        int count=1;
        while(count < position){
            previous= Current;
            Current= Current->next;
            count++;
        }
        previous->next=Current->next;
        Current->next= NULL;
        delete Current;
    }
}
void print(Node* &head){
    Node* temp=head;
    while(temp !=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}


int main(){
    Node* node1 = new Node(10);
    cout<<node1->data<<endl;

    Node* head= node1;
    insertathead(head,40);
    print(head);
    insertathead(head,30);
    print(head);
    insertathead(head,80);
    print(head);

    deletenode(head,2);
    print(head);
    return 0;
    
}


// DOUBLY LINKED LIST
// LENGTH OF A LINKED LIST AND NORMAL TRAVERSAL OF A DOUBLY LINKED LIST

#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* prev;
    Node* next;

    Node(int data){
        this->data=data;
        this->prev=NULL;
        this->next=NULL;
    
    }

};



void print(Node* &head){
    Node* temp= head;

    while(temp != NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

int getlen(Node* &head){
    int len=0;
    Node* temp= head;

    while(temp != NULL){
        len++;
        temp=temp->next;
    }
    return len;
}

int main(){
    Node* node1= new Node(10);
    Node* head= node1;
    print(head);

    cout<<"LENGTH OF THE FUNCTION IS "<<getlen(head);
   

}



// INSERTION FROM HEAD AND TAIL IN DOUBLY LINKED LIST


#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* prev;
    Node* next;

    Node(int data){
        this->data=data;
        this->prev=NULL;
        this->next=NULL;
    }
};

void insertathead(Node* &head,int d){
    Node* temp= new Node(d);
    temp->next=head;
    head->prev=temp;
    head=temp;
    
}

void insertattail(Node* &tail, int d){
    Node* temp= new Node(d);
    tail->next= temp;
    temp->prev= tail;
    tail=temp;
}

void print(Node* &head){
    Node* temp= head;

    while(temp != NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
int getlen(Node* &head){
    int len=0;
    Node* temp= head;

    while(temp != NULL){
        len++;
        temp=temp->next;
    }
    return len;
}


int main(){
    Node* node1= new Node(15);

    Node* head= node1;
     Node* tail= node1;
    print(head);
    insertathead(head,58);
    print(head);
     insertathead(head,38);
    print(head);
    insertattail(tail,41);
    print(head);
    cout<<"The length of the function is "<<getlen(head);

}


INSERT AT ANY POSITION AND LENGTH AND ADRESS OF EVERYTHING


#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* prev;
    Node* next;

    Node(int data){
        this->data=data;
        this->prev=NULL;
        this->next=NULL;
    }
};

void insertathead(Node* &head,int d){
    Node* temp= new Node(d);
    temp->next=head;
    head->prev=temp;
    head=temp;
    
}

void insertattail(Node* &tail, int d){
    Node* temp= new Node(d);
    tail->next= temp;
    temp->prev= tail;
    tail=temp;
}
void insertatnode(Node* &head, Node* &tail,int position , int d){
    if(position==1){
        insertathead(head,d);
        return;
    }


}
void print(Node* &head){
    Node* temp= head;

    while(temp != NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
int getlen(Node* &head){
    int len=0;
    Node* temp= head;

    while(temp != NULL){
        len++;
        temp=temp->next;
    }
    return len;
}


int main(){
    Node* node1= new Node(15);

    Node* head= node1;
     Node* tail= node1;
    print(head);
    insertathead(head,58);
    print(head);
     insertathead(head,38);
    print(head);
    insertattail(tail,41);
    print(head);
    cout<<"The length of the function is "<<getlen(head);

}



#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* previous;
    Node* next;

    Node(int data){
        this->data=data;
        this->previous=NULL;
        this->next=NULL;
    }
};

void insertathead(Node* &head, int d){
    Node* temp= new Node(d);
    temp->next=head;
    head->previous=temp;
    head=temp;

}

void insertattail(Node* &tail, int d){
    Node* temp= new Node(d);
    tail->next=temp;
    temp->previous=tail;
    tail=temp;
}
void insertatposition(Node* &head, Node* &tail, int position, int d){

    if(position==1){
        insertathead(head,d);
        return;
    }
    Node* temp= head;
    int count=1;

    while(count< position-1){
        temp=temp->next;
        count++;
    }

    Node* nodetoinsert= new Node(d);
    nodetoinsert->next=temp->next;
    temp->next->previous= nodetoinsert;
    nodetoinsert->previous=temp;
    temp->next=nodetoinsert;

    if(temp->next==NULL){
        insertattail(tail,d);
        return;
    }

}
void print(Node* &head){
    Node* temp=head;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

int getlength(Node* head){
    int length=0;
    Node* temp= head;

    while(temp != NULL){
        length++;
        temp=temp->next;
        
    }
    return length;

}

int main(){
    Node* node1= new Node(16);
    cout<<node1->data<<endl;

    Node* head=  node1;
    Node* tail=  node1;
    insertathead(head,48);
    print(head);
    insertattail(tail,80);
    print(head);
    insertatposition(head,tail,2,99);
    print(head);

    cout<<"The length of the linked list  "<<getlength(head)<<endl;
    cout<<"HEAD is"<<head->data<<endl;
    cout<<"ADDRESS OF HEAD next IS "<<head->next<<endl;
    cout<<"ADDRESS OF HEAD previous IS "<<head->previous<<endl;
    cout<<"TAIL is"<<tail->data<<endl;
    cout<<"ADDRESS OF TAIL next IS "<<tail->next<<endl;
    cout<<"ADDRESS OF TAIL previous IS "<<tail->previous<<endl;


}


CORRECTED DOUBLY LINKED LIST CODE



#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node* prev;

    Node(int data){
        this->data=data;
        this->next=NULL;
        this->prev=NULL;
    }
};
void insertathead(Node* &head, Node* &tail, int d){
    if(head==NULL){
        Node* temp= new Node(d);
        head=temp;
        tail=temp;
    }
    else{
    Node* temp= new Node(d);
    temp->next=head;
    head->prev=temp;
    head=temp;

    }
}
void insertattail(Node* &head, Node* &tail, int d){
    if(tail==NULL){
        Node* temp= new Node(d);
        head=temp;
        tail=temp;
    }
    else{
    Node* temp= new Node(d);
    tail->next=temp;
    temp->prev=tail;
    tail=temp;

    }
}

void insertatposition(Node* &head, Node* &tail, int position, int d){

    if(position==1){
        insertathead(head,tail,d);
        return;
    }
    Node* temp= head;
    int count=1;

    while(count< position-1){
        temp=temp->next;
        count++;
    }

    Node* nodetoinsert= new Node(d);
    nodetoinsert->next=temp->next;
    temp->next->prev= nodetoinsert;
    nodetoinsert->prev=temp;
    temp->next=nodetoinsert;

    if(temp->next==NULL){
        insertattail(head,tail,d);
        return;
    }

}


void print(Node* &head){
    Node* temp= head;
    while(temp != NULL){
        cout<< temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

int main(){

    Node* head= NULL;
    Node* tail= NULL;

    insertathead(head,tail,89);
    print(head);
    insertattail(head,tail,84);
    print(head);
    insertathead(head,tail,48);
    print(head);
    insertattail(head,tail,77);
    print(head);
    insertatposition(head,tail,3,8888);
    print(head);
    
}


DELETION OF DOUBLY LINKED LIST


#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node* prev;

    Node(int data){
        this->data=data;
        this->next=NULL;
        this->prev=NULL;
    }
    ~Node(){
        int value=this->data;
        if(this->next != NULL){
            delete next;
            this->next=NULL;
        }
        cout<<"The deleted value is "<<value<<endl;
    }
};
void insertathead(Node* &head, Node* &tail, int d){
    if(head==NULL){
        Node* temp= new Node(d);
        head=temp;
        tail=temp;
    }
    else{
    Node* temp= new Node(d);
    temp->next=head;
    head->prev=temp;
    head=temp;

    }
}
void deletenode(Node* &head,int position){
    if(position==1){
        Node* temp= head;
        temp->next-> prev= NULL;
        head=temp->next;
        temp->next=NULL;
        delete temp;
    }else{
        Node* prev=NULL;
        Node* current= head;
        int count=1;
        while(count< position){
            prev=current;
            current=current->next;
            count++;
        }
        current->prev=NULL;
        prev->next= current->next;
        current->next=NULL;
        delete current;


    }
}
void print(Node* &head){
    Node* temp= head;
    while(temp != NULL){
        cout<< temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

int main(){

    Node* head=NULL;
    Node* tail= NULL;
    insertathead(head,tail,77);
    print(head);
    insertathead(head,tail,17);
    print(head);
    insertathead(head,tail,37);
    print(head);

    deletenode(head,2);
    print(head);
    cout<<"value of head is "<<head->data;
}





#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
     Node(int data){
        this->data=data;
        this->next=NULL;
     }
};

void insertnode(Node* &tail, int element, int d){
    if(tail==NULL){
        Node* newNode= new Node(d);
        tail= newNode;
        newNode->next= newNode;
    }else{
        Node* current= tail;

        while(current->data != element){
            current= current->next;
        }
        Node* temp= new Node(d);
        temp->next= current->next;
        current->next=temp;


    }
}

void print(Node* &tail){
    Node* temp= tail;
    do{
        cout<<tail->data<<" ";
        temp=tail->next;

    } while(tail != temp);
        cout<<endl;

    
}

int main(){

    Node* tail=NULL;
    insertnode(tail,1,5);
    print(tail);
    
    insertnode(tail,5,7);
    print(tail);
    
}