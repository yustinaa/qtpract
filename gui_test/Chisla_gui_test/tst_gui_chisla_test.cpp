#include <QtTest>
#include <QLineEdit>
#include <QComboBox>
#include <QPushButton>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QApplication>

class gui_chisla_test : public QObject
{
    Q_OBJECT

public:
    gui_chisla_test();
    ~gui_chisla_test();

private slots:
    void test_case1();
    void test_valInput_data();
    void test_valInput();
    void test_ui_elements_exist(); // Новый тест для проверки элементов UI
    void initTestCase();
};

gui_chisla_test::gui_chisla_test() {}

gui_chisla_test::~gui_chisla_test() {}

void gui_chisla_test::initTestCase()
{
    int argc = 0;
    char *argv[] = {nullptr};
    static QApplication app(argc, argv);  // Статический объект
}

void gui_chisla_test::test_case1() {}

void gui_chisla_test::test_valInput_data()
{
    QTest::addColumn<QTestEventList>("inputEvents1");
    QTest::addColumn<QTestEventList>("inputEvents2");
    QTest::addColumn<bool>("expected");
    //числа
    QTestEventList valid1;
    valid1.addKeyClicks("123");
    QTestEventList valid2;
    valid2.addKeyClicks("456");
    QTest::newRow("valid numbers") << valid1 << valid2 << true;
    //(буквы + числа)
    QTestEventList invalid1;
    invalid1.addKeyClicks("abc");
    QTestEventList invalid2;
    invalid2.addKeyClicks("456");
    QTest::newRow("invalid first input") << invalid1 << invalid2 << false;
}

void gui_chisla_test::test_valInput()
{
    QFETCH(QTestEventList, inputEvents1);
    QFETCH(QTestEventList, inputEvents2);
    QFETCH(bool, expected);
    MainWindow w;
    w.show();
    //симуляция ввода данных
    inputEvents1.simulate(w.ui->lineEdit);
    inputEvents2.simulate(w.ui->lineEdit_2);
    //проверка валидности через оригинальную функцию
    bool isValid = w.val_Input();
    // сравнение с ожидаемым результатом
    QCOMPARE(isValid, expected);
}

// проверка наличия и элементов ui
void gui_chisla_test::test_ui_elements_exist()
{
    MainWindow w;
    w.show();

    // созданы ли нужные объекты
    QVERIFY2(w.ui->lineEdit != nullptr, "lineEdit не создан!");
    QVERIFY2(w.ui->lineEdit_2 != nullptr, "lineEdit_2 не создан!");
    QVERIFY2(w.ui->lineEdit_3 != nullptr, "lineEdit_3 (результат) не создан!");
    QVERIFY2(w.ui->pushButton != nullptr, "pushButton не создан!");
    QVERIFY2(w.ui->comboBox_3 != nullptr, "comboBox_3 не создан!");
}

QTEST_APPLESS_MAIN(gui_chisla_test)

#include "tst_gui_chisla_test.moc"
