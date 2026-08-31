#include <std.h>
inherit WEAPON;
 
int weapon_hit();

void create() {
    ::create();
    set_id(({"staff", "shortstaff"}));
    set_name("staff");
    set_short("%^ORANGE%^Sh%^RESET%^or%^ORANGE%^ts%^RESET%^ta%^ORANGE%^ff%^RESET%^");
    set_long("A short staff, just 3 feet in length. It can easily be handled
with one hand.");
    set_mass(15);
    set_curr_value("gold", 110);
    set_wc(1);           
    set_type("blunt");
    set_hands(1);
    //set_hit( (: this_object(),"weapon_hit" :) );
}

int weapon_hit() {
    int result, chance;
    string obname, tpname;
    obname = this_player()->query_current_attacker()->query_cap_name();
    tpname = this_player()->query_cap_name();
    if(random(10) == 0) {
      message("info", "%^ORANGE%^You smash "+obname+" mightily.%^RESET%^", this_player() );
      message("info", "%^ORANGE%^"+tpname+" smashes you mightily.%^RESET%^",
this_player()->query_current_attacker());
      message("info", "%^ORANGE%^"+tpname+" smashes "+obname+" mightily.%^RESET%^",
environment(this_player()), ({ this_player(),
this_player()->query_current_attacker() }) );
    result=(100 - random(50));
    this_player()->add_mp(result);
    return (result/3);
    }
}
 
int query_auto_load(){ 
    if(this_player()->query_guild()=="illuminati") return 1; 
}
