#include <iostream>
#include <fstream>
using namespace std;

struct MechanicalComponent {
    int componentID;       
    string componentName; 
    double mass;           
    double volume;         
    string material;       
    double maxStress;      
    double tolerance;      
};
void inputComponentDetails(MechanicalComponent &component);
void saveComponentToFile(const MechanicalComponent &component);
void printComponentsFromFile();
int main() {
    // MechanicalComponent component;
    // inputComponentDetails(component);
    printComponentsFromFile();
    return 0;
}

void inputComponentDetails(MechanicalComponent &component) {
    cout << "Enter Component ID: ";
    cin >> component.componentID;

    cout << "Enter Component Name: ";
    cin.ignore();  
    getline(cin, component.componentName);

    cout << "Enter Mass (kg): ";
    cin >> component.mass;

    cout << "Enter Volume (m^3): ";
    cin >> component.volume;

    cout << "Enter Material: ";
    cin.ignore();  
    getline(cin, component.material);

    cout << "Enter Max Stress (Pa): ";
    cin >> component.maxStress;

    cout << "Enter Tolerance (mm): ";
    cin >> component.tolerance;
    saveComponentToFile(component);
}

void saveComponentToFile(const MechanicalComponent &component) {
    ofstream outFile("mechanicalcomponent.txt",ios::app);

    if (outFile.is_open()) {
        outFile << "Component ID: " << component.componentID << endl;
        outFile << "Component Name: " << component.componentName << endl;
        outFile << "Mass: " << component.mass << " kg" << endl;
        outFile << "Volume: " << component.volume << " m^3" << endl;
        outFile << "Material: " << component.material << endl;
        outFile << "Max Stress: " << component.maxStress << " Pa" << endl;
        outFile << "Tolerance: " << component.tolerance << " mm" << endl;

        outFile.close();
        cout << "Component details saved to mechanicalcomponent.txt" << endl;
    } else {
        cout << "Unable to open file for writing." << endl;
    }
}

void printComponentsFromFile() {
    ifstream inFile("mechanicalcomponent.txt");
    if (inFile.is_open()) {
        string line;
        while (getline(inFile, line)) {
            if (line.find(": ") != string::npos) {
                // Reading the component ID
                int componentID = stoi(line.substr(line.find(": ") + 2));
                cout << "Component ID: " << componentID << endl;
            }

            if (getline(inFile, line) && line.find(": ") != string::npos) {
                // Reading the component name
                string componentName = line.substr(line.find(": ") + 2);
                cout << "Component Name: " << componentName << endl;
            }

            if (getline(inFile, line) && line.find(": ") != string::npos) {
                // Reading the mass
                double mass = stod(line.substr(line.find(": ") + 2));
                cout << "Mass: " << mass << " kg" << endl;
            }

            if (getline(inFile, line) && line.find(": ") != string::npos) {
                // Reading the volume
                double volume = stod(line.substr(line.find(": ") + 2));
                cout << "Volume: " << volume << " m^3" << endl;
            }

            if (getline(inFile, line) && line.find(": ") != string::npos) {
                // Reading the material
                string material = line.substr(line.find(": ") + 2);
                cout << "Material: " << material << endl;
            }

            if (getline(inFile, line) && line.find(": ") != string::npos) {
                // Reading the max stress
                double maxStress = stod(line.substr(line.find(": ") + 2));
                cout << "Max Stress: " << maxStress << " Pa" << endl;
            }

            if (getline(inFile, line) && line.find(": ") != string::npos) {
                // Reading the tolerance
                double tolerance = stod(line.substr(line.find(": ") + 2));
                cout << "Tolerance: " << tolerance << " mm" << endl;
            }

            cout << endl;  // Print a newline to separate components

            // Skip the empty line between components (if present)
            getline(inFile, line);
        }

        inFile.close();
    } else {
        cout << "Unable to open file for reading." << endl;
    }
}