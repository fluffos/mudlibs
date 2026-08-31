#include <std.h>
inherit MONSTER;

void create() {
::create();
set_name("High Elf Cleric");
set_id(({"cleric","high elf","elf","high"}));
set_short("A cleric of the High Elf army.");
set_long("This is one of the females allowed to help the soldiers"
        " in battle. Many females have been banned from fighting"
        " in wars unless they prove themselves. This is one of them");
set("aggressive",1);
set_class("fighter");
set_race("elf");
set_body_type("human");
set_alignment(1500);
set_level(99);
set_skill("blunt", 300);
set_skill("attack", 250);
set_skill("defense",200);
set_stats("strength",150);
set_gender("female");
set_spell_chance(1000);
set_spells(({"lifetap"}));
new("/d/helves/wpn/l_blunt")->move(this_object());
new("/d/helves/arm/clericrobes")->move(this_object());
set_heart_beat(1);
command("wield scepter");
command("wear robes");

}
