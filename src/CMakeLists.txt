set(libs "${libs_to_build}")

# Process subdirectories
foreach(libname ${libs})
    if(EXISTS ${PROJECT_SOURCE_DIR}/src/${libname}/CMakeLists.txt)
        message(STATUS "Processing src/${libname}")
        add_subdirectory(${libname})
    else()
        message(
            ${HIGHLIGHTED_STATUS}
            "Skipping src/${libname} : it does not contain a CMakeLists.txt file"
        )
    endif()
    
    
endforeach(libname ${libs})
    
