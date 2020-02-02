@.str1 = private unnamed_addr constant [3 x i8] c"%d\00", align 1
@.str2 = private unnamed_addr constant [4 x i8] c"%d\0A\00", align 1
@x = common global i32 0, align 4

define i32 @main() #0 {
  %1 = alloca i32, align 4
  store i32 0, i32* %1, align 4
  store i32 15, i32* @x, align 4
  ret i32 0
}
declare dso_local i32 @scanf(i8*, ...)
declare dso_local i32 @printf(i8*, ...)
