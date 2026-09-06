/*
**
** skeleton.c
**
** (C) Tron
**
*/

#include <npc.h>



void
create_monster()
{

    set_name("skeleton");
    set_short("A living skeleton");
    set_long("This otherwise ordinary human skeleton has\n"+
      "a hollow look in his eyes and a faint blue aura.\n");
    set_level(10);
    set_hp(170);
    set_wc(15);
    set_ac(12);
    set(LIV_UNDEAD);
    set_wander(5);
    set(NPC_AGGRESSIVE);
}

void
killed_by(object ob) {

    string *tmp;

    tmp = ({
      "The skeleton drops down with quite a noise.",
      "Pieces of bones scatter all over.",
    });

    environment()->tell_here(tmp[random(sizeof(tmp))],this_object());
}
