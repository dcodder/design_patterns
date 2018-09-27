#include<iostream>
#include<string>
#include<vector>
using namespace std;

struct DataInfo{
    int id;
    string name;
    string phno;
};

class Subject{
    vector < class Observer* > views;
    DataInfo data;
public:
    void attach(Observer *obs){
        views.push_back(obs);
    }
    void setData(DataInfo dt){
        data = dt;
        notify();
    }
    void setName(string tmpname){
        data.name = tmpname;
        notify();
    }
    void setPhone(int tmpid){
        data.id = tmpid;
        notify();
    }
    void setPhone(string tph){
        data.phno = tph;
        notify();
    }
    DataInfo getData(){
        return data;
    }
    string getName(){
        return data.name;
    }
    int getId(){
        return data.id;
    }
    string getPhone(){
        return data.phno;
    }
    void notify();
};

class Observer{
    Subject* sub1;
    string name;
public:
    Observer(Subject *tmpsub,string tmpname){
        sub1 = tmpsub;
        name = tmpname;
        sub1->attach(this);
    }
    void update();
    void setSubject(Subject *tmpsub){
        sub1 = tmpsub;
        sub1->attach(this);
    }
protected:
    Subject *getSubject(){
        return sub1;
    }
    string getName(){
        return name;
    }
};

void Subject::notify() {
  for (int i = 0; i < views.size(); i++)
    views[i]->update();
}

void Observer::update(){
    DataInfo info = getSubject()->getData();
    string name = getName();
    cout<<name<<" saw an update on "<<info.name<<" Record:"<<endl;
    cout<<info.name<<", "<<info.phno<<endl;
}

int main(){
    Subject s1,s2;
    Observer ob1(&s1,"Ashu");
    Observer ob2(&s1,"Ganesh");
    Observer ob3(&s2,"Sravanthi");
    DataInfo d1 = {124356,"Prashant","8978965432"};
    s1.setData(d1);
    DataInfo d2 = {125876,"Syam","9896785438"};
    s2.setData(d2);
    s1.setPhone("6895745982");
    return 0;
}

