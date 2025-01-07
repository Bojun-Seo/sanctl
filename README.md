# sanctl
Sanitizer controlling library.
This library currently supports only the `lsanctl` library, which is used to manage `LSan`.
The goal of this project is to provide various libraries to control sanitizers.

# Prerequisites for this project
On ubuntu 24.04 and 22.04
```
$ sudo apt install build-essential git cmake patchelf
```

# Way to build the project
```
$ git clone https://github.com/Bojun-Seo/sanctl.git; cd sanctl
$ mkdir build; cd build
$ cmake ..
$ make
$ sudo make install # optional
```

# Usages
Following guide assumes that `liblsanctl.so` is installed on the system. In other words, you have already run `sudo make install` command.
Therefore, please use `/path/to/liblsanctl.so` instead of `liblsanctl.so` in the following guide if the library is not installed on the system.

## Option #1
1. Build your program with `-fsanitize=leak` option enabled
2. Run your program with `LD_PRELOAD=liblsanctl.so`
```
$ g++ -fsanitize=leak samples/infinite_leak_gen.cpp -o infinite_loop
$ LD_PRELOAD=liblsanctl.so ./infinite_loop
```

## Option #2
1. Don't need to rebuild your target
2. Run your program with `LD_PRELOAD="liblsan.so.0:liblsanctl.so"`
```
$ LD_PRELOAD="liblsan.so.0:liblsanctl.so" ./a.out
```

## Option #3
1. Don't need to rebuild and don't need to use `LD_PRELOAD` environment variable
2. Add dependences to your target program and just run it.
```
$ patchelf --add-needed liblsanctl.so a.out
$ patchelf --add-needed liblsan.so.0 a.out
$ ./a.out
```

# Example results
```
$ LD_PRELOAD=liblsanctl.so out/samples/infinite_loop

=================================================================
==470904==ERROR: LeakSanitizer: detected memory leaks

Direct leak of 4 byte(s) in 1 object(s) allocated from:
    #0 0x732347e16222 in operator new(unsigned long) ../../../../src/libsanitizer/lsan/lsan_interceptors.cpp:248
    #1 0x5bdc33eeb184 in main (/home/bojun/sanctl/build/out/samples/infinite_loop+0x1184) (BuildId: 090690393669a4cc25a2ffa181ee5c268f512cc0)
    #2 0x73234762a1c9 in __libc_start_call_main ../sysdeps/nptl/libc_start_call_main.h:58
    #3 0x73234762a28a in __libc_start_main_impl ../csu/libc-start.c:360
    #4 0x5bdc33eeb0a4 in _start (/home/bojun/sanctl/build/out/samples/infinite_loop+0x10a4) (BuildId: 090690393669a4cc25a2ffa181ee5c268f512cc0)

SUMMARY: LeakSanitizer: 4 byte(s) leaked in 1 allocation(s).

=================================================================
==470904==ERROR: LeakSanitizer: detected memory leaks

Direct leak of 8 byte(s) in 2 object(s) allocated from:
    #0 0x732347e16222 in operator new(unsigned long) ../../../../src/libsanitizer/lsan/lsan_interceptors.cpp:248
    #1 0x5bdc33eeb184 in main (/home/bojun/sanctl/build/out/samples/infinite_loop+0x1184) (BuildId: 090690393669a4cc25a2ffa181ee5c268f512cc0)
    #2 0x73234762a1c9 in __libc_start_call_main ../sysdeps/nptl/libc_start_call_main.h:58
    #3 0x73234762a28a in __libc_start_main_impl ../csu/libc-start.c:360
    #4 0x5bdc33eeb0a4 in _start (/home/bojun/sanctl/build/out/samples/infinite_loop+0x10a4) (BuildId: 090690393669a4cc25a2ffa181ee5c268f512cc0)

SUMMARY: LeakSanitizer: 8 byte(s) leaked in 2 allocation(s).
^C
```
