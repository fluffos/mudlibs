#include <std.h>
inherit MONSTER;

int i;

void create() {
    ::create();
    set_name("Arctic bear");
    set_short("Arctic bear");
    set_id(({"monster", "bear", "artic bear"}));
    set_long("This is a huge bear that has made its home here in the tundra. A white pelt helps it to blend in with its surroundings.");
    set_level(30+random(6));
    set("aggressive", 15+random(5));
    if(random(2)) set_gender("male"); else set_gender("female");
    set_race("bear");
    set_heart_beat(1);
    set_class("fighter");
    set_subclass("warrior");
    set_body_type("human");
}

