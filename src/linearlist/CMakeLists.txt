# build_lib(
#     LIBNAME linearlist
#     SOURCE_FILES
#         sequenatialist.cpp
#         singlelinkedlist.cpp
#     HEADER_FILES
#         sequenatialist.h
#         singlelinkedlist.h
# )
add_library(
    linearlist
    STATIC
        sequenatiallist.cpp
        singlelinkedlist.cpp
        sequenatiallist.h
        singlelinkedlist.h
)