@.str1 = private unnamed_addr constant [3 x i8] c"%d\00", align 1
@.str2 = private unnamed_addr constant [4 x i8] c"%d\0A\00", align 1
@n = common global i32 0, align 4
@x = common global i32 0, align 4
@i = common global i32 0, align 4

define i32 @main() #0 {
  %1 = alloca i32, align 4
  store i32 0, i32* %1, align 4
  %2 = call i32 (i8*, ...) @scanf(i8* getelementptr inbounds ([3 x i8], [3 x i8]* @.str1, i32 0, i32 0), i32* @n)
  store i32 1, i32* @i, align 4
  br label %3

3:
  %4 = load i32, i32* @i, align 4
  %5 = load i32, i32* @n, align 4
  %6 = icmp sle i32 %4, %5
  br i1 %6, label %7, label %12

7:
  %8 = load i32, i32* @i, align 4
  store i32 %8, i32* @x, align 4
  br label %9

9:
  %10 = load i32, i32* @i, align 4
  %11 = add nsw i32 %10, 1
  store i32 %2, i32* %11, align 4
  br label %3

12:
  ret i32 0
}
declare dso_local i32 @scanf(i8*, ...)
declare dso_local i32 @printf(i8*, ...)
