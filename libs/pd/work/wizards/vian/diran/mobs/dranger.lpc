#include <std.h>
#include <diran.h>

inherit MOB"mob_inherit";

void create() {
::create();
    set_name("duergar ranger");
    set_short("a duergar ranger");
    set_long("This sturdy looking duergar is a member of the city's rangers.  He protects the city against the Mountain Dwarves.");
    set_id(({"ranger", "duergar", "duergar ranger", "dranger"}));
    set_level(51);
    set_race("dwarf");
    set_faction("duergar");
    set_body_type("dwarf");
    set("aggressive",20);
    set_gender("male"); 
    add_money("gold", random(75));
        new(ARM"mdgwhitepants")->move(this_object());
     force_me("wear trousers");
             new(ARM"drshirt")->move(this_object());
     force_me("wear shirt");
                  new(ARM"daquiver")->move(this_object());
     force_me("wear quiver");
                  new(WEP"mdabow")->move(this_object());
     force_me("wield bow");
         set_race("duergar");


}



