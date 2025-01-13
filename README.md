## Overview

This project demonstrates the implementation and testing of three core data structures: `CNode`, `CStack`, and `CQueue`. The program is written in C++ and uses object-oriented programming principles to define and test these classes.

---

## Features

### 1. `CNode` Class
The `CNode` class represents a single node that stores an integer value and a pointer to the next node.

#### Key Methods:
- **SetValue(int value):** Sets the value of the node.
- **GetValue() const:** Gets the value of the node.
- **SetNextNode(CNode* next):** Sets the pointer to the next node.
- **GetNextNode() const:** Gets the pointer to the next node.

### 2. `CStack` Class
The `CStack` class implements a stack data structure using `CNode`.

#### Key Methods:
- **Push(int value):** Pushes a value onto the stack.
- **Pop():** Removes and returns the top value from the stack.
- **Print():** Prints all values in the stack.

### 3. `CQueue` Class
The `CQueue` class implements a queue data structure using `CNode`.

#### Key Methods:
- **Push(int value):** Adds a value to the end of the queue.
- **Pop():** Removes and returns the front value from the queue.
- **Print():** Prints all values in the queue.

---

## Code Details

### Header Files
- **`CNode.h`:** Declares the `CNode` class.
- **`CStack.h`:** Declares the `CStack` class.
- **`CQueue.h`:** Declares the `CQueue` class.

### Main File
The main file tests the functionality of the `CNode`, `CStack`, and `CQueue` classes.

#### Key Test Cases:
1. **Testing `CNode`:**
    - Create nodes with and without initial values.
    - Set and get values of nodes.
    - Create a linked list using `CNode` pointers.
    - Test copy constructor and assignment operator.

2. **Testing `CStack`:**
    - Push multiple values onto the stack.
    - Pop values from the stack.
    - Print the stack contents.
    - Test copy constructor and assignment operator.

3. **Testing `CQueue`:**
    - Push multiple values onto the queue.
    - Pop values from the queue.
    - Print the queue contents.
    - Test copy constructor and assignment operator.

### Sample Output
```plaintext
Testing CNode:
node1 value: 10
node2 value: 20
node3 value: 30, next node value: 20
node4 (copy of node3) value: 30, next node value: 20
node4 (assigned from node1) value: 10

Testing CStack:
Stack: 3 2 1
Pop: 3
Stack: 2 1
stack2 (copy of stack): 2 1
stack2 after push: 4 2 1
stack after push to stack2: 2 1
stack3 (assigned from stack): 2 1

Testing CQueue:
Queue: 1 2 3
Pop: 1
Queue: 2 3
queue2 (copy of queue): 2 3
queue2 after push: 4 2 3
queue after push to queue2: 2 3
queue3 (assigned from queue): 2 3
```

---

## How to Run

1. **Compile the program:**
   ```bash
   g++ -o Homework1 Homework1.cpp CNode.cpp CStack.cpp CQueue.cpp
   ```
2. **Run the executable:**
   ```bash
   ./Homework1
   ```

---

## License

This project is for educational purposes only and is not intended for production use.
