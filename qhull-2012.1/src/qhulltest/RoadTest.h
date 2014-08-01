/****************************************************************************
**
** Copyright (c) 2008-2012 C.B. Barber. All rights reserved.
** $Id$$Change: 1490 $
** $Date: 2012/02/19 $$Author: bbarber $
**
****************************************************************************/

#ifndef ROADTEST_H
#define ROADTEST_H

//pre-compiled with RoadTest.h
#include <QObject>    // Qt C++ Framework
#include <QtTest/QtTest>

#define QHULL_USES_QT 1

namespace orgQhull {

#//!\name Defined here

    //! RoadTest -- Generic test for Qt's QTest
    class RoadTest;
    //! TESTadd_(t) -- Add a RoadTest

/** Test Name objects using Qt's QTestLib

Template:

class Name_test : public RoadTest
{
    Q_OBJECT
#//Test slot
private slots:
    void t_name();
    //Executed before any test
    void initTestCase();
    void init();          // Each test
    //Executed after each test
    void cleanup(); //RoadTest::cleanup();
    // Executed after last test
    void cleanupTestCase();
};

void
add_Name_test()
{
    new Name_test();
}

Send additional output to cout
*/

class RoadTest : public QObject
{
    Q_OBJECT

#//!\name Class globals
protected:
    static QList<RoadTest *>
                        s_testcases; ///! List of testcases to execute.  Initialized via add_...()
    static int          s_test_count; ///! Total number of tests executed
    static int          s_test_fail; ///! Number of failed tests
    static QStringList  s_failed_tests; ///! List of failed tests

#//!\name Test slots
public slots:
    void cleanup();

public:
#//!\name Constructors, etc.
    RoadTest()  { s_testcases.append(this); }
    ~RoadTest() { s_testcases.removeAll(this); }

#//Helper
    void                recordFailedTest();


#//!\name Class functions
    static int          runTests(QStringList arguments);

};//RoadTest

#define TESTadd_(t) extern void t(); t();


}//orgQhull

namespace QTest{

template<>
inline char *
toString(const std::string &s)
{
    return qstrdup(s.c_str());
}

}//namespace QTest

#endif //ROADTEST_H

