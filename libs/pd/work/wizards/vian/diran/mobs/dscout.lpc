#include <std.h>
#include <diran.h>

inherit MOB"mob_inherit";

void create() {
::create();
    set_name("duergar scout");
    set_short("a duergar scout");
    set_long("This sturdy looking duergar is a member of the city's scouts.  He protects the city against the Mountain Dwarves.");
    set_id(({"scout", "duergar", "duergar scout", "dscout"}));
    set_level(51);
    set_race("dwarf");
    set_body_type("dwarf");
    set("aggressive",20);
    set_faction("duergar");
    set_gender("male"); 
    add_money("gold", random(75));
        set_spell_chance(20);
    set_spells(({"stab", "kick", "punch"}));
        new(ARM"dgpants")->move(this_object());
     force_me("wear pants");
             new(ARM"dgshirt")->move(this_object());
     force_me("wear shirt");
                  new(WEP"mdsknife")->move(this_object());
     force_me("wield dagger");
    set_race("duergar");

}
