#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

using namespace std;

enum class SeatClass { Economy, Business };
enum class FlightSeatStatus { Available, Held, Booked };
enum class BookingStatus { Created, Confirmed, Cancelled };

struct Airport {
    string code;
    string city;
};

struct Flight {
    string number;
    Airport source;
    Airport destination;
};

struct Seat {
    string number;
    SeatClass seatClass;
};

struct FlightSchedule {
    string id;
    Flight flight;
    string departureTime;
};

struct FlightSeat {
    FlightSchedule schedule;
    Seat seat;
    FlightSeatStatus status = FlightSeatStatus::Available;
};

struct Passenger {
    string name;
    string documentNumber;
};

struct Ticket {
    Passenger passenger;
    FlightSeat* seat;
};

struct Booking {
    string id;
    vector<Ticket> tickets;
    BookingStatus status = BookingStatus::Created;
};

class AirlineBookingService {
    int bookingCounter = 1;

public:
    void holdSeats(const vector<FlightSeat*>& seats) {
        for (FlightSeat* seat : seats) {
            if (seat->status != FlightSeatStatus::Available) {
                throw runtime_error("Seat not available: " + seat->seat.number);
            }
        }

        for (FlightSeat* seat : seats) {
            seat->status = FlightSeatStatus::Held;
        }
    }

    Booking confirmBooking(const vector<Passenger>& passengers, const vector<FlightSeat*>& seats) {
        if (passengers.size() != seats.size()) {
            throw runtime_error("Each passenger needs one seat");
        }

        vector<Ticket> tickets;
        for (int i = 0; i < static_cast<int>(seats.size()); i++) {
            if (seats[i]->status != FlightSeatStatus::Held) {
                throw runtime_error("Seat not held: " + seats[i]->seat.number);
            }
            seats[i]->status = FlightSeatStatus::Booked;
            tickets.push_back(Ticket{passengers[i], seats[i]});
        }

        return Booking{
            "B" + to_string(bookingCounter++),
            tickets,
            BookingStatus::Confirmed
        };
    }
};

int main() {
    Airport delhi{"DEL", "Delhi"};
    Airport mumbai{"BOM", "Mumbai"};
    Flight flight{"AI-202", delhi, mumbai};
    FlightSchedule schedule{"FS1", flight, "Tomorrow 10 AM"};

    FlightSeat seat{schedule, Seat{"12A", SeatClass::Economy}};
    Passenger passenger{"Yash", "PASS123"};

    AirlineBookingService service;
    service.holdSeats({&seat});
    Booking booking = service.confirmBooking({passenger}, {&seat});

    cout << "Airline booking confirmed: " << booking.id
         << ", seat: " << booking.tickets.front().seat->seat.number << endl;
    return 0;
}
