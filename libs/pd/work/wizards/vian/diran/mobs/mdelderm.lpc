#include <std.h>
#include <diran.h>

inherit MOB"mob_inherit";

void create() {
::create();
    set_name("elder");
    set_short("a mountain dwarf elder");
    set_long("This sturdy looking mountain dwarf is a member of the city's elders.  He protects the city against the Duergar.");
    set_id(({"elder", "dwarf", "mountain dwarf", "mountain dwarf elder", "mdelderm"}));
    set_level(46);
    set_race("dwarf");
    set_body_type("dwarf");
    set("aggressive",20);
        set_faction("diran");
    set_gender("male"); 
    add_money("gold", random(75));
   new(ARM"mdemsweater")->move(this_object());
     force_me("wear sweater");
        new(ARM"mdempants")->move(this_object());
     force_me("wear pants");
             new(ARM"mdemring")->move(this_object());
     force_me("wear ring");
}


