#include <std.h>
inherit ARMOUR;

void create() {
    ::create();
    set_name("red scalemail boots");
    set_short("%^BOLD%^%^RED%^R%^RESET%^%^RED%^e%^BOLD%^%^RED%^d"
     "%^RESET%^%^RED%^ S%^BOLD%^%^RED%^c%^RESET%^%^RED%^a%^BOLD%^%^RED%^l"
     "%^RESET%^%^RED%^e%^BOLD%^%^RED%^m%^RESET%^%^RED%^a%^BOLD%^%^RED%^i"
     "%^RESET%^%^RED%^l %^BOLD%^%^RED%^B%^RESET%^%^RED%^o%^BOLD%^%^RED%^o"
     "%^RESET%^%^RED%^t%^BOLD%^%^RED%^s%^RESET%^");
    set_long("These boots were formed from the scales of the Great "
    "Fire Dragon. They were made for the general and are one of a kind.");
    set_id( ({ "boots" , "red boots","red scalemail boots" }) );
    set_ac(6);
    set_wear("%^RED%^Your feet seem to be surrounded by heat.");
    set_remove("%^BOLD%^%^RED%^The heat around your feet fades.");
    set_mass(17);
    set_curr_value("gold", 128);
    set_type("boots");
    set_limbs( ({ "right foot","left foot" }) );
}                  
int query_auto_load()
{
 if(this_player()->query_level() < 50) return 0;
 return 1;
}                   
