#include <iostream>
using namespace std;

class Car {
private:
    int id;
    string name;
    float rent;
    int status; // 0 = Available, 1 = Rented

public:
    void addCar() {
        cout << "\nEnter Car ID: ";
        cin >> id;

        cout << "Enter Car Name: ";
        cin >> name;

        cout << "Enter Rent per Day: ";
        cin >> rent;

        status = 0;
        cout << "\nCar Added Successfully!\n";
    }

    void showCar() {
        cout << "\nID: " << id;
        cout << "\nName: " << name;
        cout << "\nRent per Day: " << rent;

        if(status == 0)
            cout << "\nStatus: Available\n";
        else
            cout << "\nStatus: Rented\n";
    }

    int getId() {
        return id;
    }

    int getStatus() {
        return status;
    }

    void rentCar() {
        int days;
        cout << "Enter number of days: ";
        cin >> days;

        float total = days * rent;
        status = 1;

        cout << "\nCar Rented Successfully!\n";
        cout << "Total Rent = " << total << endl;
    }

    void returnCar() {
        status = 0;
        cout << "\nCar Returned Successfully!\n";
    }
};

int main() {
    Car c[100];
    int count = 0;
    int choice;

    while(1) {
        cout << "\n===== Car Rental System =====\n";
        cout << "1. Add Car\n";
        cout << "2. View Cars\n";
        cout << "3. Rent Car\n";
        cout << "4. Return Car\n";
        cout << "5. Exit\n";

        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice) {
            case 1:
                c[count].addCar();
                count++;
                break;

            case 2:
                if(count == 0) {
                    cout << "\nNo Cars Available!\n";
                } else {
                    for(int i = 0; i < count; i++) {
                        c[i].showCar();
                    }
                }
                break;

            case 3: {
                int id, found = 0;
                cout << "Enter Car ID: ";
                cin >> id;

                for(int i = 0; i < count; i++) {
                    if(c[i].getId() == id) {
                        found = 1;

                        if(c[i].getStatus() == 1) {
                            cout << "\nCar already rented!\n";
                        } else {
                            c[i].rentCar();
                        }
                    }
                }

                if(!found)
                    cout << "\nCar Not Found!\n";

                break;
            }

            case 4: {
                int id, found = 0;
                cout << "Enter Car ID: ";
                cin >> id;

                for(int i = 0; i < count; i++) {
                    if(c[i].getId() == id) {
                        found = 1;

                        if(c[i].getStatus() == 0) {
                            cout << "\nCar already available!\n";
                        } else {
                            c[i].returnCar();
                        }
                    }
                }

                if(!found)
                    cout << "\nCar Not Found!\n";

                break;
            }

            case 5:
                cout << "\nExiting...\n";
                return 0;

            default:
                cout << "\nInvalid Choice!\n";
        }
    }
}
