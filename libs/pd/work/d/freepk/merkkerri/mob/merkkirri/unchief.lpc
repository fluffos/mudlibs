#include <mjungle.h>
#include <std.h>
inherit UNDEAD;

void create() {
::create();
set_name("undead warchief");
set_short("%^BOLD%^YELLOW%^Undead Warchief%^RESET%^");
set_long("This is the corpse of a once mighty Merkkirri Warchief.  At one time he probably led the Merkkirri to slaughter hundreds of innocent villagers.  Odds are that he is not much friendlier in death.");
set("aggressive", 19);
set_id(({"undead", "warchief", "undead warchief", "chief"}));
set_skill("melee", 180);
set_skill("attack", 180);
set_race("undead");
set_class("fighter");
set_subclass("warrior");
set_stats("strength", 70);
set_stats("dexterity", 70);
set_body_type("gnoll");
set_gender("male");
set_spell_chance(27);
set_skill("charging", 300);
set_spells(({"rush"}));
add_money("gold", (random(250)));
add_money("electrum", (random(250)));
new(MOB "warhelm")->move(this_object());
new(MOB "mask")->move(this_object());
new(MOB "shimmergll")->move(this_object());
new(MOB "shimmerglr")->move(this_object());
new(MOB "shimmerbor")->move(this_object());
new(MOB "shimmerbol")->move(this_object());
command("wear all");
set_lang_prof("merkish", 10);
set_level(35);
set("alignment", -1000);

}
