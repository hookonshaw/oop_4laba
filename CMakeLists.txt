cmake_minimum_required(VERSION 3.10)
project(GeometryFigures VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(GTest REQUIRED)

set(MAIN_SOURCE
    src/main.cpp
)

set(HEADERS
    include/array.ipp
    include/point.ipp
    include/figure.ipp
    include/pentagon.ipp
    include/rhombus.ipp
    include/trapezoid.ipp
)

# Основная программа
add_executable(geometry_figures ${MAIN_SOURCE})
target_include_directories(geometry_figures PRIVATE include)
target_compile_features(geometry_figures PRIVATE cxx_std_20)

# Тестовые файлы - проверяем существование
if(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/test/array_test.cpp")
    set(ARRAY_TEST_SOURCES test/array_test.cpp)
endif()

if(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/test/figure_test.cpp")
    set(FIGURE_TEST_SOURCES test/figure_test.cpp)
endif()

if(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/test/tests.cpp")
    set(MAIN_TEST_SOURCES test/tests.cpp)
endif()

# Тесты для Array (если файл существует)
if(ARRAY_TEST_SOURCES)
    add_executable(array_tests ${ARRAY_TEST_SOURCES})
    target_include_directories(array_tests PRIVATE include)
    target_compile_features(array_tests PRIVATE cxx_std_20)
    target_link_libraries(array_tests GTest::gtest GTest::gtest_main)
endif()

# Тесты для Figure и фигур (если файл существует)
if(FIGURE_TEST_SOURCES)
    add_executable(figure_tests ${FIGURE_TEST_SOURCES})
    target_include_directories(figure_tests PRIVATE include)
    target_compile_features(figure_tests PRIVATE cxx_std_20)
    target_link_libraries(figure_tests GTest::gtest GTest::gtest_main)
endif()

# Все тесты вместе (только если оба файла существуют)
if(ARRAY_TEST_SOURCES AND FIGURE_TEST_SOURCES)
    if(MAIN_TEST_SOURCES)
        add_executable(all_tests ${ARRAY_TEST_SOURCES} ${FIGURE_TEST_SOURCES} ${MAIN_TEST_SOURCES})
    else()
        add_executable(all_tests ${ARRAY_TEST_SOURCES} ${FIGURE_TEST_SOURCES})
    endif()
    target_include_directories(all_tests PRIVATE include)
    target_compile_features(all_tests PRIVATE cxx_std_20)
    target_link_libraries(all_tests GTest::gtest GTest::gtest_main)
endif()

# Добавляем запуск тестов (если цели существуют)
include(GoogleTest)
if(TARGET array_tests)
    gtest_discover_tests(array_tests)
endif()

if(TARGET figure_tests)
    gtest_discover_tests(figure_tests)
endif()

if(TARGET all_tests)
    gtest_discover_tests(all_tests)
endif()