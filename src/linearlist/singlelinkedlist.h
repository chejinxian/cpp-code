#ifndef SINGLELINKEDLIST_H
#define SINGLELINKEDLIST_H

template<typename T>
class SingleLinkedList
{
private:
    typedef struct Lnode
    {
        T data;
        struct Lnode * next;
    }Lnode;
    bool withHead;
    Lnode * m_pointer;
    // T data;
    // SingleLinkedList * next;
    
public:
    SingleLinkedList(/* args */);
    SingleLinkedList(bool head);
    ~SingleLinkedList();
    void Clear();
    bool IsEmpty();
    unsigned int GetLength();
    bool GetElem(unsigned int i, T &e);
    void * LocateElem(T e);
    bool Insert(unsigned int i, T e);
    bool Delete(unsigned int i);
    void CreatList_H(T &elem, unsigned int n);
    void CreatList_R(T &elem, unsigned int n);
};

#endif