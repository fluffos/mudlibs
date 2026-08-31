#include <std.h>
inherit MONSTER;

void create() {
    string *name;
    int i;

    ::create();

    name = ({ "cave tiger", "white tiger", "fat tiger",
      "giant tiger","huge tiger", "arctic tiger",
      "devil tiger", "forest tiger", "young tiger",
      "baby tiger", "brown tiger", "baby white tiger",
      "black tiger", "baby black tiger"});

    i = random(sizeof(name));
    set_name("tiger");
    set_short(name[i]);
    set_level(i+40);
    set("aggressive", (i+25) );
    set_race("tiger");
    set_body_type("feline");
    set_gender("male");
    set_id(({ "tiger", name[i] }));
    set_long("This tiger roams the forbidden forest as the king of the "
      "forest.");
}
