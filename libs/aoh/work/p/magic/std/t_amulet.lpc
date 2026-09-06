// Softbyte: Use /p/magic/obj/t_amulet

#include <magic.h>
inherit M_AMULET;

create()
{
  ::create();
  seteuid(getuid());
  log_file("magic/outdated.log","p/magic/std//std_teleport.c by "+
  QueryCreator()+"/"+QueryICreator()+" on "+ctime()+".\n");
}