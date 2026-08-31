#include <std.h>
#include <diran.h>

inherit MOB"mob_inherit";

void create() {
::create();
    set_name("man");
    set_short("a mountain dwarf man");
    set_long("This sturdy looking mountain dwarf is a member of the city's men.  He protects the city against the Duergar.");
    set_id(({"man", "dwarf", "mountain dwarf", "mountain dwarf man", "mdman"}));
    set_level(46);
    set_race("dwarf");
    set_body_type("dwarf");
    set("aggressive",20);
    set_gender("male"); 
        set_faction("diran");
    add_money("gold", random(75));
   new(WEP"mdmsword")->move(this_object());
     force_me("wield sword");
   new(ARM"mdmsweater")->move(this_object());
     force_me("wear sweater");
        new(ARM"mdempants")->move(this_object());
     force_me("wear pants");
             new(ARM"mdmring")->move(this_object());
     force_me("wear ring");
}


