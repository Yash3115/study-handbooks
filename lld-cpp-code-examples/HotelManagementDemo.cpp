#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

using namespace std;

enum class RoomType { Single, Double, Suite };
enum class RoomStatus { Available, Occupied, Cleaning, Maintenance };
enum class ReservationStatus { Confirmed, CheckedIn, CheckedOut, Cancelled };

struct Room {
    string id;
    string number;
    RoomType type;
    double pricePerNight;
    RoomStatus status = RoomStatus::Available;
};

struct Guest {
    string id;
    string name;
};

struct Reservation {
    string id;
    Guest guest;
    int roomIndex;
    int checkInDay;
    int checkOutDay;
    ReservationStatus status = ReservationStatus::Confirmed;
};

class HotelService {
    vector<Room> rooms;
    vector<Reservation> reservations;
    int reservationCounter = 1;

public:
    void addRoom(const Room& room) {
        rooms.push_back(room);
    }

    Reservation bookRoom(const Guest& guest, RoomType type, int fromDay, int toDay) {
        for (int i = 0; i < static_cast<int>(rooms.size()); i++) {
            if (rooms[i].type == type && isAvailable(i, fromDay, toDay)) {
                Reservation reservation{
                    "R" + to_string(reservationCounter++),
                    guest,
                    i,
                    fromDay,
                    toDay,
                    ReservationStatus::Confirmed
                };
                reservations.push_back(reservation);
                return reservation;
            }
        }
        throw runtime_error("No room available");
    }

    void checkIn(const string& reservationId) {
        Reservation& reservation = findReservation(reservationId);
        reservation.status = ReservationStatus::CheckedIn;
        rooms[reservation.roomIndex].status = RoomStatus::Occupied;
    }

    double checkOut(const string& reservationId) {
        Reservation& reservation = findReservation(reservationId);
        int nights = reservation.checkOutDay - reservation.checkInDay;
        reservation.status = ReservationStatus::CheckedOut;
        rooms[reservation.roomIndex].status = RoomStatus::Cleaning;
        return nights * rooms[reservation.roomIndex].pricePerNight;
    }

private:
    bool isAvailable(int roomIndex, int fromDay, int toDay) const {
        for (const Reservation& reservation : reservations) {
            bool sameRoom = reservation.roomIndex == roomIndex;
            bool active = reservation.status != ReservationStatus::Cancelled;
            bool overlaps = fromDay < reservation.checkOutDay && reservation.checkInDay < toDay;
            if (sameRoom && active && overlaps) return false;
        }
        return true;
    }

    Reservation& findReservation(const string& id) {
        for (Reservation& reservation : reservations) {
            if (reservation.id == id) return reservation;
        }
        throw runtime_error("Reservation not found");
    }
};

int main() {
    HotelService service;
    service.addRoom(Room{"ROOM-1", "101", RoomType::Single, 2000});
    service.addRoom(Room{"ROOM-2", "201", RoomType::Suite, 8000});

    Guest guest{"G1", "Yash"};
    Reservation reservation = service.bookRoom(guest, RoomType::Single, 1, 3);
    service.checkIn(reservation.id);
    double bill = service.checkOut(reservation.id);

    cout << "Reservation: " << reservation.id << ", bill: " << bill << endl;
    return 0;
}
