# sanctl
Sanitizer controlling library

# Way to build lsanctl library(liblsan.so)
```
$ g++ -c -fPIC src/lsanctl.cpp -o lsanctl.o
$ g++ lsanctl.o -shared -o liblsanctl.so -lpthread
```

# Way to build test sample(infinite_leak_gen)
```
$ g++ -fsanitize=leak test/infinite_leak_gen.cpp -o infinite_leak_gen
```

# Way to test lsanctl with sample
```
$ LD_PRELOAD=./liblsanctl.so ./infinite_leak_gen
```
