#include <algorithm>
#include <iostream>
#include <set>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

enum class Visibility { Public, FollowersOnly, Private };

struct User {
    string id;
    string name;
};

struct Comment {
    string id;
    User author;
    string text;
};

struct Post {
    string id;
    User author;
    string content;
    Visibility visibility;
    int createdAt;
    set<string> likedByUserIds;
    vector<Comment> comments;
};

class SocialMediaService {
    unordered_map<string, User> users;
    unordered_map<string, Post> posts;
    unordered_map<string, set<string>> followingByUser;
    int postCounter = 1;
    int commentCounter = 1;
    int timeCounter = 1;

public:
    void addUser(const User& user) {
        users[user.id] = user;
    }

    void follow(const User& follower, const User& followee) {
        followingByUser[follower.id].insert(followee.id);
    }

    Post createPost(const User& author, const string& content, Visibility visibility) {
        Post post{
            "P" + to_string(postCounter++),
            author,
            content,
            visibility,
            timeCounter++,
            {},
            {}
        };
        posts[post.id] = post;
        return post;
    }

    void likePost(const User& user, const string& postId) {
        posts[postId].likedByUserIds.insert(user.id);
    }

    Comment addComment(const User& user, const string& postId, const string& text) {
        Comment comment{"C" + to_string(commentCounter++), user, text};
        posts[postId].comments.push_back(comment);
        return comment;
    }

    vector<Post> getFeed(const User& user) {
        vector<Post> feed;
        set<string> following = followingByUser[user.id];

        for (const auto& entry : posts) {
            const Post& post = entry.second;
            if (post.author.id == user.id || following.count(post.author.id)) {
                feed.push_back(post);
            }
        }

        sort(feed.begin(), feed.end(), [](const Post& a, const Post& b) {
            return a.createdAt > b.createdAt;
        });
        return feed;
    }

    const Post& getPost(const string& postId) const {
        return posts.at(postId);
    }
};

int main() {
    SocialMediaService service;
    User yash{"U1", "Yash"};
    User aman{"U2", "Aman"};

    service.addUser(yash);
    service.addUser(aman);
    service.follow(yash, aman);

    Post post = service.createPost(aman, "Learning LLD today", Visibility::Public);
    service.likePost(yash, post.id);
    service.addComment(yash, post.id, "Nice!");

    const Post& savedPost = service.getPost(post.id);
    cout << "Feed size: " << service.getFeed(yash).size() << endl;
    cout << "Likes: " << savedPost.likedByUserIds.size()
         << ", comments: " << savedPost.comments.size() << endl;
    return 0;
}
