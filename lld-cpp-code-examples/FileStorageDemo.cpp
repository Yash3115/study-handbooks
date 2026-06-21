#include <iostream>
#include <stdexcept>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

enum class PermissionType { View, Edit, Owner };

struct User {
    string id;
    string name;
};

struct FileVersion {
    int versionNumber;
    string storageKey;
    string content;
};

class DriveFile {
public:
    string id;
    string name;
    User owner;
    vector<FileVersion> versions;
    unordered_map<string, PermissionType> permissionsByUserId;

    DriveFile() = default;

    DriveFile(string id, string name, User owner)
        : id(move(id)), name(move(name)), owner(move(owner)) {
        permissionsByUserId[this->owner.id] = PermissionType::Owner;
    }

    const FileVersion& latestVersion() const {
        return versions.back();
    }
};

class FileStorageService {
    unordered_map<string, DriveFile> files;
    int fileCounter = 1;

public:
    DriveFile upload(const User& owner, const string& fileName, const string& content) {
        DriveFile file("F" + to_string(fileCounter++), fileName, owner);
        addVersion(file, content);
        files[file.id] = file;
        return file;
    }

    void addVersion(DriveFile& file, const string& content) {
        int versionNumber = static_cast<int>(file.versions.size()) + 1;
        string storageKey = file.id + "/v" + to_string(versionNumber);
        file.versions.push_back(FileVersion{versionNumber, storageKey, content});
    }

    void share(const User& owner, const string& fileId, const User& target, PermissionType permission) {
        DriveFile& file = getFile(fileId);
        if (file.owner.id != owner.id) {
            throw runtime_error("Only owner can share this file");
        }
        file.permissionsByUserId[target.id] = permission;
    }

    string download(const User& user, const string& fileId) {
        DriveFile& file = getFile(fileId);
        if (!file.permissionsByUserId.count(user.id)) {
            throw runtime_error("User does not have permission");
        }
        return file.latestVersion().content;
    }

private:
    DriveFile& getFile(const string& fileId) {
        if (!files.count(fileId)) throw runtime_error("File not found");
        return files[fileId];
    }
};

int main() {
    FileStorageService service;
    User owner{"U1", "Yash"};
    User friendUser{"U2", "Aman"};

    DriveFile file = service.upload(owner, "notes.txt", "LLD notes");
    service.share(owner, file.id, friendUser, PermissionType::View);

    cout << "Downloaded content: " << service.download(friendUser, file.id) << endl;
    return 0;
}
