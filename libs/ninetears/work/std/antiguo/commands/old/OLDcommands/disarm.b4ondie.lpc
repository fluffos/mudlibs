
/* Rage '94 - disarm cmd for fighters */
/* Redone '95, Rage */

#include "tweaks.h"
int chance(object me,string str);

int disarm(string str,object x)
{

    object *ob, tar;
    int i;
    int hold;
    object *fuk;
    int cnt;
    object me;

    if(x) me = x;
    else me = this_player();

    hold = 0;    /* gets set to 1 in the loop if target holds any weapons */

    if (!str) {
	tell_object(me,"Disarm whom?\n");  /* no string, no dude */
	return 1;
    }

    str = lower_case(str);
    str = (string)me->expand_nickname(str);

    if (str == ((string)me->query_name())) 
    {
	tell_object(me,"You dare not disarm yourself.\n");
	return 1;
    }

/* Outed, no need 4 it.
    if (!(tar = find_living(str))) 
    { 
	tell_object(me,"Can only disarm living stuff.\n");
	return 1;
    }
*/

    fuk = find_match(str, environment(me));

    for (cnt = 0; cnt < sizeof(fuk); cnt++) {
	if (((int)fuk[cnt]->query_level() > 0) && (!interactive(fuk[cnt])))
	{
		tar = fuk[cnt];
		break;
	}
    }

    if (!tar) 
    {
	capitalize(str);
	tell_object(me,str+ " is nowhere to be seen.\n");  /* Should this be here?? */
	return 1;
    }


  /* Outed, no need 4 this either....
    if (!(present(str, environment(me)))) 
    {
	tell_object(me,tar->query_cap_name()+ " is not here.\n");
	return 1;
    }
*/
  
    if ((int)me->query_timed_property("dis") == 1)
    {
	tell_object(me,"The tactical part of your brain needs a bit of recovery before you"
	  " can disarm again.\n");
	return 1;
    }
    if ((int)me->query_gp() < GPCOST_DISARM) 
    {
	tell_object(me,"Sorry, not enough guildpoints to disarm.\n");
	return 1;
    }
    if ((int)me->query_hp() < (int)this_player()->query_max_hp() / 2)
    {
	tell_object(me,"You are too tired to disarm.\n");
	return 1;
    }
    ob = (mixed *) tar->query_held_ob();
    for (i=0; i<sizeof(ob); i++) 
    {
	if ((int)tar->is_weapon(ob[i]) == 1)
	  {
	      me->adjust_gp(- (GPCOST_DISARM));
	      me->add_timed_property("dis", 1, HBLOCKOUT_DISARM);
	      if (chance(me,str) == 1)
	      {             /* success */
		  tell_object(me,"You strike "+ tar->query_cap_name()+ "'s "+
		    ob[i]->query_short()+ " to the ground.\n");
		  tell_room(environment(tar), me->query_cap_name()+ " strikes "+
		    tar->query_cap_name()+ "'s "+
		    ob[i]->query_short()+ " to the ground.\n", ({ tar, me }));
		  tell_object(tar, me->query_cap_name()+ " strikes your "+  
		    ob[i]->query_short()+ " to the ground.\n");
		  ob[i]->move(environment(tar));

		  if (random(100) > 94) 
		  {
		      tell_object(me,ob[i]->query_short()+ " is destroyed by the blow.\n");
		      tell_room(environment(tar), ob[i]->query_short()+ " is destroyed by the blow.\n", ({tar, me }));
		      tell_object(tar, ob[i]->query_short()+ " is destroyed " 
			"by the blow.\n");
		      ob[i]->dest_me();
		  }

		  hold = 1;
		  break;
	      }

	      else 
	      {                   /* failure */
		  tell_object(me,"You fail to strike "+ tar->query_cap_name()+ "'s "+
		    ob[i]->query_short()+ " to the ground.\n");
		  tell_room(environment(tar), me->query_cap_name()+ " fails to strike "+
		    tar->query_cap_name()+ "'s "+
		    ob[i]->query_short()+ " to the ground.\n", ({ tar, me }));
		  tell_object(tar, me->query_cap_name()+ " fails "
		    "to strike your "+  
		    ob[i]->query_short()+ " to the ground.\n");
		  hold = 1;
		  if (random(100) > 50) {
		      tell_object(me, tar->query_cap_name()+ " gets mad and "
			"attacks.\n");
		      tar -> attack_ob(me);
		  }
		  break;
	      }
	  }
      }
	if (hold != 1) 
	{    /* ooops, your target wasn't holding any weps */
	    tell_object(me,tar->query_cap_name()+ " is not holding any weapons.\n"); 
	    return 1;
	}
	return 1;
    }


    int chance(object me,string str)
    {
	int def, att;
	object ob;


	ob = find_living(str);

	/*
	Calculate attackers chance of success
	str*2 + dex + level + random 10 
	did this way to make it more viewable...
	*/

	att = ((int)me->query_str() * 2);
	att += (int)me->query_dex();
	att += ((int)me->query_level() + random(10));

	def = ((int)ob->query_dex() * 2);
	def += (int)ob->query_str();
	def += ((int)ob->query_level() + random(10));

	if (def > att + 10) ob->adjust_xp(50);
	if (att > def + 10) me->adjust_xp(50);

	if (def > att + 20) ob->adjust_xp(50);
	if (att > def + 20) me->adjust_xp(50);

	/* 
	Above grants some xps if a defender or attacker did something great...
	Note that the all the IFs are run... calculation > 20 more than opponent 
	gives 100xp, calculation > 10 more gives 50xp
	*/

	if (att > def) return 1;
	else return 0;

    }
