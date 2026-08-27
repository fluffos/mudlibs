/*** Flame Arrow Spell ***/
/*** Created by Eerevann Tokani ***/
/*** Completely rewritten by Wonderflug, June '95 ***/
/* fixed for NPC's Taniwha */

#define SP_NAME "Flame Arrow"
#define GP_COST 6
#define SPELLTYPE "offensive"
#define TYPE "fire"
#define save_type "fire"
#define LEVELS_PER_ARROW 1
#define LEVELS_PER_BONUS 5
#define SIZE_OF_DICE 4

inherit "/std/spells/patch.c";

/* find_unique_match() does a find match that ensures the returned
	object list contains no duplicates
	find_one_match() returns only the first matched object
*/
mixed find_unique_match(string find,mixed in);
mixed find_one_match(string find,mixed in);
int wiz_fix_damage(object caster,object victim,int damage,string save);

 /*** help file ***/
string help() {
  return
       "\n\n"
       "Spell Name: "+SP_NAME+"\n"
       "School: Conjuration\n"
       "Level: 3rd\n"
       "Gp Cost: "+GP_COST+"\n"
       "Damage Type: "+TYPE+"\n"
       "Saving Throw: Special\n"
       "Description: \n"
       "    This spell will hurl fiery bolts at a single target.  The "
       "caster gets 1 arrow per level of experience, to a maximum of 20 "
      "arrows.  In addition, you will get up to 5 extra or less.  One arrow "
       "will be shot each round, until all have been shot.  Each arrow "
       "does 1-4 hp of damage, with a +1 damage bonus per "+LEVELS_PER_BONUS+
       " levels "
       "of the caster.  If the target leaves the room, then once a saving "
       "throw is made following that, no further arrows will hit.\n\n";
       
}

mixed spell(string str, object caster);

int cast_spell(string str,object cast)
{
  int skill;
  mixed ret;
  object caster;

  if(cast) caster = cast;
  else caster= this_player();

  if(interactive(caster))
	  str = (string)caster->expand_nickname(str);

  ret = spell(str, caster);
  if (stringp(ret))
  {
	 notify_fail(ret);
	 return 0;
  }


  tell_object(caster,"You start to cast "+SP_NAME+".\n");
  tell_room(environment(caster),caster->query_cap_name()+" begins to cast "
	"a spell.\n", caster);
  return 1;
}

mixed spell(string str, object caster)
{
  mixed ob;
  int num_arrows;
  int damage_bonus;

  if ((int)caster->query_spell_effect(SPELLTYPE))
    return "You are already casting an "+SPELLTYPE+" spell.\n";
  
  ob = find_one_match(str, environment(caster));
  if (sizeof(ob))
    ob = ob[0];
  else
    return "Your target is not here.\n";

  if ((int)caster->query_gp() < GP_COST )
    return "You lack the power to cast this spell.\n";
  else caster->adjust_gp(-GP_COST);

  if ( ob == caster )
    return "That would be suicide!\n";

  num_arrows = (int)caster->query_level() / LEVELS_PER_ARROW;
  num_arrows = num_arrows > 20 ? 20 : num_arrows;
  num_arrows += random(10)-5;
  num_arrows = num_arrows <=0 ? 1 : num_arrows;
  damage_bonus = (int)caster->query_level() / LEVELS_PER_BONUS;

  caster->add_spell_effect(num_arrows+2, SPELLTYPE, SP_NAME,
    this_object(), "hb_spell", ({ num_arrows+2,ob,damage_bonus }) );
  return 1;
}

int hb_spell(object caster, mixed *params, int time)
{
  int damage;

  if (!params[1])
  {
    tell_object(caster,  "Your fiery bow goes up in smoke "
      "as your target is no more.\n");
    call_out("end_spell",0,caster);
    return 0;
  }
  if ( time == params[0] )
  {
    if ( environment(caster) != environment(params[1]) )
    {
      tell_object(caster, "Your target seems to have left.\n");
      call_out("end_spell",0,caster);
      return 1;
    }
      tell_object(caster, "A bow of pure white fire appears in your hands.\n");
      tell_room(environment(caster), "A bow of pure white fire suddenly "
        "appears in "+caster->query_cap_name()+"'s hands!\n", caster);
  return 1;
  }
  if ( time == params[0]-1 )
  {
    if (environment(caster) != environment(params[1]) )
    {
      tell_object(caster, "Your target seems to have left.\n");
      call_out("end_spell",0,caster);
      return 1;
    }
      tell_object(caster, (params[0]-2)+" bolts of fire explode into existence "
        "and float in the air around you.\n");
      tell_room(environment(caster), "The air itself bursts into "+
        (params[0]-2)+" bolts of flame, floating around "+
        caster->query_cap_name()+".\n", caster);
      return 1;
  }
 
  damage = random(SIZE_OF_DICE)+1+params[2];
  damage = wiz_fix_damage(caster,params[1],damage,save_type);
  params[1]->spell_damage(params[1],damage,TYPE,caster);
  params[1]->attack_by(caster);

  tell_object(caster, "You shoot one of the fiery bolts at "+
    params[1]->query_cap_name()+".\n");
  tell_object(params[1], "A fiery arrow comes streaking at you!\n");
  switch( damage )
  {
    case 1:
      tell_object(caster, "Your arrow singes "+params[1]->query_cap_name()+
        ".\n");
      tell_object(params[1], "You are singed as the flaming arrow grazes "
        "you.\n");
      break;
    case 2..4:
      tell_object(caster, "You burn "+params[1]->query_cap_name()+".\n");
      tell_object(params[1], "The flaming arrow burns you.\n");
      break;
    case 5..7:
      tell_object(caster, "You burn "+params[1]->query_cap_name()+
        " severely.\n");
      tell_object(params[1], "The flaming arrow burns you severely.\n");
      break;
    case 8..100:
      tell_object(caster, "Your arrow explodes into "+
        params[1]->query_cap_name()+".\n");
      tell_object(params[1], "The flaming arrow explodes as it flies "
        "into you!\n");
      break;
    default:
      tell_object(params[1], "You narrowly avoid the flaming missile.\n");
      tell_object(caster, "Your flaming arrow whizzes by "+
        params[1]->query_cap_name()+" harmlessly.\n");
      break;
  }

  if ( time == 1 )
  {
    tell_object(caster, "Your fiery bow dies away into a puff of smoke "
      "as you use up the last arrow.\n");
  }
    
  if ( environment(params[1]) != environment(caster) )
  {
    tell_room(environment(caster), caster->query_cap_name()+" pulls "+
      caster->query_possessive()+" flaming bow back, and shoots one "
      "of the fiery bolts floating around "+caster->query_objective()+
      "off into the distance.\n", caster);
    tell_room(environment(params[1]), params[1]->query_cap_name()+" is "
      "struck by a flaming arrow!\n", params[1]);
    if ( (int)params[1]->query_dex()+(int)params[1]->query_level() >
        random((int)caster->query_int()) + (int)caster->query_level() )
    {
      tell_object(caster, "You lose track of "+params[1]->query_cap_name()+
        ", and your bow dies into smoke.\n");
      call_out("end_spell",0,caster);
      return 1;
    }
  }
  else tell_room(environment(caster), caster->query_cap_name()+" pulls back "+
    caster->query_possessive()+" flaming bow and blasts an arrow at "+
    params[1]->query_cap_name()+".\n", ({ caster, params[1] }) );
   
  return GP_COST;

}

void end_spell(object caster)
{
  caster->remove_spell_effect(SP_NAME);
}
