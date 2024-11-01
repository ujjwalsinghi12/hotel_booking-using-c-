#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Room {
public:
    int roomNumber;
    string type;
    bool isBooked;

    Room(int roomNumber, string type) {
        this->roomNumber = roomNumber;
        this->type = type;
        this->isBooked = false;
    }
};

class Hotel {
private:
    vector<Room> rooms;

public:
    Hotel() {
        rooms.push_back(Room(101, "Single"));
        rooms.push_back(Room(102, "Double"));
        rooms.push_back(Room(103, "Suite"));
        rooms.push_back(Room(104, "Deluxe"));
    }

    void viewAvailableRooms() {
        cout << "Available Rooms:\n";
        for (Room &room : rooms) {
            if (!room.isBooked) {
                cout << "Room Number: " << room.roomNumber << ", Type: " << room.type << "\n";
            }
        }
    }

    void bookRoom(int roomNumber) {
        for (Room &room : rooms) {
            if (room.roomNumber == roomNumber) {
                if (!room.isBooked) {
                    room.isBooked = true;
                    cout << "Room " << roomNumber << " has been successfully booked.\n";
                } else {
                    cout << "Room " << roomNumber << " is already booked.\n";
                }
                return;
            }
        }
        cout << "Room not found.\n";
    }

    void cancelBooking(int roomNumber) {
        for (Room &room : rooms) {
            if (room.roomNumber == roomNumber) {
                if (room.isBooked) {
                    room.isBooked = false;
                    cout << "Room " << roomNumber << " booking has been successfully cancelled.\n";
                } else {
                    cout << "Room " << roomNumber << " is not booked.\n";
                }
                return;
            }
        }
        cout << "Room not found.\n";
    }
};

int main() {
    Hotel hotel;
    int choice, roomNumber;

    while (true) {
        cout << "\nHotel Booking System\n";
        cout << "1. View Available Rooms\n";
        cout << "2. Book Room\n";
        cout << "3. Cancel Booking\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                hotel.viewAvailableRooms();
                break;
            case 2:
                cout << "Enter room number to book: ";
                cin >> roomNumber;
                hotel.bookRoom(roomNumber);
                break;
            case 3:
                cout << "Enter room number to cancel booking: ";
                cin >> roomNumber;
                hotel.cancelBooking(roomNumber);
                break;
            case 4:
                return 0;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}
