cmake_minimum_required(VERSION 3.30)
project(lab1)

set(CMAKE_CXX_STANDARD 20)

# Додаємо підтримку pthread
find_package(Threads REQUIRED)

add_executable(lab1 main.cpp data.cpp f1.cpp f2.cpp f3.cpp tthread.cpp)

# Лінкуємо pthread
target_link_libraries(lab1 PRIVATE Threads::Threads)
