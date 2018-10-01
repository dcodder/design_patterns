#include<iostream>
#include<string>
using namespace std;

template < class T >
class Linux {
protected:
  void work(string name){
    cout<<name<<" is Assigned with Linux Project!"<<endl;
  }
};

template < class T >
class Postproc {
protected:
  void work(string name){
    cout<<name<<" is Assigned with PostProcessing Project!"<<endl;
  }
};

template < class T >
class Color {
protected:
  void work(string name){
    cout<<name<<" is Assigned with Display Color Project!"<<endl;
  }
};

template < class DisplayWorkPolicy >
class Display : private DisplayWorkPolicy {
public:
  void assignWork(string name) {
    this->work(name);
  }
};


int main(){
    typedef Display< Linux<string> > DisplayLinux;
    typedef Display< Postproc<string> > DisplayPostproc;
    typedef Display< Color<string> > DisplayColor;
    string nameLinux;
    string namePostproc;
    string nameColor;
    cout<<"Whom do you want to assign Linux Work: ";
    cin>>nameLinux;
    cout<<"Whom do you want to assign PostProcessing Work: ";
    cin>>namePostproc;
    cout<<"Whom do you want to assign Display Color Work: ";
    cin>>nameColor;
    DisplayLinux dl;
    DisplayPostproc dp;
    DisplayColor dc;
    dl.assignWork(nameLinux);
    dp.assignWork(namePostproc);
    dc.assignWork(nameColor);
    return 0;
}
