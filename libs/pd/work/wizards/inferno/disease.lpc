#include <std.h>
inherit "/wizards/inferno/germ";

void create() {
 ::create();
   set_name("aciditus");
   set_contagious(101);
   set_halflife(1000);
   set_lives(5);
   set_id(({ "aciditus" }));
   set_value(0);
}

void hit_me() { 
   object ob;
   ob = environment(this_object());
   tell_object(ob, "%^BOLD%^%^GREEN%^Acid comes out of the pores "
     "in your body and burns away your skin!");
   if (ob->query_name() != "amgis")
   ob->damage(random(50)+50, "acid");
   if (ob->query_hp() <= 0) ob->die();
}
