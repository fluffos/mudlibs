#include <std.h>
#include <diran.h>

inherit MOB"mob_inherit";

void create() {
::create();
    set_name("duergar guard");
    set_short("a duergar guard");
    set_long("This sturdy looking duergar is a member of the city's guard.  He protects the city against the Mountain Dwarves.");
    set_id(({"guard", "duergar", "duergar guard", "dguard"}));
    set_level(50);
    set_race("dwarf");
    set_body_type("dwarf");
    set_faction("duergar");
    set("aggressive",20);
    set_gender("male"); 
    add_money("gold", random(75));
        set_spell_chance(20);
    set_spells(({"whirl", "kick", "punch"}));
        new(WEP"mdgwhip")->move(this_object());
     force_me("wield whip");
        new(ARM"dgpants")->move(this_object());
     force_me("wear pants");
             new(ARM"dgshirt")->move(this_object());
     force_me("wear shirt");
         set_race("duergar");


}



