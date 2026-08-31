
#include <swamp.h>
#include <std.h>
inherit MONSTER;

int wraithgo();
void create() {
::create();
set_name("pixie");
set_short("tree pixie");
set_long("An extremely tiny pixie that resides in a miniature kingdom a top the tree.  It has delicate wings that resemble a dragonfly, lime green skin and glowing green eyes.");
set("aggressive",  0);
set_id(({"tree pixie", "pixie"}));
set_skill("magic attack", 250);
set_class("mage");
set_subclass("druid");
set_alignment(500);
set_skill("conjuring", 250);
set_skill("nature", 250);
set_skill("magic defense", 250);
set_skill("faith", 250);
set_stats("intelligence", 80);
set_stats("wisdom", 70);
set_race("pixie");
set_body_type("faerie");
if(random(10) > 2) set_gender("male"); else set_gender("female");
set_spell_chance(40);
set_spells(({"lash", "thornwrack", "icestorm", "bolt"}));
set_level(50);

new(MOB "pixieboots")->move(this_object());
command("wear boots");
new(MOB "pixiebelt")->move(this_object());
command("wear belt");
}
