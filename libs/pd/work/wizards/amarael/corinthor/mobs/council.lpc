#include <std.h>
#include <corinthor.h>
inherit MONSTER;

void create() {
   ::create();
        set_name("elf");
        set_id( ({"council", "elf", "monster"}) );
        set_heart_beat(1);
        set_short("a Council of Corinthor.");
        set_long("The Corinthian council are here to make sure that the king remains fair and just in all judgements. If it is deemed that the King is unable to rule, it is up to them to bring in a new ruler.");
        set_race("elf");
        if(random(2) == 1) set_gender("male");
        else set_gender("female");
        set_body_type("elf");
        set_level(14);
        set_alignment(10);
	set_class("mage");
	set_subclass("wizard");
        set_skill("magic attack", 45);
        set_spell_chance(20);
	set_spells(({"missile"}));
}
