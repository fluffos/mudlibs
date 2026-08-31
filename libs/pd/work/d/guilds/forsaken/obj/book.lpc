int query_auto_load() { 
    if(this_player()->query_guild() == "forsaken") return 1;
}
#include <std.h>
inherit WEAPON;

create() {
    ::create();
    set_id(({"book"}));
    set_name("%^ORANGE%^Book of Spells%^RESET%^");
    set_short("%^ORANGE%^Book of Spells%^RESET%^");
    set_long( "This is an old ancient tome with many spells written inside.");
    set_mass(10);
    set_curr_value("gold", 2000);
    set_wc(1);           
    set_ac(1);
    set_type("blunt");
    set_hands(2);
    set_wield("It takes you a few atemps but you finally lift up the book.");
    set_unwield("As you drop the book it falls on your foot, %^BOLD%^%^RED%^OUCH!%^RESET%^.");
}


void init() {
    ::init();
    if(this_player()->is_player() && environment(this_object()) == this_player()) set_short(this_player()->query_cap_name()+"'s %^ORANGE%^Book of Spells%^RESET%^");
    else set_short("%^ORANGE%^Book of Spells%^RESET%^");
}
