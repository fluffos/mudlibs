/* title.c
 * Externalized by Baldrick jun '97
 */

#include <standard.h>
#include <cmd.h>
inherit CMD_BASE;

void setup(){

position = 1;
}

protected int cmd(string str, object me) 
  {
  string title;

  title = me->query_title();
  if (!str) 
    {
    if(title) write("Your title is: "+title+"\n");
     else 
      write("You have no title.\n");
    }
   else 
    if (str=="-c")
      {
      write("Clearing your title.\n");
      me->set_title(0);
      return 1;
      }
    else
     me->set_title(str);
  return 1;
}

