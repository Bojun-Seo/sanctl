// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
// Copyright 2024 LG Electronics Inc.

#include <thread>
#include <unistd.h>
#include <sanitizer/lsan_interface.h>

static bool initialized;
static std::thread* background_thread;
static int interval_s = 10;

static void run_infinite_loop() {
  while (true) {
    sleep(interval_s);
    __lsan_do_recoverable_leak_check();
  }
}

static void spawn_background_thread() {
  background_thread = new std::thread(run_infinite_loop);
}

__attribute__((constructor)) static void lsanctl_init() {
  spawn_background_thread();
  initialized = true;
}

__attribute__((destructor)) static void lsanctl_finish() {
  delete background_thread;
}
