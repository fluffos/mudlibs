#include <std.h>
inherit MONSTER;

void create() {
::create();
set_name("Soldier");
set_short("A Helpless Soldier");
set_long("A Injured Soldier, resting from whatever wounds he has.");
set("aggressive",15);
set_swarm("soldier");
set_level(50);
set_id(({"soldier","monster"}));
set_class("fighter");
set_race("human");
set_body_type("human");
set_gender("male");
set_spell_chance(20);
set_spells(({"slash", "whirl"}));
set_emotes(10, ({"You hear ruffling sounds in the jungle coming from
branches."}),0);
new("/wizards/powerman/arm/bronhelm")->move(this_object());
new("/wizards/powerman/arm/bronarm")->move(this_object());
new("/wizards/powerman/arm/bronboot")->move(this_object());
new("/wizards/powerman/arm/brongaun")->move(this_object());
new("/wizards/powerman/arm/malshiel")->move(this_object());
command("wear all");
new("/wizards/powerman/arm/brodswor")->move(this_object());
command("wield sword");
set_languages("farsi");
set_speech(35,"farsi",({"Where is your honour attacking helpless soldiers?!",
"Long live our rightful king,
Malcolm!", "Curses!"}),1);

}
