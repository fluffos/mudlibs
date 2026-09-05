#include <security.h>

int cmd_setaln(string al_str)
{
 int alInt;

 if((int)this_player()->query_level() < EXPLORE)
  return 0;

 if(!al_str || !sscanf(al_str, "%d", alInt))
 {
  write("Usage: 'setaln <alignment_number>'\n");
  return 1;
 }

 write("Ok.\nAlignment set to: "+al_str+".\n");
 this_player()->set_alignment(alInt);
 command("save silent", this_player());
 return 1;
}
