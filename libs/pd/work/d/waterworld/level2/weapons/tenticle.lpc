#include <std.h>
#include <waterworld.h>
inherit WEAPON;
void create()   {
          ::create();

          set_name("tentacle");
          set_id(({"tentacle"}));
         set_short("the tentacle of some cephalopod");
         set_long("This is the severed tentacle of some cephalopod..");
          set_type("flail");
         set_wc(6);
        set_decay_rate(400);
          set_curr_value("gold",5);
}
int query_auto_load() {
        if(this_player()->query_skill("flail")>=30) {return 1;}
         else {return 0;}
}
