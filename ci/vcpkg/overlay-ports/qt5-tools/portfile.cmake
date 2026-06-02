include(${CURRENT_INSTALLED_DIR}/share/qt5/qt_port_functions.cmake)

vcpkg_list(SET OPTIONS)
if("qdoc" IN_LIST FEATURES)
    set(ENV{LLVM_INSTALL_DIR} "${CURRENT_INSTALLED_DIR}")
    vcpkg_list(APPEND OPTIONS -feature-qdoc)
else()
    vcpkg_list(APPEND OPTIONS -no-feature-qdoc)
endif()

qt_submodule_installation(
    PATCHES
        fix-pkgconfig-qt5uiplugin-not-found.patch
        libclang.patch
        android.diff
    BUILD_OPTIONS
        ${OPTIONS}
)

if(EXISTS "${CURRENT_INSTALLED_DIR}/plugins/platforms/qminimal${VCPKG_TARGET_SHARED_LIBRARY_SUFFIX}")
    file(INSTALL "${CURRENT_INSTALLED_DIR}/plugins/platforms/qminimal${VCPKG_TARGET_SHARED_LIBRARY_SUFFIX}" DESTINATION "${CURRENT_PACKAGES_DIR}/tools/${PORT}/bin/plugins/platforms")
endif()

if(VCPKG_TARGET_IS_ANDROID)
    make_directory("${CURRENT_PACKAGES_DIR}/tools/qt5/bin")
    foreach(tool IN ITEMS lconvert lrelease lupdate qcollectiongenerator qhelpgenerator)
        string(CONFIGURE [[
#!/bin/sh
prefix=$(CDPATH= cd -- "$(dirname -- "$0")"/../../../.. && pwd -P)
exec "$prefix/@HOST_TRIPLET@/tools/qt5/bin/$(basename "$0")" "$@"
]] wrapper @ONLY)
        set(file "${CURRENT_PACKAGES_DIR}/tools/qt5/bin/${tool}")
        file(WRITE "${file}" "${wrapper}")
        file(CHMOD "${file}" PERMISSIONS OWNER_READ OWNER_WRITE OWNER_EXECUTE)
    endforeach()
endif()
