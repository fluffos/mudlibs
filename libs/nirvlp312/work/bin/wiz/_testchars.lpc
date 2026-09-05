#include "/obj/play/paths.h"
#define BAR "\
------------------------------------------------------------\n"

int cmd_testchars()
{
  mapping info;
  string  *wizs, *testers;
  int     a, s, x, y;
  
  info = (mapping)TESTCHAR_D->query_info();
  s = sizeof(wizs = keys(info));
  write(BAR);
  write("\tAll Registered Test Characters [by Wizard]\n");
  write(BAR);
  for(a=0;a<s;a++)
  {
    write(" "+pad(capitalize(wizs[a]+":"), 14));
    y = sizeof(testers=info[wizs[a]]);
    for(x=0;x<y-1;x++)
      write(capitalize(testers[x])+", ");
    write(capitalize(testers[y-1])+".\n");
  }
  write(BAR);
  return 1;
}
