#include <std.h>
inherit WEAPON;

int weapon_hit(object atk);
create() {
::create();
set_id(({"A massive steel hammer", "hammer", "steel hammer", "massive hammer", "massive steel hammer"}));
set_name("hammer");
set_short("A massive steel hammer");
set_long("This hammer is heavy and quite large.  It looks quite powerful although it might tire the weak.");
set_weight(30);
set_curr_value("gold",100);
set_wc(11); // i lowered the wc, a little too uch for that easy to get -- seeker
set_ac(1);
set_type("blunt");
set_hands(2);
set_wield("%^MAGENTA%^You strain at first to lift the hammer but quickly become accustomed to it.%^RESET%^");
set_hit((:weapon_hit:));
}

int weapon_hit(object atk)
{
int result;
if(random(100) > 90) {
write("%^MAGENTA%^A heavy hit %^BOLD%^BLACK%^CRUSHES%^RESET%^MAGENTA%^ your foe causing a terrible cracking sound!%^RESET%^");
say((string)"%^MAGENTA%^You hear a disgusting cracking sound of breaking bones as "+this_player()->query_cap_name()+"'s hammer %^BOLD%^BLACK%^CRUSHES%^RESET%^MAGENTA%^ its victim!%^RESET%^");
result=(random(15))+((this_player()->query_level()/2));
return result;
}
}
int query_auto_load() {return 1; }
