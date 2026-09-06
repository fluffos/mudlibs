
/* 
   APPRAISE SKILL -- Transferred from mark and cleaned 1/1/96 --Colt

   Only approximate cost, armour and weapon class will be known. 
   And if it can be thrown or not. 

   CHANGES: Put peek in here.. depends on appraise anyway.

   Coder inv cannot be peeked anymore ++skarda
*/

#include "../thief.h"

status appraise(object owner, string str) 
{
    object ob, tm;
    string tmp;
    int suc, cst, wec, arc;

    if (!str) 
    {
	TM("Usage: 'appraise <object>' or 'app <object>'.");
	return 0;
    }

    ob = present(str, TP);

    if (!ob) 
	ob = present(str,environment(TP));

    if (!ob) 
    {
	TM("You can't see any \"" + str + "\" here.");
	return 0;
    }

    if (living(ob)) 
    {
	TM("You cannot appraise that.");
	return 1;
    }

    if (owner->query_sp() < APPRAISE_SP_COST) 
    {
	TM("You feel too tired to concentrate enough.");
	return 1;
    }

    owner->add_sp(- APPRAISE_SP_COST);

    tm = (object) owner->query_guild_object();
    /* Intelligence helps a bit with this... */
    if ((int) tm->query_t_level() < 4)
	suc = (4 - (int) tm->query_t_level()) * 10;
    else 
	suc = 0;

    suc += ((int) tm->query_skills(SK_APPRAISE) / 100) + owner->query_int();

    if (suc > 95) 
	suc = 95;

    if (random(100) < 6 || random(120) > suc) 
	suc = 0;

    arc = ob->query_ac();
    wec = ob->query_wc();
    cst = ob->query_pick_level();

    /* Success! */
    if (suc > 0) 
    {
	if (cst && ob->query_door_type()) 
	{
	    /* Door */
	    if (cst < 1) 
		TM("It is probably impossible to pick.");
	    else 
	    if (cst < 40) 
		TM("It should be easy to pick.");
	    else 
	    if (cst < 60) 
		TM("It has an average lock.");
	    else 
	    if (cst < 80) 
		TM("It would be hard to pick.");
	    else 
		TM("It seems to have a very difficult lock.");
	    return 1;
	}

	cst = ob->query_value();
	if (!cst) 
	    TM("It seems to be worthless.");
	else 
	{
	    TM("Ok. Its value is approximately ");
	    if (cst < 500) 
		cst = (cst/10) * 10;
	    else 
		cst = (cst/100) * 100;

	    if (cst < 10) 
		cst = 10; /* we still got zero values... */
	    TM(cst + " gold pieces.");
	}
	if (arc) 
	{
	    if (arc == 1) 
		TM("It is sort of an armour.");
	    else 
	    if ((arc > 1) && (arc < 4)) 
		TM("It is a good armour!");
	    else 
	    if (arc > 3) 
		TM("It is an excellent armour!\n");
	}
	if (wec) 
	{
	    if (wec < 10) 
		TM("It is sort of a weapon.");
	    else 
	    if (wec < 16) 
		TM("It is a good weapon!");
	    else 
	    if (wec < 20) 
		TM("It is an excellent weapon!");
	    else 
	    if (wec < 25) 
		TM("It's a mighty magical weapon!");
	    else 
		TM("It's one of the most powerful weapons there is!");
	}
    }
    /* Failed. Give a false value. */
    else 
    {
	cst = ob->query_value();
	if (cst > 999) 
	    TM("It seems to be worthless.");
	if (cst < 1000) 
	{
	    TM("Ok. Its value is approximately ");
	    if (random(3) == 0) 
		cst = (40 + random(75)) * 100;
	    else 
		cst = (1 + random(50)) * 10;
	    TM(cst + " gold pieces.");
	} 
	if (arc) 
	    TM("It is an armour of some sort.");
	if (wec) 
	    TM("It is a weapon of some sort.");

	/* We learn from our mistakes */

	tm->set_skill(SK_APPRAISE,tm->advance_skill(tm->query_skills(SK_APPRAISE),
	    DIFF_APPRAISE));
    }

    if (can_throw(owner, ob))
	TM("You could throw this thing.");

    return 1;
}

int peek(object owner, string arg)
{
    object ob, *inv, tm, *u;
    int suck, mani, i;
    int t_level;

    if (!arg)
    {
	notify_fail("Usage: '" + query_verb() + " <name>'\n");
	return 0;
    }

    tm = (object) owner->query_guild_object();
    t_level = (int) tm->query_thief_level();
    ob = present(lower_case(arg), environment(TP));

    if (!ob)
    {
	notify_fail("You can't see any \"" + arg + "\" here.\n");
	return 1;
    }

    if (!living(ob))
    {
	TM("That is not alive.\n");
	return 1;
    }

    if (owner->query_sp() < PEEK_SP_COST)
    {
	TM("You feel too tired to concentrate enough.\n");
	return 1;
    }

    owner->add_sp(- PEEK_SP_COST);

    /* Dexterity helps a bit with this... */

    if (t_level < 4)
	suck = (4 - t_level) * 10;
    else
	suck = 0;

    suck += ((int)tm->query_skills(SK_APPRAISE) / 100) +
    (int)owner->query_stat(ST_DEX);

    if (suck > 95)
	suck = 95;
    if (random(100) > suck)
	suck = 0;

    mani = (int)ob->query_money();

    if (suck)
    {
	if (mani > 1000)
	    mani = (mani / 100) * 100;
	else
	if (mani > 100)
	    mani = (mani / 10) * 10;
	else
	if (mani > 10)
	    mani = (mani / 5) * 5;

	if (mani > 10)
	    mani += (random(11) - 5);
    }
    else
    {
	if (random(10) < 3)
	    mani = 0;
	else
	if (random(10) < 3)
	    mani = random(100) * 1000 + random(100) * 100;
	else
	if (random(10) < 5)
	    mani = random(100) * 100 + random(100) * 5;
	else
	    mani = random(10) * 5 + random(10);

	/* We learn from our mistakes */
	/* But not from ourself!!! */
	if (ob != owner && random(100) < 30)
	    tm->set_skill(SK_APPRAISE,tm->advance_skill(tm->query_skills(SK_APPRAISE),
		DIFF_APPRAISE));
    }

    if (mani < 1)
	TM("You notice that " + arg + " has no gold.");
    else
    {
	write("It seems that " + arg + " has about " + mani + " coin");
	if (mani > 1)
	    write("s");
	write(".\n");
    }

    /* NEW: Successful peek shows player inventory as well --Colt */

    u=filter_array(users(),lambda(({'foo}),({#'!,({#'call_other,'foo,
	    "query_coder_level"}) }) ) );
    if(suck)
	inv = all_inventory(ob);
    else
	inv = all_inventory(u[random(sizeof(u))]);

    TM(upper_case(arg)+" has the following inventory: ");
    for(i=0;i<sizeof(inv);i++)
	TM(inv[i]->query_short());

    if (mani && (int)ob->query_level() > (random(100) + random(100)))
	ob->tell_me("You notice that " + (string)owner->query_name() +
	  " looks at your gold greedily!");

    return 1;
}

