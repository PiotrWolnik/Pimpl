cmake_minimum_required(VERSION 3.22)
project(Pimpl)

set(CMAKE_CXX_STANDARD 20)

## Dodaj flagi kompilacji wymuszające pisanie kodu zgodnego ze standardem.
#add_compile_options(-Wall -Wextra -Werror -Wpedantic -pedantic-errors)

# Dodaj katalogi z plikami nagłówkowymi dla wszystkich konfiguracji.
include_directories(
        include
)

# Ustaw zmienną `SOURCE_FILES`, która będzie przechowywać ścieżki do
# tych plików źródłowych, które będą niezbędne w każdej konfiguracji.
set(SOURCE_FILES
        src/gadget.cpp
        src/widget.cpp
        )

# Dodaj konfigurację typu `Debug`.
add_executable(Pimpl_debug ${SOURCE_FILES} main.cpp)


# == Unit testing using Google Testing Framework ==

# Ustaw zmienną `SOURCES_FILES_TESTS`, która będzie przechowywać ścieżki do
# plików źródłowych z testami jednostkowymi.
set(SOURCES_FILES_TESTS
        test/test_gadget_methods.cpp
        test/test_widget_methods.cpp
        test/main_gtest.cpp
        )

# Dodaj konfigurację typu `Test`.
add_executable(Pimpl_test ${SOURCE_FILES} ${SOURCES_FILES_TESTS} test/main_gtest.cpp)

# Dodaj katalogi z plikami nagłówkowymi wyłącznie do konkretnej konfiguracji (tu: `Test`).
target_include_directories(Pimpl_test PUBLIC
        googletest-master/googlemock/include
        googletest-master/googletest/include
        mocks
        )

# Dodaj podkatalog `googletest-master`.
add_subdirectory(googletest-master)

# Podlinkuj bibliotekę o identyfikatorze `gmock` (w pliku CMake) wyłącznie do konkretnej
# konfiguracji (tu: `Test`).
target_link_libraries(Pimpl_test gmock)