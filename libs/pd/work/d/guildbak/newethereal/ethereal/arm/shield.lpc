//This item's variable names were edited by Venenum because they were rude, crude, and insulting towards a fine member of the Primal Darkness staff who has done far more then the rest of the MUD will ever know. Talk about biting the hand that feeds you.
#include <std.h>
#include "ether.h"
inherit ARMOUR;
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
 set_ac(3);
 set_limbs(({"left hand","left arm","torso"}));

 set_type("shield");
} 
int query_auto_load() {
  if (this_player()->query_level() > 35) return 1;
  else return 0; 
}

