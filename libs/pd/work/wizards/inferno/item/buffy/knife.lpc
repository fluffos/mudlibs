#include <std.h>
inherit WEAPON;

int weapon_hit();
int query_auto_load();

void create() {
 ::create();
   set_name("dagger");
   set_short("%^BOLD%^%^YELLOW%^Da%^RED%^gg%^YELLOW%^er "
	"%^RESET%^of %^BOLD%^%^BLACK%^D%^BLUE%^oo%^BLACK%^m%^RESET%^");
   set_long("The whereabouts of this Dagger are very Mysterious. It "
	"has been around for as long as anyone can remember and Has a "
	"Very large diamond shaped blade which would do a lot of "
	"damage.");
   set_wc(16);
   set_weight(16);
   set_id(({ "doom", "dagger" }));
   set_value(0);
   set_type("knife");
   set_hit((: this_object(), "weapon_hit" :));
}

int weapon_hit(object ob) {
   object tp;
   int i;

   if (random(7000) > 900) return 0; 
   tp = environment(this_object());
   message("info", "Your dagger %^YELLOW%^glows%^RESET%^ with a "
	"bright %^YELLOW%^aura and cuts into "
	"%^RED%^"+ob->query_cap_name()+"'s chest with frightening "
	"%^BOLD%^%^BLACK%^evil.", tp);
   message("info", ""+tp->query_cap_name()+
	"cuts "+tp->query_possessive()+" into your "
	"%^RED%^chest%^RESET%^ with frightening "
	"%^BOLD%^%^BLACK%^evil", ob);
   message("info", "%^RED%^"+tp->query_cap_name()+
	"%^ORANGE%^ stabs %^RESET%^"+tp->query_possessive()+" dagger "
	"into "+
	ob->query_cap_name()+"'s %^RED%^chest%^RESET%^ with "
	"frightening %^BOLD%^%^BLACK%^evil!%^RESET%^",
	environment(tp), ({ tp, ob }));
   i = tp->query_level() - random(ob->query_level());
   if (i <= 25) i = 23;
   return i;
}

int query_auto_load() {
   if (this_player()->query_level() >= 5)
     return 1;
}
