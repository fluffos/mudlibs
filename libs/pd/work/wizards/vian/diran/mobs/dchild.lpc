#include <std.h>
#include <diran.h>

inherit MOB"mob_inherit";

void create() {
::create();
    set_name("duergar child");
    set_short("a duergar child");
    set_long("This sturdy looking duergar is a member of the city's children.  He protects the city against the Mountain Dwarves.");
    set_id(({"child", "duergar", "duergar child", "dchild"}));
    set_level(22);
    set_race("dwarf");
    set_body_type("dwarf");
    set_faction("duergar");
    set("aggressive",20);
    set_gender("male"); 
    add_money("gold", random(75));
        new(ARM"dcpants")->move(this_object());
     force_me("wear pants");
             new(ARM"dcshirt")->move(this_object());
     force_me("wear shirt");
         set_race("duergar");


}

