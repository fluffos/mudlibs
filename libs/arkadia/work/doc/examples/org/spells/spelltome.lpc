/*
 *  spelltome.c
 *
 *  A nice tome that contains some spells for mortals to cast.
 *
 *  Contains the following spells:
 *
 *	stop fighting	Makes all fighting in a room stop for a while, by
 *			moving the special statuette into the room
 *			(/doc/examples/spells/obj/stop_statue.c)
 *			Needed:
 *			- mushroom (/doc/examples/spells/obj/stop_mushroom.c).
 *			- 45 mana.
 *
 *
 *	melt armour	Melts the worn pieces of armour of an opponent.
 *			Not worn pieces stay intact.
 *			Needed:
 *			- 30 mana.
 *
 *  Note that when you make an object that allows players to cast spells,
 *  you MUST also put descriptions of the spells in the directory
 *  /d/<yourdomain>/open/SPELLS/. But you already knew that, because you
 *  have read the /doc/man/general/spells doc, right? ;-)
 *                                                          Tricky
 *
 *  Fixed some things so the spelltome is more according to the docs.
 *  Thanks for the hints, Nick! :-)
 */

inherit "/std/spells";

#include "/secure/std.h"
#include "/sys/tasks.h"
#include "/sys/macros.h"
#include "/sys/ss_types.h"
#include "/sys/stdproperties.h"

#define SP_STOP_INGR ({ "_stop_spell_mushroom_" })
#define SP_STOP_MANA 45
#define SP_MELT_INGR 0
#define SP_MELT_MANA 60
#define STAND_DIR "/doc/examples/spells/obj/"

void
create_spells()
{
    set_name("tome");
    set_short("dusty tome");
    set_long(break_string(
	  "An air of magic emanates from the dusty tome. It has "
	+ "curly golden letters written on the front. "
	+ "You are unable to make out what they say, they must be written "
	+ "in some ancient handwriting. The tome does have a decipherable "
	+ "tomeindex, though. At least some parts of that page look "
        + "readable.\n",70));

    add_item(({"letters","golden letters"}), "The curly golden letters "
	+ "are gibberish for you.\n");

    set_adj("dusty");

    add_prop(OBJ_I_WEIGHT, 457);
    add_prop(OBJ_I_VOLUME, 503);

    /* And we have these spells... */
    add_spell("stop!", "do_stop_spell", "stop fighting");
    add_spell("melt!", "do_melt_spell", "melt armour");
    add_prop(OBJ_M_NO_DROP, "@@wiz_check");
    add_prop(OBJ_M_NO_GIVE, "@@wiz_check");
    add_prop(OBJ_S_WIZINFO, "@@wizinfo");
}

void
init()
{
    if (this_player() == environment())
       this_player()->add_prop("_freed_orc_prisoner_",1);
    add_action("do_read","read");
    add_action("do_destruct","tear");
}


string
query_auto_load()
{
    return MASTER_OB(this_object()) + ":";
}

void
init_arg(string str)
{
    return;
}

string
wizinfo() {
   return "More info? Simply read the tome, and you'll know all about it.\n";
}

int
do_read(string str)
{
    object tp;

    notify_fail("Read what?\n");
    if (!str)
	return 0;

    tp = this_player();
    str = lower_case(str);

    if (str == "tome" || str == "dusty tome")
    {
	notify_fail("The dusty tome is too big to read at once.\n"
		  + "Read the index to make a selection.\n");
	return 0;
    }
    if (str == "tomeindex")
    {
	say(QCTNAME(tp) + " opens " + tp->query_possessive() + " dusty tome "
	  + "and starts reading it.\n");
	write("You open the dusty tome on the index. You read:\n"
	+ "    Ye olde book of Great Magick ande High Spellcraft.\n"
	+ "\n"
	+ "    Instans Paecissimus ............ Tomepage 1\n"
	+ "    Shrinkissime Armorilla ......... Tomepage 2\n"
	+ "    Getting rid of the tome ........ Tomepage 9\n"
        + "\n"
        + "The rest of the index is unfortunately unreadable.\n");
	return 1;
    }
    if (str == "tomepage 1")
    {
	say(QCTNAME(tp) + " opens " + tp->query_possessive() + " dusty tome "
	  + "and starts reading it.\n");
	write("You open the dusty tome on tomepage 1. You read:\n"
	+ "     Instans Paecissimus\n"
	+ "     -------------------\n"
	+ "\n"
	+ "     The mighty spell of Instans Paecissimus is used by powerfull\n"
	+ "     spellcasters to stop all hostilities in a room.\n"
	+ "     This spell can only be cast if the proper ingredient, being\n"
	+ "     the rare tree-mushroom is held by the spellcaster.\n"
	+ "     Novice spellcasters will probably not succeed in casting\n"
	+ "     this spell.\n"
	+ "     Cast this spell with \"stop!\".\n");
	return 1;
    }
    if (str == "tomepage 2")
    {
	say(QCTNAME(tp) + " opens " + tp->query_possessive() + " dusty tome "
	  + "and starts reading it.\n");
	write("You open the dusty tome on tomepage 2. You read:\n"
	+ "     Shrinkissime Armorilla\n"
	+ "     ----------------------\n"
	+ "\n"
	+ "     This powerfull spell was invented by accident by a novice\n"
	+ "     sorceror who wanted to cast a 'warm up' spell on a knight\n"
	+ "     who felt cold. The spell did not warm up the knight, but\n"
	+ "     instead melted his armour, rendering it useless. The only\n"
	+ "     things left on the knights body were his magically protected\n"
	+ "     undergarment and his unworn gloves.\n"
	+ "     Skillfull spellcasters will be able to cast this spell\n"
        + "     successfully on an opponent, doing more damage when they\n"
	+ "     are more skilled.\n"
	+ "     Cast this spell with \"melt! <opponent>\".\n");
	return 1;
    }
    if (str == "tomepage 9")
    {
	say(QCTNAME(tp) + " opens " + tp->query_possessive() + " dusty tome "
	  + "and starts reading it.\n");
	write("You open the dusty tome on tomepage 9. You read:\n"
	+ "     Getting rid of this tome\n"
	+ "     ------------------------\n"
	+ "\n"
	+ "     If you are not pleased with this tome anymore, you can\n"
	+ "     simply tear it apart.\n");
	return 1;
    }

    /* Read was not meant for us */
    return 0;
}


int
do_tear(string str)
{
    object tp;

    notify_fail("Tear the tome apart.\n");
    if (!str)
	return 0;

    str = lower_case(str);
    if (str != "tome apart" && str != "the tome apart")
	return 0;

    tp = this_player();
    write("You tear the tome apart.\n");
    say(QCTNAME(tp) + " tears " + tp->query_possessive() + " tome apart.\n");
    remove_object();
    return 1;
}

/* Wizards may give the tome to someone else */
int
wiz_check()
{
    if (this_player()->query_wiz_level())
    {
	call_out("check_carry",1);
	return 0;
    }
    else
	return 1;
}

void
check_carry()
{
    if (!living(environment()) || environment()->query_npc())
	remove_object();
}

/*************************************************************************
 *
 *	Standard checks before a player is allowed to cast a spell:
 *	   + is the player a ghost?
 *	   + is the player a true Hin Warrior?
 *	   + does the player have all magical ingredients?
 *	   + does the player have enough mana?
 *	   - does the player have high enough skills?
 *
 *	And afterwards:
 *	   - remove the magical ingredients
 *	   - subtract the used mana
 *	   - perhaps add a little skill?
 *
 *					(+) handled in check_player().
 */


/*
 * Function name:   check_player
 * Description:     Check if the player matches a few tests. If not, the
 *                  reason is returned.
 * Arguments:       who: The player to check
 *                  ingr: if 0, the no magical ingredients are checked.
 *                        if object or list of objects, check if the player
 *                        posesses all of them.
 *                  mana: Required mana to cast the spell
 * Returns:         0 if the player turns out to be okay, the string
 *		    with the errormessage if something is wrong.
 */
mixed
check_player(object who, mixed ingr, int mana)
{
    int i, is_wiz;

    /*
     * Test for ghosts
     */
    if (who->query_ghost())
	return "You cannot do that in your state.\n";

    /* Make sure that wizards can always cast it */
    is_wiz = who->query_wiz_level();

    /*
     * Test for all magic ingredients
     */
    if (ingr)
    {
    	if (objectp(ingr))
	    ingr = ({ ingr });

	for (i=0; i < sizeof(ingr); i++)
	{
	    if (!is_wiz && !present(ingr[i],who))
		return "One of the magic ingredients is missing!\n";
	}
    }

    /*
     * Test if enough mana
     */
    if (!is_wiz && who->query_mana() < mana)
	return "You do not feel strong enough to cast the spell.\n";

    /* Passed all tests successfully */
    return 0;
}


/*
 * Function name:   find_ingr
 * Description:	    Finds the ingredients in a person.
 * Arguments:	    ingr: A string or an array of string of ingredients
 *			  It is advisable to give your special ingredients
 *			  a special extra name, like "MY_CARROT", so not
 *			  anyones carrot will be recognised...
 *		    who:  The person to be checked for the objects.
 * Returns:	    An array with the objects found, might be empty.
 */
object *
find_ingr(mixed ingr, object who)
{
    int i;
    object ob, *return_arr;

    return_arr = ({ });

    if (ingr)
    {
	if (objectp(ingr))
	    ingr = ({ ingr });

	for (i=0; i < sizeof(ingr); i++)
	{
	    if (ob = present(ingr[i],who))
		return_arr += ({ ob });
	}
    }
    return return_arr;
}


/*
 * Function name:   lose_random_ingr
 * Description:	    Destructs one random ingredient with a chance of 1/6th,
 *		    and tells the player that it happened.
 * Arguments:	    ingr: An array of objects of ingredients, as returned
 *			  by find_ingr()
 */
void
lose_random_ingr(object *ingr)
{
    int ran;

    if (sizeof(ingr))
    {
	if (random(6))
	    previous_object()->catch_msg("Luckily you manage to keep all "
		+ "ingredients intact.\n");
	else
	{
	    ran = random(sizeof(ingr));
	    previous_object()->catch_msg("Unfortunately you lose the "
		+ ingr[ran]->short() + " in the process.\n");
	    ingr[ran]->remove_object();
	}
    }
}


/*
 * Function name:   remove_ingr
 * Description:	    Destructs all ingredients, and tells the player that
 *		    it happened.
 * Arguments:	    ingr: An array of objects of ingredients, as returned
 *			  by find_ingr()
 */
void
remove_ingr(object *ingr)
{
    int s, i;
    string wrt, *str_arr;

    if (!ingr || !sizeof(ingr))
        return;

    wrt = "You sacrificed ";
    s = sizeof(ingr);

    if (s == 1)
        wrt += LANG_ADDART(ingr[0]->short()) + ".";
    else
    {
	str_arr = map(ingr, "map_short", this_object());
        wrt += LANG_ADDART(implode(str_arr[0..(s-2)], ", "))
             + " and " +  LANG_ADDART(str_arr[s-1]) + ".";
    }
    previous_object()->catch_msg(wrt);

    /* And remove the ingredients */
    for (i=0; i < s; i++)
	ingr[i]->remove_object();
}

string
map_short(object obj)
{
    return obj->short();
}

/*************************************************************************
 *
 *  The actual spells
 */

/*
 * Function name:   do_stop_spell
 * Decription:	    Cast the stop fighting spell.
 * Returns:	    1 if spell was cast, 0 otherwise.
 */
mixed
do_stop_spell()
{
    object tp, env, *ob_arr, *ingr_arr, obj;
    int i, power, is_wiz, success;
    string fail;

    tp = previous_object();
    env = environment(tp);

    if (env->query_prop(ROOM_I_NO_MAGIC))
	return "You are not allowed to cast a spell here.\n";

    if (present("statuette of nob nar", environment(tp)))
	return "It is unnecessary to cast that spell here.\n";

    if (fail = check_player(tp, SP_STOP_INGR, SP_STOP_MANA))
	return fail;

    /* Get the object array of all ingredients */
    ingr_arr = find_ingr(SP_STOP_INGR, tp);

    /* Let's see if the player can cope with the task... */
    if (!is_wiz &&
        (success = tp->resolve_task(TASK_DIFFICULT,
              ({ SKILL_WEIGHT, 50, SS_SPELLCRAFT,
                 SKILL_WEIGHT, 90, SKILL_AVG, SS_WIS, SS_INT, SKILL_END,
                 SS_FORM_CONJURATION,SS_ELEMENT_EARTH }) )) <= 0)
    {
	tp->catch_msg("You fail to cast the spell correctly.\n");
	tell_room(environment(tp), QCTNAME(tp) + " fails to cast a spell "
		+ "correctly.\n", tp);
	lose_random_ingr(ingr_arr);

	/* Make her pay for it anyway */
	tp->add_mana(-SP_STOP_MANA);

	return 1;
    }

    tell_room(env, QCTNAME(tp) + " calls upon Nob Nar to stop all "
	+ "fighting.\n", tp);
    tp->catch_msg("You call upon Nob Nar to stop all fighting.\n");

    if (env->query_prop(ROOM_I_INSIDE))
    {
       tell_room(env, break_string(
          "Outside you hear a deep rumble. "
        + "Suddenly a bolt of lightning cuts through the ceiling and impacts "
        + "on the floor! "
        + "When the light is gone, you see a statuette has appeared on that "
        + "same spot.\n",70));
    }
    else
    {
       tell_room(env, break_string(
          "Clouds gather above you and form a dense, gray blanket. "
        + "Suddenly a bolt of lightning springs from the clouds and impacts "
        + "on the floor! "
        + "When the light is gone, you see a statuette has appeared on that "
        + "same spot.\n",70));
    }

    /* Finally start casting the spell */

    seteuid(getuid());
    obj = clone_object(STAND_DIR + "stop_statue");
    obj->move(env);

    if (success > 30)
        obj->make_peace(300);
    else
        obj->make_peace(10*success);

    /* Make her pay for it */
    tp->add_mana(-SP_STOP_MANA);

    /* And remove the ingredients */
    if (!is_wiz)
        remove_ingr(ingr_arr);

    tell_room(env, QCTNAME(tp) + " casts a spell successfully.\n", tp);
    tp->catch_msg("You cast the spell successfully.\n");

    return 1;
}


int
filter_living(object obj)
{
    return living(obj);
}


/*
 * Function name:   do_melt_spell
 * Decription:	    Cast the melt armour spell.
 * Arguments:	    who: the person whose armour is to be melted.
 * Returns:	    1 if spell was cast, 0 otherwise.
 */
mixed
do_melt_spell(string who)
{
    object *arm_arr, target, tp, env, ob_arr, *ingr_arr;
    string arm_short, how, tmp, fail;
    int i, power, is_wiz, success, old_ac, new_ac, damage, res;

    tp = this_player();
    env = environment(tp);

    if (env->query_prop(ROOM_I_NO_MAGIC))
	return "You are not allowed to cast a spell here.\n";

    if (!who || !(target = present(lower_case(who),environment(tp))))
	return "Cast the spell on who?\n";

    /* Check if the spell can be cast */
    if (fail = check_player(tp, SP_MELT_INGR, SP_MELT_MANA))
	return fail;

    /* Get the object array of all ingredients */
    ingr_arr = find_ingr(SP_MELT_INGR, tp);

    if (!is_wiz &&
        (success = tp->resolve_task(TASK_ROUTINE,
              ({ SKILL_WEIGHT, 50, SS_SPELLCRAFT,
               SKILL_WEIGHT, 90, SKILL_AVG, SS_WIS, SS_INT, SKILL_END,
               SS_FORM_TRANSMUTATION, SS_ELEMENT_EARTH}))) <= 0)
    {
	tp->catch_msg("You fail to cast the spell correctly.\n");
	tell_room(environment(tp), QCTNAME(tp) + " fails to cast a spell "
		+ "correctly.\n", tp);
	lose_random_ingr(ingr_arr);

	/* Make her pay for it anyway */
	tp->add_mana(-SP_STOP_MANA);

	return 1;
    }

    /* Find all worn pieces of armour */
    arm_arr = filter_array(all_inventory(target),"filter_worn_armours",
			   this_object());
    if (!sizeof(arm_arr))
	return capitalize(who) + " doesn't wear any armour!\n";

    /* Start casting the spell */
    tp->catch_msg("You successfully cast a melt armour spell on "
	+ capitalize(who) + "...\n");
    tell_room(env, QCTNAME(tp) + " casts a spell on " + QCTNAME(target)
	    + ".\n", tp);

    /* Calculate the avarage of the magic resistance */
    res = (target->query_magic_res(MAGIC_I_RES_FIRE)
         + target->query_magic_res(MAGIC_I_RES_MAGIC)) / 2;

    for (i=0; i < sizeof(arm_arr); i++)
    {
	arm_short = arm_arr[i]->short();

        if (success > 200)
            success = 100;
        else
            success = success/2;

	/* Now the success is a percentage, take off the resistance */
	damage = success - res;

        /* Did we do any damage, and may we cast a spell on the object? */
        if (damage > 0 && !(arm_arr[i]->query_prop(OBJ_I_NO_MAGIC)))
        {
	    if (damage > 100)
		damage = 100;
	    old_ac = arm_arr[i]->query_ac();
	    new_ac = old_ac*(100-damage)/100;
	    if (new_ac < 0)
	        new_ac = 0;
	    arm_arr[i]->set_ac(new_ac);

            /* Update the ac for the player */
	    target->update_armour(arm_arr[i]);

            if (sscanf(arm_arr[i]->short(), "%s (blackened)",tmp) == 0)
	        arm_arr[i]->set_short(arm_short + " (blackened)");

	    how = " glows bright yellow and then turns black!\n";
        }
        else
	    how = " glows pale yellow but nothing else happens!\n";

	tp->catch_msg(break_string(capitalize(who)+"'s "+arm_short + how,70));
	target->catch_msg(break_string("Your " + arm_short + how,70));
	tell_room(env,
	 ({ break_string(target->query_name() + "'s " + arm_short + how,70),
	    break_string(target->query_The_name()+"'s " + arm_short + how,70)
	 }), ({tp,target}));
    }


    /* Make her pay for it and remove the ingredients */
    if (!is_wiz)
    {
	tp->add_mana(-SP_MELT_MANA);
        remove_ingr(ingr_arr);
    }
    return 1;
}


int
filter_worn_armours(object obj)
{
    if ((function_exists("create_object",obj) == "/std/armour")
	     && obj->query_worn())
        return 1;
    return 0;
}
