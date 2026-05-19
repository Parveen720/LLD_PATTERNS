#include <iostream>
using namespace std;

// Walk strategy
class WalkableRobot {
public:
    virtual void walk() = 0;
};

class NormalWalk : public WalkableRobot {
public:
    void walk() override {
        cout << "Walking normally" << endl;
    }
};

class NoWalk : public WalkableRobot {
public:
    void walk() override {
        cout << "Cannot walk" << endl;
    }
};

// Talk strategy
class TalkableRobot {
public:
    virtual void talk() = 0;
};

class NormalTalk : public TalkableRobot {
public:
    void talk() override {
        cout << "Talking normally" << endl;
    }
};

class NoTalk : public TalkableRobot {
public:
    void talk() override {
        cout << "Cannot talk" << endl;
    }
};

// Fly strategy
class FlyableRobot {
public:
    virtual void fly() = 0;
};

class NormalFly : public FlyableRobot {
public:
    void fly() override {
        cout << "Flying normally" << endl;
    }
};

class NoFly : public FlyableRobot {
public:
    void fly() override {
        cout << "Cannot fly" << endl;
    }
};

// Robot class
class Robot {
protected:
    WalkableRobot* walkBehavior;
    TalkableRobot* talkBehavior;
    FlyableRobot* flyBehavior;

public:
    Robot(WalkableRobot* w,
          TalkableRobot* t,
          FlyableRobot* f) {

        walkBehavior = w;
        talkBehavior = t;
        flyBehavior = f;
    }

    void walk() {
        walkBehavior->walk();
    }

    void talk() {
        talkBehavior->talk();
    }

    void fly() {
        flyBehavior->fly();
    }

    virtual void projection() = 0;
};

class CompanionRobot : public Robot {
public:
    CompanionRobot(WalkableRobot* w,
                   TalkableRobot* t,
                   FlyableRobot* f)
        : Robot(w, t, f) {}

    void projection() override {
        cout << "Displaying worker efficiency stats" << endl;
    }
};

int main() {

    // Normal objects
    NormalWalk nw;
    NormalTalk nt;
    NoFly nf;

    // Pass addresses using &
    CompanionRobot robot1(&nw, &nt, &nf);

    robot1.walk();
    robot1.talk();
    robot1.fly();
    robot1.projection();

    cout << endl;

    NoWalk nowalk;
    NoTalk notalk;
    NormalFly normalfly;

    CompanionRobot robot2(&nowalk, &notalk, &normalfly);

    robot2.walk();
    robot2.talk();
    robot2.fly();
    robot2.projection();

    return 0;
}