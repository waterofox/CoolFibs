#ifndef FIBSCOUNTER_H
#define FIBSCOUNTER_H
#include <QObject>

class fibsCounter : public QObject
{
    Q_OBJECT
private:
    int _null_n = 0;
    int _first_n = 0;
    int _to_n = 0;
public:
    fibsCounter(const int null_n,const int first_n, const int to_n);
    int count();
    int count_reset(const int null_n, const int first_n, const int to_n);
    ~fibsCounter();
};

#endif // FIBSCOUNTER_H
