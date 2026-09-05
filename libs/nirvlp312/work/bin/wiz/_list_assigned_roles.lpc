#include "/obj/lib/wiz/roles.h"
#include <ansi.h>

int cmd_list_assigned_roles(string str)
{
  int x, y;
  if(str)
  {
    string *t;
    if(!valid_wizard(str))
    {
      write(str+" is not a valid wizard.\n");
    }
    else if(!(t=(mixed)JOBS->query_titles(str)) || !(y=sizeof(t)))
    {
      write(str+" is not currently assigned any roles.\n");
    }
    else
    {
      write("\n\t"+capitalize(str)+"'s Roles:\n\n");
      for(x=0;x<y;x++)
      {
        write(" ~~ "+t[x]+"\n");
      }
      write("\n");
    }
  }
  else
  {
    string *b;
    mixed *c, *wdf;
    int    d, e;
    
    b = (string*)JOBS->query_p_names();
    c = (mixed*)JOBS->query_p_titles();
    
    y = sizeof(b);
    
    write("\n\tAll Assigned Roles\n");
    
    for(x = 0; x < y; x ++)
    {
      write("\n");
      write(" "+BOLD+capitalize(pad(b[x], 15))+NORM+"\n");
      wdf = c[x];
      e = sizeof(wdf);
      for(d=0;d<e;d++)
      {
        write("   ~~ "+wdf[d]+"\n");
      }
    }
    write("\n");
  }
  return 1;
}
