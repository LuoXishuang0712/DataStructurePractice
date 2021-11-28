# Usgae

Every Folder represent a project.

the source file ans header file name as same as folder is my library. You can use it independly, I had try my best to cut down its dependence.

the source file ended with "_test" is the library example.

to complain it, just use 
```bash
<compiler> -o output <library>_test.cpp
```

eg.
```bash
g++ -o output -g queue_test.cpp
```

-g used to enable gdb debuger.

### before compile, to ensure you has installed the compiler!