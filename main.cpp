#include <iostream>
#include <string>
#include <limits>
#include "ArrayQueue.hpp"

using namespace std;

void displayMenu() {
    cout << "\n--- ArrayQueue Test Menu ---" << endl;
    cout << "1. Enqueue (Add)" << endl;
    cout << "2. Dequeue (Remove)" << endl;
    cout << "3. View Front" << endl;
    cout << "4. View Back" << endl;
    cout << "5. Check Size/Full/Empty" << endl;
    cout << "6. Clear Queue" << endl;
    cout << "7. Create Backup/Copy" << endl;
    cout << "8. View Backup Queue Stats" << endl;
    cout << "0. Exit" << endl;
    cout << "Choice: ";
}

int main() {
    int size = 0;

    while (true) {
        cout << "Enter max size for the queue (positive integer): ";

        // Check if the input is a valid integer
        if (cin >> size && size > 0) {
            // Success! We have a valid positive integer.
            break; 
        } else {
            // If we are here, input was either not an int (like 'abc') or <= 0
            cout << "Invalid input. Please enter a positive whole number." << endl;

            cin.clear(); // Clear the error flag
            // Discard everything in the buffer until the next newline
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }

    cout << "Queue size set to: " << size << endl;
    ArrayQueue<int> backupQueue(size);
    ArrayQueue<int> myQueue(size);
    int choice, value;

    do {
        displayMenu();

        if (!(cin >> choice)) {
        cout << "Invalid input. Please enter a number." << endl;
        cin.clear();                // 1. Reset the error flags
        cin.ignore(10000, '\n');    // 2. Discard the "junk" in the buffer
        continue;                   // 3. Restart the loop
        }
        try {
            switch (choice) {
                case 1:
                    cout << "Enter integer to enqueue: ";
                    while (!(cin >> value)) {
                        cout << "That's not an integer. Try again: ";
                        cin.clear();
                        cin.ignore(10000, '\n');
                    }
                    myQueue.enqueue(value);
                    cout << "Enqueued " << value << endl;
                    break;

                case 2:
                    // Note: Your dequeue is void, so we peek front first if we want to see it
                    cout << "Dequeuing front element..." << endl;
                    myQueue.dequeue(); 
                    break;

                case 3:
                    cout << "Front element: " << myQueue.front() << endl;
                    break;

                case 4:
                    cout << "Back element: " << myQueue.back() << endl;
                    break;

                case 5:
                    cout << "Current Length: " << myQueue.getLength() << endl;
                    cout << "Max Size: " << myQueue.getMaxSize() << endl;
                    cout << "Is Empty: " << (myQueue.isEmpty() ? "Yes" : "No") << endl;
                    cout << "Is Full: " << (myQueue.isFull() ? "Yes" : "No") << endl;
                    break;

                case 6:
                    myQueue.clear();
                    cout << "Queue cleared." << endl;
                    break;

                case 7:
                    cout << "Backing up / Copying (backupQueue = myQueue)..." << endl;
                    backupQueue = myQueue; // This calls operator= and copy()
                    cout << "Backup created successfully!" << endl;
                    break;

                case 8:
                    cout << "--- Backup Queue Stats ---" << endl;
                    cout << "Size: " << backupQueue.getLength() << endl;
                    if (!backupQueue.isEmpty()) {
                        cout << "Front: " << backupQueue.front() << endl;
                        cout << "Back: " << backupQueue.back() << endl;
                    } else {
                        cout << "Backup is currently empty." << endl;
                    }
                    break;

                case 0:
                    cout << "Exiting..." << endl;
                    break;

                default:
                    cout << "Invalid choice." << endl;
            }
        } catch (string e) {
            cout << "EXCEPTION: " << e << endl;
        }

    } while (choice != 0);

    return 0;
}