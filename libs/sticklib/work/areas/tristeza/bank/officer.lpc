#include "locker_defs.h"

#define	FOOP	AREA_TRISTEZA "npc/citymonster"

inherit FOOP;

#include <npc_defs.h>

int has_shouted;

void
create_monster()
{
    set_name("Officer");
    set_id(({"officer"}));
    set_short("Officer");
    set_long("He's the storage officer.");
    set(NPC_SET_PK_FLAG, 1);
    set_gender(1);
    set_race("human");
    set_level(40);
    set_ac(20);
    set_hp(1000);
    set_ep(500000);
    return;
}

void
reset_monster()
{
    has_shouted = 0;
    return;
}

int
hit_player(int dam, int hc, int dtype, object enemy)
{
    if(!has_shouted && query_attack()) {
	shout(capitalize(name)+" shouts: Help! "+
	  query_attack()->query_name()+" is trying to kill me.\n");
	has_shouted = 1;
    }
    //fair fight, no target practising ++Tron
    if(query_verb() && this_player() && !this_player()->query_coder_level()) {
	this_player()->tell_me("The shopkeeper swiftly avoids your attempts \
and you only dreamed about the perfect hit.");
	return ::hit_player(0, hc, dtype, enemy);
    }
    return ::hit_player(dam, hc, dtype, enemy);
}

int
attacked_by(object orig, int to_top, int flags)
{
    if (to_top >= 0)
	extra_attacked_by(orig);

    return ::attacked_by(orig, to_top, flags);
}
