#include <std.h>
inherit MONSTER;

void create() {
    ::create();
    set_name("Soldier");
    set_short("A Soldier of Malcolm's army");
    set_long("A Typical Soldier, looking weary and enthusiastic about the
battle.");
set("aggressive",20);
set_class("fighter");
set_moving(1);
set_speed(10);
set_swarm("soldier");
set_level(56);
set_id(({"soldier"}));
set_subclass("soldier");
set_skill("attack", 199);
set_skill("defense",250);
set_race("human");
set_body_type("human");
set_gender("male");
set_spell_chance(25);
set_spells(({"slash", "rush"}));
set_emotes(10, ({"The soldier looks weary. But the gleam of hope in his eyes is
still apparent."}),0);
new("/wizards/powerman/arm/bronhelm")->move(this_object());
new("/wizards/powerman/arm/bronarm")->move(this_object());
new("/wizards/powerman/arm/bronboot")->move(this_object());
new("/wizards/powerman/arm/brongaun")->move(this_object());
new("/wizards/powerman/arm/malshiel")->move(this_object());
command("wear all");
new("/wizards/powerman/arm/brodswor")->move(this_object());
new("/wizards/powerman/arm/brodswor")->move(this_object());
command("wield sword");
command("wield sword 2");
command("sharpen sword");
command("sharpen sword 2");
set_languages("farsi");
if(random(2))
set_speech(35,"farsi",({"Long live Scotland!", 
"My death will be an honorable one.", 
"May Macbeth never walk amongst the humans ever again!"}),1);

}
