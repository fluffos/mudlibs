#include <std.h>
inherit MONSTER;

void create() {
::create();
set_name("Soldier");
set_short("A Camouflaged Soldier");
set_long("A Camouflaged Soldier, hiding in the woods using branches.");
set("aggressive",15);
set_swarm("soldier");
set_class("fighter");
set_level(40);
set_id(({"soldier"}));
set_skill("defense",200);
set_race("human");
set_body_type("human");
set_gender("male");
set_skill("blunt", 150);
set_skill("attack", 149);
set_spell_chance(25);
set_spells(({"maul", "whirl"}));
set_emotes(10, ({"You hear ruffling sounds in the jungle coming from branches."}),0);
new("/wizards/powerman/arm/bronhelm")->move(this_object());
new("/wizards/powerman/arm/bronarm")->move(this_object());
new("/wizards/powerman/arm/bronboot")->move(this_object());
new("/wizards/powerman/arm/brongaun")->move(this_object());
new("/wizards/powerman/arm/malshiel")->move(this_object());
command("wear all");
new("/wizards/powerman/arm/branch")->move(this_object());
new("/wizards/powerman/arm/branch")->move(this_object());
command("wield branch");
command("wield branch 2");
set_languages("farsi");
set_speech(35,"farsi",({"We've been discovered!", 
"Long live our rightful king, Malcolm!", "Curses!"}),1);

}
