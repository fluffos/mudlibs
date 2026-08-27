/*** Major Missile Spell ***/
/*** Created by Eerevann Tokani ***/


#define SP_NAME "Major Missile"
#define GP_COST 10
#define SPELLTYPE "offensive"
#define TYPE "magical"
#define SIZE_OF_DICE 4
#define save_type "spells"

int ADJ_COST;

string help() {
       return
       "\n\n"
       "Spell Name: "+SP_NAME+"\n"
       "School: Invocation\n"
       "Level: 5th\n"
       "Gp Cost: "+GP_COST+"\n"
       "Damage Type: Magical\n"
       "Saving Throw: None\n"
       "Description: \n"
       "    This spell will send small bolts of energy at the target.  The"
       " bolts do 2-5 points of damage each.  The wizard gets 1 missile "
       "for every 2 levels of experience, up to a maximum of 15 missiles.\n";
       

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
  say(this_player()->query_cap_name()+" begins to cast an offensive spell.\n",
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
   int i;
 int damage;
 int NO_OF_DICE;

 NO_OF_DICE = ((this_player()->query_level())+1)/2;

 if(NO_OF_DICE == 0)
    NO_OF_DICE = 1;

 if (NO_OF_DICE > 15)
    NO_OF_DICE = 15;


  if (!params[1])
  {
    tell_object(this_player(),
      "Your spell failed ... there is no one of that name here.\n");
    return 0;
  }
  
   /* Specialists spend only half guild points to cast spells native to their
    * school, so GP_COST is checked and halved, if necessary.     */
  
  ADJ_COST = GP_COST;
  
  if((string)previous_object()->query_guild_name() == "invoker")
    ADJ_COST = GP_COST/2;
  
  if (params[2] && (int)previous_object()->adjust_gp(-ADJ_COST)<0)
  {
    tell_object(previous_object(), "You are too mentally drained to cast.\n");
    return 0;
  }
    
  say((string)previous_object()->query_cap_name()+
   " chants, 'majio magyiz myssl'.\n", ({params[1],previous_object()}));
    
  if(params[1] == previous_object())
   { 

   /** when cast upon self ***  only need altar chant part ***/

    tell_object(params[1], "Wouldn't that be suicide?\n");
    say((string)previous_object()->query_cap_name()+
      " stops casting.\n",params[1]);
   }
  else
  {
   tell_object(previous_object(), "You chant, 'majio magyiz myssl'.\n");
   
   tell_object(params[1], (string)previous_object()->query_cap_name() +
    " chants, 'majio magyiz myssl'.\n");
   
   tell_object(params[1], "You are hit by "+NO_OF_DICE+" magic missile(s).\n");
   
   tell_object(previous_object(), "You cast "+SP_NAME+" and hit "+
    (string)params[1]->query_cap_name() + " with "+NO_OF_DICE+
     " magic missile(s).\n");
   
   say((string)previous_object()->query_cap_name()+
    " finishes a spell as "+params[1]->query_cap_name()+" is struck by "+
      NO_OF_DICE+" magic missiles(s).\n",
       ({params[1],previous_object()}) );
  }

  for ( i=1 ; i<=NO_OF_DICE ; i++)
    damage = damage + random(SIZE_OF_DICE)+2;

  params[1]->spell_damage(params[1],damage,TYPE);

  params[1]->attack_by(previous_object());

  return GP_COST;

}
