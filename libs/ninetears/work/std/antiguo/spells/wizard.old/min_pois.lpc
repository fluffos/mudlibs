/*** Minor Poison Protection Spell ***/
/*** Created by Eerevann Tokani ***/


#define SP_NAME "Minor Poison Resistance"
#define GP_COST 6
#define TYPE "poison"

int ADJ_COST;

string help() {
       return
       "\n\n"
       "Spell Name: "+SP_NAME+"\n"
       "School: Abjuration\n"
       "Level: 3rd\n"
       "Gp Cost: "+GP_COST+"\n"
       "Description: \n"
       "    This spell reduces damage done by Poison based attacks "
       "by 25% plus +1% per level of the caster.\n"
       "    The duration is based upon the casters level.\n";
       

}

mixed spell(string str, int skill, int cast);

int cast_spell(string str)
{
  int skill;
  mixed ret;

  str = (string)this_player()->expand_nickname(str);
  
  ret = spell(str, skill, 1);
  if (stringp(ret))
  {
    notify_fail(ret);
    return 0;
  }
  write("You start to cast "+SP_NAME+".\n");
  say(this_player()->query_cap_name()+" begins to cast a spell.\n",
     previous_object());
  return 1;
  }

mixed spell(string str, int skill, int cast)
{
  mixed ob;

  if ((int)this_player()->query_spell_effect("defensive"))
    return "You are already casting an defensive spell.\n";
  ob = find_match(str, environment(this_player()));
  if (sizeof(ob))
    ob = ob[0];
  else
    ob = 0;

  this_player()->add_spell_effect(1, "defensive", SP_NAME,
    this_object(), "hb_spell", ({ skill,ob,cast }));
  return 1;
}

int hb_spell(object caster, mixed *params)
{
  int resist_value;
  int level;

  if (!params[1])
  {
    tell_object(this_player(),
      "Your spell failed ... there is no one of that name here.\n");
    return 0;
  }
  
   /* Specialists spend only half guild points to cast spells native to their
    * school, so GP_COST is checked and halved, if necessary.     */
  
  ADJ_COST = GP_COST;
  
  if((string)previous_object()->query_guild_name() == "abjurer")
    ADJ_COST = GP_COST/2;
  
  if (params[2] && (int)previous_object()->adjust_gp(-ADJ_COST)<0)
  {
    tell_object(previous_object(), "You are too mentally drained to cast.\n");
    return 0;
  }
    
  say((string)previous_object()->query_cap_name()+
   " chants, 'mior poyze rissas'.\n", ({params[1],previous_object()}));
    
  if(params[1] == previous_object())
   { 
    tell_object(params[1], "You chant, 'mior poyze rissas'.\n");
    tell_object(params[1], "You cast "+SP_NAME+" upon yourself.\n");
    say((string)previous_object()->query_cap_name()+
      " casts a spell upon "+params[1]->query_objective()+"self.\n",params[1]);
   }
  else
  {
   tell_object(previous_object(), "You chant, 'mior poyze rissas'.\n");
   
   tell_object(params[1], (string)previous_object()->query_cap_name() +
    " chants, 'mior poyze rissas'.\n");
   
   tell_object(params[1], "You feel slightly resistant to Poison attacks.\n");
   
   tell_object(previous_object(), "You cast "+SP_NAME+" on "+
    (string)params[1]->query_cap_name() + ".\n");
   
   say((string)previous_object()->query_cap_name()+
    " casts a spell upon "+params[1]->query_cap_name()+".\n",
       ({params[1],previous_object()}) );
  }

  level = (int)previous_object()->query_level();
  resist_value = level + 25;

   params[1]->add_timed_property(TYPE,resist_value,50+(level*4));
  return GP_COST;
}

