#include <iostream>
#include "CStack.h"
#pragma once
using namespace std;
class CStack 
{
private:
    CNode* m_pclsHeadNode;

    void Initialize() 
    {
        m_pclsHeadNode = nullptr;
    }

    void DeepCopy(const CStack& clsOriginalToCopy) 
    {
        if (clsOriginalToCopy.m_pclsHeadNode) {
            m_pclsHeadNode = new CNode(*(clsOriginalToCopy.m_pclsHeadNode));
            CNode* current = m_pclsHeadNode;
            CNode* originalCurrent = clsOriginalToCopy.m_pclsHeadNode->GetNextNode();
            while (originalCurrent) {
                current->SetNextNode(new CNode(*originalCurrent));
                current = current->GetNextNode();
                originalCurrent = originalCurrent->GetNextNode();
            }
        }
        else 
        {
            m_pclsHeadNode = nullptr;
        }
    }

    void CleanUp() 
    {
        while (m_pclsHeadNode) 
        {
            CNode* temp = m_pclsHeadNode;
            m_pclsHeadNode = m_pclsHeadNode->GetNextNode();
            delete temp;
        }
    }

public:
    CStack() 
    {
        Initialize();
    }

    CStack(const CStack& clsOriginalToCopy) 
    {
        Initialize();
        DeepCopy(clsOriginalToCopy);
    }

    ~CStack() {
        CleanUp();
    }

    CStack& operator=(const CStack& clsOriginalToCopy) 
    {
        if (this != &clsOriginalToCopy) 
        {
            CleanUp();
            DeepCopy(clsOriginalToCopy);
        }
        return *this;
    }

    void Push(int intValue) 
    {
        CNode* newNode = new CNode(intValue, m_pclsHeadNode);
        m_pclsHeadNode = newNode;
    }

    int Pop() {
        if (IsEmpty()) 
        {
            throw std::runtime_error("Stack is empty");
        }
        int value = m_pclsHeadNode->GetValue();
        CNode* temp = m_pclsHeadNode;
        m_pclsHeadNode = m_pclsHeadNode->GetNextNode();
        delete temp;
        return value;
    }

    bool IsEmpty() const 
    {
        return m_pclsHeadNode == nullptr;
    }

    void Print() const 
    {
        CNode* current = m_pclsHeadNode;
        while (current) 
        {
            std::cout << current->GetValue() << " ";
            current = current->GetNextNode();
        }
        std::cout << std::endl;
    }
};
