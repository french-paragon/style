set(LIB_NAME StyleTextDocument)
set(LIB_SRC styletextdocument_global.h
            overloadableproperty.h
            abstractstyle.cpp
            abstracttextdocument.cpp
            abstracttextparagraph.cpp
            unitvalue.cpp
            stylemanager.cpp
            paragraphstyle.cpp
            spanstyle.cpp
            spanview.cpp)

add_library(${LIB_NAME} ${LIB_SRC})

target_compile_definitions(${LIB_NAME}
  PRIVATE STYLE_TEXTDOCUMENT_LIBRARY)

target_link_libraries(${LIB_NAME} Qt5::Core Qt5::Gui)
