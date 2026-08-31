#include <std.h>
inherit WEAPON;

string *guilds = ({ "AoD", "darksoul" });
int weapon_hit();

void create() {
    ::create();
    set_name("blade");

    set_short("%^ORANGE%^H%^RESET%^eron %^ORANGE%^M%^RESET%^arked %^ORANGE%^B%^RESET%^lade");
    set_long("The blade, very slightly curved and sharp only on one edge, bore a heron etched into the steel near the hilt. Short quillons, worked to look like braid, flanked the hilt. The balance is perfect the edge sharpened to perfection.");
    set_id( ({"blade" }) );
    set_hands(1);
    set_wc(11);          
    set_ac(2);   
    set_curr_value("gold", 100+random(35));
    set_type("blade");        
    set_hit((:this_object(),"weapon_hit":));
}
int query_auto_load()
{                                   
    if (this_player()->query_level() > 20) return 1;
}
int slap_on_the_wrist(string str) {
    if (!str || present(str, this_player()) != this_object()) return 0;
    if (member_array(this_player()->query_guild(),guilds) != -1) return 0;
    write("This does not belong to you!");
    say(this_player()->query_cap_name()+" yelps as Angrist burns them!",
      this_player());
    return 1;
}

void init() {
    ::init();
    add_action("slap_on_the_wrist", "wield");
}
