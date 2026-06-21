#include <iostream>
#include <set>
#include <stdexcept>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

enum class ConversationType { Direct, Group };
enum class DeliveryStatus { Sent, Delivered, Read };

struct User {
    string id;
    string name;
};

struct Conversation {
    string id;
    ConversationType type;
    set<string> participantIds;
};

struct Message {
    string id;
    string conversationId;
    string senderId;
    string text;
};

struct MessageDelivery {
    string messageId;
    string userId;
    DeliveryStatus status;
};

class ChatService {
    unordered_map<string, Conversation> conversations;
    unordered_map<string, vector<Message>> messagesByConversation;
    unordered_map<string, vector<MessageDelivery>> deliveriesByMessage;
    int conversationCounter = 1;
    int messageCounter = 1;

public:
    Conversation createConversation(ConversationType type, const vector<User>& users) {
        Conversation conversation;
        conversation.id = "C" + to_string(conversationCounter++);
        conversation.type = type;
        for (const User& user : users) {
            conversation.participantIds.insert(user.id);
        }
        conversations[conversation.id] = conversation;
        return conversation;
    }

    Message sendMessage(const string& conversationId, const User& sender, const string& text) {
        if (!conversations.count(conversationId)) {
            throw runtime_error("Conversation not found");
        }

        Conversation& conversation = conversations[conversationId];
        if (!conversation.participantIds.count(sender.id)) {
            throw runtime_error("Sender is not part of this conversation");
        }

        Message message{
            "M" + to_string(messageCounter++),
            conversationId,
            sender.id,
            text
        };

        messagesByConversation[conversationId].push_back(message);

        for (const string& participantId : conversation.participantIds) {
            if (participantId != sender.id) {
                deliveriesByMessage[message.id].push_back(
                    MessageDelivery{message.id, participantId, DeliveryStatus::Sent}
                );
            }
        }

        return message;
    }

    void markAsRead(const string& messageId, const string& userId) {
        for (MessageDelivery& delivery : deliveriesByMessage[messageId]) {
            if (delivery.userId == userId) {
                delivery.status = DeliveryStatus::Read;
            }
        }
    }

    vector<Message> getMessages(const string& conversationId) {
        return messagesByConversation[conversationId];
    }
};

int main() {
    User yash{"U1", "Yash"};
    User aman{"U2", "Aman"};

    ChatService service;
    Conversation conversation = service.createConversation(ConversationType::Direct, {yash, aman});
    Message message = service.sendMessage(conversation.id, yash, "Hello Aman!");
    service.markAsRead(message.id, aman.id);

    cout << "Messages in chat: " << service.getMessages(conversation.id).size() << endl;
    return 0;
}
