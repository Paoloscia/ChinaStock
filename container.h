#ifndef CONTAINER_H
#define CONTAINER_H
#include <string>
template <class T>


#endif // CONTAINER_H

class Container {
    //friend class Iteratore;
private:
    class nodo {
    private:
        friend class Container<T>; // DA VEDERE!!!
        nodo(const T&, nodo* = nullptr);
        T info;
        nodo* next;
        void distruggi();

    };
    static void eliminaNodo(); //CAPIRE MEGLIO STATICI, CONTROLLARE!!!!!!!!
    nodo* primo, *ultimo;
    //nodo *copia(const nodo*);
    //nodo *lastNode(const nodo*);
public:
    Container();
    Container(const Container&);
    ~Container();
    Container& operator=(const Container&);
    bool operator==(const Container<T>&) const;
    bool operator!=(const Container<T>&) const;

    void aggiungi(const T&);


    class constIteratore
       {
           friend Container<T>;
       private:
           const nodo* puntatore;
           constIteratore(nodo*);
       public:
           constIteratore();
           constIteratore& operator=(const constIteratore&);
           constIteratore& operator++();
           constIteratore& operator++(int);
           const T& operator*() const;
           const T* operator->() const;
           bool operator==(const constIteratore&);
           bool operator!=(const constIteratore&);
       };


    class Iteratore{
    friend class Container;
    private:
    nodo * puntatore;
    //bool pte;
    Iteratore(nodo *); //bool=false
    public:
    Iteratore();
    Iteratore &operator++();
    Iteratore &operator++(int);
    const T &operator*() const;
    const T *operator->() const;
    bool operator==(const Iteratore &) const;
    bool operator!=(const Iteratore &) const;

    };
    constIteratore inizio() const;
    constIteratore fine() const;
    //T& front() const; -> ritorno il primo con tipo T->info
    //T& back() const; -> ritorno l'ultimo con tipo T->info
    Iteratore inizio();
    Iteratore fine();
    void rimuovi(const T&);
    void rimuovi_s(std::string); //DA RIVEDERE!!!
    Iteratore cerca(const T&);
    Iteratore cerca_s(std::string); // DA RIVEDERE!!!
    constIteratore cerca(const T&) const;
    constIteratore cerca_s(std::string) const; //DA RIVEDERE!!!
};

//-------------------------------------IMPLEMENTAZIOONE METODI--------------------------

template <class T>
Container<T>::nodo::nodo(const T& obj, nodo* n) : info(obj), next(n) {}

template<class T>
void Container<T>::nodo::distruggi()
{
    if (next) next->distruggi();
    delete this;
}
