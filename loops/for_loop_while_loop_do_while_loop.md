## Loops in C++

### 1. **What are Loops?**

Loops are control structures that repeat a block of code multiple times until a specified condition is met. C++ supports three types of loops:

- **`for` loop**
- **`while` loop**
- **`do-while` loop**

### 2. **Real-Life Example of Loops:**

Imagine you’re organizing a birthday party and need to hand out 10 gift bags to kids. Instead of giving each bag individually, you could use a loop to streamline the process.

### 3. **`for` Loop**

The `for` loop is useful when you know in advance how many times you want to repeat a task.

**Syntax:**

```cpp
for(initialization; condition; increment/decrement) {
    // code to be repeated
}
```

**Real-Life Example: Counting and Distributing Gifts**

```cpp
#include <iostream>
using namespace std;

int main() {
    for(int i = 1; i <= 10; i++) {
        cout << "Giving gift bag " << i << " to a child." << endl;
    }
    return 0;
}
```

**Explanation:**

- Initialization: `int i = 1;` starts the loop with the first gift.
- Condition: `i <= 10;` repeats the loop until 10 gifts are given.
- Increment: `i++` increases the count after each loop iteration.

### 4. **`while` Loop**

The `while` loop is useful when you’re unsure how many times the loop should run and depend on a condition.

**Syntax:**

```cpp
while(condition) {
    // code to be repeated
}
```

**Real-Life Example: Checking for Rain Until it Stops**

```cpp
#include <iostream>
using namespace std;

int main() {
    bool isRaining = true;

    while(isRaining) {
        cout << "Waiting for the rain to stop..." << endl;

        // Simulating a check if rain stopped
        isRaining = false; // Assume the rain stops after one check
    }

    cout << "The rain has stopped. Let's go outside!" << endl;
    return 0;
}
```

**Explanation:**

- The loop runs as long as `isRaining` is true. Once it becomes false, the loop stops.

### 5. **`do-while` Loop**

The `do-while` loop is similar to the `while` loop, but it guarantees the loop runs at least once, even if the condition is false initially.

**Syntax:**

```cpp
do {
    // code to be repeated
} while(condition);
```

**Real-Life Example: Playing a Game Until the User Decides to Quit**

```cpp
#include <iostream>
using namespace std;

int main() {
    char playAgain;

    do {
        cout << "Playing the game..." << endl;

        // Asking if the user wants to play again
        cout << "Do you want to play again? (y/n): ";
        cin >> playAgain;

    } while(playAgain == 'y' || playAgain == 'Y');

    cout << "Thanks for playing!" << endl;
    return 0;
}
```

**Explanation:**

- The loop runs at least once and continues as long as the user chooses to keep playing.
---

### Summary

- **`for` loop**: Ideal when the number of iterations is known.
- **`while` loop**: Suitable for looping until a condition changes.
- **`do-while` loop**: Ensures the loop runs at least once.

### Practice Problem:

Try writing a loop to simulate counting steps while walking to reach a destination.
