ENABLE_QT()

# TODO: put header files here.
SET(DEMO_HDRS board.h mwo_mainwindow.h mwo_application.h mwo_logger.h game_widget.h)

# TODO: put srouce files here.
SET(DEMO_SRCS ${DEMO_HDRS} board.cpp game_widget.cpp mwo_application.cpp mwo_mainwindow.cpp mwo_logger.cpp main.cpp)

# TODO: put QT Moc files here.
SET(MOC_DEMO_HDRS game_widget.h mwo_application.h mwo_mainwindow.h)
QT4_WRAP_CPP(MOC_DEMO_SRCS ${MOC_DEMO_HDRS})

# TODO: put output file name here.
ADD_EXECUTABLE(fiveinrow.oar ${DEMO_SRCS} ${MOC_DEMO_SRCS} )
TARGET_LINK_LIBRARIES(fiveinrow.oar
   onyx_data
   onyx_screen
   onyx_sys
   onyx_ui
   ${QT_LIBRARIES}
   ${ADD_LIB}
)

