#include "../defs.h"

inherit ROOM;

void create(){
  seteuid(getuid());
  set("author", "Waxer");
  set("light", 1);
  set_outside("zone", "2");
  set("short", "at the battle of Cephrin");
  set("long", @EndDesc
This is a small gorge, long dried in the vastly changing
temperatures of the Keldrosian seasons.  The crevace is
perhaps twelve feet across and sixteen feet deep.  On
the opposite side of the crevace the path has been split into
two directions.  You would have to jump accross to access either
side.  The gorge lays like a coffin beneath you.
EndDesc);

set("item_desc", ([ 
                 "skeletons" : "Fallen warriors to an unknown cause lie here like garbage.\n",
                 "armor" : "This armor is completely useless, it has rotten beyond use.\n",
]));
set("objects", ([ OBJ(f_armor) : 1, ]));
set("exits", ([
     "down" : ROOMS(gorge),
     "northwest" : ROOMS(b8),
     "northeast": ROOMS(b7),
     "east" : ROOMS(b5),
     "west" : ROOMS(b6),
     "south" : ROOMS(b2),
]));
set("pre_exit_func", ([ "northeast" : "foo", "northwest" : "foo" ]));
set("exit_suppress", ({ "down" }));

::create();
}
void init(){
  add_action("look","look");
}

int foo(){
int x;
if(wizardp(TP)) return 0;
  x = random(34)+5;
if(x > (int)TP->query("stat/strength")){
                              write("You fall into the gorge below in a failed jump!\n");
                             TP->receive_damage(random(20));
                             TP->move_player(ROOMS(gorge));
                             return 1;
                            }else{ write("You jump across the gorge with a mighty leap!\n"); return 0; }
}


void look(){
  object ob;
  object ske;
   ob= present("armor",TO);
if(!ob){return;}
   ob->remove();
ske = clone_object(MON(warrior));
ske->move(TO);
tell_object(TP, "The rusted suit of armor takes the form of a skeleton warrior which
attacks you on site!\n");
ske->kill_ob(TP);
}