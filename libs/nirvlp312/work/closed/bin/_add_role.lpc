#include "/obj/lib/wiz/roles.h"

int cmd_add_role(string str)
{
  string role, desc;
  
  if(!str || sscanf(str, "%s#%s",role,desc) < 2)
  {
    write("Usage: 'add_role <role#desc>'\n");
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
      
    if(JOBS->valid_job_title(role))
    {
      write("There is already a job title named \""
        + role + "\".\n");
    }
    else
    {
      JOBS->add_job_title(role, desc);
      write("Ok: added a job title named:\n"
        + role + "\n");
    }
  } 
  
  return 1;
}