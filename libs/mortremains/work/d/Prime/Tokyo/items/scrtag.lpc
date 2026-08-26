
#include "/u/d/dalceon/mydefines.h"
inherit OBJECT;

void create(){
    seteuid(getuid());

    set("prevent_drop",1);
    set("invisible",2);
    set("short", "tracker_object");
   set("id", ({ "tracker_object" }));
}

void init() {
   add_action("tell_orb", "go");
}

int tell_orb(){

   object *orbs;
   int i;
   orbs = children("/d/Prime/Tokyo/items/screen");
   for(i=0;i<sizeof(orbs);i++) {
      if(environment(orbs[i])) 
         orbs[i]->orb_tell(PENV->query("short"),orbs[i]);
   }
   return 0;
}
