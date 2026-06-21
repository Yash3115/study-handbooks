#include <cmath>
#include <iostream>
#include <stdexcept>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

enum class OrderStatus { Created, Paid, Accepted, Preparing, PickedUp, Delivered, Cancelled };
enum class PartnerStatus { Available, Assigned, Offline };

struct Location {
    double x;
    double y;

    double distanceTo(const Location& other) const {
        double dx = x - other.x;
        double dy = y - other.y;
        return sqrt(dx * dx + dy * dy);
    }
};

struct MenuItem {
    string id;
    string name;
    double price;
    bool available = true;
};

struct Restaurant {
    string id;
    string name;
    Location location;
    unordered_map<string, MenuItem> menu;
    bool open = true;
};

struct Customer {
    string id;
    string name;
    Location location;
};

struct DeliveryPartner {
    string id;
    string name;
    Location location;
    PartnerStatus status = PartnerStatus::Available;
};

struct OrderItem {
    MenuItem item;
    int quantity;
};

struct FoodOrder {
    string id;
    Customer customer;
    Restaurant restaurant;
    vector<OrderItem> items;
    int partnerIndex = -1;
    OrderStatus status = OrderStatus::Created;

    double total() const {
        double amount = 0;
        for (const OrderItem& item : items) {
            amount += item.item.price * item.quantity;
        }
        return amount;
    }
};

class FoodDeliveryService {
    vector<DeliveryPartner> partners;
    int orderCounter = 1;

public:
    void addPartner(const DeliveryPartner& partner) {
        partners.push_back(partner);
    }

    FoodOrder placeOrder(const Customer& customer, const Restaurant& restaurant, const vector<OrderItem>& items) {
        if (!restaurant.open) throw runtime_error("Restaurant is closed");
        for (const OrderItem& item : items) {
            if (!item.item.available) throw runtime_error("Item unavailable: " + item.item.name);
        }

        int partnerIndex = assignNearestPartner(restaurant.location);
        partners[partnerIndex].status = PartnerStatus::Assigned;

        FoodOrder order{
            "FO" + to_string(orderCounter++),
            customer,
            restaurant,
            items,
            partnerIndex,
            OrderStatus::Accepted
        };
        return order;
    }

    void markDelivered(FoodOrder& order) {
        order.status = OrderStatus::Delivered;
        partners[order.partnerIndex].status = PartnerStatus::Available;
        partners[order.partnerIndex].location = order.customer.location;
    }

    string partnerName(const FoodOrder& order) const {
        return partners[order.partnerIndex].name;
    }

private:
    int assignNearestPartner(const Location& restaurantLocation) {
        int bestIndex = -1;
        double bestDistance = 1e18;

        for (int i = 0; i < static_cast<int>(partners.size()); i++) {
            if (partners[i].status == PartnerStatus::Available) {
                double distance = partners[i].location.distanceTo(restaurantLocation);
                if (distance < bestDistance) {
                    bestIndex = i;
                    bestDistance = distance;
                }
            }
        }

        if (bestIndex == -1) throw runtime_error("No delivery partner available");
        return bestIndex;
    }
};

int main() {
    Restaurant restaurant;
    restaurant.id = "R1";
    restaurant.name = "Tasty Bites";
    restaurant.location = Location{10, 10};
    restaurant.menu["I1"] = MenuItem{"I1", "Dosa", 120, true};

    Customer customer{"C1", "Yash", Location{15, 15}};

    FoodDeliveryService service;
    service.addPartner(DeliveryPartner{"D1", "Ravi", Location{11, 11}});

    FoodOrder order = service.placeOrder(
        customer,
        restaurant,
        {OrderItem{restaurant.menu["I1"], 2}}
    );
    service.markDelivered(order);

    cout << "Food order delivered: " << order.id
         << ", partner: " << service.partnerName(order)
         << ", total: " << order.total() << endl;
    return 0;
}
