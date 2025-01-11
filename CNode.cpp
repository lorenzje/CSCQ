#include <iostream>
#include "CNode.h"
#pragma once
using namespace std;
class CNode {
private:
    int m_intValue;
    CNode* m_pclsNextNode;

    void ShallowCopy(const CNode& clsOriginalToCopy)
    {
        m_intValue = clsOriginalToCopy.m_intValue;
        m_pclsNextNode = clsOriginalToCopy.m_pclsNextNode;
    }

protected:
    void Initialize() 
    {
        m_intValue = 0;
        m_pclsNextNode = nullptr;
    }

    void CleanUp() 
    {
        // No dynamic memory allocated, so no cleanup needed
    }

public:
    CNode() 
    {
        Initialize();
    }

    CNode(int intValue) : m_intValue(intValue), m_pclsNextNode(nullptr) {}

    CNode(int intValue, CNode* pclsNextNode) : m_intValue(intValue), m_pclsNextNode(pclsNextNode) {}

    CNode(const CNode& clsOriginalToCopy) 
    {
        ShallowCopy(clsOriginalToCopy);
    }

    ~CNode() 
    {
        CleanUp();
    }

    CNode& operator=(const CNode& clsOriginalToCopy) 
    {
        if (this != &clsOriginalToCopy)
        {
            CleanUp();
            ShallowCopy(clsOriginalToCopy);
        }
        return *this;
    }

    void SetValue(int intNewValue) 
    {
        m_intValue = intNewValue;
    }

    int GetValue() const 
    {
        return m_intValue;
    }

    void SetNextNode(CNode* pclsNextNode)
    {
        m_pclsNextNode = pclsNextNode;
    }

    CNode* GetNextNode() const 
{
        return m_pclsNextNode;
    }
};
