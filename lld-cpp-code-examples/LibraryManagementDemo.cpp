#include <iostream>
#include <stdexcept>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

enum class CopyStatus { Available, Loaned, Lost };

struct Book {
    string isbn;
    string title;
    string author;
};

struct BookCopy {
    string barcode;
    Book book;
    CopyStatus status = CopyStatus::Available;
};

struct Member {
    string id;
    string name;
};

struct Loan {
    string id;
    Member member;
    string barcode;
    int issueDay;
    int dueDay;
    bool returned = false;
};

class LibraryService {
    unordered_map<string, vector<BookCopy>> copiesByIsbn;
    unordered_map<string, Loan> activeLoansByBarcode;
    int loanCounter = 1;

public:
    void addCopy(const BookCopy& copy) {
        copiesByIsbn[copy.book.isbn].push_back(copy);
    }

    Loan issueBook(const Member& member, const string& isbn, int today) {
        vector<BookCopy>& copies = copiesByIsbn[isbn];
        for (BookCopy& copy : copies) {
            if (copy.status == CopyStatus::Available) {
                copy.status = CopyStatus::Loaned;
                Loan loan{
                    "L" + to_string(loanCounter++),
                    member,
                    copy.barcode,
                    today,
                    today + 14,
                    false
                };
                activeLoansByBarcode[copy.barcode] = loan;
                return loan;
            }
        }
        throw runtime_error("No copy available");
    }

    double returnBook(const string& barcode, int today) {
        auto it = activeLoansByBarcode.find(barcode);
        if (it == activeLoansByBarcode.end()) {
            throw runtime_error("No active loan found");
        }

        Loan loan = it->second;
        int lateDays = max(0, today - loan.dueDay);

        for (auto& entry : copiesByIsbn) {
            for (BookCopy& copy : entry.second) {
                if (copy.barcode == barcode) {
                    copy.status = CopyStatus::Available;
                }
            }
        }

        activeLoansByBarcode.erase(it);
        return lateDays * 10.0;
    }
};

int main() {
    LibraryService service;
    Book book{"ISBN-1", "Clean Architecture", "Robert Martin"};
    service.addCopy(BookCopy{"COPY-1", book});

    Member member{"M1", "Yash"};
    Loan loan = service.issueBook(member, "ISBN-1", 1);
    cout << "Issued copy: " << loan.barcode << ", due day: " << loan.dueDay << endl;

    double fine = service.returnBook("COPY-1", 16);
    cout << "Returned book. Fine: " << fine << endl;
    return 0;
}
