cmake_minimum_required(VERSION 4.1)  # Укажите минимальную версию CMake
project(calc VERSION 0.0.1)          # Имя проекта и его версия

set(CMAKE_CXX_STANDARD 17)              # Укажите стандарт C++

# Укажите директории, содержащие исходные файлы
include_directories(src)

# Добавьте исполняемый файл и его источники
add_executable(exec src/calc.cpp)

