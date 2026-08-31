#include <std.h>
inherit GERM;

void create() {
 ::create();
   set_name("aciditus");
   set_contagious(77);
   set_halflife(1000);
   set_lives(7);
   set_id(({ "aciditus" }));
   set_value(0);
}

void hit_me() {
   object ob = environment(this_object());
   if (ob->query_name() != "amgis" && random(5) == 2) {
       tell_object(ob, "%^BOLD%^%^GREEN%^Acid comes out of the pores in your body and burns away your skin!");
       ob->damage(random(ob->query_level() * 2), "acid");

       if (ob->query_hp() <= 0)
           ob->die();
   }
}
