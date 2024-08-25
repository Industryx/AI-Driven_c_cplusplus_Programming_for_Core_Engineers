### Notes on Infinite Loops and Nested Loops in C++ (Without Arrays)

#### **1. Infinite Loops:**

An **infinite loop** runs indefinitely because its condition is always true or it lacks a termination condition. Infinite loops can be intentional or result from logic errors.

**Example 1: Intentional Infinite Loop using `while`:**

```cpp
#include <iostream>

int main() {
    while (true) { // Loop condition is always true
        std::cout << "This loop will run forever!\n";
    }
    return 0;
}
```

- **Explanation**:  
  The condition `true` is always met, so the loop runs endlessly.

**Example 2: Accidental Infinite Loop using `for`:**

```cpp
#include <iostream>

int main() {
    for (int i = 1; i <= 5;) { // Missing increment step
        std::cout << "i: " << i << std::endl;
        // 'i++' is missing, causing an infinite loop
    }
    return 0;
}
```

- **Explanation**:  
  The loop lacks an increment step (`i++`), so `i` never changes, resulting in an infinite loop.

**Example 3: Infinite Loop using `do-while`:**

```cpp
#include <iostream>

int main() {
    int x = 1;
    do {
        std::cout << "This will keep printing\n";
    } while (x == 1); // Condition is always true
    return 0;
}
```

- **Explanation**:  
  The condition `x == 1` never changes, leading to an endless loop.

#### **2. Nested Loops:**

**Nested loops** involve placing one loop inside another. They are commonly used for tasks requiring multiple levels of iteration.

**Example 1: Simple Nested `for` Loop:**

```cpp
#include <iostream>

int main() {
    for (int i = 1; i <= 3; i++) { // Outer loop
        for (int j = 1; j <= 2; j++) { // Inner loop
            std::cout << "i: " << i << ", j: " << j << std::endl;
        }
    }
    return 0;
}
```

- **Explanation**:  
  - The outer loop runs 3 times, while the inner loop runs 2 times for each iteration of the outer loop.
  - The output looks like:
    ```
    i: 1, j: 1
    i: 1, j: 2
    i: 2, j: 1
    i: 2, j: 2
    i: 3, j: 1
    i: 3, j: 2
    ```

**Example 2: Nested `while` Loop:**

```cpp
#include <iostream>

int main() {
    int i = 1;
    while (i <= 3) { // Outer loop
        int j = 1;
        while (j <= 2) { // Inner loop
            std::cout << "i: " << i << ", j: " << j << std::endl;
            j++;
        }
        i++;
    }
    return 0;
}
```

- **Explanation**:  
  The logic and output are similar to the previous example but using `while` loops instead.

**Example 3: Nested `do-while` Loop:**

```cpp
#include <iostream>

int main() {
    int i = 1;
    do { // Outer loop
        int j = 1;
        do { // Inner loop
            std::cout << "i: " << i << ", j: " << j << std::endl;
            j++;
        } while (j <= 2);
        i++;
    } while (i <= 3);
    return 0;
}
```

- **Explanation**:  
  The logic is similar to the previous examples but using `do-while` loops.

#### **Key Points:**
- **Infinite Loops** can be intentional or result from errors.
- **Nested Loops** are useful for tasks involving multiple levels of iteration.
- Proper use of conditions and increment/decrement operations is crucial to avoid unintended infinite loops.

These examples cover different loop structures without relying on arrays.