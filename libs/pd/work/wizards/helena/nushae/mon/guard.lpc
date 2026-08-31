#include <std.h>
#include <nushae.h>

inherit MONSTER;

void create() {
  ::create();
    set_id(({ "guard", "merguard" }));
    set_short("a palace guard");
    set_name("guard");
    set_level(25);
    set_long("Standing straight and rigid, the palace guard is ever alert and ready to give his life for the King and Queen.");
    set_body_type("merperson");
    set_race("merfolk");
    set_gender("male");
    new(WEAP "cspear")->move(this_object());
    this_object()->force_me("wield spear");
    new(ARM "ibracers")->move(this_object());
    this_object()->force_me("wear bracers");
}
