@.str1 = private unnamed_addr constant [3 x i8] c"%d\00", align 1
@.str2 = private unnamed_addr constant [4 x i8] c"%d\0A\00", align 1
@n = common global i32 0, align 4
@x = common global i32 0, align 4
@i = common global i32 0, align 4

define i32 @main() #0 {
  %1 = alloca i32, align 4
  store i32 0, i32* %1, align 4
  %2 = call i32 (i8*, ...) @scanf(i8* getelementptr inbounds ([3 x i8], [3 x i8]* @.str1, i64 0, i64 0), i32* @n)
  %3 = load i32, i32* @n, align 4
  %4 = load i32, i32* @i, align 4
  store i32 %4, i32* @x, align 4
  ret i32 0
}
declare dso_local i32 @scanf(i8*, ...)
declare dso_local i32 @printf(i8*, ...)
