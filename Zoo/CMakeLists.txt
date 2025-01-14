cmake_minimum_required(VERSION 3.16)
project(zoocpp)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_TOOLCHAIN_FILE "C:/path_to_vcpkg/scripts/buildsystems/vcpkg.cmake") //указать фактический путь

find_package(PostgreSQL REQUIRED)
find_package(libpqxx REQUIRED)
find_package(Qt5 REQUIRED COMPONENTS Widgets)
find_package(bcrypt REQUIRED)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /clr")

set(SOURCES
    main.cpp
    PostgresDB.cpp
    LoginSignUpForm.cpp
    DashboardAnimalForm.cpp
)

add_executable(${PROJECT_NAME} ${SOURCES})

target_link_libraries(${PROJECT_NAME} pqxx pq Qt5::Widgets bcrypt)
