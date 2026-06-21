#include <iostream>
#include <memory>
#include <set>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

enum class ChannelType { Email, Sms, Push };
enum class NotificationStatus { Created, Sent, Failed };

struct User {
    string id;
    string email;
    string phone;
};

struct Notification {
    string id;
    User user;
    string title;
    string body;
    NotificationStatus status = NotificationStatus::Created;
};

class NotificationChannel {
public:
    virtual ~NotificationChannel() = default;
    virtual ChannelType type() const = 0;
    virtual void send(const User& user, const string& title, const string& body) = 0;
};

class EmailChannel : public NotificationChannel {
public:
    ChannelType type() const override {
        return ChannelType::Email;
    }

    void send(const User& user, const string& title, const string&) override {
        cout << "Email sent to " << user.email << ": " << title << endl;
    }
};

class SmsChannel : public NotificationChannel {
public:
    ChannelType type() const override {
        return ChannelType::Sms;
    }

    void send(const User& user, const string&, const string& body) override {
        cout << "SMS sent to " << user.phone << ": " << body << endl;
    }
};

struct NotificationPreference {
    string userId;
    set<ChannelType> enabledChannels;
};

class NotificationService {
    unordered_map<ChannelType, shared_ptr<NotificationChannel>> channels;
    unordered_map<string, NotificationPreference> preferences;

public:
    void registerChannel(shared_ptr<NotificationChannel> channel) {
        channels[channel->type()] = channel;
    }

    void setPreference(const NotificationPreference& preference) {
        preferences[preference.userId] = preference;
    }

    void send(Notification& notification) {
        NotificationPreference preference = preferences[notification.user.id];
        for (ChannelType channelType : preference.enabledChannels) {
            if (channels.count(channelType)) {
                channels[channelType]->send(notification.user, notification.title, notification.body);
            }
        }
        notification.status = NotificationStatus::Sent;
    }
};

int main() {
    User user{"U1", "yash@example.com", "9999999999"};

    NotificationService service;
    service.registerChannel(make_shared<EmailChannel>());
    service.registerChannel(make_shared<SmsChannel>());
    service.setPreference(NotificationPreference{user.id, {ChannelType::Email, ChannelType::Sms}});

    Notification notification{"N1", user, "Order shipped", "Your order is on the way"};
    service.send(notification);

    cout << "Notification status: SENT" << endl;
    return 0;
}
