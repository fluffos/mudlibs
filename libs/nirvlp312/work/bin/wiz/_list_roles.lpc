#include <ansi.h>
#include "/obj/lib/wiz/roles.h"

int cmd_list_roles(string str)
{
  string *roles;
  int    sz;
  
  if(!(roles=(string *)JOBS->query_job_titles()) ||
     !(sz = sizeof(roles)))
  {
    write("\nNo roles created.\n\n");
  }
  else
  {
    int x;
    string desc;
    write("\n");
    for(x = 0; x < sz; x ++)
    {
      write(BOLD+roles[x]+NORM+"\n");
      desc=(string)JOBS->query_description(roles[x]);
      desc=format("\n  "+desc, 65);
      desc=implode(explode(desc,"\n"),"\n  ");
      write(desc+"\n\n");
    }
  }
  
  return 1;
}