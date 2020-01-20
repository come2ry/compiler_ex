; ModuleID = 'ifthen.c'
source_filename = "ifthen.c"
target datalayout = "e-m:e-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-unknown-linux-gnu"

@n = common dso_local global i32 0, align 4

; Function Attrs: noinline nounwind optnone uwtable
define dso_local i32 @main() #0 {
  %1 = alloca i32, align 4
  store i32 0, i32* %1, align 4
  store i32 10, i32* @n, align 4
  %2 = load i32, i32* @n, align 4
  %3 = icmp slt i32 %2, 11
  br i1 %3, label %4, label %13

4:                                                ; preds = %0
  %5 = load i32, i32* @n, align 4
  %6 = add nsw i32 %5, 1
  store i32 %6, i32* @n, align 4
  %7 = load i32, i32* @n, align 4
  %8 = icmp slt i32 %7, 12
  br i1 %8, label %9, label %12

9:                                                ; preds = %4
  %10 = load i32, i32* @n, align 4
  %11 = add nsw i32 %10, 1
  store i32 %11, i32* @n, align 4
  br label %12

12:                                               ; preds = %9, %4
  br label %13

13:                                               ; preds = %12, %0
  ret i32 0
}

attributes #0 = { noinline nounwind optnone uwtable "correctly-rounded-divide-sqrt-fp-math"="false" "disable-tail-calls"="false" "less-precise-fpmad"="false" "min-legal-vector-width"="0" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-jump-tables"="false" "no-nans-fp-math"="false" "no-signed-zeros-fp-math"="false" "no-trapping-math"="false" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "unsafe-fp-math"="false" "use-soft-float"="false" }

!llvm.module.flags = !{!0}
!llvm.ident = !{!1}

!0 = !{i32 1, !"wchar_size", i32 4}
!1 = !{!"clang version 9.0.0 (Red Hat 9.0.0-1.el7)"}
