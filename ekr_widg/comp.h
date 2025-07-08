#ifndef COMP_H
#define COMP_H
#include<algorithm>
#include <QTextStream>
#include <QDataStream>
#include <QFile>
struct Comp
{
    QString Name;
    QString Section;
    int Price;
    friend QTextStream& operator>>(QTextStream& in, Comp& X)
    {
        X.Name = in.readLine();
        X.Section = in.readLine();
        in>>X.Price;
        in.readLine();
        return in;
    }
    friend QTextStream& operator<<(QTextStream& out, Comp& X) {
        out << X.Name << " " << X.Section << " " << X.Price<<"\n";
        return out;
    }
    friend bool operator == (Comp& a, Comp& b)
    {

        return a.Name==b.Name;
    }
    friend bool operator <(Comp& a, Comp& b)
    {

        return a.Name<b.Name;
    }
};
struct Bag
{
    int Num;
    QString Section;
    QString Name;
    friend QTextStream& operator>>(QTextStream& in, Bag& X) {
        X.Name = in.readLine(); // читать всю строку полностью
        in>>X.Num;
        in.readLine();
        X.Section = in.readLine();
        return in;
    }
    friend QTextStream& operator<<(QTextStream& out, Bag& X) {
        out << X.Name<< " " << X.Num << " " << X.Section<<"\n";
        return out;
    }
    friend bool operator == (Bag&a, Bag& b)
    {
        return a.Name==b.Name;
    }
    friend bool operator <(Bag& a, Bag& b)
    {

        return a.Name<b.Name;
    }
};
template<typename TT>
struct Comp_name {//в обратном алфавитном порядке
    bool operator()(const TT& a, const TT& b) const
    {
        return a.Name > b.Name;
    }
};
template<typename T1>
struct Comp_sec {//секции  алфавитном порядке, внутри - обратный
    bool operator()(const T1& a, const T1& b) const
    {
        if (a.Section == b.Section)
        {
            return a.Name > b.Name; // внутри секции
        }
        return a.Section < b.Section; // секции по алфавиту

    }
};
template <class T>
class COMP
{    int n;
    T *A;
public:
    COMP (): n(0), A(nullptr){}
    COMP(int n_): n(n_), A(new T[n_])
    {}
    ~COMP()
    {delete[] A;}
    COMP(const COMP &s2) : n(s2.n), A(new T[s2.n]) {
        for (int i=0; i<s2.n; i++)
        {A[i]=s2.A[i];}
    }

    COMP &operator=(const COMP &s) {
        if (this != &s) {
            delete[] A;
            n = s.n;
            A = new T[n];
            for (int i=0; i<s.n; i++)
            {A[i]=s.A[i];}
        }
        return *this;
    }
    COMP  (COMP && moved) noexcept : n(moved.n), A(moved.A)
    {
        moved.n = 0;
        moved.A= nullptr;
    }
    COMP & operator=(COMP && moved) noexcept
    {
        if (this!= &moved)
        {
            delete [] A;
            n=moved.n;
            A=moved.A;
            moved.n = 0;
            moved.A= nullptr;}
        return *this;
    }
    int GetCount () const
    {return n;}

    T& operator[](int index) const
    {return A[index];}
    T& at(int index)
    { return A[index]; }
    void clear()
    {
        delete[] A;
        n = 0;
        A = nullptr; // нач размер по умолчанию
    }
    friend QTextStream& operator<<(QTextStream& out,const COMP& s)
    {
        out << s.n << "\n";
        for (int i = 0; i < s.n; ++i)
            out << s.A[i];
        out << "\n";
        return out;

    }

    friend QTextStream& operator>>(QTextStream& in, COMP& s)
    {
        in >> s.n;
        in.readLine();
        delete[] s.A;//освобождаем память дин массива если он уже был создан ранее
        s.A = new T[s.n];
        for (int i = 0; i < s.n; i++)
            in >> s.A[i];
        std::sort(s.A, s.A + s.n);
        return in;
    }
    void sort_alf()//сортировка в алфавитном порядке
    {
        std::sort(A, A + n,Comp_name<T>());
    }
    void sort_sec()//названия секций в алфавитном порядке, внутри - обратный алфавитный
    {
        std::sort(A, A + n,Comp_sec<T>());
    }
    T& find_obj(const QString& a)
    {    for (int i = 0; i < n; ++i)
        {
            if (A[i].Name == a)
            {
                return A[i];
            }
        }
        throw ("item not found");

    }

    friend COMP operator + (const COMP &x, const COMP &y)//объединение
    {
        int i=0, k=0, j=0;
        COMP z(x.n+y.n);
        while(i<x.n&&j<y.n)
        {
            if(x.A[i]<y.A[j])
            {z.A[k++]=x.A[i++];}
            else if (y.A[j]<x.A[i])
            {z.A[k++]=y.A[j++];}
            else {
                z.A[k++]=y.A[j++];
                i++;
            }
        }
        while (i<x.n)
        {z.A[k++]=x.A[i++];}
        while (j<y.n)
        {z.A[k++]=y.A[j++];}
        z.n=k;
        std::sort(z.A, z.A + z.n);
        return z;
    }
};

#endif // COMP_H
