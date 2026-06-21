#include <iostream>
#include <stdexcept>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

enum class VehicleType { Bike, Car, Truck };
enum class SpotType { Bike, Compact, Large };
enum class TicketStatus { Active, Paid };

struct Vehicle {
    string number;
    VehicleType type;
};

class ParkingSpot {
public:
    string id;
    SpotType type;
    bool occupied = false;
    string parkedVehicleNumber;

    ParkingSpot(string id, SpotType type) : id(move(id)), type(type) {}

    bool canFit(const Vehicle& vehicle) const {
        if (occupied) return false;
        if (vehicle.type == VehicleType::Bike) return true;
        if (vehicle.type == VehicleType::Car) {
            return type == SpotType::Compact || type == SpotType::Large;
        }
        return type == SpotType::Large;
    }

    void park(const Vehicle& vehicle) {
        occupied = true;
        parkedVehicleNumber = vehicle.number;
    }

    void freeSpot() {
        occupied = false;
        parkedVehicleNumber.clear();
    }
};

struct ParkingTicket {
    string id;
    Vehicle vehicle;
    int spotIndex;
    int entryHour;
    TicketStatus status = TicketStatus::Active;
};

class ParkingLotService {
    vector<ParkingSpot> spots;
    unordered_map<string, ParkingTicket> activeTickets;
    int ticketCounter = 1;

public:
    void addSpot(const ParkingSpot& spot) {
        spots.push_back(spot);
    }

    ParkingTicket parkVehicle(const Vehicle& vehicle, int currentHour) {
        for (int i = 0; i < static_cast<int>(spots.size()); i++) {
            if (spots[i].canFit(vehicle)) {
                spots[i].park(vehicle);
                ParkingTicket ticket{
                    "T" + to_string(ticketCounter++),
                    vehicle,
                    i,
                    currentHour,
                    TicketStatus::Active
                };
                activeTickets[ticket.id] = ticket;
                return ticket;
            }
        }
        throw runtime_error("No compatible parking spot available");
    }

    double unparkVehicle(const string& ticketId, int exitHour) {
        auto it = activeTickets.find(ticketId);
        if (it == activeTickets.end()) {
            throw runtime_error("Invalid ticket");
        }

        ParkingTicket ticket = it->second;
        int hours = max(1, exitHour - ticket.entryHour);
        double fee = hours * 20.0;

        spots[ticket.spotIndex].freeSpot();
        activeTickets.erase(it);
        return fee;
    }

    string spotIdForTicket(const ParkingTicket& ticket) const {
        return spots[ticket.spotIndex].id;
    }
};

int main() {
    ParkingLotService service;
    service.addSpot(ParkingSpot("B1", SpotType::Bike));
    service.addSpot(ParkingSpot("C1", SpotType::Compact));
    service.addSpot(ParkingSpot("L1", SpotType::Large));

    Vehicle car{"DL-01-1234", VehicleType::Car};
    ParkingTicket ticket = service.parkVehicle(car, 10);

    cout << "Parked vehicle at spot: " << service.spotIdForTicket(ticket) << endl;
    cout << "Exit fee: " << service.unparkVehicle(ticket.id, 12) << endl;
    return 0;
}
