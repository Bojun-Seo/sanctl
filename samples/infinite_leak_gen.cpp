// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
// Copyright 2024 LG Electronics Inc.

#include <iostream>
#include <unistd.h>

int main() {
  while (true) {
    sleep(10);
    new int;
  }
  return 0;
}

