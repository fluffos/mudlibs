#include <std.h>

inherit WEAPON;

int weapon_hit(object atk);

create() {
    ::create();
    set_id(({"staff", "oak staff"}));
    set_name("staff");
    set_short("an oak staff");
    set_long( "This oak staff appears to be an excellent weapon.");
    set_mass(9);
    set_curr_value("gold",30+random(40));
    set_wc(8);
    set_type("blunt");
    set_wield("The essence of life flows into your hands.");
    set_unwield("You unwield the staff.");
    set_hit((:weapon_hit:));
}
int weapon_hit(object atk)
{
    int result;
    if(random(102) > 93) {
        write("Your staff steals the life from your opponent.");
        say((string)this_player()->query_cap_name()+
          "'s staff drinks life from "
          +this_player()->query_possessive()+" opponent.");

        result=(random(10+random(25)-random(10))*((this_player()->query_level()/
15)));
        result=random(result)+1;
        this_player()->add_hp(result);
        return result;
    }
}
