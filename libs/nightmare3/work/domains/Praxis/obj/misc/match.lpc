/*    /d/standard/obj/misc/match.c
 *    from Nightmare IV
 *    a match used to light other things
 *    created by Descartes of Borg 940427
 */

#include <std.h>

inherit LIGHT;

void create() {
    light::create();
    set_name("match");
    set_id( ({ "match", "matchstick" }) );
    set_adjectives( ({ "a", "small", "wooden" }) );
    set_short("a small match");
    set_long( "A small match made of wood with a flamable strike-point "
      "at the tip.  Evidently, if you strike it, it will catch fire."
    );
    set_light(1, "strike", "extinguish");
    set_fire(1);
    set_fuel_required(1);
    set_fuel(45);
    set_source_required(0);
    set_disable_weapon(1);
    set_light_function( (: this_object(), "strike_match" :) );
    set_mass(10);
    set_value(11);
    set_burnt_value(10);
}

int strike_match(object ob) {
    if(random(100) > 50) {
        write("You strike the match and it burns to life!");
        say((string)this_player()->query_cap_name()+" lights a match.");
        return 1;
    }
    else {
        write("You strike a match, but nothing happens.");
        say((string)this_player()->query_cap_name()+" strikes a match, "
          "but nothing happens.");
        return 0;
    }
}
