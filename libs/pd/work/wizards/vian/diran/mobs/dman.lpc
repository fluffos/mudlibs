#include <std.h>
#include <diran.h>

inherit MOB"mob_inherit";

void create() {
::create();
    set_name("duergar man");
    set_short("a duergar man");
    set_long("This sturdy looking duergar is a member of the city's men.  He protects the city against the Mountain Dwarves.");
    set_id(({"man", "duergar", "duergar man", "dman"}));
    set_level(51);
    set_race("dwarf");
    set_body_type("dwarf");
    set("aggressive",20);
    set_faction("duergar");
    set_gender("male"); 
    add_money("gold", random(75));
        new(ARM"dgpants")->move(this_object());
     force_me("wear pants");
             new(ARM"dgshirt")->move(this_object());
     force_me("wear shirt");
                  new(WEP"dwsword")->move(this_object());
     force_me("wield sword");
         set_race("duergar");


}



