#include "/obj/lib/wiz/roles.h"
#include <ansi.h>

int cmd_unassign_role(string str)
{
  string devName;
  string role;
  
  if(!str || sscanf(str,"%s %s",devName,role) < 2)
  {
    write("Usage: 'unassign_role <devName> <role>'\n");
  }
  
  else
  {
    string *words;
    int    x, y;
      
    /* properly capitalize all words */
    words = explode(role, " ");
    y = sizeof(words);
    for(x = 0; x < y; x ++)
    {
      words[x] = capitalize(words[x]);
    }
    role = implode(words, " ");
    
    if(!JOBS->valid_job_title(role))
    {
      write("There is NOT a job title named \""
        + role + "\".\n");
    }
    
    else
    {
      string *cts;
      devName = lower_case(devName);
        
      cts = (string *)JOBS->query_titles(devName);
        
      if(!cts || member_array(role, cts) == -1)
      {
        write("Error. "+capitalize(devName)
          +" does NOT hold the role of "+role+".\n");
      }
      else
      {
        JOBS->delete_title(devName, role);
        
        write("Ok: Deleted a role from " + capitalize(devName)
              +" named " + BOLD + role + NORM + "\n");
      }
    }
  }
  return 1;
}