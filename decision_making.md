## Conditional Statements in C++ for Mechanical Engineering Students

Conditional statements allow a program to make decisions and execute specific code blocks based on whether certain conditions are true or false. In C++, the main conditional statements are `if`, `else`, `if-else`, and `switch`. Let's dive into each one with explanations and examples.

### 1. **The `if` Statement**

The `if` statement checks a condition. If the condition is true, the code inside the `if` block is executed.

**Syntax:**

```cpp
if (condition) {
    // Code to be executed if condition is true
}
```

**Example:**

Imagine you’re checking if a certain machine temperature is above a safety limit:

```cpp
#include <iostream>
using namespace std;

int main() {
    int temperature = 80; // Temperature in degrees Celsius

    if (temperature > 75) {
        cout << "Warning: Temperature is above the safe limit!" << endl;
    }

    return 0;
}
```

In this example, if the temperature exceeds 75°C, the program will print a warning message.

### 2. **The `else` Statement**

The `else` statement runs when the `if` condition is false.

**Syntax:**

```cpp
if (condition) {
    // Code to be executed if condition is true
} else {
    // Code to be executed if condition is false
}
```

**Example:**

Continuing with the temperature example:

```cpp
#include <iostream>
using namespace std;

int main() {
    int temperature = 70; // Temperature in degrees Celsius

    if (temperature > 75) {
        cout << "Warning: Temperature is above the safe limit!" << endl;
    } else {
        cout << "Temperature is within the safe range." << endl;
    }

    return 0;
}
```

If the temperature is 70°C (not greater than 75°C), the program will indicate that it’s within the safe range.

### 3. **The `if-else if-else` Statement**

Sometimes, you need to check multiple conditions. This is where `else if` comes in handy.

**Syntax:**

```cpp
if (condition1) {
    // Code to be executed if condition1 is true
} else if (condition2) {
    // Code to be executed if condition2 is true
} else {
    // Code to be executed if neither condition1 nor condition2 is true
}
```

**Example:**

Let’s extend the temperature check to include multiple safety levels:

```cpp
#include <iostream>
using namespace std;

int main() {
    int temperature = 85; // Temperature in degrees Celsius

    if (temperature > 90) {
        cout << "Critical Alert: Machine shutdown required!" << endl;
    } else if (temperature > 75) {
        cout << "Warning: Temperature is above the safe limit!" << endl;
    } else {
        cout << "Temperature is within the safe range." << endl;
    }

    return 0;
}
```

In this example, if the temperature is above 90°C, a critical alert is issued. If it’s between 75°C and 90°C, a warning is displayed. Otherwise, it’s considered safe.

### 4. **The `switch` Statement**

The `switch` statement is a great way to handle multiple conditions based on the value of a single variable.

**Syntax:**

```cpp
switch (variable) {
    case value1:
        // Code to be executed if variable == value1
        break;
    case value2:
        // Code to be executed if variable == value2
        break;
    // You can have any number of cases
    default:
        // Code to be executed if none of the above cases match
}
```

**Example:**

Imagine you want to categorize different types of mechanical components based on their ID:

```cpp
#include <iostream>
using namespace std;

int main() {
    int componentID = 2;

    switch (componentID) {
        case 1:
            cout << "Component: Gear" << endl;
            break;
        case 2:
            cout << "Component: Bearing" << endl;
            break;
        case 3:
            cout << "Component: Piston" << endl;
            break;
        default:
            cout << "Component not recognized!" << endl;
    }

    return 0;
}
```

In this example, if the `componentID` is 2, the program identifies it as a "Bearing." If none of the cases match, the `default` block runs.

### Real-Life Mechanical Engineering Context

Imagine you're controlling a cooling system in a factory. You want to decide when to turn on or off the cooling fans based on the current temperature of the machines:

```cpp
#include <iostream>
using namespace std;

int main() {
    int temperature = 68;

    if (temperature > 80) {
        cout << "Cooling fans ON - High speed" << endl;
    } else if (temperature > 60) {
        cout << "Cooling fans ON - Low speed" << endl;
    } else {
        cout << "Cooling fans OFF" << endl;
    }

    return 0;
}
```

### Summary

- **`if`** checks a condition and runs code if true.
- **`else`** provides an alternative if the `if` condition is false.
- **`if-else if-else`** handles multiple conditions.
- **`switch`** is best for multiple choices based on a single variable.

These conditional statements are the backbone of decision-making in C++. They allow your programs to behave dynamically based on inputs, making them crucial in automation and control systems in mechanical engineering.
