# SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
# Copyright 2024 LG Electronics Inc.

cmake_minimum_required(VERSION 3.20)
project(sanctl LANGUAGES CXX)

set(CMAKE_INSTALL_PREFIX /usr)

add_subdirectory(src)
add_subdirectory(tests)
