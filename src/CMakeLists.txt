# SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
# Copyright 2024 LG Electronics Inc.

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/out/lib)

add_library(lsanctl SHARED lsanctl.cpp)

install(TARGETS lsanctl DESTINATION ${CMAKE_INSTALL_PREFIX}/lib)
