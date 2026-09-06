// Moved to /bin/pub 17-oct-95 by Doomdark.



#include <player_defs.h>


/* Every player may now consider //Graah */
int
cons_cmd(string str, object me)
{
    int LEVEL;
    int magic;
    object ob;

    if (!me && !(me = this_player())) return 0;
    if (!str) return notify_fail("Consider what?\n"), 0;

    ob = present(lower_case(str), environment(me));

    if (!ob) {
	notify_fail("You cannot see any " + str + " here.\n");
	return 0;
    }

    if (!living(ob)) {
	notify_fail("That doesn't seem to be alive.\n");
	return 0;
    }

    if (ob == me) {
	me->tell_me("Easy! Very easy indeed!");
	return 1;
    }

    LEVEL = (int) me->query_level();
    magic = (int)ob->query_level() + (int)ob->query_wc() + (int)ob->query_ac();

    if ((int)ob->query_coder_level())
	magic += (int)ob->query_coder_level() * 10;

    /* Get player's max spell damage */
    switch(LEVEL) {
    case  5.. 9: magic -=  5; break;
    case 10..14: magic -= 10; break;
    case 15..20: magic -= 20; break;
    case 21..22: magic -= 85; break;
    case 23..26: magic -= 120; break;
    case 27..200: magic -= 160; break;
    default: break;
    }

    magic -= (LEVEL + (int)me->query_wc() +
      (int)me->query_ac());

    magic += (int)ob->query_spell_dmg();

    if(magic <= -20)
	me->tell_me("You could eat that for a snack, but why bother?");
    else if(magic > -20 && magic <= -10)
	me->tell_me("You can kill that with a wink of your eye!");
    else if(magic > -10 && magic <= -6)
	me->tell_me("Should be a piece of cake.");
    else if(magic > -6 && magic <= -3)
	me->tell_me("A good challenge, but you will probably win.");
    else if(magic > -3 && magic <= 2)
	me->tell_me("You are nearly equal in power. You might need some luck.");
    else if(magic > 2 && magic <= 5)
	me->tell_me("That will be quite hard. Use magic and good weapons.");
    else if(magic > 5 && magic <= 10)
	me->tell_me("May be too tough for you alone. Be careful!");
    else if(magic > 10 && magic <= 15)
	me->tell_me("I advice you to gain more power before trying that!");
    else if(magic > 15 && magic <= 18)
	me->tell_me("Do you feel lucky, punk?");
    else if(magic > 18 && magic <= 20)
	me->tell_me("Are you MAD?!??!!");
    else if(magic > 20 && magic <= 24)
	me->tell_me("You ARE mad!!!!!!");
    else me->tell_me("Would you like to borrow a cross and a shovel?");

    return 1;
}
