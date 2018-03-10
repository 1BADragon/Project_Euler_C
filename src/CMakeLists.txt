ADD_EXECUTABLE(launcher main)

if(UNIX)
TARGET_LINK_LIBRARIES(launcher dl)
endif()