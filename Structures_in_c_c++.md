### Notes on Structures in C++

Structures in C++ are a way to group related variables of different data types under a single name. They are especially useful when we want to represent a real-life entity that has multiple attributes.

#### 1. Defining a Structure

To define a structure in C++, use the `struct` keyword. Here is an example that defines a structure named `Car` to represent a real-life car:

```cpp
#include <iostream>
using namespace std;

struct Car {
    string brand;
    string model;
    int year;
    double price;
};

int main() {
    // Example usage of the Car structure
    Car myCar;
    myCar.brand = "Toyota";
    myCar.model = "Corolla";
    myCar.year = 2020;
    myCar.price = 20000.50;

    cout << "Car Details:" << endl;
    cout << "Brand: " << myCar.brand << endl;
    cout << "Model: " << myCar.model << endl;
    cout << "Year: " << myCar.year << endl;
    cout << "Price: $" << myCar.price << endl;

    return 0;
}
```

In this example, the `Car` structure has four members: `brand`, `model`, `year`, and `price`. Each member represents an attribute of the car.

#### 2. Initializing a Structure

There are multiple ways to initialize a structure in C++. You can assign values directly to the members, as shown in the example above, or use an initializer list:

```cpp
Car anotherCar = {"Honda", "Civic", 2019, 18000.75};

cout << "Another Car Details:" << endl;
cout << "Brand: " << anotherCar.brand << endl;
cout << "Model: " << anotherCar.model << endl;
cout << "Year: " << anotherCar.year << endl;
cout << "Price: $" << anotherCar.price << endl;
```

The initializer list `{}` allows for a concise way to initialize all members at once.

#### 3. Nested Structures

A structure can contain another structure as a member. This is useful for representing more complex entities. For example, a `Person` can have an `Address` structure:

```cpp
struct Address {
    string street;
    string city;
    string state;
    int zipCode;
};

struct Person {
    string name;
    int age;
    Address address; // Nested structure
};

int main() {
    Person person;
    person.name = "John Doe";
    person.age = 30;
    person.address.street = "123 Elm Street";
    person.address.city = "New York";
    person.address.state = "NY";
    person.address.zipCode = 10001;

    cout << "Person Details:" << endl;
    cout << "Name: " << person.name << endl;
    cout << "Age: " << person.age << endl;
    cout << "Address: " << person.address.street << ", " 
         << person.address.city << ", " 
         << person.address.state << " - " 
         << person.address.zipCode << endl;

    return 0;
}
```

In this example, `Person` contains an `Address`, showing how nested structures can represent entities with multiple related properties.

#### 4. Array of Structures

Sometimes, you need to store multiple records of the same type. You can create an array of structures to do this. For instance, let's create an array of `Car` structures:

```cpp
Car carFleet[3] = {
    {"Ford", "Fusion", 2018, 15000.99},
    {"Tesla", "Model S", 2022, 75000.50},
    {"BMW", "X5", 2021, 60000.00}
};

for (int i = 0; i < 3; i++) {
    cout << "Car " << i + 1 << " Details:" << endl;
    cout << "Brand: " << carFleet[i].brand << endl;
    cout << "Model: " << carFleet[i].model << endl;
    cout << "Year: " << carFleet[i].year << endl;
    cout << "Price: $" << carFleet[i].price << endl;
    cout << endl;
}
```

Here, `carFleet` is an array of `Car` structures, allowing us to store and manipulate multiple car records efficiently.

#### Summary

- **Defining a Structure**: Use the `struct` keyword to group variables.
- **Initializing a Structure**: Assign values directly or use an initializer list.
- **Nested Structures**: Use one structure as a member of another.
- **Array of Structures**: Store multiple records of the same type efficiently.

These examples illustrate how structures can be used to model real-life entities and their attributes in C++.