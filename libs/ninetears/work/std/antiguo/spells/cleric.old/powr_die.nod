#define save_type "magical"

object caster;

mixed spell(string str, int cast);

/* Power word Die.
  Made by Baldrick June 1993.
    Mods for FR jan '95, by the same nerd.
    Uses saving throw to balance the spell. But it should be *very* high level
  To get it:
  Have fun with it.

  --Added magic resistance adj. and made the formulas WORK :)
       --Wonderflug, march 95
*/

string help() 
{
  return
	"This spell kills the one you use it at, if the victim is "
	"powerful enough it may survive.\n\n";
}

int cast_spell(string str,object cast)
{
  mixed ret;

  caster = cast ? cast : this_player();

  if(interactive(caster))
	  str = (string)caster->expand_nickname(str);
  ret = spell(str, 1);
  if (stringp(ret))
	 {
	 notify_fail(ret);
	 return 0;
	 }
  return 1;
}

mixed spell(string str, int cast) 
  {     
  mixed ob;
  int skill;
  int check;
  int cost;
  int c_roll, t_roll;

  cost = 40;

  if (cast && (int)caster->adjust_gp(-cost) < 0)
	return "Too low on power.\n";
  if (!str || str == "")
	return "You shout but there is no target for it.\n";
  ob = find_match(str, environment(caster));
  if (sizeof(ob))
    	ob = ob[0];
  else
    	return "All that shouting at nothing tires you out somewhat.\n";

  if (!living(ob))
    	return ("All that shouting at dead objects tires you out somewhat.\n");

  if (ob->query_creator())
    	return ("You don't think it is wise to kill an immortal.\n");
  if (ob->query_property("dead"))
	 return (string)ob->query_cap_name() + " is already dead.\n";

  if(member_array(caster,ob->query_attacker_list()) != -1) 
	return("Your word comes out only as a whisper.\n");

/* here is the "saving throw" I'm trying out */

  c_roll = random( (int)caster->query_level() * (int)caster->query_wis() + 5 );
  t_roll = (int)ob->query_level() * (int)ob->query_wis();
  if ( c_roll * ( (100 - (int)ob->query_property("magical")) / 100 ) < t_roll )
  {
	tell_object(ob, "You hear "+(string)caster->query_cap_name()+
	  " whisper death to you.\n");
	caster->attack_ob(ob);
	return ("Your word comes out only as a whisper.\n");
  }

  tell_object(caster,"You call upon the gods to help you kill " +
         ob->query_cap_name() + ".\n");
  tell_room(environment(caster),(string)caster->query_cap_name() + 
	" shouts: DIE "+(string)ob->query_cap_name() + "!\n",
	({ ob, caster }) );
  tell_object(ob, "You feel " + (string)caster->query_cap_name() +
    	"'s word attack you.\n\nThe powerword killed you.\n\n");
  ob->do_death(caster);
  return 1;
}
