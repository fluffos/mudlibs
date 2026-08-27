/*
 * hermit.c
 */

/*
 * This is the hermit that is sitting in cave1.c. Most living beings that are
 * not players should inherit /std/monster.c. If your mobile is not to have
 * two arms and two legs, the you should probably inherit /std/creature.c
 */
#pragma strict_types

inherit "/std/monster";

#include "ex.h"		/* This include was not really needed but if the hermit
			 * one day will have a staff or something might be good
			 * to have. */
#include <ss_types.h>   /* Skills and stats are defined in /sys/ss_types.h */
#include <stdproperties.h>      /* Properties */

/*
 * The create routine, called create_monster() in this case since we inherit
 * /std/monster.c
 */
void
create_monster()
{
    /*
     * First we'll give the hermit a name. It's not really necessary but
     * it's always nice. Players can then adress this hermit as 'hurble'.
     * To let them 'exa hermit' we add the name 'hermit' too. Both set_name()
     * and add_name() are functions defined in /std/object.c. Since all
     * objects inherit /std/object.c you can call these functions in all
     * objects.
     */
    set_name("hurble");
    add_name("hermit");

    /*
     * Living beings belong to a race. This one is human.
     */
    set_race_name("human");

    /*
     * Let's add some adjektives. The first adjektive we set to 'old' and
     * then we add 'skinny' too. This way players can both 'exa skinny hermit'
     * as well as 'exa old human' or 'exa old skinny hurble'. Nice, don't you
     * think?
     */
    set_adj("old");
    add_adj("skinny");

    /*
     * You don't have to set the long description in a mobile, but perhaps
     * it's more fun to have some additional information about the mobile?
     * The long description is what player will see when they examine or
     * look at this object.
     */
    set_long("It looks like he's been sitting here a while.\n");

    /*
     * The short description is what players see when they look in a room
     * or check their inventory. If you don't set the dhort description then
     * default will be used, which in case of living beings is all adjektives
     * added and the race name when not introduced. If introduced, the name
     * of the being. In this case, 'old skinny human' as unmet and 'hurble'
     * as met (introduced). Note that if you set this short description, it
     * will always be shown, both as unmet ans met description.
     */
    set_short("old skinny hermit");

    /*
     * Then we want to set the stats of the mobile. This hermit is not
     * particulary strong or intelligent or anything. 15 in all stats.
     */
    default_config_mobile(15);

    /*
     * Perhaps your mobile is skilled? This hermit is not, he just know
     * a little about herbalism. Try 'man skill_list' to see all skills
     * there are. The skills are defined in /sys/ss_types.h
     */
    set_skill(SS_HERBALISM, 30);

    /*
     * We want the hermit to say things, and do some actions too.
     * set_act_time() is used to indicate how often we want the mobile to
     * do something, as well as set_chat_time() how often he should talk.
     * The higher the value the long between actions.
     */
    set_act_time(5);
    add_act("emote makes some strange noise.");
    add_act("moan");
    add_act( ({ "say I can do stuff after eaechothers too.", "smile" }) );

    set_chat_time(7);
    add_chat("I don't get visitors very often.");
    add_chat("Please leave me, I like to be alone.");
    add_chat("Some people even gets afraid of me.");
    /*
     * It's possible to get the mobile to do and say other stuff if in a fight.
     * Then you use set_cact_time() and add_cact() resp. set_cchat_time() and
     * add_cchat(). If these are not set, then mobile will continue with normal
     * sayings and actions if fighting.
     */
}
