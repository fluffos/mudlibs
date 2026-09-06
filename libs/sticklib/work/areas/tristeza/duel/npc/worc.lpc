#include <areas.h>

#define	FOOP	AREA_TRISTEZA "duel/npc/orc"

inherit FOOP;


void
reset(status arg) {

    if(arg) return;

    write(previous_object());
    ::reset(arg);

    level=20+random(8);

    set_hp(level*8+250);
    set_ep(level*25000);


    set_wander(15);
    set_wimpy(0);

    msgout ="walks";

    move_object(clone_object(AREA_TRISTEZA "duel/obj/spear"),
      this_object());

    move_object(clone_object(AREA_TRISTEZA "duel/obj/shield"),
      this_object());

    command("wear shield");
    command("wield spear");

    set_short("Orc warlord");
    set_name("orc warlord");
    set_id("warlord");
    set_race("orc");
    set_ac(level + 15 + random(5));
    set_wc(25 + random(level/2));  
    set_keep_hb(1);
    l_chat();
}
