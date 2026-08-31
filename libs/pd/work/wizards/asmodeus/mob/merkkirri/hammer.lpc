#include <std.h>
inherit WEAPON;

int weapon_hit();
create() {
::create();
set_id(({"A massive steel hammer", "hammer", "steel hammer", "massive hammer", "massive steel hammer"}));
set_name("hammer");
set_short("A massive steel hammer");
set_long("This hammer is heavy and quite large.  It looks quite powerful although it might tire the weak.");
set_weight(30);
set_value(400);
set_wc(15); // i lowered the wc, a little too uch for that easy to get -- seeker
set_ac(1);
set_type("blunt");
set_hands(2);
set_wield("%^MAGENTA%^You strain at first to lift the hammer but quickly become accustomed to it.%^RESET%^");
set_hit((:this_object(),"weapon_hit":));
}

int weapon_hit()
{
int result;
object atk;
atk = (object)this_player()->query_current_attacker();
if(random(100) > 85) {
write("%^MAGENTA%^A heavy hit %^BOLD%^BLACK%^CRUSHES%^RESET%^MAGENTA%^ your foe causing a terrible cracking sound!%^RESET%^");
say((string)"%^MAGENTA%^You hear a disgusting cracking sound of breaking bones as "+this_player()->query_cap_name()+"'s hammer %^BOLD%^BLACK%^CRUSHES%^RESET%^MAGENTA%^ its victim!%^RESET%^");
result=(random(20))+((this_player()->query_level()));
return result;
}
}
int query_auto_load() {return 1; }
