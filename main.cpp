#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Room {
    string type;
    double area = 0;
};

struct Floor {
    double height;
    double area = 0;
    vector<Room> rooms;
};

struct Building {
    string type;
    double area = 0;
    bool furnace = false;
    vector<Floor> floors;
};


struct Plot {
    int id = 0;
    double area = 0;
    vector<Building> buildings;
};

int main() {
    int quantity_plots;
    cout << "Enter the total number of plots: ";
    cin >> quantity_plots;
    vector<Plot> plots(quantity_plots);
    for (auto &plot: plots) {
        cout << "Enter plot number: ";
        cin >> plot.id;
        cout << "Enter the area of the plot: ";
        cin >> plot.area;
        int quantity_buildings;
        cout << "Enter the number of buildings on the plot: ";
        cin >> quantity_buildings;
        plot.buildings.resize(quantity_buildings);
        for (auto &building: plot.buildings) {
            cout << "Enter the area of the building: ";
            cin >> building.area;
            cout << "Enter the building type: ";
            cin >> building.type;
            if (building.type == "house") {
                int quantity_floors;
                //так как по условию количество этажей от 1 до 3
                while (true) {
                    cout << "Enter the number of floors in the house: ";
                    cin >> quantity_floors;
                    if (quantity_floors >= 1 && quantity_floors <= 3)break;
                    else cout << "Error of input" << endl;
                }
                building.floors.resize(quantity_floors);
                for (auto &floor: building.floors) {
                    cout << "Enter the area of the floor: ";
                    cin >> floor.area;
                    cout << "Enter height of floor: ";
                    cin >> floor.height;
                    int quantity_rooms;
                    //так как по условию количество комнат от 2 до 4
                    while (true) {
                        cout << "Enter the number of rooms: ";
                        cin >> quantity_rooms;
                        if (quantity_rooms >= 2 && quantity_rooms <= 4)break;
                        else cout << "Error of input" << endl;
                    }
                    floor.rooms.resize(quantity_rooms);
                    for (auto &room: floor.rooms) {
                        cout << "Enter the area of the room: ";
                        cin >> room.area;
                        cout << "Enter the room type: ";
                        cin >> room.type;
                    }
                }
            } else {
                building.floors.resize(1);
                building.floors[0].area = building.area;
                cout << "Enter the height of the building's ceiling: ";
                cin >> building.floors[0].height;
            }
            if (building.type == "house" || building.type == "bathhouse") {
                string is_furnace;
                cout << "Is there a furnace (yes/no): ";
                cin >> is_furnace;
                if (is_furnace == "yes")building.furnace = true;
            }
        }
    }
    double area_total = 0;
    double area_buildings = 0;
    for (const auto &plot: plots) {
        area_total += plot.area;
        for (const auto &building: plot.buildings) {
            area_buildings += building.area;
        }
    }
    cout << "Percentage of land occupied by buildings: " << 100.0 * area_buildings / area_total << '%';
    return 0;
}
