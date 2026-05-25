#include<bits/stdc++.h>
using namespace std;

class ISubscriber {
public:
    virtual void update() = 0;
    virtual ~ISubscriber() {}
};

class IChannel {
public:
    virtual void subscribe(ISubscriber* subscriber) = 0;
    virtual void unsubscribe(ISubscriber* subscriber) = 0;
    virtual void notifySubscribers() = 0;
    virtual ~IChannel() {}
};

class Channel : public IChannel {
private:
    vector<ISubscriber*> subscribers;
    string name;
    string latestVideo;

public:
    Channel(const string& name) {
        this->name = name;
    }

    void subscribe(ISubscriber* subscriber) override {
        subscribers.push_back(subscriber);
    }

    void unsubscribe(ISubscriber* subscriber) override {
        auto it = find(subscribers.begin(), subscribers.end(), subscriber);

        if (it != subscribers.end()) {
            subscribers.erase(it);
        }
    }

    void notifySubscribers() override {
        for (ISubscriber* sub : subscribers) {
            sub->update();
        }
    }

    void uploadVideo(const string& title) {
        latestVideo = title;

        cout << name << " uploaded " << title << endl;

        notifySubscribers();
    }

    string getVideoData() {
        return "New video: " + latestVideo;
    }
};

class Subscriber : public ISubscriber {
private:
    string name;
    Channel* channel;

public:
    Subscriber(const string& name, Channel* channel) {
        this->name = name;
        this->channel = channel;
    }

    void update() override {
        cout << "Hey " << name << ", "
             << channel->getVideoData() << endl;
    }
};

int main() {

    Channel* channel = new Channel("Parveen Gaming");

    Subscriber* subs1 = new Subscriber("Parveen1", channel);
    Subscriber* subs2 = new Subscriber("Hemant", channel);

    channel->subscribe(subs1);
    channel->subscribe(subs2);

    channel->uploadVideo("Observer Pattern");

    channel->unsubscribe(subs1);

    channel->uploadVideo("Decorator Pattern Tutorial");

    delete subs1;
    delete subs2;
    delete channel;

    return 0;
}