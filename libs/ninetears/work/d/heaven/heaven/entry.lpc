#include "path.h"
inherit "/std/room";
int blocked;
object port;
string lifter;

void init() {
/*
shield_it(SHIELD,"/d/ss/daggerford/ladyluck");
*/
::init();
add_action("do_overload","overload");
}

void reset() {
if (!port)
 {
  port=clone_object(ROOM+"field");
  port->set_short("field (glowing)");
  port->move(this_object());
}
}
void setup() {
blocked=0;
lifter="";
set_light(100);
set_short("castle entry");
set_long("You stand upon the entrance to the Palace of the Gods, A glowing "+
"portal serves as the doorway into the interior of the palace.  You cannot see "+
"through the portal.  You shiver as you feel the power of the portal.\n");
add_item("corridor","The only way go north would be to lift the pass the field.\n");
add_item("portcullis","It glows a fierce red.  It pulsates with power.\n");
add_exit("south",ROOM+"path1","path");
add_exit("north",ROOM+"palace1","road");
modify_exit("north",({"function","go_north","message","N$N walks through the field."+
" The field flares up and engulfs N$N.\n"}));

}

int go_north() {
 if(this_player()->query_lord()) {
 return 1;
 }
if (blocked==1) {
 if (lifter==(string)this_player()->query_cap_name()) {
    say("The field reappears as "+this_player()->query_cap_name()
+ "releases it.\n");
    port->set_short("Field (glowing)");
    blocked=0;
     lifter="";
     }
  return 1;
  }
notify_fail("You run right into the field!  You feel momentarily disoriented.\n");
say(this_player()->query_cap_name()+" goes north. The portal flares.\n");
}

int do_overload(string str) {
 if (str == "field") {
  say(this_player()->query_cap_name()+" approaches the field.\n");
  if ((string)this_player()->query_guild_ob()=="/std/guilds/priest")  {
    write("You attempt to overload the field with your immortal power.\n"+
     "The field shimmers and dissapears, but you feel it pressing against "+
     "the power limits of inanimate objects to reinstate itelsef.\n"+
     "You keep overloading it.\n");
    say(this_player()->query_cap_name()+" stares at the field and "+
"concentrates.\n"+
 "The field shimmers, then vanishes.\n");
    blocked=1;
    lifter=(string)this_player()->query_cap_name();
 port->set_short("Field (overloaded by "+(string)this_player()->query_cap_name()+".)");
    return 1;
   }
  write("What?.\n");
  say(this_player()->query_cap_name()+" looks seriously confused.\n");
  return 1;
}

}
void dest_me()
{
if (port)
port-> dest_me();
::dest_me();
}

