#pragma once
#ifndef CSTACK_H
#define CSTACK_H

#include "CNode.h"

class CStack {
private:
    CNode* m_pclsHeadNode;

    void Initialize();
    void DeepCopy(const CStack& clsOriginalToCopy);
    void CleanUp();

public:
    CStack();
    CStack(const CStack& clsOriginalToCopy);
    ~CStack();
    CStack& operator=(const CStack& clsOriginalToCopy);

    void Push(int intValue);
    int Pop();
    bool IsEmpty() const;
    void Print() const;
};

#endif // CSTACK_H
