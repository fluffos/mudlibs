#include <std.h>
inherit MONSTER;

void create() {
::create();
set_name("High Elf");
set_short("A member of the High Elf army.");
set_long("This is a common elf of the High Elf army. He stands taller"
        " than the average elf. He is fairly dressed with one of the biggest"
        " axes you have ever seen. He eyes you intently then smiles.");
set("aggressive",1);
set_class("fighter");
set_level(80);
set_id(({"soldier","elf","high elf","high"}));
set_skill("two handed", 300);
set_subclass("soldier");
set_skill("attack", 500);
set_skill("defense",200);
set_race("elf");
set_body_type("elf");
set_gender("male");
set_spell_chance(60);
set_spells(({"whirl"}));
new("/d/helves/wpn/h_axe")->move(this_object());
new("/d/helves/arm/soldierchainmail")->move(this_object());
command("wield axe");
command("wear chainmail");
set_exp(1050000);
}
