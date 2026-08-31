#include <std.h>
inherit WEAPON;

int weapon_hit(object atk);

create() {
    ::create();
    set_id(({"rod", "rusted rod"}));
    set_name("rod");
    set_short("a rusted rod");
    set_long( "A long metal rod, rusted with age.");
    set_mass(10);
    set_curr_value("gold",100+random(40));
    set_wc(8);
    set_type("blunt");
    set_wield("Your hands tingle from the rod.");
    set_unwield("You unwield the rod, grinning happily.");
    set_hit((:weapon_hit:));  
}
int weapon_hit(object atk)
{
    int result;
    if(random(102) > 85) {
        write("Your rod heals you.");
        say((string)this_player()->query_cap_name()+"'s rod glows, draining "+this_player()->query_possessive()+".");
        result = 10 + random(25) - random(10) * (this_player()->query_level()/15);
        result = random(result);
        this_player()->add_hp(result);
        return result;
    }
}
int query_auto_load() { 
    if(this_player()->query_level() > 19)
    return 1;
}
