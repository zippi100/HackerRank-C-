// Message Order
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Message {
public: 
    Message() {}
    const string& get_text() {
        return m;
    }
    const int& get_id() {
        return id;
    }
    void set_text(string text){m = text;}
    void set_id(int i) {id = i;}
private:
    string m;
    int id;
};

bool operator < (Message &a, Message &b){
    return a.get_id() < b.get_id();
}

class MessageFactory {
public:
    MessageFactory() {}
    Message create_message(const string& text) {
        Message m;
        ++id;
        m.set_text(text);
        m.set_id(id);
        return m;
    }
private:
    int id = 0;
};

class Recipient {
public:
    Recipient() {}
    void receive(const Message& msg) {
        messages_.push_back(msg);
    }
    void print_messages() {
        fix_order();
        for (auto& msg : messages_) {
            cout << msg.get_text() << endl;
        }
        messages_.clear();
    }
private:
    void fix_order() {
        sort(messages_.begin(), messages_.end());
    }
    vector<Message> messages_;
};

class Network {
public:
    static void send_messages(vector<Message> messages, Recipient& recipient) {
    // simulates the unpredictable network, where sent messages might arrive in unspecified order
        random_shuffle(messages.begin(), messages.end());         
        for (auto msg : messages) {
            recipient.receive(msg);
        }
    }
};



int main() {
    MessageFactory message_factory;
    Recipient recipient;
    vector<Message> messages;
    string text;
    while (getline(cin, text)) {
        messages.push_back(message_factory.create_message(text));
    }
    Network::send_messages(messages, recipient);
    recipient.print_messages();
}

