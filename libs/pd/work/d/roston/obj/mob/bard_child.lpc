#include <std.h>
#include <roston.h>
inherit MONSTER;

void create() {
    ::create();
    set_name("bard child");
    set_id( ({ "monster" , "bard", "bard child", "child" }) );
    set_short("Bard Child");
    set_level(35);
    set_long("This is one of the children of the old Bard. He is singing softly to himself.");
    set_alignment(100);
    set_race("elf");
    set_body_type("elf");
    set_gender("male");
    set("aggressive", 20);
    set_spell_chance(20);
    set_spells( ({ "song of blades", "ballad of blood", "jab" }) );
    new(ARM"tunic")->move(this_object());
    force_me("wear tunic");
}
