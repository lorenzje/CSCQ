#pragma once
#ifndef CNODE_H
#define CNODE_H

class CNode {
private:
    int m_intValue;
    CNode* m_pclsNextNode;

protected:
    void Initialize();
    void CleanUp();

public:
    CNode();
    CNode(int intValue);
    CNode(int intValue, CNode* pclsNextNode);
    CNode(const CNode& clsOriginalToCopy);
    ~CNode();
    CNode& operator=(const CNode& clsOriginalToCopy);

    void SetValue(int intNewValue);
    int GetValue() const;

    void SetNextNode(CNode* pclsNextNode);
    CNode* GetNextNode() const;
};

#endif // CNODE_H
