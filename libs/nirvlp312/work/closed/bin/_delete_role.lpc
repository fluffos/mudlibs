#include "/obj/lib/wiz/roles.h"

int cmd_delete_role(string str)
{
  string role, desc;
  
  if(!str)
  {
    write("Usage: 'delete_role <role>'\n");
  }
  
  else
  {
    string *words;
    int    x, y;
      
    /* properly capitalize all words */
    role = str;
    words = explode(role, " ");
    y = sizeof(words);
    for(x = 0; x < y; x ++)
    {
      words[x] = capitalize(words[x]);
    }
    role = implode(words, " ");
      
    if(!JOBS->valid_job_title(role))
    {
      write("There is not a job title named \""
        + role + "\".\n");
    }
    else
    {
      JOBS->delete_job_title(role);
      write("Ok: delete a job title named:\n"
        + role + "\n");
    }
  } 
  
  return 1;
}
