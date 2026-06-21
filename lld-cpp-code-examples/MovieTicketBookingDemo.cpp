#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

using namespace std;

enum class SeatStatus { Available, Locked, Booked };
enum class BookingStatus { Created, Confirmed, Cancelled };

struct Movie {
    string id;
    string title;
};

struct Seat {
    string id;
    string row;
    int number;
};

struct Show {
    string id;
    Movie movie;
    string startTime;
};

struct ShowSeat {
    string id;
    Show show;
    Seat seat;
    SeatStatus status = SeatStatus::Available;
    string lockedByUserId;
};

struct Booking {
    string id;
    string userId;
    Show show;
    vector<ShowSeat*> seats;
    BookingStatus status = BookingStatus::Created;
};

class BookingService {
    int bookingCounter = 1;

public:
    void lockSeats(const string& userId, const vector<ShowSeat*>& seats) {
        for (ShowSeat* seat : seats) {
            if (seat->status != SeatStatus::Available) {
                throw runtime_error("Seat not available: " + seat->seat.id);
            }
        }

        for (ShowSeat* seat : seats) {
            seat->status = SeatStatus::Locked;
            seat->lockedByUserId = userId;
        }
    }

    Booking confirmBooking(const string& userId, const Show& show, const vector<ShowSeat*>& seats) {
        for (ShowSeat* seat : seats) {
            if (seat->status != SeatStatus::Locked || seat->lockedByUserId != userId) {
                throw runtime_error("Seat is not locked by this user");
            }
        }

        for (ShowSeat* seat : seats) {
            seat->status = SeatStatus::Booked;
        }

        return Booking{
            "B" + to_string(bookingCounter++),
            userId,
            show,
            seats,
            BookingStatus::Confirmed
        };
    }
};

int main() {
    Movie movie{"M1", "Interstellar"};
    Show show{"S1", movie, "7 PM"};

    ShowSeat a1{"SS1", show, Seat{"A1", "A", 1}, SeatStatus::Available, ""};
    ShowSeat a2{"SS2", show, Seat{"A2", "A", 2}, SeatStatus::Available, ""};

    BookingService service;
    vector<ShowSeat*> selectedSeats{&a1, &a2};

    service.lockSeats("U1", selectedSeats);
    Booking booking = service.confirmBooking("U1", show, selectedSeats);

    cout << "Booking confirmed: " << booking.id << ", seats: " << booking.seats.size() << endl;
    return 0;
}
