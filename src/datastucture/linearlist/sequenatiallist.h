#define MAXLENGTH 500


template <typename T>
class SequenatialList
{
private:
    T m_data[MAXLENGTH];
    unsigned int m_listLength;
public:

//  methods
    SequenatialList(/* args */);
    ~SequenatialList();


    void Clear();
    bool IsEmpty();
    unsigned int GetLength();
    bool GetElem(unsigned int i, T& e);
    unsigned int LocateElem(T e);
    bool Insert(unsigned int i, T e);
    bool Delete(unsigned int i);
    
// public:

//  variable
    // T m_data[MAXLENGTH];
    // unsigned int m_listLength;
};

