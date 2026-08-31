#include <std.h>
#include <aciri.h>
inherit WEAPON;

void create() {
 ::create();
   set_name("bow");
   set_short("a mystical bow");
   set_long("The bow has been enchanted with magic as old as the world itself. "
     "This bow is used by archers of a long lost faith.");
   set_weight(6);
   set_id(({ "bow", "mystical bow" }));
   set_wc(11);
   set_type("blunt");
   set_value(193);
   set_skill(70);
   set_hit((:this_object(),"weapon_hit":));
}

int query_auto_load() {
   if (this_player()->query_level() >= 35) return 3;
}

int weapon_hit() {
   int dmg;
   object ob, tp;
   tp = this_player();
   ob = tp->query_current_attacker();
   if(random(100) > 15) return 0;
   write("%^BOLD%^%^RED%^A web of fire launches from your bow and engulfs your "
     "opponent in flame!");
   say("%^BOLD%^%^RED%^A web of fire launches from "+tp->query_cap_name()+"'s "
     "bow and engulfs "+ob->query_cap_name()+"!");
   dmg = random(75) + tp->query_level() - (ob->query_level()/2);
   return dmg;
}
