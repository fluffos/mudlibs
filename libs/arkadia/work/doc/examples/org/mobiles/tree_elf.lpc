/*
 * tree_elf.c
 */

/*
 * This elf is sitting at the top of a large tree. If attacked, he simply 
 * pushes the attacker off the tree to :)
 */
#pragma strict_types

inherit "/std/monster";

#include "ex.h"	
#include <ss_types.h>   /* Skills and stats are defined in /sys/ss_types.h */
#include <stdproperties.h>      /* Properties */
#include <macros.h>	/* QTNAME and more nice definitions */

/*
 * The create routine
 */
void
create_monster()
{
    set_name("tree_elf");
    set_race_name("elf");
    set_adj("agile");
    set_long("He looks suspiciously back at you.\n");

    /*
     * Yet another way to set the stats in a mobile
     *           str  dex  con  int  wis  dic
     */
    set_stats( ({ 34,  60,  40,  65,  50,  63 }) );

    /*
     * When we give a mobile constitution and intelligence, mana, hp and
     * fatigue is not automatically updated. This make it possible to let
     * your mobile start out tired, or hurt. If the mobile is configured with
     * the default_config_mobile() function the refreshment is done
     * automatically.
     */
    refresh_mobile();

    /*
     * Since this mobile will push down its attackers we don't need to worry
     * about giving it much skills.
     */
}

/*
 * The function attacked_by() is called each time this object is attacked by
 * someone. We'll use it as a trigger and let the elf make his special move
 * when attacked.
 */
void
attacked_by(object ob)
{
    /*
     * So, ob attacked us, well, we use a call_out() and then push him off.
     * call_out() helps us call a function after some time has passed. More
     * is written in the room falling.c about call_out() or use can try the
     * man command. Using call_out() will hopefully make it look like the
     * elf is reacting on something rather than happen exactly the same
     * moment the player gives the kill command or whatever.
     */
    call_out("react", 1, ob);

    /*
     * Let the old version of attacked_by() be run too now that we have done
     * what we want.
     */
    ::attacked_by(ob);
}

/*
 * Here we do the pushing
 */
void
react(object ob)
{
    /*
     * Make sure ob is still around (in the same environment as this_object())
     * environment() give the environment to an object. If no argument is
     * given then this_object() is the default, so it wouldn't have to be
     * given down below.
     */
    if (!present(ob, environment(this_object())))
	return;

    /*
     * Stop the fighting
     */
    ob->stop_fight(this_object());
    this_object()->stop_fight(ob);

    /*
     * Write something to people who are looking. Third argument to tell_room()
     * makes sure ob doesn't get both messages.
     */
    tell_room(environment(), QCTNAME(this_object()) + " pushes " +
	QTNAME(ob) + " down the tree!\n", ob);

    /*
     * Since QCTNAME is an VBFC we can't use tell_object(). Instead we send
     * the message to catch_msg(), defined in all living objects.
     */
    ob->catch_msg(QCTNAME(this_object()) + " moves quickly and pushes you " +
	"down the tree!\n");

    ob->move_living("M", EX_ROOM + "falling", 1);
}
