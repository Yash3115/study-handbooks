#include <iostream>
#include <stdexcept>
#include <string>
#include <unordered_map>

using namespace std;

enum class CartStatus { Active, CheckedOut };
enum class CouponType { Percentage, FixedAmount };

struct Product {
    string id;
    string name;
    double price;
};

struct CartItem {
    Product product;
    int quantity;

    double total() const {
        return product.price * quantity;
    }
};

struct Coupon {
    string code;
    CouponType type;
    double value;

    double discount(double subtotal) const {
        if (type == CouponType::Percentage) {
            return subtotal * value / 100.0;
        }
        return value;
    }
};

class Cart {
public:
    string userId;
    unordered_map<string, CartItem> itemsByProductId;
    bool hasCoupon = false;
    Coupon coupon;
    CartStatus status = CartStatus::Active;

    explicit Cart(string userId = "") : userId(move(userId)) {}

    void addItem(const Product& product, int quantity) {
        if (quantity <= 0) throw runtime_error("Quantity must be positive");
        if (itemsByProductId.count(product.id)) {
            itemsByProductId[product.id].quantity += quantity;
        } else {
            itemsByProductId[product.id] = CartItem{product, quantity};
        }
    }

    void updateQuantity(const string& productId, int quantity) {
        if (quantity <= 0) {
            itemsByProductId.erase(productId);
            return;
        }
        if (!itemsByProductId.count(productId)) {
            throw runtime_error("Product is not in cart");
        }
        itemsByProductId[productId].quantity = quantity;
    }

    void removeItem(const string& productId) {
        itemsByProductId.erase(productId);
    }

    double subtotal() const {
        double amount = 0;
        for (const auto& entry : itemsByProductId) {
            amount += entry.second.total();
        }
        return amount;
    }

    double total() const {
        double amount = subtotal();
        double discount = hasCoupon ? coupon.discount(amount) : 0;
        return max(0.0, amount - discount);
    }
};

class CartService {
    unordered_map<string, Cart> cartsByUserId;

public:
    Cart& getCart(const string& userId) {
        if (!cartsByUserId.count(userId)) {
            cartsByUserId[userId] = Cart(userId);
        }
        return cartsByUserId[userId];
    }

    void checkout(const string& userId) {
        Cart& cart = getCart(userId);
        if (cart.itemsByProductId.empty()) {
            throw runtime_error("Cart is empty");
        }
        cart.status = CartStatus::CheckedOut;
    }
};

int main() {
    Product keyboard{"P1", "Keyboard", 1500};
    Product mouse{"P2", "Mouse", 700};

    CartService service;
    Cart& cart = service.getCart("U1");
    cart.addItem(keyboard, 1);
    cart.addItem(mouse, 2);
    cart.hasCoupon = true;
    cart.coupon = Coupon{"SAVE10", CouponType::Percentage, 10};

    cout << "Cart subtotal: " << cart.subtotal() << endl;
    cout << "Cart total after discount: " << cart.total() << endl;

    service.checkout("U1");
    cout << "Cart status: CHECKED_OUT" << endl;
    return 0;
}
