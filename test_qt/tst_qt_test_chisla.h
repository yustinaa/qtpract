#ifndef TST_QT_TEST_CHISLA_H
#define TST_QT_TEST_CHISLA_H

#include "chisla.h"
#include <QtTest/QTest>

class Qt_test_chisla : public QObject
{
    Q_OBJECT

public:
    Qt_test_chisla() = default;
    ~Qt_test_chisla() = default;

private slots:
    void test_case1();
    void test_nod();
    void test_nok();
    void test_prime();
    void test_arm();
    //test data
    void test_nod_data();
    void test_nok_data();
    void test_prime_data();
    void test_arm_data();

private:
    Chisla A;
    Chisla B;
};

#endif // TST_QT_TEST_CHISLA_H
