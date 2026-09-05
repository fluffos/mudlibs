#include "/obj/lib/wiz/roles.h"
#include <ansi.h>

int cmd_assign_role(string str)
{
  string devName;
  string role;
  
  if(!str || sscanf(str,"%s %s",devName,role) < 2)
  {
    write("Usage: 'assign_role <devName> <role>'\n");
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
      devName = lower_case(devName);
      
      if(!valid_wizard(devName))
      {
        write("No such wizard named \""+devName+"\"\n");
      }
    
      else
      {
        string *cts;
        
        cts = (string *)JOBS->query_titles(devName);
        
        if(cts && member_array(role, cts) > -1)
        {
          write(capitalize(devName)+" already holds the "+
          "role of : "+BOLD+role+NORM+".\n");
        }
        
        else
        {
          JOBS->add_title(devName, role);
        
          write("Ok: added a role to " + capitalize(devName)
            +" named " + BOLD + role + NORM + "\n");
        }
      }
    }
  }
  return 1;
}