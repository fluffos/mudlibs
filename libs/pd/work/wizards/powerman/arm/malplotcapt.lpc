#include <std.h>
inherit MONSTER;

void create() {
::create();
set_name("Captain");
set_short("A Captain of Malcolm's army, plotting the next move.");
set_long("The captain of his brigade, he controls how his set of troops act in
combat.");
set("aggressive",20);
set_class("fighter");
set_swarm("soldier");
set_level(57);
set_id(({"soldier","captain"}));
set_skill("attack", 220);
set_subclass("soldier");
set_skill("defense", 220);
set_race("human");
set_body_type("human");
set_gender("male");
set_skill("blade", 150);
set_spell_chance(40);
set_spells(({"behead"}));
set_emotes(10, ({
"%^CYAN%^The Captain plots: %^RESET%^We'll strike at dawn.", 
"The Captain ponders.",
"%^CYAN%^The Captain says:%^RESET%^ The Soldiers should be able to hold up Macbeth's army temporarily.",
"%^CYAN%^The Captain plots:%^RESET%^ Using this pincer move...", 
"The Captain wonders." }),0);
new("/wizards/powerman/arm/bronhelm")->move(this_object());
new("/wizards/powerman/arm/bronarm")->move(this_object());
new("/wizards/powerman/arm/bronboot")->move(this_object());
new("/wizards/powerman/arm/brongaun")->move(this_object());
new("/wizards/powerman/arm/malshiel")->move(this_object());
new("/wizards/powerman/arm/ironplat")->move(this_object());
new("/wizards/powerman/arm/finecape")->move(this_object());
command("wear all");
new("/wizards/powerman/arm/diasword")->move(this_object());
new("/wizards/powerman/arm/diasword")->move(this_object());
command("wield sword");
command("wield sword 2");
command("sharpen sword");
command("sharpen sword 2");
set_languages("farsi");
set_speech(35,"farsi",({"Attack Soldiers, Attack!", "My death will be an
honorable one.", "May Macbeth never walk amongst the humans ever again!"}),1);

}
