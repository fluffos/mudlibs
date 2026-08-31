#include <std.h>
#include <diran.h>

inherit MOB"mob_inherit";

void create() {
::create();
    set_name("duergar psion");
    set_short("a duergar psion");
    set_long("This sturdy looking duergar is a member of the city's psions.  He protects the city against the Mountain Dwarves.");
    set_id(({"psion", "duergar", "duergar psion", "dpsion"}));
    set_level(50);
    set_race("dwarf");
    set_body_type("dwarf");
    set("aggressive",20);
    set_gender("male"); 
    set_faction("duergar");
    add_money("gold", random(75));
    set_spell_chance(20);
    set_spells(({"psisurge", "kick", "punch"}));
        new(WEP"mdmstaff")->move(this_object());
     force_me("wield staff");
        new(ARM"dgpants")->move(this_object());
     force_me("wear pants");
             new(ARM"dpshirt")->move(this_object());
     force_me("wear shirt");
         set_race("duergar");


}



