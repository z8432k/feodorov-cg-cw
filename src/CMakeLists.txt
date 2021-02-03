set(CMAKE_INCLUDE_CURRENT_DIR_IN_INTERFACE  ON)

find_package(Qt4 REQUIRED)

include_directories(include)


add_library(main OBJECT figure.cc)
target_link_libraries(main
        Qt4::QtCore
        Qt4::QtGui)

add_library(moc_mainwindow OBJECT moc_mainwindow.cpp)
target_link_libraries(moc_mainwindow
        Qt4::QtCore
        Qt4::QtGui)

add_library(mainwindow OBJECT mainwindow.cc)
target_link_libraries(mainwindow
        Qt4::QtCore
        Qt4::QtGui)

add_executable(figure)
target_link_libraries(figure
        main
        moc_mainwindow
        mainwindow
        Qt4::QtCore
        Qt4::QtGui)

