#include "sequenatiallist.h"

template <typename T>
SequenatialList<T>::SequenatialList(/* args */)
: m_listLength(0),
  m_data(new T[MAXLENGTH])
{
}

template <typename T>
SequenatialList<T>::~SequenatialList()
{
    delete[] m_data;
}

template <typename T>
void SequenatialList<T>::Clear()
{
    m_listLength=0;
}

template <typename T>
bool SequenatialList<T>::IsEmpty()
{
    if(m_listLength)
    {
        return false;
    }
    return true;
}

template <typename T>
unsigned int SequenatialList<T>::GetLength()
{
    return m_listLength;
}

template <typename T>
bool SequenatialList<T>::GetElem(unsigned int i,T& e)
{
    if(i<1||i>=m_listLength)
    {
        return false;
    }
    e=m_data[i-1];
    return true;
}

template <typename T>
unsigned int SequenatialList<T>::LocateElem(T e)
{
    for(unsigned int i=0;i<m_listLength;i++)
    {
        if(m_data[i]==e)
        {
            return i+1;
        }
    }
    return 0;
}

template <typename T>
bool SequenatialList<T>::Insert(unsigned int i,T e)
{
    if(i<1||i>m_listLength+1)
    {
        return false;
    }
    if(m_listLength==MAXLENGTH)
    {
        return false;
    }
    for(int j=m_listLength;j>=i;j--)
    {
        m_data[j]=m_data[j-1];
    }
    m_data[i-1]=e;
    m_listLength++;
    return true;
}

template <typename T>
bool SequenatialList<T>::Delete(unsigned int i)
{
    if(i<=1||i>m_listLength)
    {
        return false;
    }
    for(int j=i;j<m_listLength;j++)
    {
        m_data[j-1]=m_data[j];
    }
    m_listLength--;
    return true;
}