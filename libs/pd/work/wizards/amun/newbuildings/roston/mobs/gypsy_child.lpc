#include <std.h>
inherit MONSTER;

void create() {
    ::create();
    set_name("gypsy child");
    set_id( ({ "monster" , "qypsy", "child", "gypsy child" }) );
    set_short("Gypsy Child");
    set_level(35);
    set_long("This is one of the children of the old Bard. She is a small gypsy, but is tougher than she looks.");
    set_alignment(100);
    set_race("faerie");
    set_body_type("faerie");
    set_gender("female");
    new("/wizards/amun/newbuildings/roston/armour/dress")->move(this_object());
    force_me("wear dress");
}
