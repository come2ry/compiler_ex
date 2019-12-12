program M;
var x, y, z;
procedure A;
var x;
begin
    x := 1
end;
procedure B;
var y;
begin
    y := 2;
    x := 5;
end;
begin
    z := 3;
end.



@x = common global i32 0, align 4
@z = common global i32 0, align 4
@y = common global i32 0, align 4
define void @A() #0 {
  %1 = alloca i32, align 4
  store i32 1, i32* %1, align 4
  ret void
}
define void @B() #0 {
  %1 = alloca i32, align 4
  store i32 2, i32* %1, align 4
  store i32 5, i32* @x, align 4
  ret void
}
define i32 @main() #0 {
  %1 = alloca i32, align 4
  store i32 0, i32* %1, align 4
  store i32 3, i32* @z, align 4
  ret i32 0
}