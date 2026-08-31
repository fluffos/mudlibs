#include <std.h>

#include <caves.h>

inherit MONSTER;

void create()  {
::create();
    set_name("goblin king");
    set_short("goblin king");
    set_id(({"monster", "goblin", "king", "razaak"}));
    set_long("The goblin king known as Razaak.");
    set_level(80);
    set("aggressive", 60);
    set_swarm(1);
    set_gender("male");
    set_race("goblin");
    set_heart_beat(1);
    set_skill("attack", 480);
    set_skill("defense", 400);
    set_skill("double wielding", 400);
    set_skill("blade", 480);
    set_stats("strength", 120); 
    set_stats("constitution", 120); 
    set_stats("dexterity", 120);
    set_class("fighter");
    set_subclass("warrior");
    set_body_type("goblin");
    set_spell_chance (100);
    set_spells(({"slash"}));
  
    new(WEAPONS"kings_sword") ->move(this_object());
    force_me("wield sword");
    new(WEAPONS"kings_sword") ->move(this_object());
    force_me("wield sword");
    new(EQUIPMENT"heavy_platemail") ->move(this_object());
    force_me("wear platemail");
    new(EQUIPMENT"spiked_helmet") ->move(this_object());
    force_me("wear helmet");
}
