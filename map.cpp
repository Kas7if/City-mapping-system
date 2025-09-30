#include <iostream>
#include <vector>
#include "city.hpp"

using namespace std;

const size_t MAX_CITIES = 10; // Adjust as needed

vector<City> cities;

void enter_city_info();
void calculate_distance();
void print_all_cities();
void menu();

int main() {
    menu();
    return 0;
}

void menu() {
    char choice;
    do {
        cout << "\nMenu:\n";
        cout << "1) Enter city Information\n";
        cout << "2) Calculate Distance between two cities\n";
        cout << "3) Print All cities\n";
        cout << "4) Quit\n";
        cout << "Choose an option: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case '1':
                enter_city_info();
                break;
            case '2':
                calculate_distance();
                break;
            case '3':
                print_all_cities();
                break;
            case '4':
                cout << "Quitting...\n";
                break;
            default:
                cout << "Invalid option, please try again.\n";
        }
    } while (choice != '4');
}

void enter_city_info() {
    if (cities.size() >= MAX_CITIES) {
        cout << "City list is full. Choose to overwrite an existing city.\n";
        print_all_cities();
        size_t index;
        cout << "Enter the index of the city to overwrite: ";
        cin >> index;
        cin.ignore();

        if (index < cities.size()) {
            string name;
            double x, y;
            cout << "Enter new city name: ";
            getline(cin, name);
            cout << "Enter new x coordinate: ";
            cin >> x;
            cout << "Enter new y coordinate: ";
            cin >> y;
            cin.ignore();
            cities[index].set_name(name.c_str());
            cities[index].set_location(x, y);
        } else {
            cout << "Invalid index.\n";
        }
    } else {
        string name;
        double x, y;
        cout << "Enter city name: ";
        getline(cin, name);
        cout << "Enter x coordinate: ";
        cin >> x;
        cout << "Enter y coordinate: ";
        cin >> y;
        cin.ignore();
        cities.emplace_back(name.c_str(), x, y);
    }
}

void calculate_distance() {
    if (cities.size() < 2) {
        cout << "Not enough cities to calculate distance.\n";
        return;
    }

    print_all_cities();
    size_t index1, index2;
    cout << "Enter the index of the first city: ";
    cin >> index1;
    cout << "Enter the index of the second city: ";
    cin >> index2;

    if (index1 < cities.size() && index2 < cities.size() && index1 != index2) {
        double dist = cities[index1].distance(cities[index2]);
        cout << "Distance between " << cities[index1].get_name() << " and " << cities[index2].get_name() << " is " << dist << "\n";
    } else {
        cout << "Invalid city indices.\n";
    }
}

void print_all_cities() {
    if (cities.empty()) {
        cout << "No cities to display.\n";
        return;
    }
    for (size_t i = 0; i < cities.size(); ++i) {
        cout << i << ": " << cities[i].get_name() << " at ";
        cities[i].get_location().Output();
        cout << "\n";
    }
}
