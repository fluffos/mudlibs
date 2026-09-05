#include "/sys/security.h"

int cmd_vis(string arg)
{
  int level, is_invis;

  level = (int)this_player()->query_level();
  is_invis = (int)this_player()->query_invis();
 if (!is_invis)
 {
  write("You are not invisible.\n");
  return 1;
 }
  this_player()->set_invis(0);
 if((int)this_player()->query_visible()) /* force this, annoying "Someone" bug */
  command("visible", this_player());
 write("You are now visible.\n");
 this_player()->remote_say(this_player()->query_name()+" appears in a puff of smoke.\n");
 return 1;
}
