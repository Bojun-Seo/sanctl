# sanctl
Sanitizer controlling library

# Way to build lsanctl library(liblsanctl.so)
```
$ g++ -c -fPIC src/lsanctl.cpp -o lsanctl.o
$ g++ lsanctl.o -shared -o liblsanctl.so -lpthread
```

# Way to build test sample(infinite_leak_gen)
```
$ g++ -fsanitize=leak test/infinite_leak_gen.cpp -o infinite_leak_gen
```

# Way to test lsanctl with sample and result
```
$ LD_PRELOAD=./liblsanctl.so ./infinite_leak_gen

=================================================================
==183540==ERROR: LeakSanitizer: detected memory leaks

Direct leak of 4 byte(s) in 1 object(s) allocated from:
    #0 0x733d9aa16222 in operator new(unsigned long) ../../../../src/libsanitizer/lsan/lsan_interceptors.cpp:248
    #1 0x5d09a3859184 in main (/home/bojun/sanctl/infinite_leak_gen+0x1184) (BuildId: f403ef62b246381982c3fbd4630107c6f1ecbf45)
    #2 0x733d9a22a1c9 in __libc_start_call_main ../sysdeps/nptl/libc_start_call_main.h:58
    #3 0x733d9a22a28a in __libc_start_main_impl ../csu/libc-start.c:360
    #4 0x5d09a38590a4 in _start (/home/bojun/sanctl/infinite_leak_gen+0x10a4) (BuildId: f403ef62b246381982c3fbd4630107c6f1ecbf45)

SUMMARY: LeakSanitizer: 4 byte(s) leaked in 1 allocation(s).

=================================================================
==183540==ERROR: LeakSanitizer: detected memory leaks

Direct leak of 8 byte(s) in 2 object(s) allocated from:
    #0 0x733d9aa16222 in operator new(unsigned long) ../../../../src/libsanitizer/lsan/lsan_interceptors.cpp:248
    #1 0x5d09a3859184 in main (/home/bojun/sanctl/infinite_leak_gen+0x1184) (BuildId: f403ef62b246381982c3fbd4630107c6f1ecbf45)
    #2 0x733d9a22a1c9 in __libc_start_call_main ../sysdeps/nptl/libc_start_call_main.h:58
    #3 0x733d9a22a28a in __libc_start_main_impl ../csu/libc-start.c:360
    #4 0x5d09a38590a4 in _start (/home/bojun/sanctl/infinite_leak_gen+0x10a4) (BuildId: f403ef62b246381982c3fbd4630107c6f1ecbf45)

SUMMARY: LeakSanitizer: 8 byte(s) leaked in 2 allocation(s).
^C
```
