#include <std.h>
#include <diran.h>

inherit MOB"mob_inherit";

void create() {
::create();
    set_name("duergar wizard");
    set_short("a duergar wizard");
    set_long("This sturdy looking duergar is a member of the city's wizards.  He protects the city against the Mountain Dwarves.");
    set_id(({"wizard", "duergar", "duergar wizard", "dwizard"}));
    set_level(51);
    set_race("dwarf");
    set_body_type("dwarf");
    set_faction("duergar");
    set("aggressive",20);
    set_gender("male"); 
    add_money("gold", random(75));
        new(ARM"dgpants")->move(this_object());
     force_me("wear pants");
             new(ARM"dgshirt")->move(this_object());
     force_me("wear shirt");
                  new(WEP"mdmstaff")->move(this_object());
     force_me("wield staff");
     
    set_race("duergar");

}



