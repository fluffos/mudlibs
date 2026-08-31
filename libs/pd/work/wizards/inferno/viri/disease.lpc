#include <std.h>
inherit GERM;

void create() {
 ::create();
   set_name("aciditus");
   set_contagious(1);
   set_halflife(1000);
   set_lives(5);
   set_id(({ "aciditus" }));
   set_value(0);
}

void hit_me() { 
   object ob;
   ob = environment(this_object());
   tell_object(ob, "Acid comes out of the pores "
     "in your body and burns away your skin!");
   ob->damage(random(50)+50, "acid");
}
