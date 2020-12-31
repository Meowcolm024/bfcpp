# bfcpp

Simple `Brainfuck` interpreter in C++.

- `main.cpp` is the program entrance
- `repl.h` is the repl
- `bf.h` is the bf core lib

## ISSUES

The program is still buggy (probably related to file reading) ...

And I have no idea why it would happen ...

- `cell.bf` is not working QAQ

so ... tons of things not working orz

## Build

``` bash
make clean
make
```

## Run

Start repl:

``` bash
make run
```

Run file:

``` bash
make run ARGS="hello.bf"
```
