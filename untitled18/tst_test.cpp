#include <QtTest>
#include "../zadacha1/zadacha/functions.h"
#include "qtestcase.h"
// add necessary includes here

class test : public QObject
{
    Q_OBJECT

public:
    test();
    ~test();

private slots:
    void initTestCase();
    void cleanupTestCase();

    void test_case1();
    void test_case2();
    void test_case3();
};

test::test() {}

test::~test() {}

void test::initTestCase() {}

void test::cleanupTestCase() {}
int counter(QVector <int> a) {
    int pr=1;
    for(int i=0; i<a.size(); i++) pr=pr*a[i];
    return pr;
}
void test::test_case1() {

    Functions a;
    QVector <int> k={2, 3, 5};
    QVector <int> l={2,2,2,2,2,2};

    QCOMPARE(a.checkPrimary(11), {});
    QCOMPARE(a.checkPrimary(30), k);
    QCOMPARE(a.checkPrimary(64), l);
    QVERIFY(2000000000==counter(a.checkPrimary(2000000000)));

}
void test::test_case2() {

    Functions a;
    float x=-1000, y=0.74, z=0.524;
    double epsilon=0.01;

    double expected = std::sin(x);
    double result = a.Sin(x, epsilon);

    QVERIFY(std::fabs(result - expected) < epsilon);
    expected = std::sin(y);
    result = a.Sin(y, epsilon);
    QVERIFY(std::fabs(result - expected) < epsilon);
    expected = std::sin(z);
    result = a.Sin(z, epsilon);
    QVERIFY(std::fabs(result - expected) < epsilon);

}
bool equat(double a1, double a2, double a3, QVector<double> vec) {
    if(a1*vec[0]*vec[0] + a2*vec[0] + a3 == 0 && a1*vec[1]*vec[1] + a2*vec[1] + a3 == 0) return true;
    else return false;
}
void test::test_case3() {
    Functions a;
    double a1=1.0, a2=3.0, a3=-4.0;
    QVERIFY(equat(a1,a2,a3, a.solveQuadratic(a1,a2,a3)));

}


QTEST_APPLESS_MAIN(test)

#include "tst_test.moc"
