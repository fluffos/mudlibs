#include "../defs.h"

inherit ROOM;

void create(){
  seteuid(getuid());
  set("author", "Waxer");
  set("light", 1);
  set_outside("zone", "2");
  set("short", "at the battle of Cephrin");
  set("long", @EndDesc
The ground is quite rough here.  Weeds and rocks
make movement quite difficult.  Farther to the west
a great forest of cedar and pine trees blankets the
mountain the battlefield rests on.  It seems there
is a large structure buried within the forest.  A castle
perhaps?  You can't get a good look from here.
EndDesc);

set("item_desc", ([ 
                 "skeletons" : "Fallen warriors to an unknown cause lie here like garbage.\n",
                 "armor" : "This armor is completely useless, it has rotten beyond use.\n",
]));
set("objects", ([ OBJ(f_armor) : 1, OBJ(f_helmet) : 1, ]));
set("exits", (["east" : ROOMS(b4), ]));

::create();
}
void init(){
  add_action("look","look");
}


void look(){
  object ob, ob2, ske, buf;
   ob2 = present("helmet",TO);
   ob= present("armor",TO);
if(!ob && !ob2){return;}
   ob->remove();
   ob2->remove();
ske = clone_object(MON(warrior));
buf = clone_object(MON(ghoul));
buf->move(TO);
ske->move(TO);
tell_object(TP, "The rusted suit of armor takes the form of a skeleton warrior which
attacks you on sight!\n");
ske->kill_ob(TP);
buf->kill_ob(TP);
}