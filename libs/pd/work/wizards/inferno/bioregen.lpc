#include <std.h>
inherit "/wizards/inferno/germ";

void create() {
 ::create();
   set_name("bioregen");
   set_contagious(0);
   set_halflife(100);
   set_lives(7);
   set_id(({ "bioregen", "germ" }));
   set_value(0);
}

void hit_me() { 
   object ob;
   ob = environment(this_object());
   if (ob->query_hp() >= ob->query_max_hp()) return;
   tell_object(ob, "%^BOLD%^%^GREEN%^The virus within you molds with "
	"your skin, healing you.");
   ob->heal(110 + random(200));
}
