#include <iostream>
#include <stdexcept>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

enum class OrderStatus { Created, Confirmed, Cancelled };

struct Book {
    string id;
    string title;
    string author;
    string category;
    double price;
};

class InventoryItem {
public:
    Book book;
    int stock;

    InventoryItem() : stock(0) {}
    InventoryItem(Book book, int stock) : book(move(book)), stock(stock) {}

    bool hasStock(int quantity) const {
        return stock >= quantity;
    }

    void reduceStock(int quantity) {
        if (!hasStock(quantity)) {
            throw runtime_error("Not enough stock for " + book.title);
        }
        stock -= quantity;
    }
};

struct CartItem {
    Book book;
    int quantity;
};

class Cart {
public:
    unordered_map<string, CartItem> items;

    void addBook(const Book& book, int quantity) {
        if (items.count(book.id)) {
            items[book.id].quantity += quantity;
        } else {
            items[book.id] = CartItem{book, quantity};
        }
    }

    double total() const {
        double amount = 0;
        for (const auto& entry : items) {
            amount += entry.second.book.price * entry.second.quantity;
        }
        return amount;
    }
};

struct Order {
    string id;
    vector<CartItem> items;
    double amount;
    OrderStatus status;
};

class BookstoreService {
    unordered_map<string, Book> books;
    unordered_map<string, InventoryItem> inventory;
    int orderCounter = 1;

public:
    void addBook(const Book& book, int stock) {
        books[book.id] = book;
        inventory[book.id] = InventoryItem(book, stock);
    }

    vector<Book> searchByTitle(const string& keyword) const {
        vector<Book> result;
        for (const auto& entry : books) {
            if (entry.second.title.find(keyword) != string::npos) {
                result.push_back(entry.second);
            }
        }
        return result;
    }

    Order checkout(const Cart& cart) {
        for (const auto& entry : cart.items) {
            const CartItem& item = entry.second;
            if (!inventory.count(item.book.id) || !inventory[item.book.id].hasStock(item.quantity)) {
                throw runtime_error("Book unavailable: " + item.book.title);
            }
        }

        vector<CartItem> orderItems;
        for (const auto& entry : cart.items) {
            const CartItem& item = entry.second;
            inventory[item.book.id].reduceStock(item.quantity);
            orderItems.push_back(item);
        }

        return Order{
            "O" + to_string(orderCounter++),
            orderItems,
            cart.total(),
            OrderStatus::Confirmed
        };
    }
};

int main() {
    BookstoreService service;
    Book cleanCode{"B1", "Clean Code", "Robert Martin", "Programming", 499};
    Book design{"B2", "System Design Basics", "Alex Xu", "Technology", 699};

    service.addBook(cleanCode, 5);
    service.addBook(design, 2);

    vector<Book> results = service.searchByTitle("Code");
    cout << "Search result: " << results.front().title << endl;

    Cart cart;
    cart.addBook(cleanCode, 2);
    Order order = service.checkout(cart);

    cout << "Order confirmed: " << order.id << ", amount: " << order.amount << endl;
    return 0;
}
