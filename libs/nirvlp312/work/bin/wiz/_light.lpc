/* 08/02/06 Earwax: changed this to use soul light rather than wiz */

#include "/sys/security.h"

int cmd_light(string str)
{
 int x;

 if((int)this_player()->query_level() < CREATE)
  return 0;

 if(!str || !sscanf(str, "%d", x))
 {
  write("Usage: 'light <number>'\n");
    write("Your internal light currently is set to: ");
    write((int)this_player()->query_wiz_soul_light()); write("\n");
    write("The room has a total light level of: ");
    write((int)this_player()->query_current_light()); write("\n");
  return 1;
 }

  write("Your internal light is set to: "); write(x); write("\n");
  x = (int)this_player()->set_wiz_soul_light(x);
  write("You room now has a total light level of: ");
  write(x); write("\n");
 return 1;
}

