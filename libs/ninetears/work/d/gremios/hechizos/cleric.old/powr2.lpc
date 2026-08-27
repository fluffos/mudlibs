#define save_type "magical"
#define SP_NAME "Power Word: Die"
#define SPELLTYPE "offensive"
#define GP_COST 40

mixed spell(object caster,string str);

/* Power word Die.
  Made by Baldrick June 1993.
    Mods for FR jan '95, by the same nerd.
    Uses saving throw to balance the spell. But it should be *very* high level
  To get it:
  Have fun with it.

  Wonderflug's mods:
  --Magic resistance done.   	
  --Check for pacified target.
  --Added a casting delay, some new fancy messages. 
  --Basically rewrote it.
*/

string help() 
{
  return "\n"
	"Spell name: "+SP_NAME+"\n"
	"GP Cost: "+GP_COST+"\n"
	"Sphere: All\n"
	"\nDescription: \n"
	"This spell kills the one you use it at; if the victim is "
	"powerful enough it may survive.\n\n";
}

int cast_spell(string str,object cast)
{
  mixed ret;
  object caster;

  caster = cast ? cast : this_player();

  if(interactive(caster))
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

  if ( (int)caster->query_spell_effect(SPELLTYPE) )
    return "You are already casting a spell.\n";

  if ( !str || str == "" )
	return "You shout and shout but feel that a target would help.\n";

  ob = find_match( str, environment(caster) );
  if ( sizeof(ob) )
    ob = ob[0];
  else ob = 0;

  if (ob && !living(ob))
        return ("All that shouting at dead objects tires you out somewhat.\n");
  if (ob && ob->query_creator())
        return ("You don't think it is wise to kill an immortal.\n");
  if (ob && ob->query_property("dead"))
         return (string)ob->query_cap_name()+" is already dead.\n";
  if (ob && ob->query_pacify_spell())
	return ("You don't feel like harming "+(string)ob->query_cap_name()+
	  ", seeing how peaceful "+ob->query_pronoun()+" is.\n");

  if(ob && member_array(caster,ob->query_attacker_list()) != -1)
        return("You cannot concentrate enough while you are fighting "
	  "your target.\n");

  tell_object(caster, "You begin to cast Power Word: Die.\n");
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
  int cost;
  int c_roll, t_roll;

  switch( time )
  {
    case 4:
	tell_object(caster, "You start to chant in a hissing, "
	  "cursing tongue.\n");
	tell_room(environment(caster), caster->query_cap_name()+" chants "
	  "quietly in a hissing, cursing sound.\n", caster);
	return 1;
    case 3:
	tell_object(caster, "Your chanting becomes a vile, twisted "
	  "shouting.\n");
	tell_room(environment(caster), caster->query_cap_name()+"'s chant "
	  "grows louder, into a foul, twisted shout.\n", caster);
	return 1;
    case 2:
	tell_object(caster, "You cut off abruptly, a pall of silence "
	  "drops over the area.\n");
	tell_room(environment(caster), caster->query_cap_name()+" cuts off "
	  "abruptly and an ominous silence fills the air.\n", caster);
	return 1;
    default:
	break;
  }

  cost = GP_COST;

  if ( (int)caster->adjust_gp(-cost) < 0)
	return "Too low on power.\n";

  ob = params[0];

  if (!ob || environment(ob) != environment(caster) )
  {
	tell_object(caster, "Your target seems to have left.\n");
	tell_room(environment(caster), caster->query_cap_name()+
	  " looks very confused and curses.\n", caster);
	return 1;
  }

/* here is the "saving throw" I'm trying out */

  c_roll = random( (int)caster->query_level() * (int)caster->query_wis() + 5 );
  t_roll = (int)ob->query_level() * (int)ob->query_wis();
  if ( c_roll * ( (100 - (int)ob->query_property("magical")) / 100 ) < t_roll )
  {
	tell_object(ob, "You hear "+(string)caster->query_cap_name()+
	  " whisper death to you through the silence.\n");
	caster->attack_ob(ob);
	return ("Your word comes out only as a whisper.\n");
  }

  tell_object(caster,"You shout into the sudden silence: DIE "+
	ob->query_cap_name()+"!\n\nYou call upon the gods to help you kill " +
         ob->query_cap_name() + ".\n");
  tell_room(environment(caster),(string)caster->query_cap_name() + 
	" shouts in the sudden silence: DIE "
	+(string)ob->query_cap_name() + "!\n",
	({ caster }) );
  tell_object(ob, "\nYou feel " + (string)caster->query_cap_name() +
    	"'s word attack you.\n\nThe powerword killed you.\n\n");
  ob->do_death(caster);
  return 1;
}
