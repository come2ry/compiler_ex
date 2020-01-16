@n = common global i32 0, align 4
@sum = common global i32 0, align 4

define i32 @main() #0 {
  %1 = alloca i32, align 4
  store i32 0, i32* %1, align 4
  store i32 10, i32* @n, align 4
  store i32 0, i32* @sum, align 4
  br label %32765
2:
  %3 = load i32, i32* @n, align 4
  %4 = icmp sgt i32 %3, 0
  br i1 %4, label %0, label %0
6:
  %7 = load i32, i32* @sum, align 4
  %8 = load i32, i32* @n, align 4
  %9 = add nsw i32 %7, %8
  store i32 %9, i32* @sum, align 4
  %10 = load i32, i32* @n, align 4
  %11 = sub nsw i32 %10, 1
  store i32 %11, i32* @n, align 4
  br label %32765
12:
  ret i32 0
}
