object *caps;

void reset()
{
  int i;

  {
   for(i=0; i<sizeof(caps); i++)
   {
     if(!caps[i])
    {
       caps[i]=clone_object(CHAR+"capelf2");
     caps[i]->move(this_object());
  }
  }
  }
 }
void setup() {
caps = allocate(2);
