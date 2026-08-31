#include <std.h>
#include <diran.h>

inherit MOB"mob_inherit";

void create() {
::create();
    set_name("woman");
    set_short("a mountain dwarf woman");
    set_long("This sturdy looking mountain dwarf is a member of the city's women.  She protects the city against the Duergar.");
    set_id(({"woman", "dwarf", "mountain dwarf", "mountain dwarf woman", "mdwoman"}));
    set_level(44);
        set_faction("diran");
    set_race("dwarf");
    set_body_type("dwarf");
    set("aggressive",20);
    set_gender("female"); 
    add_money("gold", random(75));
   new(ARM"mdwring")->move(this_object());
     force_me("wear ring");
   new(ARM"mdwsweater")->move(this_object());
     force_me("wear sweater");
        new(ARM"mdwpants")->move(this_object());
     force_me("wear pants");
}


