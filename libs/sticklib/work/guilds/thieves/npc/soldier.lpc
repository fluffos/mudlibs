#include <npc.h>

#include "dirs.h"

void
create_treasure()
{
    set_name("soldier");
    set_id( ({ "soldier", "guild_guard", "mercenary", "thief_soldier" }) );
    set_short("Soldier");
    set_long(
      "A tough-looking mercenary, hired to defend the guild.");
    set_level(12+random(8));
    set_hp(75+20*level);
    set(NPC_YES_CONDITION);
    set_gender(random(2) + 1);
    set_money(random(100) + 99);
    set_alignment(AL_NEUTRAL);

    /*GRIN*/
    set_wc(18 + random(6));
    set_ac(17);

    call_out("check_beat",5);
}

check_beat()
{
    object g;
    remove_call_out("check_beat");
    if(!attacker_ob && !alt_attacker_ob && environment()) {
	g = present("guild_guard",environment());
	if(g && g->query_attack()) {
	    attack_object(g->query_attack());
	}
    }
    call_out("check_beat",5);
}
