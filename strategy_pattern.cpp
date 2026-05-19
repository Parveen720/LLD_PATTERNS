#include <iostream>
using namespace std;

// --strategy interface for walk--
class WalkableRobot{
    public:
    virtual void walk()=0;
    virtual ~WalkableRobot() {}
};

//  -- Concrete Stratagies for walk ---
class NormalWalk: public WalkableRobot{
    public:
    void walk() override{
        cout<< "Walking normally"<<endl;
    }

};

class NoWalk:public WalkableRobot{
    public:
    void walk() override {
        cout<<"Cannot walk"<<endl;
    }
};
//  starategies interface for talk 
class TalkableRobot{
    public:
    virtual void talk()=0;
    virtual ~TalkableRobot(){}
};

// Concrete strategies for talk 

class NoramalTalk: public TalkableRobot {
    public:
    void talk() override{
        cout<< "Talking normally"<<endl;
    }
};

class NoTalk:public TalkableRobot{
    public:
    void talk() override{
        cout<<"Cannot talk"<<endl;
    }
};

class FlyableRobot{
    public:
    virtual void fly()=0;
    virtual ~FlyableRobot(){}
};

class NormalFly:public FlyableRobot{
    public:
    void fly() override{
        cout<<"FLying normally"<<endl;
    }
};

class Nofly:public FlyableRobot{
   public:
   void fly() override{
       cout<<"canot fly"<<endl;
   }
};

//robot class

class Robot{
    protected:
    WalkableRobot* walkBehavior;
    TalkableRobot* talkBehavior;
    FlyableRobot* flyBehavior;

   public:
   Robot(WalkableRobot* w,TalkableRobot* t,FlyableRobot* f){
    this->walkBehavior=w;
    this->talkBehavior=t;
    this->flyBehavior=f;
   } 

   void walk(){
    walkBehavior->walk();
   }
   void talk(){
    talkBehavior->talk();

   }
   void fly(){
    flyBehavior->fly();
   }
   virtual void projection()=0;
};

class CompanioinRobot: public Robot{
    public:
    CompanioinRobot(WalkableRobot* w,TalkableRobot* t,FlyableRobot* f):Robot(w,t,f){}

    void projection() override{
        cout<<"Displating worker efficiency stats"<<endl;
    }
};

int main(){
    Robot* robot1=new CompanioinRobot(new NormalWalk(),new NoramalTalk(),new Nofly());
    robot1->walk();
    robot1->talk();
    robot1->fly();
    robot1->projection();
    cout<<endl;
    Robot* robot2=new CompanioinRobot(new NoWalk(),new NoTalk(),new NormalFly());
    robot2->walk();
    robot2->talk();
    robot2->fly();
    robot2->projection();

    return 0;
}