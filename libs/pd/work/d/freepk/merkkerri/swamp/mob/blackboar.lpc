#include <swamp.h>
#include <std.h>
inherit MONSTER;

void create() {
::create();
set_name("boar");
set_short("black boar");
set_long("Black boars are mean tempered hogs that populate the swamp.  They
feed on seaweed and tangleweeds which are unable to grasp the boar due to its
strange fur which tears the plant.  ");
set("aggressive",  30);
set_id(({"hog", "black boar", "boar"}));
set_class("fighter");
set_subclass("warrior");
set_alignment(0);
set_race("hog");
set_body_type("hog");
if(random(5) > 2) set_gender("male"); else set_gender("female");
set_spell_chance(25);
set_skill("charging", 300);
set_spells(({"rush"}));
set_level(43);

}
