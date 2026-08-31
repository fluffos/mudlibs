#include <std.h>
inherit WEAPON;
string *guilds = ({ "AoD", "darksoul" });
create() {
    ::create();
    set_id(({"knife","dark souls knife","darksouls knife"}));
    set_curr_value("gold", 200);
    set_name("dark souls knife");
    set_short("%^BOLD%^%^BLACK%^D%^WHITE%^a%^BLACK%^r%^WHITE%^k %^BLACK%^S%^WHITE%^o%^BLACK%^u%^WHITE%^l%^BLACK%^s %^WHITE%^K%^BLACK%^n%^WHITE%^i%^BLACK%^f%^WHITE%^e%^RESET%^");
    set_long( "%^BOLD%^%^WHITE%^This Knife was formed from the %^BLACK%^S%^WHITE%^o%^BLACK%^u%^WHITE%^l of a Ancient warrior.%^RESET%^");
    set_mass(15);
    set_curr_value("gold",90);
    set_wc(11);
    set_type("knife");
    set_hands(1);    
    set("skill level", 0);
    set_wield("%^BOLD%^%^BLACK%^The Power of past souls fills you.%^RESET%^");
    set_unwield("%^BOLD%^%^WHITE%^You feel the power of the souls leave you.%^RESET%^");
}
int query_auto_load() {
    if(member_array(this_player()->query_guild(),guilds)==-1) return 0;
    if(this_player()->query_level() < 40) return 0;

    return 1; 
}

int slap_on_the_wrist(string str) {
    if (!str || present(str, this_player()) != this_object()) return 0;
    if (member_array(this_player()->query_guild(),guilds)!=-1) return 0;
    write("%^BOLD%^%^RED%^YOU ARE NOT A DARKSOUL!!!!!!!!!!");
    say(this_player()->query_cap_name()+" prances around like a little girly person.", this_player());
    return 1;
}

void init() {
    ::init();
    add_action("slap_on_the_wrist", "wield");
}
