#include <std.h>
#include <diran.h>

inherit MOB"mob_inherit";

void create() {
::create();
    set_name("elder");
    set_short("a mountain dwarf elder");
    set_long("This sturdy looking mountain dwarf is a member of the city's elders.  She protects the city against the Duergar.");
    set_id(({"elder", "dwarf", "mountain dwarf", "mountain dwarf elder", "mdelderf"}));
    set_level(46);
    set_race("dwarf");
    set_body_type("dwarf");
    set("aggressive",20);
    set_gender("female"); 
        set_faction("diran");
    add_money("gold", random(75));
   new(ARM"mdefsweater")->move(this_object());
     force_me("wear sweater");
        new(ARM"mdefpants")->move(this_object());
     force_me("wear pants");
             new(ARM"mdefring")->move(this_object());
     force_me("wear ring");
                  new(ARM"mdefnecklace")->move(this_object());
     force_me("wear necklace");
}


