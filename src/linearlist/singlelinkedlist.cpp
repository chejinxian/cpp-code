#include "singlelinkedlist.h"

template <typename T>
SingleLinkedList<T>::SingleLinkedList()
: withHead(false),
  m_pointer(nullptr)
{

}

template <typename T>
SingleLinkedList<T>::SingleLinkedList(bool head)
: withHead(head),
  m_pointer(new Lnode)
{
    m_pointer->next=nullptr;
}

template <typename T>
SingleLinkedList<T>::~SingleLinkedList()
{
    Lnode * temp;
    while(m_pointer)
    {
        temp=m_pointer->next;
        delete m_pointer;
        m_pointer=temp;
    }
}

template <typename T>
bool SingleLinkedList<T>::GetElem(unsigned int i,T& e)
{
    Lnode * p;
    int j=1;
    if(withHead)
    {
        p=m_pointer->next;
        // while (p&&j<i)
        // {
        //     p=p->next;
        //     j++;
        // }
        // if(!p||j>i)
        // {
        //     return false;
        // }
        // e=p->data;
        // return true;      
    }
    else
    {
        p=m_pointer;
        // while(p&&j<i)
        // {
        //     p=p->next;
        //     j++;
        // }
        // if(!p||j>i)
        // {
        //     return false;
        // }
        // e=p->data;
        // return true; 
    }
    while (p&&j<i)
        {
            p=p->next;
            j++;
        }
        if(!p||j>i)
        {
            return false;
        }
        e=p->data;
        return true; 
}

template <typename T>
void * SingleLinkedList<T>::LocateElem(T e)
{
    Lnode * p;
    if(withHead)
    {
        p=m_pointer->next;
    }
    else
    {
        p=m_pointer;
    }
    // while(p)
    // {
    //     if(e==p->data)
    //     {
    //         return p;
    //     }
    //     p=p->next;
    // }
    // return nullptr;
    while(p&&e!=p->data)
    {
        p=p->next;
    }
    return (void *)p;
}

template <typename T>
bool SingleLinkedList<T>::Insert(unsigned int i, T e)
{
    Lnode * p=m_pointer;
    unsigned int j=0;
    if(withHead)
    {
        while(p&&j<(i-1))
        {
            p=p->next;
            j++;
        }
        if(!p||j>(i-1))
        {
            return false;
        }
        Lnode * s=new Lnode;
        s->next=p->next;
        p->next=s;
        s->deata=e;
        return true;    
    }
    else
    {
        if(i!=1)
        {
            while(p&&j<(i-1))
            {
                p=p->next;
                j++;
            }
            if(!p||j>(i-1))
            {
                return false;
            }
            Lnode * s=new Lnode;
            s->next=p->next;
            p->next=s;
            s->deata=e;
            return true;
        }
        else
        {
            Lnode * s=new Lnode;
            s->next=p;
            s->data=e;
            m_pointer=s;
            return true;
        }
    }
    
}

template <typename T>
bool SingleLinkedList<T>::Delete(unsigned int i)
{
    Lnode * p=m_pointer;
    Lnode * q;
    unsigned j=0;
    if(withHead)
    {
        while(p&&j<(i-1))
        {
            p=p->next;
            j++;
        }
        if(!(p->next)||j>(i-1))
        {
            return false;
        }
        q=p->next;
        p->next=q->next;
        delete q;
    }
    else
    {
        if(i!=1)
        {
            while(p&&j<(i-1))
            {
                p=p->next;
                j++;
            }
            if(!(p->next)||j>(i-1))
            {
                return false;
            }
            q=p->next;
            p->next=q->next;
            delete q;
        }
        else
        {
            m_pointer=p->next;
            delete p;
        }
    }
}

template <typename T>
void SingleLinkedList<T>::Clear()
{
    Lnode * p=m_pointer->next;
    Lnode * q;
    while(p)
    {
        q=p->next;
        delete p;
        p=q;
    }
    if(!withHead)
    {
        delete m_pointer;
    }
}

template <typename T>
bool SingleLinkedList<T>::IsEmpty()
{
    if(withHead)
    {
        if(m_pointer->next)
        {
            return false;
        }
        else
        {
            return true;
        }
    }
    else
    {
        if(m_pointer)
        {
            return false;
        }
        else
        {
            return true;
        }
    }
}

template <typename T>
void SingleLinkedList<T>::CreatList_H(T &elem, unsigned int n)
{
    if(!IsEmpty())
    {
        return;
    }
    for(unsigned int i=n;i>0;i--)
    {
        Lnode * s;
        s->data=elem[i-1];
        if(withHead)
        {
            s->next=m_pointer->next->next;
            m_pointer->next=s;
        }
        else
        {
            s->next=m_pointer->next;
            m_pointer=s;
        }
    }
}

template <typename T>
void SingleLinkedList<T>::CreatList_R(T &elem, unsigned int n)
{
    if(!IsEmpty())
    {
        return;
    }
    Lnode * rear;
    if(withHead)
    {
        rear=m_pointer;
    }
    else
    {
        rear->next=m_pointer;
    }
    for(unsigned int i=0;i<n;i++)
    {
        Lnode * s=new Lnode;
        s->data=elem[i];
        s->next=nullptr;
        rear->next=s;
        rear=s;
    }
}