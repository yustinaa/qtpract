#include "tst_qt_test_chisla.h"

void Qt_test_chisla::test_case1()
{}
void Qt_test_chisla::test_nod_data()
{
    QTest::addColumn<int>("a");
    QTest::addColumn<int>("b");
    QTest::addColumn<int>("result");

    QTest::newRow("all 0") << 0 << 0 << 0;
    QTest::newRow("10 & 1, nod 1") << 10 << 1 << 1;
    QTest::newRow("7 & 5, nod 1") << 7 << 5 << 1;
}
void Qt_test_chisla::test_nok_data()
{
    QTest::addColumn<int>("a");
    QTest::addColumn<int>("b");
    QTest::addColumn<int>("result");

    QTest::newRow("all 0") << 0 << 0 << 0;
    QTest::newRow("1 & 10, nok 10") << 10 << 1 << 10;
    QTest::newRow("7 & 5, nok 35") << 7 << 5 << 35;
}
void Qt_test_chisla::test_prime_data()
{
    QTest::addColumn<int>("a");
    QTest::addColumn<int>("result");

    QTest::newRow("all 0") << 0 << 0;
    QTest::newRow("10 is not prime") << 10 << 0;
    QTest::newRow("7 is prime") << 7 << 1;
}
void Qt_test_chisla::test_arm_data()
{
    QTest::addColumn<int>("a");
    QTest::addColumn<int>("result");
    QTest::newRow("153 is Armstrong") << 153 << 1;
    QTest::newRow("10 is not Armstrong") << 10 << 0;
    QTest::newRow("0 is not Armstrong") << 0 << 1;
}
void Qt_test_chisla::test_nod()
{
    QFETCH(int, a);
    QFETCH(int, b);
    QFETCH(int, result);
    A = Chisla(a);
    B = Chisla(b);
    QCOMPARE(A.nod1(B), result);
}
void Qt_test_chisla::test_nok()
{
    // retrieve data
    QFETCH(int, a);
    QFETCH(int, b);
    QFETCH(int, result);

    A = Chisla(a);
    B = Chisla(b);
    QCOMPARE(A.nok1(B), result);

}
void Qt_test_chisla::test_prime()
{
    // retrieve data
    QFETCH(int, a);
    QFETCH(int, result);

    A = Chisla(a);
    QCOMPARE(A.isPrime(), result);


}
void Qt_test_chisla::test_arm()
{
    // retrieve data
    QFETCH(int, a);
    QFETCH(int, result);

    A = Chisla(a);
    QCOMPARE(A.is_Armstrong(), result);

}
QTEST_APPLESS_MAIN(Qt_test_chisla)

//#include "tst_qt_test_chisla.moc"
