// 1-May-97 / Graah: Made it much harder to pick all doors.
#include <cmd.h>
#include <daemons.h>
#include <criminal.h>
#include <skills.h>
#include "../thief.h"

/* Define this if crimes are active */
/* #define CRIME */

varargs nomask status
pick_cmd(string str, object me)
{
    object dir, pck, tm;
    int flag, brk, succ, sk_pick, advantage;
    string tmp, dirname;

    if (!str) {
	this_player()->tell_me("Pick what?");
	return 1;
    }
    if (!me && !(me = this_player())) return 0;
    if (!(tm = present("tmark", me))) return 0;

    if (!tm->still_thief(0)) return 0;

    advantage = (int)tm->query_advantage();
    sk_pick = (int)tm->query_skills(SK_PICK);
    flag = 0;

    if (!(pck = present("lockpick", me)))
    {
	me->tell_me("You need a lock pick to pick the lock.");
	return 1;
    }

    if (me->query_sp() < PICK_SP_COST)
    {
	me->tell_me("You can't concentrate enough to do this now.");
	return 1;
    }

    if (sscanf(str, "account %s", tmp) == 1)
    {
	if (environment(me) != find_object(AREA_TRISTEZA + "bank/bank_back"))
	{
	    me->tell_me("You'll have to be in the back room of the \
Bank to do this!");
	    return 1;
	}

	if (!tmp)
	{
	    me->tell_me("Pick account! Pick account! Yeah! Hmmmmm...whose \
account you said you were going to pick...?");
	    return 1;
	}

	me->add_sp(-(PICK_SP_COST));

	if (sk_pick < random(10001) || random(100) < 80)
	{
	    me->tell_me("Oh-oh...you failed at this time! Be careful!");
	    return 1;
	}

	me->tell_me("\n\n\tSUCCESS!\n\n");
	me->tell_me("\nYou got " + (1 + random(1000000)) + " coins!!!\n\n");
	return 1;
    }

    if (!str ||
      !(dir = present(lower_case(str), environment(me))))
    {
	me->tell_me("Pick what?");
	return 0;
    }

    dirname = (string)dir->query_name();

    if (!dir->query_pick_level())
    {
	me->tell_me(dirname + " cannot be picked.");
	return 1;
    }

    if (!dir->query_is_locked() && !dir->query_is_closed())
    {
	me->tell_me("But " + dirname + " is wide open. Why to pick it?");
	return 1;
    }

    if (dir->query_pick_level() < 0)
    {
	me->tell_me(dirname +
	  " is much too complex for you to pick.");
	return 1;
    }

    me->add_sp(- PICK_SP_COST);

    if (random(100) < 96)
    {
	succ = random(sk_pick / 100 + me->query_stat(ST_DEX) + 42);
	// Was succ -= (int)dir->query_pick_level()
	// That was nothing... /Graah
	succ -= 50 + random(10 * (int)dir->query_pick_level());
	//had to add random was *impossiable* to pick any house -- Chao
	if (advantage)
	{
	    if (advantage > 0) succ += random(advantage * 15);
	    else succ -= random((-(advantage)) * 15);
	}
	if (pck->id("glowing"))
	{
	    me->tell_me("Wow, this is a great lockpick!");
	    succ += (20 + random(20));
	}
    } else succ = 0;

    if (succ > 0)
    {
	/* Was unlocked? Then we try to lock it. */
	if (!dir->query_is_locked())
	{
	    if (!dir->query_can_lock())
	    {
		me->tell_me("You can't lock " + dirname + ".");
		return 1;
	    }
	    me->tell_me("Ok. You lock " + dirname + ".");
	    environment(me)->tell_here(
	      (string)me->query_name() + " locks " + dirname + ".",
	      ({ me }));
	    dir->set_locked(1,0);
	    flag = 2;
	}
	else
	{
	    if (dir->pick_door())
	    {
		me->tell_me("You manage to pick the lock of " + str +
		  " successfully!");
		environment(me)->tell_here(
		  (string)me->query_name() + " unlocks " + dirname + ".",
		  ({ me }));
		flag = 1;
	    }
	    else
	    {
		me->tell_me("You try all you can, but " + str +
		  " is still locked.");
		return 1;
	    }
	}
	dir->set_both_status();
    }

    brk = 5 + (int)tm->thief_dex() * 2 + (sk_pick / 150);
    if (flag) brk += 15;
    if (flag == 2) brk -= 5; /* Locking the door, breaks more often */
    brk += (advantage * 2 + random(advantage * 6));
    if (brk > 97) brk = 97;

    if (random(100) > brk && random(3))
    {
	if (!pck->id("glowing"))
	{
	    if (flag) me->tell_me("Unfortunately your lockpick breaks!");
	    else me->tell_me("Oops! Your lockpick breaks.");
	    me->add_weight(-((int)pck->query_weight()));
	    destruct(pck);
	}
	else
	if (random(100) > 98)
	{
	    me->tell_me("OH SH..!!! You broke your MAGIC lockpick!\n");
	    me->add_weight(-((int)pck->query_weight()));
	    destruct(pck);
	}
    }

    if (!flag)
    {
	me->tell_me("You failed to pick the lock.");

	/* Urgh... we can lock/unlock the same door all the time and
	   gain more and more skill...it's good that our lockpicks can
	   break. */
	tm->set_skill(SK_PICK,(int)tm->advance_skill(sk_pick, DIFF_PICK));
    }

#ifdef CRIME
    /* Test if someone can notice this. It's a crime only in city. */
    if (environment(ob)->query_in_city() &&
      (sk_pick < random(12000)))
    {
	CRIME_D->crime(me, CR_BURGLARY);
    }
#endif

    return 1;
}
