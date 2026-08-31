#include <std.h>
inherit ARMOUR;

void create() {
    ::create();
    set_name("Red Scalemail Boots");
    set_short("%^BOLD%^%^RED%^R%^RESET%^%^RED%^e%^BOLD%^%^RED%^d"
     "%^RESET%^%^RED%^ S%^BOLD%^%^RED%^c%^RESET%^%^RED%^a%^BOLD%^%^RED%^l"
     "%^RESET%^%^RED%^e%^BOLD%^%^RED%^m%^RESET%^%^RED%^a%^BOLD%^%^RED%^i"
     "%^RESET%^%^RED%^l %^BOLD%^%^RED%^B%^RESET%^%^RED%^o%^BOLD%^%^RED%^o"
     "%^RESET%^%^RED%^t%^BOLD%^%^RED%^s%^RESET%^");
    set_long("These Boots were formed from the scales of the Great "
    "Fire Dragon. There were made for the General and are 1 of a kind.");
    set_id( ({ "boots" , "red boots","red scalemail boots" }) );
    set_ac(18);
    set_wear("%^RED%^Your Feet seem to be surrounded by heat.");
    set_remove("%^BOLD%^%^RED%^The heat around your feet fades.");
    set_mass(17);
    set_value(450);
    set_type("boots");
    set_limbs( ({ "right foot","left foot" }) );
}                  
int query_auto_load()
{
 if (wizardp(this_player())) return 1;
 return 1;
}                   
