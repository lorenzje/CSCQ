// ------------------------------------------------------------------------------------------
// Name: Your name here
// Class: C Programming
// Abstract: Homework 1.
// ------------------------------------------------------------------------------------------
#pragma once
// ------------------------------------------------------------------------------------------
// Includes
// ------------------------------------------------------------------------------------------
#include "CNode.h"
#include "CStack.h"
#include "CQueue.h"
#include <iostream>
using namespace std;

int main() 
{
    // Test CNode
    std::cout << "Testing CNode:\n";
    CNode node1;
    node1.SetValue(10);
    std::cout << "node1 value: " << node1.GetValue() << std::endl;
    CNode node2(20);
    std::cout << "node2 value: " << node2.GetValue() << std::endl;
    CNode node3(30, &node2);
    std::cout << "node3 value: " << node3.GetValue() << ", next node value: " << node3.GetNextNode()->GetValue() << std::endl;
    CNode node4(node3);
    std::cout << "node4 (copy of node3) value: " << node4.GetValue() << ", next node value: " << node4.GetNextNode()->GetValue() << std::endl;
    node4 = node1;
    std::cout << "node4 (assigned from node1) value: " << node4.GetValue() << std::endl;

    // Test CStack
    std::cout << "\nTesting CStack:\n";
    CStack stack;
    stack.Push(1);
    stack.Push(2);
    stack.Push(3);
    stack.Print();
    std::cout << "Pop: " << stack.Pop() << std::endl;
    stack.Print();
    CStack stack2(stack);
    std::cout << "stack2 (copy of stack): ";
    stack2.Print();
    stack2.Push(4);
    std::cout << "stack2 after push: ";
    stack2.Print();
    std::cout << "stack after push to stack2: ";
    stack.Print();
    CStack stack3;
    stack3 = stack;
    std::cout << "stack3 (assigned from stack): ";
    stack3.Print();

    // Test CQueue
    std::cout << "\nTesting CQueue:\n";
    CQueue queue;
    queue.Push(1);
    queue.Push(2);
    queue.Push(3);
    queue.Print();
    std::cout << "Pop: " << queue.Pop() << std::endl;
    queue.Print();
    CQueue queue2(queue);
    std::cout << "queue2 (copy of queue): ";
    queue2.Print();
    queue2.Push(4);
    std::cout << "queue2 after push: ";
    queue2.Print();
    std::cout << "queue after push to queue2: ";
    queue.Print();
    CQueue queue3;
    queue3 = queue;
    std::cout << "queue3 (assigned from queue): ";
    queue3.Print();

    return 0;
}
