### Notes on Encapsulation and Abstraction in C++

#### 1. **Encapsulation**

Encapsulation is the process of wrapping data and methods that operate on the data within a single unit or class. This helps protect the internal state of the object from unintended interference and misuse.

**Real-life Example:**
Think of a capsule, which is a protective cover that encapsulates the medicine inside. Similarly, in C++, encapsulation allows us to bundle the data (attributes) and the methods (functions) together inside a single class, protecting them from outside interference.

**Code Example:**
```cpp
#include <iostream>
using namespace std;

class Car {
private:  // Private members are only accessible within this class
    string model;
    int speed;

public:  // Public members can be accessed outside the class
    void setCarDetails(string m, int s) {
        model = m;
        speed = s;
    }

    void showCarDetails() {
        cout << "Model: " << model << ", Speed: " << speed << " km/h" << endl;
    }
};

int main() {
    Car myCar;
    myCar.setCarDetails("Tesla Model S", 150);  // Setting car details
    myCar.showCarDetails();  // Accessing car details
    return 0;
}
```

In the example above, the car's `model` and `speed` are encapsulated within the `Car` class. They are private and cannot be accessed directly from outside the class, maintaining data integrity and security.

#### 2. **Abstraction**

Abstraction is the concept of hiding the complex implementation details and showing only the essential features of an object. It helps reduce programming complexity and effort.

**Real-life Example:**
Think of a TV remote control. You only need to know which button to press to perform an action (like changing the channel or adjusting the volume) without needing to understand the complex electronic processes happening inside the TV.

**Code Example:**
```cpp
#include <iostream>
using namespace std;

class RemoteControl {
public:
    void powerOn() {
        cout << "TV is turned ON." << endl;
    }
    
    void powerOff() {
        cout << "TV is turned OFF." << endl;
    }

    void changeChannel(int channel) {
        cout << "Channel changed to: " << channel << endl;
    }
};

int main() {
    RemoteControl remote;
    remote.powerOn();
    remote.changeChannel(5);
    remote.powerOff();
    return 0;
}
```

In the example above, the `RemoteControl` class abstracts the complex internal operations of a TV and provides simple methods for turning it on or off and changing the channel.

#### 3. **Access Specifiers: Private, Public, Protected**

- **Private:** Members declared as private are accessible only within the same class.
- **Public:** Members declared as public are accessible from outside the class.
- **Protected:** Members declared as protected are accessible within the same class and its derived classes.

**Code Example Demonstrating Access Specifiers:**
```cpp
#include <iostream>
using namespace std;

// Base class
class Car {
private:
    // Private members: Accessible only within the Car class
    string model;
    int speed;

protected:
    // Protected member: Accessible within the Car class and derived classes
    string engineType;

public:
    // Public method to set car details
    void setCarDetails(string m, int s, string e) {
        model = m;
        speed = s;
        engineType = e;
    }

    // Public method to show car details
    void showCarDetails() {
        cout << "Model: " << model << ", Speed: " << speed << " km/h" << endl;
        cout << "Engine Type: " << engineType << endl;
    }
};

// Derived class
class SportsCar : public Car {
public:
    // Method to display the engine type, accessing the protected member from the base class
    void displayEngineType() {
        cout << "SportsCar Engine Type: " << engineType << endl;
    }
};

int main() {
    Car myCar;
    myCar.setCarDetails("Toyota", 120, "Petrol");
    myCar.showCarDetails();

    // Cannot access private members directly: Uncommenting the following lines will cause errors
    // cout << myCar.model; 
    // cout << myCar.speed; 

    SportsCar mySportsCar;
    mySportsCar.setCarDetails("Ferrari", 200, "Turbo");
    mySportsCar.showCarDetails();
    mySportsCar.displayEngineType();  // Accessing protected member via derived class method

    return 0;
}
```


### **Expected Output:**

When you run the code, the output will be:
```
Model: Toyota, Speed: 120 km/h
Engine Type: Petrol
Model: Ferrari, Speed: 200 km/h
Engine Type: Turbo
SportsCar Engine Type: Turbo
```

### **Key Points:**

- **Private Members:** Cannot be accessed outside the class or by derived classes.
- **Protected Members:** Can be accessed by derived classes.
- **Public Members:** Can be accessed from anywhere, including from outside the class.
  


#### 4. **Abstract Classes and Interfaces**

- **Abstract Class:** A class that contains at least one pure virtual function (a function declared with `= 0`) is called an abstract class. It cannot be instantiated directly and must be inherited by other classes.

- **Interface:** In C++, an interface can be represented as an abstract class with only pure virtual functions.

**Code Example of Abstract Class and Interface:**
```cpp
#include <iostream>
using namespace std;

class Shape {  // Abstract Class
public:
    virtual void draw() = 0;  // Pure virtual function
};

class Circle : public Shape {
public:
    void draw() override {
        cout << "Drawing a Circle." << endl;
    }
};

class Rectangle : public Shape {
public:
    void draw() override {
        cout << "Drawing a Rectangle." << endl;
    }
};

int main() {
    Circle c;
    Rectangle r;

    c.draw();  // Calling overridden function
    r.draw();  // Calling overridden function

    return 0;
}
```

In the example above, `Shape` is an abstract class with a pure virtual function `draw()`. The `Circle` and `Rectangle` classes inherit from `Shape` and provide their own implementation for the `draw()` method.

### Summary
- **Encapsulation** protects data by restricting access to class members using access specifiers.
- **Abstraction** hides complex implementation details, providing only the essential features.
- **Access Specifiers** control the accessibility of class members:
  - **Private:** Accessible only within the class.
  - **Public:** Accessible from anywhere.
  - **Protected:** Accessible within the class and derived classes.
- **Abstract Classes and Interfaces** provide a blueprint for other classes and enforce the implementation of specific methods.