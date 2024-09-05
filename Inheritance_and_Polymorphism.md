### Notes on Types of Inheritance, Function Overloading, and Function Overriding in C++

#### 1. **Types of Inheritance in C++**
Inheritance allows a new class (derived class) to acquire the properties and behaviors of an existing class (base class). It promotes code reusability and establishes a relationship between classes. Here are the types of inheritance in C++:

##### a. **Single Inheritance**
Single inheritance involves one base class and one derived class. The derived class inherits properties from a single base class.

**Real-life Example:**
Imagine a school where there is a general "Teacher" category, and then a specific "MathTeacher" category. The "MathTeacher" inherits common properties like `name`, `age`, and `subject` from the "Teacher".

```cpp
#include <iostream>
using namespace std;

class Teacher {
public:
    string name;
    int age;

    void teach() {
        cout << name << " is teaching." << endl;
    }
};

class MathTeacher : public Teacher {
public:
    void teachMath() {
        cout << name << " is teaching Math." << endl;
    }
};

int main() {
    MathTeacher mt;
    mt.name = "Alice";
    mt.age = 30;
    mt.teach();      // Output: Alice is teaching.
    mt.teachMath();  // Output: Alice is teaching Math.
    return 0;
}
```

##### b. **Multiple Inheritance**
Multiple inheritance involves one derived class inheriting from multiple base classes. 

**Real-life Example:**
Consider a person who is both a "Doctor" and a "Professor". The class "Person" inherits from both "Doctor" and "Professor".

```cpp
#include <iostream>
using namespace std;

class Doctor {
public:
    void diagnose() {
        cout << "Diagnosing patients." << endl;
    }
};

class Professor {
public:
    void teach() {
        cout << "Teaching students." << endl;
    }
};

class Person : public Doctor, public Professor {
};

int main() {
    Person p;
    p.diagnose();  // Output: Diagnosing patients.
    p.teach();     // Output: Teaching students.
    return 0;
}
```

##### c. **Multilevel Inheritance**
Multilevel inheritance involves a derived class inheriting from another derived class, forming a chain of inheritance.

**Real-life Example:**
Imagine an "Animal" class, which is inherited by "Mammal", and further, the "Mammal" is inherited by "Human".

```cpp
#include <iostream>
using namespace std;

class Animal {
public:
    void eat() {
        cout << "Eating..." << endl;
    }
};

class Mammal : public Animal {
public:
    void breathe() {
        cout << "Breathing..." << endl;
    }
};

class Human : public Mammal {
public:
    void speak() {
        cout << "Speaking..." << endl;
    }
};

int main() {
    Human h;
    h.eat();      // Output: Eating...
    h.breathe();  // Output: Breathing...
    h.speak();    // Output: Speaking...
    return 0;
}
```

##### d. **Hierarchical Inheritance**
Hierarchical inheritance involves multiple derived classes inheriting from a single base class.

**Real-life Example:**
A "Vehicle" class can be inherited by "Car", "Bike", and "Truck".

```cpp
#include <iostream>
using namespace std;

class Vehicle {
public:
    void start() {
        cout << "Vehicle starting..." << endl;
    }
};

class Car : public Vehicle {
};

class Bike : public Vehicle {
};

int main() {
    Car c;
    Bike b;
    c.start();  // Output: Vehicle starting...
    b.start();  // Output: Vehicle starting...
    return 0;
}
```

##### e. **Hybrid Inheritance**
Hybrid inheritance is a combination of more than one type of inheritance.

**Real-life Example:**
Consider a "Person" class inherited by "Student" and "Teacher". "Teacher" is further inherited by "Researcher".


```cpp
class Person {
public:
    string name;
    int age;
    Person(string n, int a) : name(n), age(a) {}
};

class Student : public Person {
public:
    int studentID;
    Student(string n, int a, int id) : Person(n, a), studentID(id) {}
};

class Teacher : public Person {
public:
    int teacherID;
    Teacher(string n, int a, int id) : Person(n, a), teacherID(id) {}
};

class Researcher : public Teacher {
public:
    string researchTopic;
    Researcher(string n, int a, int id, string topic) : Teacher(n, a, id), researchTopic(topic) {}
};
```

This code demonstrates hybrid inheritance where `Student` and `Teacher` classes inherit from `Person`, and `Researcher` further inherits from `Teacher`.


### 2.Polymorphism Definition

**Polymorphism** allows an object to take on many forms, enabling functions, methods, or objects to behave differently depending on the context in which they are used. It is achieved through method overloading, method overriding, or using base class references to refer to derived class objects.


####  **Function Overloading**

Function overloading allows multiple functions with the same name but different parameters (type or number) within the same scope.

**Real-life Example:**
Think of a "Print" function that can print different types of messages: an integer, a float, or a string.

```cpp
#include <iostream>
using namespace std;

class Printer {
public:
    void print(int num) {
        cout << "Printing an integer: " << num << endl;
    }
    void print(double num) {
        cout << "Printing a double: " << num << endl;
    }
    void print(string text) {
        cout << "Printing a string: " << text << endl;
    }
};

int main() {
    Printer p;
    p.print(5);          // Output: Printing an integer: 5
    p.print(5.67);       // Output: Printing a double: 5.67
    p.print("Hello");    // Output: Printing a string: Hello
    return 0;
}
```

####  **Function Overriding**
Function overriding allows a derived class to provide a specific implementation of a function that is already defined in its base class.

**Real-life Example:**
Consider a "Bank" class with a `displayInterestRate()` function. A "SavingsAccount" class can override this function to display a specific interest rate for savings accounts.

```cpp
#include <iostream>
using namespace std;

class Bank {
public:
    virtual void displayInterestRate() {
        cout << "Base interest rate: 2%" << endl;
    }
};

class SavingsAccount : public Bank {
public:
    void displayInterestRate() override {
        cout << "Savings account interest rate: 4%" << endl;
    }
};

int main() {
    Bank* b;
    SavingsAccount sa;
    b = &sa;
    b->displayInterestRate();  // Output: Savings account interest rate: 4%
    return 0;
}
```

### Summary
- **Inheritance** types include Single, Multiple, Multilevel, Hierarchical, and Hybrid, each allowing classes to inherit properties in different ways.
- **Function Overloading** lets you define multiple functions with the same name but different parameter lists.
- **Function Overriding** enables a derived class to provide a specific implementation of a function already defined in its base class.

These concepts promote code reuse, modularity, and flexibility in object-oriented programming using C++.