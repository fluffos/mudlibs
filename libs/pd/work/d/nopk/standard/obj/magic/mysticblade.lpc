#include <std.h>
inherit WEAPON;
int weapon_hit(object atk);
void create() {
    ::create();
    set_properties(([ "no store":1, ]));
    set_curr_value("gold", 0);
    set_hit ( (: weapon_hit :) );
}
int weapon_hit(object atk)
{
    int result, wcl;
    string weap;
    weap = this_object()->query_name();
    wcl = (int)this_object()->query_wc();
    if(random(100) > 89) {
     write("%^YELLOW%^Your "+weap+"%^YELLOW%^ glows causing "+atk->query_cap_name()+" to scream in pain!%^RESET%^");
     say("%^YELLOW%^"+this_player()->query_cap_name()+"'s "+weap+"%^YELLOW%^ glows breifly causing "+atk->query_cap_name()+" to scream in pain!%^RESET%^");
     tell_object(atk, "%^YELLOW%^You scream in pain as "+this_player()->query_cap_name()+"'s "+weap+"%^YELLOW%^ glows breifly.%^RESET%^");
     result=(random(15))+(wcl*5);
    }
}
