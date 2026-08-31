#include <std.h>
inherit MONSTER;

void create() {
::create();
set_name("demon");
set_short("chaos demon");
set_long("%^GREEN%^The chaos demon appears as a swirling mass of colors in the form of a four-armed demon.  It's face is featurless except for three voids that seem to serve as eyes near its forehead and forming in the shape of a triangle pointed down.  While the demon is comprised of many colors, the majority of the creature is a swirling royal blue.");
set_id(({"demon", "chaos demon"}));
set_level(50);
set_hp(1700);
set_stats("strength", 50);
set_skill("blade", 200);
set_skill("attack", 200);
set_stats("dexterity", 45);
set_skill("defense", 175);
set_skill("magic attack", 250);
set_skill("faith", 125);
set_skill("healing", 150);
set_stats("constitution", 100);
set_race("Demon");
set_body_type("artrell");
set_gender("male");
set_emotes(10, ({"The demon swirls into a dark %^MAGENTA%^violet%^RESET%^.", "The demon swirls into a %^BLUE%^royal blue%^RESET%^.", "The demon swirls into a %^BLUE%^royal blue%^RESET%^.", "The demon swirls into a %^BLUE%^royal blue%^RESET%^.", "The demon swirls into an eerie %^GREEN%^green%^RESET%^.", "The demon seems to %^BOLD%^BLACK%^darken%^RESET%^."}), 0);
set_spell_chance(20);
set_spells(({"whirl", "slash", "rapture", "annihilate"}));
new("wizards/armrha/wep/csword")->move(this_object());
new("/wizards/armrha/wep/csword")->move(this_object());
new("/wizards/armrha/wep/sword")->move(this_object());
new("/wizards/armrha/wep/sword")->move(this_object());
command("wield sword");
command("wield sword 2");
command("wield sword 3");
command("wield sword 4");
}
