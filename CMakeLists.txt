cmake_minimum_required(VERSION 3.12)
project(segment2d_cpp LANGUAGES CXX)

add_executable(segment2d_cpp
    main.cpp
    Point2.cpp
    Vector2.cpp
    Segment2.cpp
)
target_compile_features(segment2d_cpp PRIVATE cxx_std_17)
