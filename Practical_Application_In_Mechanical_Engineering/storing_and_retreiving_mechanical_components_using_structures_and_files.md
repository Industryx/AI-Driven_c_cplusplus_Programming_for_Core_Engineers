### Storing and retreiving mechanical components using structures and files

This program demonstrates how to use structures to store mechanical component details, input these details from the user, save them to a file, and then read and print these details from the file. The program uses basic file handling operations in C++: reading from and writing to text files using the `<fstream>` library.

#### Key Components of the Program

1. **Structure Definition (`MechanicalComponent`)**: 
   A structure named `MechanicalComponent` is defined to represent a mechanical component. It contains the following fields:

   ```cpp
   struct MechanicalComponent {
       int componentID;       // Unique ID of the component
       string componentName;  // Name of the component
       double mass;           // Mass of the component in kg
       double volume;         // Volume of the component in m^3
       string material;       // Material of the component
       double maxStress;      // Maximum stress the component can handle in Pascals
       double tolerance;      // Tolerance of the component in mm
   };
   ```

2. **Function to Input Component Details (`inputComponentDetails`)**:
   This function takes a reference to a `MechanicalComponent` object and fills its fields with data provided by the user.

   ```cpp
   void inputComponentDetails(MechanicalComponent &component) {
       cout << "Enter Component ID: ";
       cin >> component.componentID;
       
       cout << "Enter Component Name: ";
       cin.ignore();  // Clears input buffer to handle getline correctly
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

       saveComponentToFile(component); // Save the component details to a file
   }
   ```

3. **Function to Save Component Details to a File (`saveComponentToFile`)**:
   This function writes the component details to a file named `mechanicalcomponent.txt` in an append mode.

   ```cpp
   void saveComponentToFile(const MechanicalComponent &component) {
       ofstream outFile("mechanicalcomponent.txt", ios::app); // Open file in append mode
       if (outFile.is_open()) {
           outFile << "Component ID: " << component.componentID << endl;
           outFile << "Component Name: " << component.componentName << endl;
           outFile << "Mass: " << component.mass << " kg" << endl;
           outFile << "Volume: " << component.volume << " m^3" << endl;
           outFile << "Material: " << component.material << endl;
           outFile << "Max Stress: " << component.maxStress << " Pa" << endl;
           outFile << "Tolerance: " << component.tolerance << " mm" << endl;
           outFile.close(); // Close the file after writing
           cout << "Component details saved to mechanicalcomponent.txt" << endl;
       } else {
           cout << "Unable to open file for writing." << endl;
       }
   }
   ```

4. **Function to Read and Print Component Details from File (`printComponentsFromFile`)**:
   This function reads the component details from the file `mechanicalcomponent.txt` and prints them to the console.

   ```cpp
   void printComponentsFromFile() {
       ifstream inFile("mechanicalcomponent.txt");
       if (inFile.is_open()) {
           string line;
           while (getline(inFile, line)) {
               if (line.find(": ") != string::npos) {
                   int componentID = stoi(line.substr(line.find(": ") + 2));
                   cout << "Component ID: " << componentID << endl;
               }
               if (getline(inFile, line) && line.find(": ") != string::npos) {
                   string componentName = line.substr(line.find(": ") + 2);
                   cout << "Component Name: " << componentName << endl;
               }
               if (getline(inFile, line) && line.find(": ") != string::npos) {
                   double mass = stod(line.substr(line.find(": ") + 2));
                   cout << "Mass: " << mass << " kg" << endl;
               }
               if (getline(inFile, line) && line.find(": ") != string::npos) {
                   double volume = stod(line.substr(line.find(": ") + 2));
                   cout << "Volume: " << volume << " m^3" << endl;
               }
               if (getline(inFile, line) && line.find(": ") != string::npos) {
                   string material = line.substr(line.find(": ") + 2);
                   cout << "Material: " << material << endl;
               }
               if (getline(inFile, line) && line.find(": ") != string::npos) {
                   double maxStress = stod(line.substr(line.find(": ") + 2));
                   cout << "Max Stress: " << maxStress << " Pa" << endl;
               }
               if (getline(inFile, line) && line.find(": ") != string::npos) {
                   double tolerance = stod(line.substr(line.find(": ") + 2));
                   cout << "Tolerance: " << tolerance << " mm" << endl;
               }
               cout << endl;  // Print a newline to separate components
               getline(inFile, line); // Skip the empty line between components
           }
           inFile.close();
       } else {
           cout << "Unable to open file for reading." << endl;
       }
   }
   ```

5. **Main Function (`main`)**:
   This is the entry point of the program. It calls the `printComponentsFromFile` function to read and print the details from the file.

   ```cpp
   int main() {
       printComponentsFromFile(); // Print all components stored in the file
       return 0;
   }
   ```

#### Key Points to Understand:

- **File Handling**: The program demonstrates reading from and writing to a file using `ifstream` and `ofstream`.
- **Structure Usage**: The `MechanicalComponent` structure organizes related data in a single object, making it easier to manage and pass data around functions.
- **Input and Output Operations**: It uses both `cin` for input and `getline` to handle multi-word input correctly, and `cout` to display the data.
- **Error Handling**: Basic checks ensure the file is opened correctly before performing operations, preventing runtime errors.

By understanding each of these parts, you can see how this program effectively demonstrates using structures, file input/output, and basic error handling in C++.