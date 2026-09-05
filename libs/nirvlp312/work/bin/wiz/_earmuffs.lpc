#include <security.h>

int cmd_earmuffs(string str)
{
 object soul;
 if((int)this_player()->query_level() < CREATE)
  return 0;

# ifdef __LDMUD__
    soul = this_player();
# else
 if(!(soul = present("wiz_soul", this_player())))
 {
  write("You don't even have a freakin' soul, man!\n"+
        "Type 'soul on' for the love of Pete.\n");
  return 1;
 }
# endif

 if(!str)
  write("Your earmuffs are " + ((int)soul->query_muffled() ? "on" : "off") + ".\n");
 else
 {
  if(str == "on")
   soul->set_muffled(1);
  else if(str == "off")
   soul->set_muffled(0);
  else
  {
   write("Usage: 'earmuffs <on|off>'\n");
   return 1;
  }
  write("You turn your earmuffs "+str+".\n");
#ifndef __LDMUD__
  this_player()->update(6);
#endif
 }
 return 1;
}

