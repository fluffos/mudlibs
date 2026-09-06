// Hiding ability - uses sneak skill.
// 26-Sep-97 / Graah

#include "../thief.h"
#include <weatherdesc.h>

int
hide(object owner) 
{
    object tm;
    string tmp, fail_mesg, *fail_mesg2;
    int sneak, success, il;

    if (!owner->query_can_move()) 
    {
	TM("You can't try hiding in your condition!");
	return 0;
    }

    if (owner->is_fighting()) 
    {
	TM("Not now, there's a fight going on.");
	return 0;
    }

    if (owner->query_sp() < HIDE_SP_COST) 
    {
	TM("You feel too tired and are unable to concentrate.");
	return 0;
    }

    tm = (object) owner->query_guild_object();

    if (tm->query_sneak())
    {
	TM("You are already sneaking.");
	return 0;
    }

    il = (int)owner->query_invis();
    if ((il > 0) && (il < IL_TOTALLY_INVISIBLE))
    {
	TM("You are already invisible.");
	return 0;
    }

    owner->add_sp(- HIDE_SP_COST);

    if (((int)tm->stealth() + (int)tm->query_adv()) <
      (10 + random(25)))
	success = 0;
    else
	success = ((int) tm->thief_dex() * 2 +
	  ((int)tm->query_skills(SK_SNEAK) / 45 )) - (random(125));

    if (success > 0 && (random(100) < 5)) success = 0;

    TM("Hiding...any real action will break it.");

    if (success > 0)
    {
	// TODO: Any messages when a thief goes hiding?

	// Hidden ones should be where-proof? Got to check it...
	if (il < IL_TOTALLY_INVISIBLE) owner->set_invis(IL_HIDDEN);

	// Let's advance skills here as well cause otherwise
	// high level players never advance -Cigam

	if (random(100) < 20)
	    if ((int)owner->query(LIV_CARRY_RATE) <= 75)
		tm->set_skill(SK_SNEAK,
		  tm->advance_skill((int)tm->query_skills(SK_SNEAK),
		    DIFF_SNEAK));
    }
    else
    {  
	if ((int)environment(owner)->query(ROOM_WD) < WD_OUTDOORS)
	    environment(owner)->tell_here(
	      ":%<me.name>% squats in a corner and thinks %<me.pronoun>% \
is hidden.",0,0,owner,owner,0,0);
	else
	    environment(owner)->tell_here(
	      ":%<me.name>% squats quietly nearby, and thinks %<me.pronoun>% \
is hidden.",0,0,owner,owner,0,0);

	if (((int)tm->query_adv() + 3) >= random(10))
	    if ((int)owner->query(LIV_CARRY_RATE) <= 75)
		tm->set_skill(SK_SNEAK,
		  tm->advance_skill((int)tm->query_skills(SK_SNEAK),
		    DIFF_SNEAK));
    }

    write("Hiding> ");
    input_to("hiding_stop", 128, owner);
    return 1;
}

void
hiding_stop(string str, object ob)
{
    object tm;
    string cmd, tmp;
    int il, hs;

    if (!ob) return;

    hs = 0;

    if (stringp(str))
    {
	// They try to cheat with input_to. But, thanks to clever
	// Amylaar input_to, and flag 128, that doesn't work :)
	if (str[0] == '!') str = str[1..<1];

	if (sscanf(str, "%s %s", cmd, tmp) != 2) cmd = str;

	// Thief mark's hidden must ONLY be set for this and cleared then.
	tm = (object)ob->query_guild_object();
	if (tm) tm->set_hidden(1);
	if (cmd != "hide") ob->force_us(str);
	if (tm)
	{
	    // Command caused hide to stop?
	    hs = ((int)tm->query_hidden() == 0);
	    tm->set_hidden(0);
	}

	// Commands allowed when hiding. Now even those commands can stop
	// hiding, if they set_hidden to 0 from tmark. Mainly stab.
	if (!hs &&
	  (str == "" || member(({
		"exa", "examine", "l", "look", "stab", "hide",
	      }), cmd) != -1))
	{
	    write("Hiding> ");
	    input_to("hiding_stop", 128, ob);
	    return;
	}
    }
    else
    {
	write("Hiding> ");
	input_to("hiding_stop", 128, ob);
	return;
    }

    il = (int)ob->query_invis();
    if ((il > 0) && (il < IL_TOTALLY_INVISIBLE)) ob->set_invis(IL_VISIBLE);

    ob->tell_me("\nStopped hiding.");
}
