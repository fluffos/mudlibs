#include <npc.h>

#include <areas.h>

void
create_monster() {

    set_level(25);
    set_name("orc guard");
    set_id(({"guard", "orc"}));
    set_race("orc");
    set_short("Strong guard orc");
    set_long("This orc seems to be guarding something. He's very "+
      "strong looking and determinate to keep his post.");
    set(NPC_AGGRESSIVE);

    set_wc(30);
    set_ac(25);
    set_stat(ST_STR, 30);
    load_chat(5, ({ "Orc guard says: Get out!\n" }));
    load_a_chat(10, ({ "Alarm!!!\n", "Kill this bastard!\n",
	"You are not going to get pass me!\n" }));
}

void
heart_beat() {

    if(!random(10) && query_attack()) {
	move_object(clone_object(AREA_DUEL_ARENA + "npc/orc"),
	  environment());
	tell_room(environment(), "Orc arrives.\n");
    }
    ::heart_beat();
}
