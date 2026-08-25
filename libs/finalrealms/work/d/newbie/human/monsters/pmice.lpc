#include "path.h"
inherit "/obj/monster";

void setup()
{
    set_name("pirate");
    set_short("Pirate");
    set_gender(1);
    set_level(8+random(4));
    set_random_stats(8,4);
    set_long("A scruffy and somewhat depressed looking pirate, he still looks "
    "pretty mean. He has some interesting looking scars on his face. "
    "He sneers at you. "
    "\n");
   set_al(250);
    load_chat(20, ({
        1,":growls",
        1,"'You don't know a way off this scummy little island, do you ?",
        1,"'Have you got anything to drink ?",
        1,"'Where's the captain when you need her ?"
    })
    );
    load_a_chat(300, ({
        1,"'I've fought better fish than you.",
        1,"Pirate sneers.",
        1,"'I've seen jellyfish wield weapons better than you.",
        1,"Pirate spits on you."
    }));
    new("/baseobs/armours/leather")->move(this_object());
   new(OBJ+"boots")->move(this_object());
    new("/baseobs/weapons/dagger")->move(this_object());
   adjust_money(5+random(5),"silver");
   init_equip();
}





