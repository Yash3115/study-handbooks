#include <iostream>
#include <stdexcept>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

enum class OrderStatus { Created, Confirmed, Cancelled };
enum class PaymentStatus { Success, Failed };

struct Product {
    string id;
    string name;
    double price;
};

class InventoryItem {
public:
    Product product;
    int available;
    int reserved = 0;

    InventoryItem() : available(0) {}
    InventoryItem(Product product, int available) : product(move(product)), available(available) {}

    void reserve(int quantity) {
        if (available < quantity) {
            throw runtime_error("Out of stock: " + product.name);
        }
        available -= quantity;
        reserved += quantity;
    }

    void confirm(int quantity) {
        reserved -= quantity;
    }

    void release(int quantity) {
        reserved -= quantity;
        available += quantity;
    }
};

struct CartItem {
    Product product;
    int quantity;
};

class Cart {
public:
    unordered_map<string, CartItem> items;

    void addProduct(const Product& product, int quantity) {
        if (items.count(product.id)) {
            items[product.id].quantity += quantity;
        } else {
            items[product.id] = CartItem{product, quantity};
        }
    }
};

struct Order {
    string id;
    vector<CartItem> items;
    double total;
    OrderStatus status;
};

class PaymentService {
public:
    PaymentStatus pay(double amount) {
        cout << "Paid amount: " << amount << endl;
        return PaymentStatus::Success;
    }
};

class CheckoutService {
    unordered_map<string, InventoryItem>& inventory;
    PaymentService& paymentService;
    int orderCounter = 1;

public:
    CheckoutService(unordered_map<string, InventoryItem>& inventory, PaymentService& paymentService)
        : inventory(inventory), paymentService(paymentService) {}

    Order checkout(const Cart& cart) {
        for (const auto& entry : cart.items) {
            inventory[entry.second.product.id].reserve(entry.second.quantity);
        }

        double total = 0;
        vector<CartItem> orderItems;
        for (const auto& entry : cart.items) {
            total += entry.second.product.price * entry.second.quantity;
            orderItems.push_back(entry.second);
        }

        if (paymentService.pay(total) == PaymentStatus::Failed) {
            for (const CartItem& item : orderItems) {
                inventory[item.product.id].release(item.quantity);
            }
            throw runtime_error("Payment failed");
        }

        for (const CartItem& item : orderItems) {
            inventory[item.product.id].confirm(item.quantity);
        }

        return Order{
            "O" + to_string(orderCounter++),
            orderItems,
            total,
            OrderStatus::Confirmed
        };
    }
};

int main() {
    Product laptop{"P1", "Laptop", 60000};
    unordered_map<string, InventoryItem> inventory;
    inventory[laptop.id] = InventoryItem(laptop, 3);

    Cart cart;
    cart.addProduct(laptop, 1);

    PaymentService paymentService;
    CheckoutService checkoutService(inventory, paymentService);
    Order order = checkoutService.checkout(cart);

    cout << "Order confirmed: " << order.id << ", total: " << order.total << endl;
    return 0;
}
