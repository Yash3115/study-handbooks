#include <cmath>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

using namespace std;

enum class DriverStatus { Offline, Available, OnRide };
enum class RideStatus { Requested, DriverAssigned, Started, Completed, Cancelled };

struct Location {
    double latitude;
    double longitude;

    double distanceTo(const Location& other) const {
        double latDiff = latitude - other.latitude;
        double lonDiff = longitude - other.longitude;
        return sqrt(latDiff * latDiff + lonDiff * lonDiff);
    }
};

struct Rider {
    string id;
    string name;
};

struct Driver {
    string id;
    string name;
    Location location;
    DriverStatus status = DriverStatus::Available;
};

struct Ride {
    string id;
    Rider rider;
    int driverIndex;
    Location pickup;
    Location destination;
    RideStatus status = RideStatus::Requested;
    double fare = 0;
};

class RideService {
    vector<Driver> drivers;
    int rideCounter = 1;

public:
    void addDriver(const Driver& driver) {
        drivers.push_back(driver);
    }

    Ride requestRide(const Rider& rider, const Location& pickup, const Location& destination) {
        int driverIndex = findNearestAvailableDriver(pickup);
        drivers[driverIndex].status = DriverStatus::OnRide;

        Ride ride{
            "R" + to_string(rideCounter++),
            rider,
            driverIndex,
            pickup,
            destination,
            RideStatus::DriverAssigned,
            pickup.distanceTo(destination) * 100
        };
        return ride;
    }

    void startRide(Ride& ride) {
        ride.status = RideStatus::Started;
    }

    void completeRide(Ride& ride) {
        ride.status = RideStatus::Completed;
        drivers[ride.driverIndex].status = DriverStatus::Available;
        drivers[ride.driverIndex].location = ride.destination;
    }

    string driverName(const Ride& ride) const {
        return drivers[ride.driverIndex].name;
    }

private:
    int findNearestAvailableDriver(const Location& pickup) {
        int bestIndex = -1;
        double bestDistance = 1e18;

        for (int i = 0; i < static_cast<int>(drivers.size()); i++) {
            if (drivers[i].status == DriverStatus::Available) {
                double distance = drivers[i].location.distanceTo(pickup);
                if (distance < bestDistance) {
                    bestIndex = i;
                    bestDistance = distance;
                }
            }
        }

        if (bestIndex == -1) throw runtime_error("No driver available");
        return bestIndex;
    }
};

int main() {
    RideService service;
    service.addDriver(Driver{"D1", "Amit", Location{10, 10}});
    service.addDriver(Driver{"D2", "Neha", Location{20, 20}});

    Rider rider{"R1", "Yash"};
    Ride ride = service.requestRide(rider, Location{11, 11}, Location{15, 15});
    service.startRide(ride);
    service.completeRide(ride);

    cout << "Ride completed with driver: " << service.driverName(ride)
         << ", fare: " << ride.fare << endl;
    return 0;
}
