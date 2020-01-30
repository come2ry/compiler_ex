program PL1B;
var n, m, temp;
procedure fact(n, m);
begin
      if n <= 1 then
	 temp:=1
      else
      begin
	 fact(n - 1, m);
	 temp := temp * n
      end
end;
begin
   read(n);
   m := 1;
   fact(n, m);
   write(temp)
end.
