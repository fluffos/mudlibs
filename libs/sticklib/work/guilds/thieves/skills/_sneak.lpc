/* 
  SNEAK SKILL -- Transfered from mark and cleaned 1/1/96 --Colt

  CHANGES:  (add your changes here)
  Without vis/invis anymore, new max is about 15 seconds - Kel, 6-Oct-95
  New Auto-Fail -- If it's super nice day, you're gonna fail - Kel, 25-Oct-95
*/

#include "../thief.h"

#define QP query_possessive()
#define QO query_pronoun()

int sneak(object owner) 
{
    object tm;
    string tmp, fail_mesg, *fail_mesg2;
    int sneak, success;
    int FAIL_CHANCE;

    if (!owner->query_can_move()) 
    {
	TM("You can't sneak in your condition!");
	return 0;
    }

    if (owner->is_fighting()) 
    {
	TM("Not now, there's a fight going on.");
	return 0;
    }

    if (query_verb() == "hide") 
    {
	TM("Hiding is not yet taught at the guild - try again later.");
	return 0;
    }

    if (owner->query_invis()) 
    {
	TM("Why sneak when you are already invisible?!?");
	return 0;
    }

    if (owner->query_sp() < SNEAK_SP_COST) 
    {
	TM("You feel too tired and are unable to concentrate.");
	return 0;
    }

    tm = (object) owner->query_guild_object();

    owner->add_sp(- SNEAK_SP_COST);

    if (((int)tm->stealth() + (int)tm->query_adv()) <
      (10 + random(25)))
	success = 0;
    else
	success = ((int) tm->thief_dex() * 2 +
	  ((int)tm->query_skills(SK_SNEAK) / 45 )) - (random(125));

    if (success > 0 && (random(100) < 5)) success = 0;

    if (success > 0)
    {
	tmp = owner->query_move_msg("mmout");
	owner->set_move_msg("mmout", "hides " + owner->query_objective() +
	  "self into the shadows");
	owner->set_invis(IL_SNEAKING);
	owner->set_move_msg("mmout", tmp);
	sneak = 4 + (int)tm->query_skills(SK_SNEAK)/1000 + (int)tm->thief_dex() / 3 + random (11);
	TM("Sneaking...");

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
	fail_mesg = ({
	  "You trip over your own feet trying to sneak. Needless "+
	  "to say, you fail!#"+capitalize((string)owner->query_name()) +
	  " trips over " + owner->QP + " feet and almost falls flat " +
	  "on " + owner->QP + " face!",
	  "You lose your balance trying to sneak and fail miserably.#"+
	  capitalize((string)owner->query_name()) + " loses " +
	  owner->QP + " balance and stumbles around.",
	  "You stub your toe trying to sneak, way to go clutz!#"+
	  capitalize((string)owner->query_name()) + " hits " +
	  owner->QP + " toe " +
	  "and dances around the room in pain!",
	  "Sneaking...#"+capitalize((string)owner->query_name())+
	  " thinks " + owner->QO + " is sneaking, but is really " +
	  "quite visible!",
	})[random(4)];

	fail_mesg2 = explode(fail_mesg,"#");
	TM(fail_mesg2[0]);
	environment(owner)->tell_here(fail_mesg2[1],owner);
	sneak = 1;

	if (((int)tm->query_adv() + 3) >= random(10))
	    if ((int)owner->query(LIV_CARRY_RATE) <= 75)
		tm->set_skill(SK_SNEAK,
		  tm->advance_skill((int)tm->query_skills(SK_SNEAK),
		    DIFF_SNEAK));
    }

    return sneak;
}
