#include<iostream>
#include<string>
using namespace std;

struct INFO{
    int id;
    string name;
    string work;
};

class Multimedia{
    protected:
        INFO info;
        Multimedia(){}

    public:
        int getID(){
            return info.id;
        }
        string getName(){
            return info.name;
        }
        string getWork(){
            return info.work;
        }
        INFO getInfo(){
            return info;
        }
};

class MMDisplayLinux : public Multimedia{
    public:
        MMDisplayLinux(){
            cout<<"Enter the Details for MMDisplay Linux member---\n";
            cout<<"Enter Id: ";
            cin>>info.id;
            cout<<"Enter Name: ";
            cin>>info.name;
            info.work = string("Multimedia Display Linux");
        }
};

class MMDisplayDriver : public Multimedia{
    public:
        MMDisplayDriver(){
            cout<<"Enter the Details for MMDisplay Driver member---\n";
            cout<<"Enter Id: ";
            cin>>info.id;
            cout<<"Enter Name: ";
            cin>>info.name;
            info.work = string("Multimedia Display Driver");
        }
};

class MMDisplayPostproc : public Multimedia{
    public:
        MMDisplayPostproc(){
            cout<<"Enter the Details for MMDisplay Postproc member---\n";
            cout<<"Enter Id: ";
            cin>>info.id;
            cout<<"Enter Name: ";
            cin>>info.name;
            info.work = string("Multimedia Display Postproc");
        }
};

class MMCameraLinux : public Multimedia{
    public:
        MMCameraLinux(){
            cout<<"Enter the Details for MMCamera Linux member---\n";
            cout<<"Enter Id: ";
            cin>>info.id;
            cout<<"Enter Name: ";
            cin>>info.name;
            info.work = string("Multimedia Camera Linux");
        }
};

class MMCameraDriver : public Multimedia{
    public:
        MMCameraDriver(){
            cout<<"Enter the Details for MMCamera Driver member---\n";
            cout<<"Enter Id: ";
            cin>>info.id;
            cout<<"Enter Name: ";
            cin>>info.name;
            info.work = string("Multimedia Camera Driver");
        }
};

class MMCameraPostproc : public Multimedia{
    public:
        MMCameraPostproc(){
            cout<<"Enter the Details for MMCamera Postproc member---\n";
            cout<<"Enter Id: ";
            cin>>info.id;
            cout<<"Enter Name: ";
            cin>>info.name;
            info.work = string("Multimedia Camera Postproc");
        }
};


class MMFactory{
    public:
        virtual Multimedia* getMMLinux() = 0;
        virtual Multimedia* getMMDriver() = 0;
        virtual Multimedia* getMMPostproc() = 0;

};

class MMDisplayFactory : public MMFactory{
    public:
        Multimedia* getMMLinux(){
            return new MMDisplayLinux();
        }

        Multimedia* getMMDriver(){
            return new MMDisplayDriver();
        }

        Multimedia* getMMPostproc(){
            return new MMDisplayPostproc();
        }
};

class MMCameraFactory : public MMFactory{
    public:
        Multimedia* getMMLinux(){
            return new MMCameraLinux();
        }

        Multimedia* getMMDriver(){
            return new MMCameraDriver();
        }

        Multimedia* getMMPostproc(){
            return new MMCameraPostproc();
        }
};

int main()
{
    MMFactory* mm = 0;
    int flag;
    cout<<"Enter bit to select multimedia team(0-Display / 1-Camera): ";
    cin>>flag;

    if (flag)
    {
        mm = new MMDisplayFactory();
    }
    else
    {
        mm = new MMCameraFactory();
    }

    /* Use the factory to build interface. */
    Multimedia* lnx = mm->getMMLinux();
    Multimedia* drv = mm->getMMDriver();
    Multimedia* ppc = mm->getMMPostproc();

    /* See what have we recieved. */
    cout << "ID: "<<lnx->getID()<<"\nName: "<<lnx->getName()<<"\nWork: "<<lnx->getWork()<<endl;
    cout << "ID: "<<drv->getID()<<"\nName: "<<drv->getName()<<"\nWork: "<<drv->getWork()<<endl;
    cout << "ID: "<<ppc->getID()<<"\nName: "<<ppc->getName()<<"\nWork: "<<ppc->getWork()<<endl;
    return 0;
}
