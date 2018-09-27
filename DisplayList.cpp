#include<iostream>
#include<string>
using namespace std;

struct Node{
        int id;
        string name;
        string info;
        struct Node* next;
};

class Display{
    Node *head;
public:
    Display(){
        head = NULL;
    }
    Display(Node nd){
        head = new Node();
        head->id = nd.id;
        head->name = nd.name;
        head->info = nd.info;
    }
    Display operator+(Node nd){
        Display tmp;
        Node *p = new Node();
        p->id = nd.id;
        p->name = nd.name;
        p->info = nd.info;
        p->next = NULL;
        if(head == NULL){
            head = p;
        }
        else{
            Node *t = head;
            while(t->next!=NULL)    t=t->next;
            t->next = p;
        }
        tmp.head = head;
        return tmp;
    }
    void print(){
        Node *t = head;
        int i=1;
        while(t!=NULL){
            cout<<"Member "<<i++<<"Details---"<<endl;
            cout<<t->id<<endl<<t->name<<endl<<t->info<<endl;
            t=t->next;
        }
    }
};

int main(){
    Display recObj;
    Node tmp;
    for(int i=0;i<3;++i){
        cout<<"Member "<<i+1<<" Details---"<<endl;
        cin>>tmp.id;
        cin>>tmp.name;
        cin>>tmp.info;
        recObj = recObj + tmp;
    }
    recObj.print();
    return 0;
}

