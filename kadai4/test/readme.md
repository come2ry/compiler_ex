# c -> llvm

```sh
clang -S -O0 -emit-llvm pl0a.c
```

# llvm run

```sh
lli pl0a.ll
```

# confirm return

```sh
lli sample.ll
echo $?
```
