#include <cmd.h>
#include <driver.h>
#include <room_defs.h>
#include <player_defs.h>

#include <invis_levels.h>

#define SP_COST 30
#define WHERE_ALL_COST  50
#define WHERE_ALL_LVL   58

/* Prototypes */
string show_where(string n, object x, int a, int b);
void where_people(object me, int lvl1, int lvl2);
int where_map(object ob, int lvl1, int lvl2);

// Global variable... ugly.
int see_always;

nomask int
where_cmd(string str, object me)
{
    object who;
    int mylevel, wholevel;
    int cost;
    int WhereON;

    see_always = 0;
    if (!me && !(me = this_player())) return 0;

    mylevel = (int)me->query_level();

    if(str == "toggle") {
	WhereON = me->query(PLR_SHOW_WHERE_ON);
	this_player()->set(WhereON ? PLR_SHOW_WHERE_OFF : PLR_SHOW_WHERE_ON);
	this_player()->tell_me("Where messages now "+(WhereON ? "on" : "off")+".");
	return 1;
    }
    if (!str || str == "all")
    {
	if (mylevel < WHERE_ALL_LVL)
	{
	    if (str)
		return notify_fail("You are not of high enough level \
to be able to use that command (min. lvl " + WHERE_ALL_LVL + "!)\n"), 0;
	    return notify_fail("Where who? (Nice message isn't it?)\n"), 0;
	}
	else
	{
	    if ((int) me->query_sp() < WHERE_ALL_COST)
		return notify_fail(
		  "You can't concentrate on that right now (too low on SPs).\n"), 0;
	    where_people(me, mylevel, (int) me->query_coder_level());
	    return 1;
	}
    }

    who = find_player(lower_case(str));

    if (!who)
	who = find_living(lower_case(str));

    str = capitalize(str);

    if (!who)
    {
	me -> tell_me("Cannot find any \""+str+"\".");
	return 1;
    }

    if (!who->query_npc() &&
      !(wholevel = where_map(who, mylevel, (int) me->query_coder_level())))
    {
	me->tell_me("Cannot find any \""+str+"\".");
	return 1;
    }

    /* Non-lord: reduce sp */
    if (mylevel) { // Necros - where should cost for everyone.
	/* Randomize it. We must prevent them finding out the
	 * levels of monsters! 
	 * Hah! For the player to do 'where monster' the monster has
	 * to pass the same level requirements as player => the
	 * level is revealed. --Val
	 */
	cost = SP_COST + random(wholevel * 2);
    }

    if ((int)TP->query_sp() < cost)
	return notify_fail(
	  "You can't concentrate enough now (too low on SPs).\n"), 0;

    if (mylevel >= 50) see_always = 1;
    TP->tell_me(show_where(str, who, wholevel, (int) me->query_coder_level()));

    return 1;
}

string
show_where(string name, object who, int wholevel, int my_clevel)
{
    string sdesc;
    string ret;

    if (wholevel && !interactive(who)) return name + " is currently link dead.";

    if (who->query_ghost()) return name + " is dead.";

    if (!environment(who)) return name + " is lost in void!";

    if (environment(who) -> query(ROOM_PREVENT_WHERE))
	return name + " seems to be somewhere out of reach by \"where\"!";
    if(who->query_prevent_where()) {
	return name + " is nowhere to be seen.";
    }

    if (!see_always) sdesc =
	(string) environment(who)->query_short(4, who);
    else sdesc =
	(string) environment(who)->query_short(2, who);
    if (!sdesc)
	sdesc = "<UNKNOWN PLACE>";

    if (wholevel) {
	ret = sprintf("%-13s (%2d)  %s.", name, wholevel,
	  sdesc);
    } else {
	ret = sprintf("%-13s (??)  %s.", name,
	  sdesc);
    }

    /* Kihi kihi, heh HEH! /Graah */
    if (wholevel > 17 && !TP->query_coder_level() &&
      random(80) < wholevel && who->query(PLR_SHOW_WHERE_ON))
    {
	who->tell_me(
	  "You feel someone somewhere trying to find out where you are...");
	if (random(70) < wholevel)
	    who->tell_me("You concentrate hard and find that it is " +
	      capitalize((string)TP->query_real_name()) + "!");
    }

    return ret;
}

void
where_people(object me, int mylevel, int my_clevel)
{
    mixed *u;
    int i, max, tmp;
    object o;

    i = sizeof( u = users() - ({ this_player() }) );
    while (i--) {
	if (!living(u[i]) || u[i]->query_coder_level()
	  || (!my_clevel && u[i]->query_prevent_where()))
	    u[i] = 0;
	else {
	    o = u[i];
	    tmp = (int) o->query_level();
	    if (mylevel >= 45
	      // Level >= 45, detect any non-coder
	      || (mylevel >= 25 && mylevel > tmp)
	      // Lord can detect lesser lords
	      || mylevel >= (tmp + 10)) {
		// Mortal can detect players of 10 or more less levels
		u[i] = show_where(capitalize((string)o->query_real_name()),
		  o, tmp, my_clevel);
	    } else u[i] = 0;
	}
    }

    u -= ({ 0 });
    max = sizeof(u);

    if (!max) {
	me -> tell_me("You concentrate on finding out location of the \
other players...\nCan't detect anyone.");
	me -> add_sp(-1);
	return;
    }

    me->tell_me("You concentrate on finding out location of the \
other players...\nYou find out locations of the following players:");

    i = 1 + max;
    if (i < 5) i = 5;
    else if (i > WHERE_ALL_COST) i = WHERE_ALL_COST;
    me->add_sp(-i);

    me->more(u);
}

// Let's make this more efficient. Map_array uses call_other and burns
// eval cost like a hog. -+ Doomdark +-
status
where_map(object ob, int mylevel, int my_clevel)
{
    int lev;

    /* No "Login"s */
    if (!living(ob)) return 0;

    /* Never coders nor testplayers */
    if (ob->query_coder_level()) return 0;

    // Now we can avoid where command and hide :) ++Tron
    // Do shadow if player hides from where.
    // Show to coders though.

    lev = (int)ob->query_level();

    // Hidden are currently never shown for noncoders /Graah
    // If you feel very high levels etc. must be able to, change this...
    if (!my_clevel &&
      ((int)ob->query_invis() == IL_HIDDEN)) return 0;

    /* Level >= 45, detect any non-coder */
    if (mylevel >= 45) return lev;

    /* Lord can detect lesser lords */
    if (mylevel >= 25) return (lev <= mylevel) ? lev : 0;

    /* Mortal can detect players of 10 or more less levels */
    if ((lev + 10) <= mylevel) return lev;

    return 0;
}
