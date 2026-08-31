#include <std.h>
inherit MONSTER;

void create() {
::create();
set_name("Soldier");
set_short("A Soldier of Macbeth's army");
set_long("A Typical Soldier, looking weary and unenthusiastic about the
battle.");
set("aggressive",20);
set_moving(1);
set_speed(10);
set_swarm("soldier");
set_subclass("soldier");
set_level(52);
set_id(({"soldier"}));
set_skill("double wielding", 150);
set_skill("attack", 199);
set_class("fighter");
set_skill("defense",250);
set_race("human");
set_body_type("human");
set_gender("male");
set_spell_chance(25);
set_spells(({"slash", "rush"}));
set_emotes(10, ({"The soldier sighs. It seems like that he does not have the
will to fight for Macbeth."}),0);
new("/wizards/powerman/arm/bronhelm")->move(this_object());
new("/wizards/powerman/arm/bronarm")->move(this_object());
new("/wizards/powerman/arm/bronboot")->move(this_object());
new("/wizards/powerman/arm/brongaun")->move(this_object());
new("/wizards/powerman/arm/macshiel")->move(this_object());
command("wear all");
new("/wizards/powerman/arm/brodswor")->move(this_object());
new("/wizards/powerman/arm/brodswor")->move(this_object());
command("wield sword");
command("wield sword 2");
command("sharpen sword");
command("sharpen sword 2");
set_languages("farsi");
set_speech(35,"farsi",({"I surrender!",
 "Long live our rightful king, Malcolm!", 
"May Macbeth never walk amongst the humans ever again!"}),1);

}
