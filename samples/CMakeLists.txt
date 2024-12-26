# SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
# Copyright 2024 LG Electronics Inc.

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/out/samples)

add_executable(infinite_loop infinite_leak_gen.cpp)
