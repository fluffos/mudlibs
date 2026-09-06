/*
 * Thief shop WILL trade with criminals, with higher sale and smaller
 * buy values of course. Also we don't care about theft crimes.
 *
 */

inherit "/lib/shop_store";

#include <room_defs.h>

#include "dirs.h"

/* New: Limit lockpicks, thieves got too clever :-)... */
/* Rised from 14 to 25 and 3 to 6 / Graah */
#define NO_OF_PICKS 15
#define NO_OF_VIALS 6

#define VALUE_HIDE  3001
#define VALUE_MAX   1000

#define ERASER \
move_object(clone_object(GDIR+"obj/eraser"),this_object())

#define PVIAL \
clone_object(GDIR + "obj/p_vial2")
#define LOCKPICK \
clone_object(GDIR + "obj/lockpick")
#define LANTERN \
move_object(clone_object(GDIR + "obj/lantern"),this_object())
#define OILFLASK \
move_object(clone_object(GDIR + "obj/oilflask"),this_object())

#include <armour_defs.h>

object *picks;
object *vials;

void vial_check()
{
    int i;
    for (i=0;i < sizeof(vials);i++)
	if (!vials[i])
	{
	    vials[i] = PVIAL;
	    move_object(vials[i],this_object());

	}
}
void
lockpick_check()
{
    int i;

    for (i = sizeof(picks) - 1; i >= 0; i--)
	if (!picks[i]) {
	    picks[i] = LOCKPICK;
	    move_object(picks[i], this_object());
	}
}

void
create_store()
{
    int i;
    object ob;

    set(NO_CLEANUP);
    picks = ({});

    vials = ({});
    for (i = 0; i < NO_OF_PICKS; i++) {
	ob = LOCKPICK;
	picks += ({ ob });
	move_object(ob, this_object());
    }
    for (i = 2 + random(3); i; --i) LANTERN;
    for (i = 2 + random(3); i; --i) OILFLASK;
    for(i = 2 + random(4);i;--i) ERASER;
    for (i=0;i < NO_OF_VIALS;i++)
    {
	ob = PVIAL;
	vials += ({ ob });
	move_object(ob,this_object());
    }
    /* Very rare, but possible */
    if (random(100) < 24)
	move_object(clone_object(GDIR + "obj/magic_lockpick"),
	  this_object());
    set_money(15000 + sizeof(users())*1000);
    set_min_value(30); /* Throw away all cheap items. */
}

void
reset_store()
{
    if (!present("lantern", this_object())) LANTERN;
    if (!present("oilflask", this_object())) OILFLASK;
    if (!present("eraser",this_object())) ERASER;

    /* Very rare, but possible */
    if (random(100) < 24)
	move_object(clone_object(GDIR + "obj/magic_lockpick"),
	  this_object());

    set_money(query_money() + sizeof(users()) * 300);
}

int accept_object(object ob) {

    if (ob->id("holy")) {
	notify_fail(
	  "Dildo tells you: Yuck! I don't like that item. Sell it elsewhere.\n");
	return 0;
    }

    if ((int)ob->query_value() <= 10) {
	notify_fail(
	  "Dildo tells you: How dare you bring me garbage! Toss it in trashcan!\n");
	return 0;
    }

    return 1;
}

int
adjust_buy_value(int value) {
    if (present("tmark", this_player())) {
	return ((2 * value + 1) / 3);
    }

    return ((3 * value + 1) / (5 +
	((int)this_player()->query_crime_level() > 1 ? 2 : 0)));
}

/* Slightly cheaper than other shops - if you are a thief. */
varargs int

adjust_sale_value(int v, object ob)
{
    if (present("tmark", this_player())) {
	return ((v * 40) / 21);
    }
    if (ob->query_thief_item()) return (v * 500);
    return (v * (5 +
	((int)this_player()->query_crime_level() > 1 ? 2 : 0)));
}

int count_value(object ob) {
    int value;

    if (!accept_object(ob)) return 0;

    if (value = (int)ob->query_value()) {
	destr_flag = (value > VALUE_HIDE);
	if (value > VALUE_MAX) value = VALUE_MAX;
	value = adjust_buy_value(value);
    }
    return value;
}
