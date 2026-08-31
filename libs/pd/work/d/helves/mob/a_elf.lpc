#include <std.h>
inherit MONSTER;

void create() {
::create();
set_name("High Elf");
set_long("This is one of the most dangerous weapons of the high elves."
	" These are the ones called the fallen. They look just like"
	" the other high elves, but they seem a little different. It looks"
	" like their skin is tainted. And they seem to give off an aura"
	" of evil." );
set("aggressive",50);
set_class("rogue");
set_level(99);
set_id(({"rogue","elf","high elf","high"}));
set_skill("knife", 300);
set_subclass("soldier");
set_skill("attack", 500);
set_skill("defense",200);
set_stats("strength",200);
set_stats("dexterity",250);
set_race("elf");
set_body_type("elf");
set_gender("male");
set_spell_chance(60);
set_spells(({"circle"}));
set_alignment(1500);
new("/d/helves/wpn/fangs")->move(this_object());
new("/d/helves/arm/r_bracer")->move(this_object());
new("/d/helves/arm/r_boots")->move(this_object());
new("/d/helves/arm/r_cloak")->move(this_object());
command("wield fangs");
command("wear all");
set_exp(5050000);
}
