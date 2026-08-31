#include <std.h>
inherit GERM;
 
void create() {
 ::create();
   set_contagious(10);
   set_halflife(1000);
   set_lives(5);
   set_id(({ "bigbadvirus" }));
   set_value(0);
}
 
void hit_me() {
   object ob = environment(this_object());

   tell_object(ob, "%^BOLD%^%^GREEN%^Acid comes out of the pores in your body and burns away your skin!%^RESET%^");
   ob->damage(random(20)+30, "acid");
}

int query_auto_load() { return 0; }
