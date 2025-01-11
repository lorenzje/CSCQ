#include <iostream>
#include "CQueue.h"
#pragma once
using namespace std;
class CQueue 
{
private:
    CNode* m_pclsHeadNode;
    CNode* m_pclsTailNode;

    void Initialize() {
        m_pclsHeadNode = nullptr;
        m_pclsTailNode = nullptr;
    }

    void DeepCopy(const CQueue& clsOriginalToCopy) {
        if (clsOriginalToCopy.m_pclsHeadNode) {
            m_pclsHeadNode = new CNode(*(clsOriginalToCopy.m_pclsHeadNode));
            CNode* current = m_pclsHeadNode;
            CNode* originalCurrent = clsOriginalToCopy.m_pclsHeadNode->GetNextNode();
            while (originalCurrent) {
                current->SetNextNode(new CNode(*originalCurrent));
                current = current->GetNextNode();
                originalCurrent = originalCurrent->GetNextNode();
            }
            m_pclsTailNode = current;
        }
        else {
            m_pclsHeadNode = nullptr;
            m_pclsTailNode = nullptr;
        }
    }

    void CleanUp() {
        while (m_pclsHeadNode) {
            CNode* temp = m_pclsHeadNode;
            m_pclsHeadNode = m_pclsHeadNode->GetNextNode();
            delete temp;
        }
        m_pclsTailNode = nullptr;
    }

public:
    CQueue() {
        Initialize();
    }

    CQueue(const CQueue& clsOriginalToCopy) {
        Initialize();
        DeepCopy(clsOriginalToCopy);
    }

    ~CQueue() {
        CleanUp();
    }

    CQueue& operator=(const CQueue& clsOriginalToCopy) {
        if (this != &clsOriginalToCopy) {
            CleanUp();
            DeepCopy(clsOriginalToCopy);
        }
        return *this;
    }

    void Push(int intValue) {
        CNode* newNode = new CNode(intValue);
        if (IsEmpty()) {
            m_pclsHeadNode = newNode;
            m_pclsTailNode = newNode;
        }
        else {
            m_pclsTailNode->SetNextNode(newNode);
            m_pclsTailNode = newNode;
        }
    }

    int Pop() {
        if (IsEmpty()) {
            throw std::runtime_error("Queue is empty");
        }
        int value = m_pclsHeadNode->GetValue();
        CNode* temp = m_pclsHeadNode;
        m_pclsHeadNode = m_pclsHeadNode->GetNextNode();
        delete temp;
        if (m_pclsHeadNode == nullptr) {
            m_pclsTailNode = nullptr;
        }
        return value;
    }

    bool IsEmpty() const {
        return m_pclsHeadNode == nullptr;
    }

    void Print() const {
        CNode* current = m_pclsHeadNode;
        while (current) {
            std::cout << current->GetValue() << " ";
            current = current->GetNextNode();
        }
        std::cout << std::endl;
    }
};
