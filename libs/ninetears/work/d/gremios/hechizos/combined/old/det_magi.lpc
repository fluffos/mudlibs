/*** Detect Magic Spell ***/
/*** Created by Eerevann Tokani ***/


#define SP_NAME "Detect Magic"
#define GP_COST 2
#define SPELLTYPE "misc"

int ADJ_COST;

string help() {
       return
       "\n\n"
       "Spell Name: "+SP_NAME+"\n"
       "School: Lesser Divination\n"
       "Level: 1st\n"
       "Gp Cost: "+GP_COST+"\n"
       "Description: \n"
       "    This spell is used to determine whether an item is magical or "
       "not.  The brightness of a magical item also gives the caster "
       "an idea of its power.  This spell must be cast upon and item to "
       "work properly.\n\n";
       

}

mixed spell(string str, int skill, int cast);

int cast_spell(string str)
{
  int skill;
  mixed ret;

  
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

  if ((int)this_player()->query_spell_effect(SPELLTYPE))
    return "You are already casting an "+SPELLTYPE+" spell.\n";
  ob = find_match(str, environment(this_player()));
  if (sizeof(ob))
    ob = ob[0];
  else
    ob = 0;

  this_player()->add_spell_effect(1, SPELLTYPE, SP_NAME,
    this_object(), "hb_spell", ({ skill,ob,cast }));
  return 1;
}

int hb_spell(object attacker, mixed *params)
{
/*** variables, dependant upon spell ***/


  if (!params[1])
  {
    tell_object(this_player(),
    "Your spell failed ... the item isn't here.\n");
    return 0;
  }
   if(living(params[1]))
   {
    tell_object(this_player(),
      "You can't cast this spell upon a living person!\n");
    return 0;
   }

   /* Specialists spend only half guild points to cast spells native to their
    * school, so GP_COST is checked and halved, if necessary.     */
  
  ADJ_COST = GP_COST;
  
  if((string)previous_object()->query_guild_name() == "diviner")
    ADJ_COST = GP_COST/2;
  
  if (params[2] && (int)previous_object()->adjust_gp(-ADJ_COST)<0)
  {
    tell_object(previous_object(), "You are too mentally drained to cast.\n");
    return 0;
  }
    
  say((string)previous_object()->query_cap_name()+
   " chants, 'magius is iseio'.\n", ({params[1],previous_object()}));
    


    tell_object(previous_object(), "You chant, 'magius is iseio'.\n");
    tell_object(previous_object(), "You cast "+SP_NAME+" upon the "+
      params[1]->query_short()+".\n");
    say((string)previous_object()->query_cap_name()+
      " casts a spell upon the "+params[1]->query_short()+".\n",
      previous_object());
    say((string)previous_object()->query_cap_name()+
      " looks intently at the "+params[1]->query_short()+".\n",
      previous_object());
    tell_object(previous_object(), 
       params[1]->enchant_string()+"\n");
    
 /*** specific spell stuff here ***/

  return GP_COST;
}
