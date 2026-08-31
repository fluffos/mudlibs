
#include <std.h>
inherit ROOM;

void create() {
   ::create();
   set_properties( ([
     "forest" : 1,
     "no bump" : 1,
     "outdoors" : 1
   ]) );
   set_short("Training Room");
   set_long("Vera's Training Room");
}

void init() {
   ::init();
   add_action("train","train");
   add_action("stop","stop");
}

int stop(string str) {
   object *inv;
   int i;
   if(str != "training")
   return notify_fail("Stop what?\n");
   inv = all_inventory(environment(this_player()));
   write("You end your training session.\n");
   for(i=0; i<sizeof(inv); i++) {
   if(!living(inv[i])) continue;
   inv[i]->cease_all_attacks();
   present("dummy", environment(this_player()))->remove();
   return 1;
   }
   return 1;
}

