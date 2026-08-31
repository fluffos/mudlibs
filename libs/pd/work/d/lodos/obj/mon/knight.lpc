#include <std.h>
#include <lodos.h>
inherit MONSTER;

void create() {
    ::create();
    set_short("a knight in armour");
    set_id( ({ "knight in armour", "knight" }) );
    set_name("knight");
    set_level(25);
    set_long("The knight in shining armour guards this tower instead "
      "of wandering the land, conquering evil.");
    set_body_type("human");
    set_race("human");
    set_gender("male");
    set_alignment(200);
    make(ARM"scalemail");
    make(WEA"javelin");
    force_me("wield javelin");
    force_me("wear scalemail");
}

