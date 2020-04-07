#ifndef CONTAINER_H
#define CONTAINER_H

template <class T>


#endif // CONTAINER_H

class Container {
private:
    class nodo {
    private:
        friend class Container<T>;
        nodo(const T&, nodo* = nullptr);
        T info;
        nodo* next;
        ~nodo(); // ridefiniamo il distruttore
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

    class Iteratore{

    };
};
