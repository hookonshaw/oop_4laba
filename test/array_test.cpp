#include <gtest/gtest.h>
#include <Array.h>

class ArrayTest : public ::testing::Test {
protected:
    void SetUp() override {}

    void TearDown() override {}
};

TEST_F(ArrayTest, DefaultConstructor) {
    Array<int> arr;
    EXPECT_EQ(arr.getSize(), 0);
    EXPECT_GE(arr.getCapacity(), 1);
}

TEST_F(ArrayTest, SizeConstructor) {
    Array<int> arr(5);
    EXPECT_EQ(arr.getSize(), 5);
}

TEST_F(ArrayTest, ValueConstructor) {
    Array<int> arr(3, 42);
    EXPECT_EQ(arr.getSize(), 3);
    EXPECT_EQ(arr[0], 42);
    EXPECT_EQ(arr[1], 42);
    EXPECT_EQ(arr[2], 42);
}

TEST_F(ArrayTest, InitializerListConstructor) {
    Array<int> arr{1, 2, 3, 4, 5};
    EXPECT_EQ(arr.getSize(), 5);
    EXPECT_EQ(arr[0], 1);
    EXPECT_EQ(arr[4], 5);
}

TEST_F(ArrayTest, AddElementAndSize) {
    Array<int> arr;
    arr.addElement(10);
    arr.addElement(20);
    arr.addElement(30);
    
    EXPECT_EQ(arr.getSize(), 3);
}

TEST_F(ArrayTest, AddElementAndAccess) {
    Array<int> arr;
    arr.addElement(10);
    arr.addElement(20);
    
    EXPECT_EQ(arr[0], 10);
    EXPECT_EQ(arr[1], 20);
}

TEST_F(ArrayTest, RemoveLast) {
    Array<int> arr{1, 2, 3};
    arr.removeLast();
    
    EXPECT_EQ(arr.getSize(), 2);
    EXPECT_EQ(arr[0], 1);
    EXPECT_EQ(arr[1], 2);
}

TEST_F(ArrayTest, RemoveLastEmpty) {
    Array<int> arr;
    EXPECT_NO_THROW(arr.removeLast());
    EXPECT_EQ(arr.getSize(), 0);
}

TEST_F(ArrayTest, RemoveAtIndex) {
    Array<int> arr{1, 2, 3, 4, 5};
    arr.removeAtIndex(2); // Удаляем элемент с индексом 2 (значение 3)
    
    EXPECT_EQ(arr.getSize(), 4);
    EXPECT_EQ(arr[0], 1);
    EXPECT_EQ(arr[1], 2);
    EXPECT_EQ(arr[2], 4);
    EXPECT_EQ(arr[3], 5);
}

TEST_F(ArrayTest, ClearAll) {
    Array<int> arr{1, 2, 3, 4, 5};
    arr.clearAll();
    
    EXPECT_EQ(arr.getSize(), 0);
}

TEST_F(ArrayTest, CopyConstructor) {
    Array<int> original{1, 2, 3};
    Array<int> copy(original);
    
    EXPECT_EQ(copy.getSize(), original.getSize());
    EXPECT_EQ(copy[0], 1);
    EXPECT_EQ(copy[1], 2);
    EXPECT_EQ(copy[2], 3);
}

TEST_F(ArrayTest, AssignmentOperator) {
    Array<int> original{1, 2, 3};
    Array<int> copy;
    copy = original;
    
    EXPECT_EQ(copy.getSize(), original.getSize());
    EXPECT_EQ(copy[0], 1);
    EXPECT_EQ(copy[1], 2);
    EXPECT_EQ(copy[2], 3);
}

TEST_F(ArrayTest, MoveConstructor) {
    Array<int> original{1, 2, 3};
    Array<int> moved(std::move(original));
    
    EXPECT_EQ(moved.getSize(), 3);
    EXPECT_EQ(moved[0], 1);
    EXPECT_EQ(moved[1], 2);
    EXPECT_EQ(moved[2], 3);
}

TEST_F(ArrayTest, Resize) {
    Array<int> arr{1, 2, 3};
    arr.resize(5);
    
    EXPECT_GE(arr.getCapacity(), 5);
    EXPECT_EQ(arr.getSize(), 3);
}

TEST_F(ArrayTest, OutOfBoundsAccess) {
    Array<int> arr{1, 2, 3};
    EXPECT_NO_THROW(arr[0]);
    EXPECT_NO_THROW(arr[2]);
}

TEST_F(ArrayTest, CapacityGrowth) {
    Array<int> arr;
    size_t initial_capacity = arr.getCapacity();
    for (int i = 0; i < initial_capacity + 1; ++i) {
        arr.addElement(i);
    }
    
    EXPECT_GT(arr.getCapacity(), initial_capacity);
    EXPECT_EQ(arr.getSize(), initial_capacity + 1);
}