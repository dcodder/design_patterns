#include<iostream>
#include<string>
using namespace std;

struct DispMember{
    int id;
    string name;
    string info;
};

class DisplaySingleton{
public:
    static DisplaySingleton* getInstance();
    void setdata(int,int,string,string);
    DispMember getdata(int);
    void setinfo(int,string);
private:
    static DispMember data[5];
    static DisplaySingleton* instance;
    DisplaySingleton(){
        for(int i=0;i<5;++i){
            data[i].id = -1;
            data[i].name = "";
            data[i].info = "";
        }
    }
};

DispMember DisplaySingleton::data[5];
DisplaySingleton* DisplaySingleton::instance = NULL;
DisplaySingleton* DisplaySingleton::getInstance(){
    if(!instance){
        instance = new DisplaySingleton();
    }
    return instance;
}

void DisplaySingleton::setdata(int idx,int tmpid,string tmpname,string tmpinfo){
    data[idx].id = tmpid;
    data[idx].name = tmpname;
    data[idx].info = tmpinfo;
}

DispMember DisplaySingleton::getdata(int idx){
    return data[idx];
}

void DisplaySingleton::setinfo(int idx,string tmpinfo){
    data[idx].info = tmpinfo;
}

int main(){
    DisplaySingleton *inst1;
    inst1 = inst1->getInstance();
    int ch;
    int idx = 0;
    int tempidx;
    int id;
    string name;
    string info;
    while(true){
        cout<<"Menu-------"<<endl;
        cout<<"1. Enter Member Details"<<endl;
        cout<<"2. Retrieve Member Details"<<endl;
        cout<<"3. Exit"<<endl;
        cout<<"Enter Choice: "<<endl;
        cin>>ch;
        switch(ch){
        case 1:
            cout<<"1. Enter Member Details------"<<endl;
            cout<<"Enter Id: ";
            cin>>id;
            cout<<"Enter Name: ";
            cin>>name;
            cout<<"Enter Info: ";
            cin>>info;
            if(idx<5){
                inst1->setdata(idx,id,name,info);
                idx++;
                cout<<endl;
            }
            else{
                cout<<"No More Rooms are Empty for Member Entry!"<<endl;;
            }
            break;
        case 2:
            cout<<"Enter Valid Member Index (1-5)";
            cin>>tempidx;
            if(tempidx<1&&tempidx>5){
                cout<<"Wrong Index!"<<endl;
                continue;
            }
            else{
                DispMember mb = inst1->getdata(tempidx-1);
                if(mb.id < 0){
                    cout<<"Member Details are not Available!"<<endl;
                    continue;
                }
                cout<<"Member Id: "<<mb.id<<endl;
                cout<<"Member Name: "<<mb.name<<endl;
                cout<<"Member has the Info: "<<mb.info<<endl;
            }
            break;
        case 3:
            goto out;
        default:
            cout<<"Please Enter the Correct Choice!"<<endl;;
        }
    }
    out:
    DisplaySingleton* inst2;
    inst2 = inst2->getInstance();
    inst2->setinfo(1,"Driver");
    DispMember mb = inst2->getdata(1);
    cout<<"Member Id: "<<mb.id<<endl;
    cout<<"Member Name: "<<mb.name<<endl;
    cout<<"Member has the Info: "<<mb.info<<endl;
    return 0;
}
