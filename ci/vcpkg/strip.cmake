find_program(STRIP_COMMAND NAMES strip REQUIRED)

file(GLOB_RECURSE binaries LIST_DIRECTORIES false
    "${CURRENT_PACKAGES_DIR}/lib"
    "${CURRENT_PACKAGES_DIR}/plugins/lib"
    "${CURRENT_PACKAGES_DIR}/tools"
    "${CURRENT_PACKAGES_DIR}/debug/lib"
    "${CURRENT_PACKAGES_DIR}/debug/plugins"
    "${CURRENT_PACKAGES_DIR}/tools"
)
file(GLOB_RECURSE data LIST_DIRECTORIES false
    "${CURRENT_PACKAGES_DIR}/lib/pkgconfig"
    "${CURRENT_PACKAGES_DIR}/debug/lib/pkgconfig"
)
list(REMOVE_ITEM binaries ${data} "")
foreach(file IN LISTS binaries)
    string(FIND "${file}" "/tools/" tools_index)
    if(tools_index EQUAL -1 OR IS_EXECUTABLE "${file}")
        execute_process(COMMAND "${STRIP_COMMAND}" -S "${file}")
    endif()
endforeach()
