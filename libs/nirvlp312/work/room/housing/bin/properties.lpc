#include "../defs.h"

int *priv_cost() { return ({ 2, 0 }); }

status
main(string arg, object room, object master)
{
  string *t, *t2;
  int i, j;

  t = (string *)room->query_properties();
  write(HIK+"Properties set:\n"+NORM+NORM);
  write((sizeof(t) ? implode(t, "\n")+"\n" : "None set.\n")+"\n");

  write(HIK+"Available properties: \n"+NORM+NORM);
  i = sizeof(t2 = (string *)master->query_upgrades());
  j = 0;
  
  if (!i)
  {
    write("None.\n");
    return 1;
  }
  
  while(i--)
    if (!sizeof(t) || member_array(t2[i], t) > -1)
      if (text_contains(t2[i], "property"))
      {
        j++;
        write(" 100,000 "+t2[i]+"\n");
      }

  if (!j)
    write("None available.\n");
      
  return 1;
}
