begin
decl
int a,b;
enddecl
read(a);
read(b);
a=a*a+b*b;
write(a);
write(b*b);
write(8);
if(a>30) then
write(a);
else 
write(b);
endif;
if(a==25) then
write(a);
else
write(b);
endif;

while(a<50) do
a=a+1;
if(a==38) then 
continue;
endif;
if(a==44) then 
break;
endif;
write(a);
endwhile;

end;

