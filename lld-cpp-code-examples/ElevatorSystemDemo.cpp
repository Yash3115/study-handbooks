#include <cmath>
#include <iostream>
#include <set>
#include <string>
#include <vector>

using namespace std;

enum class Direction { Up, Down, Idle };
enum class ElevatorState { Idle, Moving, DoorOpen };

struct ElevatorRequest {
    int sourceFloor;
    int destinationFloor;

    Direction direction() const {
        return destinationFloor > sourceFloor ? Direction::Up : Direction::Down;
    }
};

class ElevatorCar {
public:
    string id;
    int currentFloor;
    Direction direction = Direction::Idle;
    ElevatorState state = ElevatorState::Idle;
    set<int> destinations;

    ElevatorCar(string id, int currentFloor) : id(move(id)), currentFloor(currentFloor) {}

    void addDestination(int floor) {
        destinations.insert(floor);
    }

    void moveOneStep() {
        if (destinations.empty()) {
            direction = Direction::Idle;
            state = ElevatorState::Idle;
            return;
        }

        int target = *destinations.begin();
        direction = target > currentFloor ? Direction::Up : Direction::Down;
        state = ElevatorState::Moving;

        if (currentFloor < target) currentFloor++;
        else if (currentFloor > target) currentFloor--;

        if (currentFloor == target) {
            destinations.erase(target);
            openAndCloseDoor();
        }
    }

private:
    void openAndCloseDoor() {
        state = ElevatorState::DoorOpen;
        cout << id << " stopped at floor " << currentFloor << endl;
        state = ElevatorState::Idle;
    }
};

class NearestElevatorStrategy {
public:
    ElevatorCar* selectElevator(vector<ElevatorCar>& elevators, const ElevatorRequest& request) {
        ElevatorCar* best = &elevators[0];
        int bestDistance = abs(best->currentFloor - request.sourceFloor);

        for (ElevatorCar& elevator : elevators) {
            int distance = abs(elevator.currentFloor - request.sourceFloor);
            if (distance < bestDistance) {
                best = &elevator;
                bestDistance = distance;
            }
        }
        return best;
    }
};

class ElevatorController {
    vector<ElevatorCar>& elevators;
    NearestElevatorStrategy strategy;

public:
    ElevatorController(vector<ElevatorCar>& elevators) : elevators(elevators) {}

    ElevatorCar* requestElevator(const ElevatorRequest& request) {
        ElevatorCar* elevator = strategy.selectElevator(elevators, request);
        elevator->addDestination(request.sourceFloor);
        elevator->addDestination(request.destinationFloor);
        return elevator;
    }
};

int main() {
    vector<ElevatorCar> elevators;
    elevators.emplace_back("E1", 0);
    elevators.emplace_back("E2", 8);

    ElevatorController controller(elevators);
    ElevatorCar* assigned = controller.requestElevator(ElevatorRequest{3, 7});

    cout << "Assigned elevator: " << assigned->id << endl;
    while (!assigned->destinations.empty()) {
        assigned->moveOneStep();
    }
    return 0;
}
