#include <std.h>
#include "ether.h"
inherit ETHERARM;
//pyro && kumi
void create() {
 ::create();
 set_name("shield");
 set_short("%^BLUE%^Shi%^BOLD%^%^BLUE%^el%^BOLD%^%^CYAN%^d %^BOLD%^%^WHITE%^of %^CYAN%^O%^BOLD%^%^BLUE%^me%^RESET%^%^BLUE%^ns%^RESET%^");
 set_long("This ornate %^RED%^shield is rather small. It seems quite fragile%^RESET%^, but somehow it seems to have been able %^RED%^to live through many battles."
          " It%^RESET%^ looks to be made of mithril, but it's hard%^RED%^ to know for sure. The shield has a magical%^RESET%^ aura surrounding it.");
 set_weight(50);
 set_id( ({ "shield","shield of omens" }) );
 set_curr_value("gold", 100);
 set_ac(4);
 set_limbs(({"left hand","left arm","torso"}));
 set_heart_beat(1);
 set_type("shield");
} 
int query_auto_load() {
  if (this_player()->query_level() > 35) return 1;
  else return 0; 
}
void heart_beat() {
   object kumi = this_object()->query_worn();
   object azire = (object)kumi->query_current_attacker();
   if(!kumi) return;
   if(random(100) > 78 && kumi->query_current_attacker()) {
        write("%^BOLD%^%^BLUE%^You swing your shield %^BLACK%^smashing%^BLUE%^ "+azire->query_cap_name()+" upside the head%^RESET%^.");
        tell_room(environment("%^BOLD%^%^BLUE%^"+this_player()), kumi->query_cap_name()+"%^BLACK%^ smashes%^BLUE%^ "+azire->query_cap_name()+" upside the head with "+this_object()->query_short()+"%^RESET%^.", ({ kumi }));
        (azire->set_paralyzed(random(2), "look.. birdies..", "The birdies fly away"));
   }
   set_heart_beat(1);
    return 1;
}
