#include <std.h>
#include <zolenia.h>
inherit WEAPON;

int weapon_hit();
void create() {::create();;
     set_name("dragonsfury");;
     set_short("%^BOLD%^dr%^GREEN%^ago%^RESET%^%^GREEN%^nsfu%^BOLD%^%^WHITE%^ry%^RESET%^");;
     set_long("This blade is infused with magically altered scales of dragons, taking the very essence of a dragon's fury and putting it into a sword.");;
     set_id( ({"blade", "sword", "dragonsfury"}) );;
     set_hands(1);;
     set_wc(12);;
     set_ac(3);;
     set_curr_value("gold", 400+random(35));;
     set_type("blade");;
     set_wield("%^BOLD%^Dr%^GREEN%^ago%^RESET%^%^GREEN%^nsfu%^BOLD%^%^WHITE%^ry%^RESET%^%^BOLD%^ glows with extreme power as you wield it.%^RESET%^");
     set_hit((:this_object(),"weapon_hit":));;
}
int weapon_hit()
{
int result;
object atk;

     if(random(100) < 15) {write("The %^BOLD%^dr%^GREEN%^ago%^RESET%^%^GREEN%^nsfu%^BOLD%^%^WHITE%^ry%^RESET%^ pulsates with energy and strikes hard.");;
say((string)""+this_player()->query_cap_name()+"'s %^BOLD%^dr%^GREEN%^ago%^RESET%^%^GREEN%^nsfu%^BOLD%^%^WHITE%^ry%^RESET%^ pulses with energy as it strikes.");;
result=(random(30))+((this_player()->query_level())*1.25);;
return result;;
}
}
int query_auto_load() {
  return (this_player() && this_player()->query_level() > 39);
}

