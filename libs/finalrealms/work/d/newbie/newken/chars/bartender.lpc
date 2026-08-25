#include "path.h"
inherit "/obj/monster";
void setup()
{
    set_name("bartenderess");
    add_alias("bartender");
    add_alias("kender");
    set_name("bartenderess");
    set_long(" This bartenderess is a cute, blonde Kender woman. She smiles "
      "and offers you a drink.\n");
    set_guild("handler");
    set_race("kender");
    set_alignment(-200);
    set_level(70+random(10));
    set_random_stats(15,23);
    set_join_fights();
    set_gender(2);
    add_clone(ITEM+"hoopak", 1);
    add_clone(ITEM+"handlercoat", 1);
    this_object()->init_equip();
}
