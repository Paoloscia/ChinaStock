#ifndef DEEPPOINTER_H
#define DEEPPOINTER_H

template <class T>
class deepPointer{
private:
    T* pted;
public:
    deepPointer(T* =nullptr);
    deepPointer(const deepPointer&);
    deepPointer& operator=(const deepPointer&);
    T* operator->() const;
    ~deepPointer();
    bool operator==(const deepPointer&) const;
    bool operator!=(const deepPointer&) const;
    bool operator>(const deepPointer&) const;
    bool operator<(const deepPointer&) const;
    operator T*() const;

};

template <class T>
deepPointer<T>::deepPointer(T* itm): pted(itm){}

template <class T>
deepPointer<T>::deepPointer(const deepPointer& dptr){
      if(!dptr)
          pted=nullptr;
      else
          pted=dptr.pted->clone();
}

template <class T>
deepPointer<T>& deepPointer<T>::operator=(const deepPointer& dptr){
        if(this != &dptr){
            if(pted)
                delete pted;
            pted = dptr.pted->clone();
    }
    return *this;
}

template <class T>
T* deepPointer<T>::operator->() const{
       return pted;
}

template <class T>
deepPointer<T>::~deepPointer(){
    if(pted)
        delete pted;
}

template <class T>
bool deepPointer<T>::operator==(const deepPointer& dptr) const{
    return *pted==*(dptr.pted);
}

template <class T>
bool deepPointer<T>::operator!=(const deepPointer& dptr) const{
    return *pted!=*(dptr.pted);
}

template<class T>
bool deepPointer<T>::operator<(const deepPointer& dptr) const{
    return *pted<*(dptr.pted);
}

template<class T>
bool deepPointer<T>::operator>(const deepPointer& dptr) const{
    return *pted>*(dptr.pted);
}

template<class T>
deepPointer<T>::operator T *() const
{
    return pted;
}

#endif
