#include <gtest/gtest.h>
#include <memory>
#include <cmath>
#include <sstream>

#include <Point.h>
#include <Figure.h>
#include <Pentagon.h>
#include <Rhombus.h>
#include <Trapezoid.h>

class PointTest : public ::testing::Test {
protected:
    void SetUp() override {}
    void TearDown() override {}
};

TEST_F(PointTest, DefaultConstructor) {
    Point<double> p;
    EXPECT_DOUBLE_EQ(p.coordinate_x, 0.0);
    EXPECT_DOUBLE_EQ(p.coordinate_y, 0.0);
}

TEST_F(PointTest, ParameterizedConstructor) {
    Point<double> p(3.5, 2.1);
    EXPECT_DOUBLE_EQ(p.coordinate_x, 3.5);
    EXPECT_DOUBLE_EQ(p.coordinate_y, 2.1);
}

TEST_F(PointTest, EqualityOperator) {
    Point<double> p1(1.0, 2.0);
    Point<double> p2(1.0, 2.0);
    Point<double> p3(1.0, 3.0);
    
    EXPECT_TRUE(p1 == p2);
    EXPECT_FALSE(p1 == p3);
}

TEST_F(PointTest, InequalityOperator) {
    Point<double> p1(1.0, 2.0);
    Point<double> p2(1.0, 3.0);
    
    EXPECT_TRUE(p1 != p2);
    EXPECT_FALSE(p1 != p1);
}

TEST_F(PointTest, StreamOutput) {
    Point<double> p(1.5, 2.5);
    std::ostringstream oss;
    oss << p;
    
    std::string output = oss.str();
    EXPECT_TRUE(output.find("1.5") != std::string::npos);
    EXPECT_TRUE(output.find("2.5") != std::string::npos);
}

TEST_F(PointTest, StreamInput) {
    Point<double> p;
    std::istringstream iss("3.14 2.71");
    iss >> p;
    
    EXPECT_DOUBLE_EQ(p.coordinate_x, 3.14);
    EXPECT_DOUBLE_EQ(p.coordinate_y, 2.71);
}

class FigureTest : public ::testing::Test {
protected:
    void SetUp() override {}
    void TearDown() override {}
};

TEST_F(FigureTest, PentagonDefaultConstructor) {
    Pentagon<double> pentagon;
    EXPECT_NO_THROW(pentagon.calculateArea());
    EXPECT_NO_THROW(pentagon.calculateCenter());
}

TEST_F(FigureTest, PentagonAreaCalculation) {
    Pentagon<double> pentagon;
    double area = pentagon.calculateArea();
    
    EXPECT_FALSE(std::isnan(area));
    EXPECT_FALSE(std::isinf(area));
    EXPECT_GE(area, 0.0);
}

TEST_F(FigureTest, PentagonCenterCalculation) {
    Pentagon<double> pentagon;
    Point<double> center = pentagon.calculateCenter();
    
    EXPECT_FALSE(std::isnan(center.coordinate_x));
    EXPECT_FALSE(std::isnan(center.coordinate_y));
    EXPECT_FALSE(std::isinf(center.coordinate_x));
    EXPECT_FALSE(std::isinf(center.coordinate_y));
}

TEST_F(FigureTest, RhombusDefaultConstructor) {
    Rhombus<double> rhombus;
    EXPECT_NO_THROW(rhombus.calculateArea());
    EXPECT_NO_THROW(rhombus.calculateCenter());
}

TEST_F(FigureTest, RhombusAreaCalculation) {
    Rhombus<double> rhombus;
    double area = rhombus.calculateArea();
    
    EXPECT_FALSE(std::isnan(area));
    EXPECT_FALSE(std::isinf(area));
    EXPECT_GE(area, 0.0);
}

TEST_F(FigureTest, TrapezoidDefaultConstructor) {
    Trapezoid<double> trapezoid;
    EXPECT_NO_THROW(trapezoid.calculateArea());
    EXPECT_NO_THROW(trapezoid.calculateCenter());
}

TEST_F(FigureTest, FigureEquality) {
    Pentagon<double> pentagon1({Point<double>(0,0), Point<double>(1,0), 
                               Point<double>(1,1), Point<double>(0,1), Point<double>(0.5,1.5)});
    Pentagon<double> pentagon2({Point<double>(0,0), Point<double>(1,0), 
                               Point<double>(1,1), Point<double>(0,1), Point<double>(0.5,1.5)});
    
    EXPECT_TRUE(pentagon1 == pentagon2);
}

TEST_F(FigureTest, FigureInequality) {
    Pentagon<double> pentagon1({Point<double>(0,0), Point<double>(1,0), 
                               Point<double>(1,1), Point<double>(0,1), Point<double>(0.5,1.5)});
    Pentagon<double> pentagon2({Point<double>(0,0), Point<double>(2,0), 
                               Point<double>(2,2), Point<double>(0,2), Point<double>(1,3)});
    
    EXPECT_TRUE(pentagon1 != pentagon2);
}

TEST_F(FigureTest, StreamOutputOperator) {
    Pentagon<double> pentagon;
    std::ostringstream oss;
    oss << pentagon;
    std::string output = oss.str();
    
    EXPECT_FALSE(output.empty());
    EXPECT_TRUE(output.find('(') != std::string::npos);
}

TEST_F(FigureTest, PentagonValidInitialization) {
    EXPECT_NO_THROW({
        Pentagon<double> pentagon({
            Point<double>(0,0), Point<double>(1,0), 
            Point<double>(1,1), Point<double>(0,1), 
            Point<double>(0.5,1.5)
        });
    });
}

TEST_F(FigureTest, PentagonInvalidInitialization) {
    EXPECT_THROW({
        Pentagon<double> pentagon({
            Point<double>(0,0), Point<double>(1,0), 
            Point<double>(1,1)  // Только 3 точки вместо 5
        });
    }, std::invalid_argument);
}

TEST_F(FigureTest, RhombusValidInitialization) {
    EXPECT_NO_THROW({
        Rhombus<double> rhombus({
            Point<double>(0,0), Point<double>(1,1), 
            Point<double>(2,0), Point<double>(1,-1)
        });
    });
}

TEST_F(FigureTest, RhombusInvalidInitialization) {
    EXPECT_THROW({
        Rhombus<double> rhombus({
            Point<double>(0,0), Point<double>(1,1), 
            Point<double>(2,0)  // Только 3 точки вместо 4
        });
    }, std::invalid_argument);
}

TEST_F(FigureTest, TrapezoidValidInitialization) {
    EXPECT_NO_THROW({
        Trapezoid<double> trapezoid({
            Point<double>(0,0), Point<double>(4,0), 
            Point<double>(3,2), Point<double>(1,2)
        });
    });
}

TEST_F(FigureTest, TrapezoidInvalidInitialization) {
    EXPECT_THROW({
        Trapezoid<double> trapezoid({
            Point<double>(0,0), Point<double>(4,0), 
            Point<double>(3,2)  // Только 3 точки вместо 4
        });
    }, std::invalid_argument);
}