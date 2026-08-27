#define SP_COST 40
 
mixed spell(string str, int cast);
object caster;

/* Finger of Death.
   Made by Baldrick June 1993.
   Mods for FR jan '95, by the same nerd.
   Uses saving throw to balance the spell. But it should be *very* high level
   To get it:
   Have fun with it.

  --Added magic resistance check and made the formula actually work
     --Wonderflug, march 95
*/

string help() 
{
  return
    "This spell kills the one you manage to touch, if the victim is powerful " 
    "enough it may survive.\n\n";
}
 
int cast_spell(string str, object who) 
{
  mixed ret;
 
  caster = who ? who : this_player();
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
  int achit, THAC0, defenderac, result;

  if (cast && (int)caster->adjust_gp(-SP_COST) < 0)
	return "Too low on power.\n";
  if (!str || str == "")
	return "You wave you hands in the air trying to touch nothing.\n";
  ob = find_match(str, environment(caster));
  if (sizeof(ob))
	ob = ob[0];
  else
    	return "Who is " + capitalize(str) + "?\n";

  if (!living(ob))
    	return ("Why kill a dead object ?.\n");
  if (ob->query_creator())
    	return ("You don't think it is wise to kill an Immortal.\n");
  if (ob->query_property("dead"))
    	return (string)ob->query_cap_name() + " is already dead.\n";

  if(member_array(caster,ob->query_attacker_list()) != -1)  
	return("You try to reach your victim, but miss.\n");

/* here is the "saving throw" I'm trying out 
 * First, does the wizard manage to touch the victim?
 */
      /* the AC the caster will hit. */

  THAC0 = (int)caster->query_thac0();
  achit = ((int)caster->query_level() + roll(1,20) - THAC0);
  defenderac = ((int)ob->extra_bonus("defend") + (int)ob->query_level()
		- (int)ob->query_total_ac());

  achit = achit * ( (100 - (int)ob->query_property("magical")) / 100 );

  result = (achit - defenderac);
  if (result < 0)
  {
    	ob->adjust_gp(-(SP_COST/3));
    	tell_object(ob, "You notice "+(string)this_player()->query_cap_name()+
      	  " grabs after you, but misses.\n");
    	caster->attack_ob(ob);
    	return ("You try to reach for your victim, but miss.\n");
  }
  tell_object(caster,"You touch and kill "+ob->query_cap_name()+".\n");
  tell_room(environment(caster), (string)caster->query_cap_name() 
	+" touches "+(string)ob->query_cap_name()+" and the poor victim "
	"dies.\n", ({ ob, caster }) );
  tell_object(ob, "You feel a tingling sensation as "+
	(string)caster->query_cap_name()+" touches you, and then nothing.."
	"\n\n");
  ob->do_death(caster);
  return 1;
}
