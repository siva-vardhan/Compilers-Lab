type
  List
  {
    int data;
    List next;
  }
endtype

decl
    List head;
enddecl

int main()
{
  decl
    int x,y;
    List p, q;
  enddecl

  begin
    x = initialize();
    

p=alloc();
q=alloc();
p.data=33;
p.next=q;
q.data=44;
q.next=null;
head=p;






q=head;
x=q.data;
write(x);
q=q.next;
y=q.data;
write(y);



  end
}

