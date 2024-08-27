### **Lecture 8: Pointers in C++**

---

#### **1. Basics of Pointers**

**What is a Pointer?**  
A pointer is a variable that stores the memory address of another variable.

**Why Use Pointers?**  
Pointers allow efficient memory management, dynamic memory allocation, and enable passing large data structures to functions without copying them.

**Pointer Syntax:**  
To declare a pointer:
```cpp
int* ptr;
```
Here, `ptr` is a pointer to an integer.

**Example:**
```cpp
#include <iostream>
using namespace std;

int main() {
    int num = 10;
    int* ptr = &num; // Pointer stores the address of num

    cout << "Value of num: " << num << endl;
    cout << "Address of num: " << &num << endl;
    cout << "Value stored in ptr: " << ptr << endl;
    cout << "Value pointed by ptr: " << *ptr << endl;

    return 0;
}
```
**Explanation:**
- The address-of operator `&` is used to get the memory address of the variable `num`.
- The dereference operator `*` is used to access the value at the memory address stored by `ptr`.

---

#### **2. Pointers and Arrays**

**Relationship Between Arrays and Pointers:**  
In C++, the name of an array acts as a pointer to its first element. Pointers can be used to traverse or access elements of an array.

**Example:**
```cpp
#include <iostream>
using namespace std;

int main() {
    int arr[3] = {10, 20, 30};
    int* ptr = arr; // Pointer points to the first element of the array

    for (int i = 0; i < 3; i++) {
        cout << "Element " << i << ": " << *(ptr + i) << endl;
    }

    return 0;
}
```
**Explanation:**
- `arr` acts as a pointer pointing to the first element.
- Pointer arithmetic (e.g., `ptr + i`) allows accessing the array elements sequentially.

**Pointer Arithmetic with Arrays:**
You can increment or decrement pointers to navigate through array elements:
```cpp
cout << *ptr << endl; // Outputs first element (10)
cout << *(ptr + 1) << endl; // Outputs second element (20)
```

---

#### **3. Pointers and Functions**

**Passing Pointers to Functions:**  
Passing pointers to functions allows functions to modify the original variables directly. It is also useful for passing large data structures without copying them.

**Example:**
```cpp
#include <iostream>
using namespace std;

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int x = 5, y = 10;
    swap(&x, &y); // Passing addresses of x and y to the swap function
    cout << "x: " << x << ", y: " << y << endl; // x: 10, y: 5

    return 0;
}
```
**Explanation:**
- The function receives the addresses of `x` and `y` as pointers.
- The values are swapped directly through dereferencing, affecting the original variables.

---

#### **4. Dynamic Memory Allocation using Pointers**

**Why Dynamic Memory?**  
Dynamic memory allocation allows allocating memory during runtime, which is useful when the size of data is not known at compile-time.

**`new` and `delete` in C++:**
```cpp
int* ptr = new int; // Allocates memory dynamically for an integer
*ptr = 50;
delete ptr; // Frees the allocated memory
```
**Explanation:**
- `new` allocates memory dynamically on the heap.
- `delete` is used to deallocate the memory and avoid memory leaks.

---

### **Key Takeaways**
- Pointers provide direct access to memory and enable efficient use of resources.
- They are essential for dynamic memory management and advanced data structures in C++.
- Understanding pointers is crucial for mastering C++ programming.

