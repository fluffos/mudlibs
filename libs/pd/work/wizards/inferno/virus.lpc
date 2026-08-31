#include <std.h>
inherit "/wizards/inferno/germ";

void create() {
 ::create();
   set_name("punchtothestomacheitis");
   set_contagious(0);
   set_halflife(100);
   set_lives(5);
   set_id(({ "punchitis" }));
   set_value(0);
}

void hit_me() { 
   object ob;
   ob = environment(this_object());
   tell_object(ob, "Two thugs run up to you, one holds you down and "
     "the other brutally punches you in the stomache!");
   ob->damage(5, "melee");
}
