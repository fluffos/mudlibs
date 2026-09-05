#include <security.h>

int cmd_setal(string al_title)
{
 if((int)this_player()->query_level() < EXPLORE)
  return 0;

 if(!al_title)
 {
  write("Usage: 'setal <alignment_title>'\n");
  return 1;
 }

 write("Ok.\nAlignment title set to: "+al_title+"\n");
 this_player()->set_al_title(al_title);
 command("save silent", this_player());
 return 1;
}
