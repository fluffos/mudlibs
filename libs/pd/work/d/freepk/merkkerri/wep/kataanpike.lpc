#include <std.h>
inherit WEAPON;

int weapon_hit(object atk);
create() {
    ::create();
    set_id(({"kataan warpike", "warpike", "pike"}));
    set_name("kataan warpike");
    set_short("%^RESET%^MAGENTA%^K%^BOLD%^BLACK%^a%^RESET%^MAGENTA%^t%^BOLD%^BLACK%^aa%^RESET%^MAGENTA%^n %^RED%^Warpike%^RESET%^");
    set_long("%^MAGENTA%^The Kataan masters wield weapons of incredible power.  Kataan warpikes are given as gifts by the demon lords and are themselves possessed by a demon.  As the Kataan gains strength, the warpike becomes even more powerful.  The pike shaft is long and slender and the blade at the head is enormous.  This weapon is quite possibly the best you will ever use.%^RESET%^");
    set_value(0);
    set_weight(23);
    set_wc(13);
    set_ac(1);
    set_type("projectile");
    set_hit( (: weapon_hit :) );
    set_hands(2);
    set_wield("%^MAGENTA%^You feel a rush of power course through your %^RED%^blood%^MAGENTA%^ as you wield the weapon of the Kataan masters.%^RESET%^");
    set_unwield("%^MAGENTA%^You hear the laughter of %^RED%^demons%^MAGENTA%^ as you unwield the pike.%^RESET%^");
}

void init() {
    ::init();
    add_action("Destruct", "sell");
    add_action("wieldMe", "wield");
}
int wieldMe(string oi) {
    object ob;
    if (!oi) return 0;
    ob = present(oi, this_player());
    if (ob != this_object()) return 0;
    if (this_player()->query_subclass() != "kataan")
    {
	message("info", "Only the Kataan masters are able to harness the demonic
powers of the Warpike.",
this_player());
      return 1;
   }
if (this_player()->query_level() < 20)
{
      message("info", "Only the Kataan masters are able to harness the demonic
powers of the Warpike.",
this_player());
      return 1;
   }
   return 0;
}
int Destruct(string str) {
   if (!str) return 0;
   if (present(str, this_player()) != this_object()) return 0;
write("%^BOLD%^GREEN%^As you try to sell the warpike, it dissolves "
         "in your hands!");
   tell_room(environment(this_player()), this_player()->query_cap_name()+
"'s Kataan Warpike dissolves as "+
         this_player()->query_subjective()
         +"tries to sell it!", ({ this_player() }));
   this_object()->remove();
   return 1;
}

int weapon_hit(object atk) {
   int result;

if(random(100) > 87) {
write("%^RESET%^MAGENTA%^The warpike %^BOLD%^BLACK%^erupts%^RESET%^MAGENTA%^ in %^BOLD%^BLACK%^black flames%^RESET%^MAGENTA%^ and burns nastily as it strikes!%^RESET%^");
say((string)"%^MAGENTA%^"+this_player()->query_cap_name()+"'s Kataan warpike %^BOLD%^BLACK%^erupts %^RESET%^MAGENTA%^in%^BOLD%^BLACK%^ black flames%^RESET%^MAGENTA%^ and burns nastily as it strikes!%^RESET%^");
result = (this_player()->query_level())/2+(random(this_player()->query_level()));
      result=random(result)+1;
this_player()->add_mp(result/2);
this_player()->add_hp(result);
atk->set_paralyzed(random(2));
      return result;
   }
   return 0;
}

int query_auto_load() { if (this_player()->query_subclass("kataan"));
    return 1; }
