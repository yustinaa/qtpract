#ifndef CHISLA_H
#define CHISLA_H
#include <QCoreApplication>
#include <cmath>
using namespace std;
class Chisla
{   int x;
public:
    Chisla() : x(0) {}
    Chisla(int a) : x(a) {}
    Chisla &operator = (const Chisla &oth)
    {if (this!=&oth)
        {x=oth.x;}
        return *this;
    }
    int nod1(Chisla& y)
    {int x1 = abs(x), y1 = abs(y.x);
        while (x1 != 0 && y1 != 0)
        {
            if (x1 > y1) x1 %= y1;

            else y1 %= x1;
        }
        return x1 + y1;
    }
    long long nok1(Chisla& y)  {
        if (x == 0 || y.x == 0) return 0;
        return (long long)abs(x) * abs(y.x) / nod1(y);
    }
    unsigned int count_cifres(unsigned int x)
    {
        unsigned int res = 0;
        if (x == 0)
        {
            res = 1;
            return res;
        }
        while (x != 0)
        {
            x /= 10;
            res++;
        }
        return res;
    }
    bool is_Armstrong()
    {
        bool res = false;
        unsigned int k = count_cifres(x);
        unsigned int sum = 0, z = x;
        while (x != 0)
        {
            unsigned int ost;
            ost = x % 10;
            ost = pow(ost, k);
            sum += ost;
            x /= 10;
        }
        if (sum == z)
            res = true;
        return res;
    }
    bool isPrime() const
    {
        unsigned long n = abs(x);
        if (n == 2) return true;
        if (n == 0 || n == 1 || n % 2 == 0) return false;

        for (unsigned long i = 3; i * i <= n; i += 2)
        {
            if (n % i == 0) return false;
        }
        return true;
    }

    friend QTextStream& operator<<(QTextStream& out, const Chisla& num) {
        out << num.x;
        return out;
    }

    friend QTextStream& operator>>(QTextStream& in, Chisla& num) {
        in >> num.x;
        return in;
    }
};

#endif // CHISLA_H
