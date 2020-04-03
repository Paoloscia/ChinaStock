#ifndef DATA_H
#define DATA_H


class Data{
public:
    Data(unsigned int = 0, unsigned int = 0, unsigned int = 0);
    int Giorno() const;
    int Mese() const;
    int Anno() const;
private:
    int giorno;
    int mese;
    int anno;
};

#endif // DATA_H
