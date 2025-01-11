#pragma once
#ifndef CQUEUE_H
#define CQUEUE_H

#include "CNode.h"

class CQueue {
private:
    CNode* m_pclsHeadNode;
    CNode* m_pclsTailNode;

    void Initialize();
    void DeepCopy(const CQueue& clsOriginalToCopy);
    void CleanUp();

public:
    CQueue();
    CQueue(const CQueue& clsOriginalToCopy);
    ~CQueue();
    CQueue& operator=(const CQueue& clsOriginalToCopy);

    void Push(int intValue);
    int Pop();
    bool IsEmpty() const;
    void Print() const;
};

#endif // CQUEUE_H
