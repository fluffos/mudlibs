/* Base Shopkeeper */

#include "citymonster.h"

int has_shouted; /* Has this shopkeeper shouted yet? */

void
reset_monster()
{
    has_shouted = 0;
}

void
create_monster()
{
    set_name("shopkeeper");
    set_id("keeper");
    set_level(40);
    set_hp(3500);
    set_wc(175);
    set(NPC_SET_PK_FLAG, 1);
    set_wander(0);
    set_wimpy(0);
    set_money((20 + random(40)) * 35 + random(100));
    set_alignment(-150 + random(301));
    set_race("human");
    set_group("cityguard");
    set_gender(random(2) ? G_MALE : G_FEMALE);
    set_long("A normal shopkeeper.");
    set_random_pick(7);
    set_ep(500000); /* Gives poor experience. */
    set_dead_ob(this_object());
}

hit_player(dam, dtype, hc, enemy)
{
    if (!has_shouted && query_attack()) {
	init_command("shout Help! "+
	  capitalize((string)query_attack()->query_real_name()) +
	  " is trying to kill me.");
	has_shouted = 1;
    }

    //fair fight, no target practising ++Tron
    if(query_verb() && this_player() && !this_player()->query_coder_level()) {
	this_player()->tell_me("The shopkeeper swiftly avoids your attempts "+
	  " and you only dreamed about the perfect hit.\n");
	return ::hit_player(0, dtype, hc, enemy);
    }
    return ::hit_player(dam, dtype, hc, enemy);
}

int
attacked_by(object orig, int to_top, int flags)
{
    int ret;
    if (!(ret = ::attacked_by(orig, to_top, flags)) || to_top < 0) return ret;
    extra_attacked_by(orig);

    return ret;
}

// Shopkeepers never flee!
int
run_away()
{
    int x;

    if (environment())
    {
	environment()->tell_here(query_name() +
	  " looks very angry!");
	x = query_wc() + 20;
	if (x > 250) x = 250;
	set_wc(x);
    }

    return 1;
}
