#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Display{
    string name;
    class Status* curr_state;
public:
    Display();
    Display(Status* s, string n){
        name = n;
        curr_state = s;
    }
    void setCurrentState(Status* s){
        curr_state = s;
    }
    void setName(string tmpname){
        name = tmpname;
    }
    string getName(){
        return name;
    }
    void ooo();                     // 0: Out of Office
    void available();               // 1: Available
    void meeting();                 // 2: In Meeting
    void lunch();                   // 3: Went for Lunch
    void ilt();                     // 4: Will come Late
};

class Status{
public:
    virtual void ooo(Display* d){ cout<<"Already Out of Office!"<<endl;}
    virtual void available(Display* d){ cout<<"Already in Office!"<<endl;}
    virtual void meeting(Display* d){ cout<<"Already in Meeting!"<<endl;}
    virtual void lunch(Display* d){ cout<<"Already at Lunch!"<<endl;}
    virtual void ilt(Display* d){ cout<<"Already Will come Late!"<<endl;}
};

class OOO:public Status{
public:
    OOO(){
        cout<<"OOO Constructor!"<<endl;
    }
    void available(Display *d);
    void meeting(Display *d);
    void lunch(Display *d);
    void ilt(Display *d);
};
class AVAIL:public Status{
public:
    AVAIL(){
        cout<<"Available Constructor!"<<endl;
    }
    void ooo(Display *d);
    void meeting(Display *d);
    void lunch(Display *d);
    void ilt(Display *d);
};
class MEET:public Status{
public:
    MEET(){
        cout<<"Meeting Constructor!"<<endl;
    }
    void ooo(Display *d);
    void available(Display *d);
    void lunch(Display *d);
    void ilt(Display *d);
};
class LUNCH:public Status{
public:
    LUNCH(){
        cout<<"Lunch Constructor!"<<endl;
    }
    void ooo(Display *d);
    void available(Display *d);
    void meeting(Display *d);
    void ilt(Display *d);
};
class ILT:public Status{
public:
    ILT(){
        cout<<"ILT Constructor!"<<endl;
    }
    void ooo(Display *d);
    void available(Display *d);
    void meeting(Display *d);
    void lunch(Display *d);
};
Display::Display(){
    curr_state = new AVAIL();   //By default the person is Available
}

void Display::ooo(){
    curr_state->ooo(this);
}
void Display::available(){
    curr_state->available(this);
}
void Display::meeting(){
    curr_state->meeting(this);
}
void Display::lunch(){
    curr_state->lunch(this);
}
void Display::ilt(){
    curr_state->ilt(this);
}

void OOO::available(Display *d){
    cout<<"Status updated from OOO to Available!"<<endl;
    d->setCurrentState(new AVAIL());
    delete this;
}
void OOO::meeting(Display *d){
    cout<<"Status updated from OOO to Meeting!"<<endl;
    d->setCurrentState(new MEET());
    delete this;
}
void OOO::lunch(Display *d){
    cout<<"Status updated from OOO to Lunch!"<<endl;
    d->setCurrentState(new LUNCH());
    delete this;
}
void OOO::ilt(Display *d){
    cout<<"Status updated from OOO to ILT!"<<endl;
    d->setCurrentState(new ILT());
    delete this;
}

void AVAIL::ooo(Display *d){
    cout<<"Status updated from Available to OOO!"<<endl;
    d->setCurrentState(new OOO());
    delete this;
}
void AVAIL::meeting(Display *d){
    cout<<"Status updated from Available to Meeting!"<<endl;
    d->setCurrentState(new MEET());
    delete this;
}
void AVAIL::lunch(Display *d){
    cout<<"Status updated from Available to Lunch!"<<endl;
    d->setCurrentState(new LUNCH());
    delete this;
}
void AVAIL::ilt(Display *d){
    cout<<"Status updated from Available to ILT!"<<endl;
    d->setCurrentState(new ILT());
    delete this;
}

void MEET::ooo(Display *d){
    cout<<"Status updated from Meeting to OOO!"<<endl;
    d->setCurrentState(new OOO());
    delete this;
}
void MEET::available(Display *d){
    cout<<"Status updated from Meeting to Available!"<<endl;
    d->setCurrentState(new AVAIL());
    delete this;
}
void MEET::lunch(Display *d){
    cout<<"Status updated from Meeting to Lunch!"<<endl;
    d->setCurrentState(new LUNCH());
    delete this;
}
void MEET::ilt(Display *d){
    cout<<"Status updated from Meeting to ILT!"<<endl;
    d->setCurrentState(new ILT());
    delete this;
}


void LUNCH::ooo(Display *d){
    cout<<"Status updated from Lunch to OOO!"<<endl;
    d->setCurrentState(new OOO());
    delete this;
}
void LUNCH::available(Display *d){
    cout<<"Status updated from Lunch to Available!"<<endl;
    d->setCurrentState(new AVAIL());
    delete this;
}
void LUNCH::meeting(Display *d){
    cout<<"Status updated from Lunch to Meeting!"<<endl;
    d->setCurrentState(new MEET());
    delete this;
}
void LUNCH::ilt(Display *d){
    cout<<"Status updated from Lunch to ILT!"<<endl;
    d->setCurrentState(new ILT());
    delete this;
}


void ILT::ooo(Display *d){
    cout<<"Status updated from ILT to OOO!"<<endl;
    d->setCurrentState(new OOO());
    delete this;
}
void ILT::available(Display *d){
    cout<<"Status updated from ILT to Available!"<<endl;
    d->setCurrentState(new AVAIL());
    delete this;
}
void ILT::meeting(Display *d){
    cout<<"Status updated from ILT to Meeting!"<<endl;
    d->setCurrentState(new MEET());
    delete this;
}
void ILT::lunch(Display *d){
    cout<<"Status updated from ILT to Lunch!"<<endl;
    d->setCurrentState(new LUNCH());
    delete this;
}


int main(){
    void (Display::*fptr[])() = {
                                  Display::ooo,
                                  Display::available,
                                  Display::meeting,
                                  Display::lunch,
                                  Display::ilt
                                };
    bool flag = true;
    int st;
    Status *s1 = new OOO();
    Display dts(s1,"Anant");
    while(flag){
        cout<<"0. Change Status to OOO"<<endl;
        cout<<"1. Change Status to Available"<<endl;
        cout<<"2. Change Status to Meeting"<<endl;
        cout<<"3. Change Status to Lunch"<<endl;
        cout<<"4. Change Status to ILT"<<endl;
        cout<<"5. Stop"<<endl;
        cout<<"Enter Choice: "<<endl;
        cin>>st;
        if(st>5) continue;
        if(st == 5) flag = false;
        cout<<dts.getName()<<" ";
        (dts.*fptr[st])();
    }
    return 0;
}


