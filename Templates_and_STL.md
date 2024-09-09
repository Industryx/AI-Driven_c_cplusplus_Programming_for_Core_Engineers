### Notes on Templates and STL (Standard Template Library) in C++

#### 1. **Templates in C++**
Templates allow writing generic and reusable code for different data types. They enable functions and classes to operate with any data type without rewriting code for each type.

##### a. **Function Templates**
A function template defines a blueprint for a function that can handle different data types. 

**Example: A function to find the maximum of two numbers**

Let's say we have a function that finds the maximum of two integers. Instead of writing separate functions for `int`, `float`, and `double`, we can use a function template:

```cpp
#include <iostream>
using namespace std;

// Function Template
template <typename T>
T findMax(T a, T b) {
    return (a > b) ? a : b;
}

int main() {
    cout << "Max of 3 and 7 is: " << findMax(3, 7) << endl;
    cout << "Max of 4.5 and 2.1 is: " << findMax(4.5, 2.1) << endl;
    return 0;
}
```

Here, `T` is a placeholder for any data type. When the function is called, the compiler automatically replaces `T` with the appropriate data type (`int`, `float`, etc.).

##### b. **Class Templates**
Class templates are used to create a class that can work with any data type.

**Example: A simple generic Pair class**

Suppose you want to create a class that stores a pair of values of any data type:

```cpp
#include <iostream>
using namespace std;

// Class Template
template <typename T1, typename T2>
class Pair {
private:
    T1 first;
    T2 second;
public:
    Pair(T1 f, T2 s) : first(f), second(s) {}
    
    void display() const {
        cout << "Pair: (" << first << ", " << second << ")" << endl;
    }
};

int main() {
    Pair<int, double> p1(5, 7.5);
    p1.display();
    
    Pair<string, char> p2("Hello", 'A');
    p2.display();

    return 0;
}
```

In this example, the `Pair` class can store any two types of data, making it flexible and reusable.

#### 2. **Standard Template Library (STL)**
STL provides a set of common data structures and algorithms to help manage collections of data. STL consists of several components, such as Vectors, Maps, and Sets.

##### a. **Vectors**
Vectors are dynamic arrays that can grow or shrink in size. They are similar to arrays but provide more flexibility.

**Real-life Example: Storing temperatures recorded every hour**

```cpp
#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> temperatures;
    temperatures.push_back(30);
    temperatures.push_back(32);
    temperatures.push_back(28);

    cout << "Temperatures recorded: ";
    for (int temp : temperatures) {
        cout << temp << " ";
    }
    cout << endl;

    temperatures.pop_back(); // Remove the last element
    cout << "After removing last: ";
    for (int temp : temperatures) {
        cout << temp << " ";
    }
    cout << endl;

    return 0;
}
```

##### b. **Maps**
Maps store key-value pairs and are used when quick lookups are needed based on a unique key.

**Real-life Example: Storing student IDs and their corresponding grades**

```cpp
#include <iostream>
#include <map>
using namespace std;

int main() {
    map<int, char> studentGrades;
    studentGrades[101] = 'A';
    studentGrades[102] = 'B';
    studentGrades[103] = 'C';

    cout << "Student Grades:" << endl;
    for (const auto& entry : studentGrades) {
        cout << "ID: " << entry.first << ", Grade: " << entry.second << endl;
    }

    return 0;
}
```

##### c. **Sets**
Sets store unique elements in sorted order and are used when duplicates are not allowed.

**Real-life Example: Keeping track of unique book titles in a library**

```cpp
#include <iostream>
#include <set>
using namespace std;

int main() {
    set<string> bookTitles;
    bookTitles.insert("C++ Programming");
    bookTitles.insert("Data Structures");
    bookTitles.insert("C++ Programming"); // Duplicate, will not be added

    cout << "Unique Book Titles in Library:" << endl;
    for (const string& title : bookTitles) {
        cout << title << endl;
    }

    return 0;
}
```

#### Summary
- **Templates** help in writing generic code for any data type.
  - **Function Templates** create functions that can operate on different data types.
  - **Class Templates** create classes that are flexible and reusable for different data types.
- **STL** provides powerful data structures like **Vectors**, **Maps**, and **Sets** for efficient data management.
  - **Vectors** offer dynamic arrays with flexible sizes.
  - **Maps** are key-value stores for fast lookups.
  - **Sets** ensure unique elements and maintain order.