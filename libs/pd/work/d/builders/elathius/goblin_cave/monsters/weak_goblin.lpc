#include <std.h>

#include <caves.h>

inherit MONSTER;

void create()  {
::create();
    set_name("goblin guard");
    set_short("weak goblin guard");
    set_id(({"monster", "goblin", "guard"}));
    set_long("This is a small goblin, one of the weakest you'll probably find.");
    set_level(55);
    set("aggressive", 60);
    set_swarm(1);
    set_gender("male");
    set_race("goblin");
    set_heart_beat(1);
    set_class("fighter");
    set_subclass("warrior");
    set_body_type("goblin");
    set_spell_chance (100);
    set_spells(({"slash"}));
  
    new(WEAPONS"weak_sword") ->move(this_object());
    force_me("wield sword");
    new(WEAPONS"weak_sword") ->move(this_object());
    force_me("wield sword");
    new(EQUIPMENT"goblin_platemail") ->move(this_object());
    force_me("wear platemail");
}
