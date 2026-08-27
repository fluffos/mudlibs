inherit "/std/room";
#include "path.h"

void setup() {
  set_short("At the Round Table");
  set_light(60);
   set_long("You are seated in a Great Hall around the fabled Round Table.\n"+
  "Gathered around you are other mighty heroes from across the"+
    " realms.  At the head of the chamber is a HUGE throne for Timion, God"+
   " of the Fighters.\nThere is a list here.\n");
  add_item("throne","The throne is made of pure marble...simple, yet majestic.\n");
   add_item("list","Type 'read list' to read the list and 'add <name>' to add a name to the list.\n");
  add_item("table","A majestic round table of pure white marble.\n");
  add_exit("down", ROOM +"hall","stairs");
}

write_list(arg)
{
 
  if(!(this_player()->query_guild_ob()=="/std/guilds/warriors/fighter"))
   {
    write("You are NOT a fighter! BEGONE!");
    return 1;
   }
 if(!arg)
   {
    write("Syntax:  add <playername>");
    return 1;
   }
  if(this_player()->query_level()>=10)
{
    write("Ok, "+arg+" added.\n");
   write_file(ROOM+"list.txt","WANTED:  "+arg+"    WANTED BY: "+this_player()->query_cap_name()+".\n");
}
 else
  write("You are not high enough level to add to the list.\n");
  return 1;
}
 
exa_list(arg)
{
 if(!arg)
  {
    write("Syntax:  read <object>\n");
    return 1;
   }
 if(!(arg=="list"))
  return 0;
 write("FOR CRIMES AGAINST THE FIGHTERS GUILD:\n"+read_file(ROOM+"list.txt"));
 return 1;
}
 
void init()
{
 add_action("write_list","add");
 add_action("exa_list","read");
 ::init();
}
