#define DAEMON "/obj/invasion/i-daemon"

#include <ansi.h>

status Busy;

string invasion_type, mob_file;
int    mob_total;

status cmd_start_invasion()
{
  if((int)this_player()->query_level() < 1000) return 0;
  if(DAEMON->query_invasion_type() || DAEMON->query_total_monsters())
  {
    write("Nirvana is currently being invaded by "+
          capitalize((string)DAEMON->query_invasion_type())+".\n"+
          "Type <end_invasion> to stop it.\n");
    return 1;
  }
  if(Busy)
  {
    write("Someone else is currently activating an invasion.\n");
    return 1;
  }
  write("Starting Invasion...\n");
  invasion_type=0;
  mob_file=0;
  mob_total=0;
  write("Type the full file-name of the monster you wish to invade:\n");
  write("[i.e. /obj/invasion/mobs/smurf.c]\n");
  write(">> ");
  input_to("get_file_name");
  return 1;
}

status get_file_name(string str)
{
  Busy=0;
  if(!str)
  {
    write("Invasion Aborted.\n");
    return 1;
  }
  if(file_size(str)<= 0)
  {
    write("Invasion Aborted.\nInvalid File.\n");     
    return 1;
  }
  mob_file=str;
  Busy=1;
  write("Ok.\n");
  write("Type the invasion type:\n");
  write("[i.e. Smurf]\n");
  write(">> ");
  input_to("get_invasion_type");
  return 1;
}

status get_invasion_type(string str)
{
  if(!str)
  {
    Busy=0;
    write("Invasion Aborted.\n");
    return 1;
  }
  invasion_type=str;
  write("Ok.\n");
  write("Type the total number of mobs to invade:\n");
  write("[i.e. 100]\n");
  write(">> ");
  input_to("get_num");
  return 1;
}

status get_num(string str)
{ 
  int x;
  Busy=0;
  if(!str || !sscanf(str,"%d",x))
  {
    write("Invasion Aborted.\n");
    return 1;
  }
  mob_total=x;
  write("Ok.\n");
  write("Invasion begun.\n");
  DAEMON->set_total_monsters(mob_total);
  DAEMON->set_invasion_type(invasion_type);
  DAEMON->set_monster_path(mob_file);
  "/obj/invasion/i-daemon"->create_monsters();
  return 1;
}
