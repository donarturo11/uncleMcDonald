# project(uncleMcDonald)

set(HEADERS 
    Fence/Fence.h 
    Fence/FencePicture.h 
    DrawMatrix/DrawMatrix.h
    TextUI/TextUI.h
    TextUI/ANSIEsc.h)
    
set(SOURCES 
    main.cpp 
    Fence/Fence.cpp 
    Fence/FencePicture.cpp
    Fence/FenceLengthError.cpp
    DrawMatrix/DrawMatrix.cpp
    TextUI/TextUI.cpp )

add_executable(
    ${PROJECT_NAME}
    ${HEADERS}
    ${SOURCES}
    )

install(TARGETS ${PROJECT_NAME} DESTINATION ${PREFIX}/bin)
