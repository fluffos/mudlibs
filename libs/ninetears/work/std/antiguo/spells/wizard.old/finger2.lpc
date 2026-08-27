#define SP_COST 40
#define SPELLTYPE "offensive"
#define SP_NAME "Finger of Death"
 
mixed spell(object caster, string str);
int hb_spell(object caster, mixed* params, int time);

/* Finger of Death.
   Made by Baldrick June 1993.
   Mods for FR jan '95, by the same nerd.
   Uses saving throw to balance the spell. But it should be *very* high level
   To get it:
   Have fun with it.

   Wonderflug's Modifications:
   -- basically rewrote the thing.  Fixed the save formulas for resistances,
   -- Added a casting delay and new messages.
   -- Made it run off the heartbeat.
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
  object caster;
 
  caster = who ? who : this_player();
  str = (string)caster->expand_nickname(str);

  ret = spell(caster, str);
  if (stringp(ret)) 
    {
    notify_fail(ret);
    return 0;
    }
  return 1;
}
 
mixed spell(object caster, string str) 
{     
  mixed ob;
  int skill;
  int check;
  int achit, THAC0, defenderac, result;

  if ( (int)caster->adjust_gp(-SP_COST) < 0)
	return "Too low on power.\n";
  if (!str || str == "")
	return "You wave your hands in the air trying to touch nothing.\n";
  ob = find_match(str, environment(caster));
  if (sizeof(ob))
	ob = ob[0];
  else
	ob = 0;

  if (ob && !living(ob))
    	return ("Why kill something already dead?\n");
  if (ob && ob->query_creator())
    	return ("You don't think it is wise to kill an Immortal.\n");
  if (ob && ob->query_property("dead"))
    	return (string)ob->query_cap_name() + " is already dead.\n";
  if (ob && ob->query_pacify_spell())
	return (string)ob->query_cap_name()+" looks too harmless to kill.\n";

  if (ob && member_array(caster,ob->query_attacker_list()) != -1)  
	return("You try to reach your victim, but miss in the rush of "
	  "combat.\n");

  tell_object(caster, "You begin to cast Finger of Death.\n");
  tell_room(environment(caster), caster->query_cap_name()+
	" begins to cast a spell.\n", caster);

  caster->add_spell_effect(4, SPELLTYPE, SP_NAME, this_object(),
    "hb_spell", ({ ob }) );
  return 1;
}

int hb_spell( object caster, mixed* params, int time )
{
  object ob;
  int skill;
  int check;
  int achit, THAC0, defenderac, result;

  switch( time )
  {
    case 4:
	tell_object(caster, "You chant in a foul tongue.\n");
	tell_room(environment(caster), caster->query_cap_name()+
	  " chants in a foul tongue.\n", caster);
	return 1;
    case 3:
	tell_object(caster, "You raise your hand up high, your chanting "
	  "reaching a crescendo.\n");
	tell_room(environment(caster), caster->query_cap_name()+
	  " raises "+caster->query_possessive()+" hand up high, the chanting "
	  "reaching a crescendo.\n", caster );
	return 1;
    case 2:
	tell_object(caster, "Your hand starts to glow with an evil light, "
	  "pulsing green and blue.\n");
	tell_room(environment(caster), caster->query_cap_name()+
	  "'s hand starts to glow with an evil light, pulsing green and "
	  "blue.\n", caster);
	return 1;
    default:
	break;
  }

  ob = params[0];
  if ( !ob || environment(ob) != environment(caster) )
  {
	tell_object(caster, "Your target isn't here.\n");
	tell_room(environment(caster), caster->query_cap_name()+" looks "
	  "rather confused and curses, the glow around "+
	  caster->query_possessive()+" hand dissappearing.\n", caster);
	return 1;
  }

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
    	tell_object(ob, "You notice "+caster->query_cap_name()+
      	  " tries to touch you with the glowing finger, but misses.\n");
    	caster->attack_ob(ob);
    	tell_object(caster, "You try to reach for your victim, but miss.\n");
	tell_room(environment(caster), caster->query_cap_name()+
	  " reaches toward "+ob->query_cap_name()+", but misses, and the "
	  "glow around "+caster->query_possessive()+" hands fades.\n",
	  ({ caster, ob }) );
	ob->attack_by(caster);
	return 1;
  }
  tell_object(caster,"You touch "+ob->query_cap_name()+" and "+
	ob->query_pronoun()+" screams horribly as "+ob->query_possessive()+
	" life ends.\n");
  tell_room(environment(caster), (string)caster->query_cap_name() 
	+" touches "+(string)ob->query_cap_name()+" and the poor victim "
	"screams horribly and dies.\n", ({ ob, caster }) );
  tell_object(ob, "You feel utter pain as "+ (string)caster->query_cap_name()+
	" touches you, and then nothing..\n\n");
  ob->do_death(caster);
  return 1;
}
