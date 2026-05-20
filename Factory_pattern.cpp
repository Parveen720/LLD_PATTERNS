#include<iostream>

using namespace std;

// product class and subclass
class Burger{
public:
    virtual void prepare()=0;
    virtual ~Burger() {}
};

class BasicBurger:public Burger{
    public:
    void prepare() override{
        cout<<"Prepare basic burger with bun,patty,and ketchup"<<endl;
    }
};

class StandardBurger:public Burger{
public:
    void prepare() override{
        cout<<"Prepare standard burger with bun, patty, cheese and leetuce"<<endl;
    }
};

class PremiumBurger:public Burger{
    public:
    void prepare() override{
        cout<<"preapre premium burger  with bun,patty,cheese and leetuce"<<endl;
    }
};

class BasicWheatBurger:public Burger{
    public:
    void prepare() override{
        cout<<"prepare basic wheat burger with bun,patty,and ketchup"<<endl;
    }
};

class StandardWheatBurger:public Burger{
    public:
    void prepare() override{
        cout<<"prepareing wheat burger eith bun,patty and cheeese"<<endl;
    }
};

class PremiumWheatBurger:public Burger{
    public:
    void prepare() override{
        cout<<"preparing whear premium burger with bun, chese ,patty"<<endl;
    }
};

class BurgerFactory{
    public:
    virtual Burger* createBurger(string& type) =0;
};

class SinghBurger:public BurgerFactory{
    public:
    Burger* createBurger(string& type) override{
        if(type=="basic"){
            return new BasicBurger();
        }else if(type=="standard"){
            return new StandardBurger();
        }else if(type=="premium"){
            return new PremiumBurger();
        }
        else{
            cout<<"invalid burger type!"<<endl;
            return nullptr;
        }
    }
};

class KingBurger:public BurgerFactory{
public:
    Burger* createBurger(string& type) override{
        if(type=="basic"){
            return new BasicWheatBurger();
        }else if(type=="standard"){
            return new StandardWheatBurger();
        }else if(type=="premium"){
            return new PremiumWheatBurger();
        }
        else{
            cout<<"invalid burger type!"<<endl;
            return nullptr;
        }
    }
   
};

int main(){
    string type="basic";

    BurgerFactory* myFactory=new KingBurger();

    Burger* burger=myFactory->createBurger(type);
    burger->prepare();
    return 0;
}