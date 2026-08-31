#include <std.h>

#include <caves.h>

inherit MONSTER;

void create()  {
::create();
    set_name("dwarven slave");
    set_short("dwarven slave");
    set_id(({"monster", "dwarf", "slave"}));
    set_long("This dwarf has been inslaved by the goblins and forced to mine the caves.");
    set_level(40);
    set_gender("male");
    set_race("dwarf");
    set_heart_beat(1);
    set_body_type("dwarf");
    set_spell_chance (100);
    set_skill("axe", 250);
    set_subclass("warrior");
    set_body_type("goblin");
    set_spells(({"hack"}));
  
    new(WEAPONS"pickaxe") ->move(this_object());
    force_me("wield pickaxe");
    new(EQUIPMENT"loincloth") ->move(this_object());
    force_me("wear loincloth");
}
