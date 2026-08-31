#include <swamp.h>
#include <std.h>
inherit MONSTER;

void create() {
::create();
set_name("swamp devil");
set_short("swamp devil");
set_long("Swamp devils are not really devils but instead lizard-like inhabitants of the Merkkirri swamp.  They have noticeably large dorsil fins and seaweed like beards.");
set("aggressive",  30);
set_swarm("");
set_id(({"swamp devil", "devil"}));
set_skill("attack", 205);
set_class("kataan");
set_subclass("none");
set_alignment(-800);
set_skill("projectile", 200);
set_stats("intelligence", 90);
set_stats("wisdom", 60);
set_race("swamp devil");
set_body_type("human");
if(random(10) > 2) set_gender("male"); else set_gender("female");
set_spell_chance(40);
set_spells(({"impale"}));
set_level(40);

new(MOB "swampspear")->move(this_object());
command("wield spear");
}
